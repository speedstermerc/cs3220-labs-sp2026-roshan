// MAC unit, the building block of the systolic array Multiply-Accumulate operation
module mac #(
    parameter IN_WIDTH = 8,
    parameter IN_FRAC = 0,
    parameter OUT_WIDTH = 8,
    parameter OUT_FRAC = 0,
    parameter MULT_LAT = 3,
    parameter ADD_LAT = 1,
    parameter K = 1,
    parameter ROWS = 1,
    parameter COLS = 1,
    parameter COLS_IDX = 1,
    parameter ROWS_IDX = 1
)(
    input                      clk,
    input                      rst,
    input                      rst_accumulator_in,
    input                      stream_out_rdy_in,
    input       [IN_WIDTH-1:0] row_data_in,
    input       [IN_WIDTH-1:0] col_data_in,
    input       [OUT_WIDTH-1:0] bypass_data_in, 
    output reg  [IN_WIDTH-1:0] row_data_out,
    output reg  [IN_WIDTH-1:0] col_data_out,
    output reg                 rst_accumulator_out,
    output reg                 stream_out_rdy_out,
    output reg [OUT_WIDTH-1:0] psum_out
);


    //TODO: Signal declarations
    wire [OUT_WIDTH-1:0] mult_out;
    wire [OUT_WIDTH-1:0] add_out;
    wire mult_done;
    wire add_done;


    //TODO: multiplier instantiation
    multiplier #(
        .INPUT_A_WIDTH(IN_WIDTH), .INPUT_B_WIDTH(IN_WIDTH),
        .INPUT_A_FRAC(IN_FRAC), .INPUT_B_FRAC(IN_FRAC),
        .OUTPUT_WIDTH(OUT_WIDTH), .OUTPUT_FRAC(OUT_FRAC),
        .DELAY(MULT_LAT)
    ) mult_inst (
        .clk(clk), .reset(rst), .en(1'b1), .stall(1'b0),
        .a_in(row_data_in), .b_in(col_data_in),
        .out(mult_out), .done(mult_done)
    );


    //TODO: adder instantiation

    adder #(
        .INPUT_A_WIDTH(OUT_WIDTH), .INPUT_B_WIDTH(OUT_WIDTH),
        .INPUT_A_FRAC(OUT_FRAC), .INPUT_B_FRAC(OUT_FRAC),
        .OUTPUT_WIDTH(OUT_WIDTH), .OUTPUT_FRAC(OUT_FRAC),
        .DELAY(ADD_LAT)
    ) add_inst (
        .clk(clk), .reset(rst), .en(1'b1), .stall(1'b0),
        .a_in(mult_out), .b_in(adder_b_in),
        .out(add_out), .done(add_done));

    //TODO: signal propagation and synchronization
    //Major approaches to look out for:
    // 1. rst_accumulator and stream_out_rdy are major control signals that dictates the flow of the data and when to reset the accumulator between different matrix multiplications
    // 2. An important part of the following design is to figure out how the data from multipliers and adders should be paired with the above two control signals
    // 3. Mainly you need to know: should I pass the results of this very own MAC's accumulator to the next MAC's accumulator or should I pass the results of the previous MAC's accumulator to this MAC's accumulator and when to do so
    // 4. Also, when should be the exact time point to reset the accumulator so my current results will not be cleared by mistake and the next matrix multiplication can start cleanly.
    
    // Pass data to neighboring MAC units
    always @(posedge clk) begin
        if (rst) begin
            row_data_out <= 0;
            col_data_out <= 0;
            rst_accumulator_out <= 0;
            stream_out_rdy_out <= 0;
        end else begin
            row_data_out <= row_data_in;
            col_data_out <= col_data_in;
            rst_accumulator_out <= rst_accumulator_in;
            stream_out_rdy_out <= stream_out_rdy_in;
        end
    end

    // pipeline syncronization for multiplier and adder outputs
    localparam TRUE_MULT_LAT = (MULT_LAT <= 1) ? 1 : MULT_LAT;
    localparam TRUE_ADD_LAT  = (ADD_LAT <= 1) ? 1 : ADD_LAT;

    reg [31:0] rst_mult_delay;
    reg [63:0] stream_out_delay;
    
    always @(posedge clk) begin
        if (rst) begin
            rst_mult_delay <= 0;
            stream_out_delay <= 0;
        end else begin
            /// shift registers to track the control signals through the pipeline
            rst_mult_delay <= {rst_mult_delay[30:0], rst_accumulator_in};
            stream_out_delay <= {stream_out_delay[62:0], stream_out_rdy_in};
        end
    end

    // When add_rst is high, the adder feeds 0
    wire add_rst = rst_mult_delay[TRUE_MULT_LAT-1];

    wire stream_now = stream_out_delay[TRUE_MULT_LAT+TRUE_ADD_LAT-1];

    wire [OUT_WIDTH-1:0] adder_b_in = add_rst ? {OUT_WIDTH{1'b0}} : add_out;


    // FROM SPEC delay = array_dimension - column_index - 1
    // To allign the time at which all columns exit
    localparam P_DELAY = (COLS - COLS_IDX - 1 >= 0) ? (COLS - COLS_IDX - 1) : 0;
    
    reg [OUT_WIDTH-1:0] psum_delay_line [0:P_DELAY];
    reg stream_now_delay_line [0:P_DELAY];
    integer i;
    
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i <= P_DELAY; i = i + 1) begin
                psum_delay_line[i] <= 0;
                stream_now_delay_line[i] <= 0;
            end
        end else begin
            psum_delay_line[0] <= add_out;
            stream_now_delay_line[0] <= stream_now;
            for (i = 1; i <= P_DELAY; i = i + 1) begin
                psum_delay_line[i] <= psum_delay_line[i-1];
                stream_now_delay_line[i] <= stream_now_delay_line[i-1];
            end
        end
    end

    wire [OUT_WIDTH-1:0] ready_psum = psum_delay_line[P_DELAY];
    wire ready_stream = stream_now_delay_line[P_DELAY];

    localparam BYPASS_W = $clog2(COLS+1) > 0 ? $clog2(COLS+1) : 1;
    reg [BYPASS_W-1:0] bypass_cnt;
    
    always @(posedge clk) begin
        if (rst) begin
            bypass_cnt <= 0;
            psum_out <= 0;
        end else begin
            if (ready_stream) begin
                // output own result
                psum_out <= ready_psum;
                bypass_cnt <= BYPASS_W'(COLS - 1);
            end else if (bypass_cnt > 0) begin
                // forward the bypass.
                psum_out <= bypass_data_in;
                bypass_cnt <= bypass_cnt - BYPASS_W'(1);
            end else begin
                psum_out <= 0;
            end
        end
    end
    
endmodule
