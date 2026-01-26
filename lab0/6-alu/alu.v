module alu #(
    parameter DATA_WIDTH = 32,
    parameter INST_WIDTH = 4
)(
    input                   i_clk,
    input                   i_rst_n,
    input  [DATA_WIDTH-1:0] i_data_a,
    input  [DATA_WIDTH-1:0] i_data_b,
    input  [INST_WIDTH-1:0] i_inst,
    input                   i_valid,
    output [DATA_WIDTH-1:0] o_data,
    output                  o_overflow,
    output                  o_valid
);

    reg [31:0] result_wire;
    reg overflow_wire;
    reg [63:0] mul_holder;
    integer i;

    //output registers
    reg o_data;
    reg o_overflow;
    reg o_valid;

    always @(*) begin
        result_wire = 32'b0;
        overflow_wire = 1'b0;
        mul_holder = 64'b0;
        
        case (i_inst)
            4'd0 : begin //signed add
                result_wire = $signed(i_data_a) + $signed(i_data_b);
                //two + make a - or two - make a +
                overflow_wire = (i_data_a[31] == i_data_b[31]) && (result_wire[31] != i_data_a[31]);
            end
            4'd1 : begin //signed sub
                result_wire = $signed(i_data_a) - $signed(i_data_b);
                // (+) - (-) = (-)     (-) - (+) = (+)
                overflow_wire = (i_data_a[31] != i_data_b[31]) && (result_wire[31] != i_data_a[31]);
            end
            4'd2 : begin //signed mul
                mul_holder = $signed(i_data_a) * $signed(i_data_b);
                result_wire = mul_holder[31:0];
                // if it doesn't perfectly sign extend, then overflow occurred.
                overflow_wire = (mul_holder[63:31] != 33'h000000000) && (mul_holder[63:31] != 33'h1FFFFFFFF);
            end
            4'd3 : begin //signed MAX
                result_wire = $signed(i_data_a) > $signed(i_data_b) ? $signed(i_data_a) : $signed(i_data_b);
                overflow_wire = 0;
            end
            4'd4 : begin //signed MIN
                result_wire = $signed(i_data_a) < $signed(i_data_b) ? $signed(i_data_a) : $signed(i_data_b);
                overflow_wire = 0;
            end
            4'd5 : begin //unsigned add
                {overflow_wire, result_wire} = i_data_a + i_data_b;
            end
            4'd6 : begin //unsigned sub
                {overflow_wire, result_wire} = i_data_a - i_data_b;
            end
            4'd7 : begin //unsigned mul
                mul_holder = i_data_a * i_data_b;
                result_wire = mul_holder[31:0];
                overflow_wire = (mul_holder[63:32] != 32'b0);
            end
            4'd8 : begin //unsigned max
                result_wire = (i_data_a > i_data_b) ? i_data_a : i_data_b;
                overflow_wire = 0;
            end
            4'd9 : begin //unsigned min
                result_wire = (i_data_a < i_data_b) ? i_data_a : i_data_b;
                overflow_wire = 0;
            end
            4'd10 : begin //and
                overflow_wire = 0;
                result_wire = i_data_a & i_data_b;
            end
            4'd11 : begin //or
                overflow_wire = 0;
                result_wire = i_data_a | i_data_b;
            end
            4'd12 : begin //xor
                overflow_wire = 0;
                result_wire = i_data_a ^ i_data_b;
            end
            4'd13 : begin //bitflip
                overflow_wire = 0;
                result_wire = ~i_data_a;
            end
            4'd14 : begin //bitreverse
                overflow_wire = 0;
                for (i=0; i<32; i=i+1) begin
                    result_wire[i] = i_data_a[31-i];
                end
            end
            default: begin
                result_wire = 32'b0;
                overflow_wire = 1'b0;
            end
        endcase
    end

    // signal o_valid
    always @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            o_data <= 32'b0;
            o_valid <= 1'b0;
            o_overflow <= 1'b0;
        end else if (i_valid) begin
            o_data <= result_wire;
            o_overflow <= overflow_wire;
            o_valid <= 1'b1;
        end else begin
            o_valid <= 1'b0; // reset after one cycle (i_valid is one clock cycle so this works)
        end
    end

endmodule