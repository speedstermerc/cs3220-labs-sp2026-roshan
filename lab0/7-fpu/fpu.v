module fpu #(
    parameter DATA_WIDTH = 32,
    parameter INST_WIDTH = 1
)(
    input                   i_clk,
    input                   i_rst_n,
    input  [DATA_WIDTH-1:0] i_data_a,
    input  [DATA_WIDTH-1:0] i_data_b,
    input  [INST_WIDTH-1:0] i_inst,
    input                   i_valid,
    output reg [DATA_WIDTH-1:0] o_data,
    output reg                 o_valid
);

    wire        sign_a = i_data_a[31];
    wire [7:0]  exp_a  = i_data_a[30:23];
    wire [23:0] mant_a = (exp_a == 8'd0) ? {1'b0, i_data_a[22:0]} : {1'b1, i_data_a[22:0]}; // stupid bug. only prepend 1 if the number isn't trying to be 0

    wire        sign_b = i_data_b[31];
    wire [7:0]  exp_b  = i_data_b[30:23];
    wire [23:0] mant_b = (exp_b == 8'd0) ? {1'b0, i_data_b[22:0]} : {1'b1, i_data_b[22:0]};

    reg [31:0]  answer_wire;
    //registers used in addition
    reg [7:0] diff;
    reg [7:0] add_exp;
    reg [27:0]  m_a, m_b, m_sum, m_temp; // 1 carry out, 1 hidden, 23 bits mantissa , 1 round bit, 1 sticky bit
    reg         res_sign;
    integer     i;
    // m_sum is [27:0]. frac is [25:3]. GRS is [2:1:0].
    reg [22:0] rounded_mant;
    reg [7:0]  final_exp;
    wire L = m_sum[3]; // LSB
    wire G = m_sum[2];
    wire R = m_sum[1];
    wire S = m_sum[0];

    //register used in multiplication
    reg [47:0] mul_product;
    reg [8:0]  mul_exp;      // 9 bits for the bias subtraction and potential overflow
    reg        mul_sign;

    // rounding logic
    wire G_m = mul_product[22];
    wire R_m = mul_product[21];
    wire S_m = |mul_product[20:0]; 
    wire L_m = mul_product[23];
    
    reg [22:0] m_rounded;
    reg [7:0]  e_final;

    always @(*) begin
        
        answer_wire = 32'b0;

        case (i_inst)
            1'd0 : begin //ADD
                //align mantissa
                if (exp_a > exp_b) begin
                    add_exp = exp_a;
                    diff = exp_a - exp_b;
                    m_a = {1'b0, mant_a, 3'b000};
                    m_temp = {1'b0, mant_b, 3'b000};
                    m_b = m_temp >> diff;
                    m_b[0] = m_b[0] | (| (m_temp & ((32'b1 << diff) - 1))); 
                end else begin
                    add_exp = exp_b;
                    diff = exp_b - exp_a;
                    m_b = {1'b0, mant_b, 3'b000};
                    m_temp = {1'b0, mant_a, 3'b000};
                    m_a = m_temp >> diff;
                    m_a[0] = m_a[0] | (| (m_temp & ((32'b1 << diff) - 1)));
                end     

                // add or subtract the mantissas depending on sign
                if (sign_a == sign_b) begin
                    m_sum = m_a + m_b;
                    res_sign = sign_a;
                end else begin
                    if (m_a >= m_b) begin
                        m_sum = m_a - m_b;
                        res_sign = sign_a;
                    end else begin
                        m_sum = m_b - m_a;
                        res_sign = sign_b;
                    end
                end

                // normalize
                if (m_sum[27]) begin // Overflow. shift right one
                    m_sum = m_sum >> 1;
                    add_exp = add_exp + 1;
                end else if (m_sum != 0) begin
                    // shift left until bit 26 is 1
                    for (i = 0; i < 27; i = i + 1) begin
                        if (m_sum[26] == 0 && add_exp > 0) begin
                            m_sum = m_sum << 1;
                            add_exp = add_exp - 1;
                        end
                    end
                end
                
                if (m_sum == 28'd0) begin
                    answer_wire = 32'b0;
                end else begin
                    final_exp = add_exp;

                    if (G && (R || S || L)) begin
                        {m_sum[27], rounded_mant} = m_sum[25:3] + 1'b1;
                        if (m_sum[27]) begin // rounding might cause a carry-out
                            final_exp = final_exp + 1;
                        end
                    end else begin
                        rounded_mant = m_sum[25:3];
                    end
                    
                    answer_wire = {res_sign, final_exp, rounded_mant};
                end

            end
            1'd1 : begin //MUL
                if (exp_a == 8'd0 || exp_b == 8'd0) begin
                    answer_wire = 32'b0;
                end else begin
                    mul_sign = sign_a ^ sign_b;
                    mul_exp = exp_a + exp_b - 8'd127;
                    mul_product = mant_a * mant_b;

                    // normalize
                    // if bit 47 is 1, the result is >= 2.0
                    if (mul_product[47]) begin
                        mul_product = mul_product >> 1;
                        mul_exp = mul_exp + 1;
                    end

                    e_final = mul_exp[7:0];

                    if (G_m && (R_m || S_m || L_m)) begin
                        {mul_product[47], m_rounded} = mul_product[45:23] + 1'b1;
                        if (mul_product[47]) e_final = e_final + 1;
                    end else begin
                        m_rounded = mul_product[45:23];
                    end
                    // now, 46 is guaranteed to be hidden because 1.0 * 1.0 > 1.
                    answer_wire = {mul_sign, e_final, m_rounded};
                end
            end
        endcase
    end



    always @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n) begin
            o_data <= 32'b0;
            o_valid <= 1'b0;
        end else if (i_valid) begin
            o_data <= answer_wire;
            o_valid <= 1'b1;
        end else begin
            o_data <= 32'b0;
            o_valid <= 1'b0;
        end
        
    end
    
    

endmodule