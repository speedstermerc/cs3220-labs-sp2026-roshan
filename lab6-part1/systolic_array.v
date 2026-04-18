// wrapper of the systolic array, instantiate MAC units and control unit, connect them with wires
module systolic_array #(
    parameter IN_WIDTH          = 8,
    parameter IN_FRAC           = 0,
    parameter OUT_WIDTH         = 8,
    parameter OUT_FRAC          = 0,
    parameter MULT_LAT          = 3,                 // Multiplication latency
    parameter ACC_LAT           = 1,                 // Addition latency (<=1, not support pipelined acc)
    parameter ROWS              = 4,                 // Row number of systolic array
    parameter K                 = 4,
    parameter COLS              = 4                  // Column number of systolic array
)(
    input                       clk,
    input                       rst_in,
    input                       rst_accumulator_rdy_in, // If 1, reset accumulator in array
    input                       stream_out_rdy_in_in,      // If 1, stream acc result out

    input [IN_WIDTH*ROWS-1:0]   row_data_in_in,         
    input [IN_WIDTH*COLS-1:0]   col_data_in_in,         
    output [OUT_WIDTH*ROWS-1:0] row_data_out
);
    //TODO: Signal declarations
    // register inputs // something todo with verilator timing issue
    reg       rst;
    reg       rst_accumulator_rdy;
    reg       stream_out_rdy;
    reg [IN_WIDTH*ROWS-1:0] row_data_in;
    reg [IN_WIDTH*COLS-1:0] col_data_in;

    always @(posedge clk) begin
        rst <= rst_in;
        rst_accumulator_rdy <= rst_accumulator_rdy_in;
        stream_out_rdy <= stream_out_rdy_in_in;
        row_data_in <= row_data_in_in;
        col_data_in <= col_data_in_in;
    end

    //TODO: MAC units instantiation
    // - Image you are drawing a spatial diagram of the MAC units; how should you connect the wires of them?
    // - Use generate block to realize the spatial diagram (You are not required to use generate block though)

    wire [IN_WIDTH-1:0] mac_row_in [0:ROWS-1][0:COLS-1];
    wire [IN_WIDTH-1:0] mac_col_in [0:ROWS-1][0:COLS-1];
    wire [IN_WIDTH-1:0] mac_row_out [0:ROWS-1][0:COLS-1];
    wire [IN_WIDTH-1:0] mac_col_out [0:ROWS-1][0:COLS-1];

    wire mac_rst_in [0:ROWS-1][0:COLS-1];
    wire mac_str_in [0:ROWS-1][0:COLS-1];
    wire mac_str_out [0:ROWS-1][0:COLS-1];
    wire mac_rst_out [0:ROWS-1][0:COLS-1];
    
    wire [OUT_WIDTH-1:0] mac_psum_out [0:ROWS-1][0:COLS-1];
    wire [OUT_WIDTH-1:0] mac_bypass_in [0:ROWS-1][0:COLS-1];

    genvar r, c;
    generate
        for (r = 0; r < ROWS; r = r + 1) begin : row_gen
            for (c = 0; c < COLS; c = c + 1) begin : col_gen
                // Matrix A coming in from the left
                if (c == 0) begin
                    assign mac_row_in[r][c] = row_data_in[r*IN_WIDTH +: IN_WIDTH];
                end else begin
                    assign mac_row_in[r][c] = mac_row_out[r][c-1];
                end

                // Matrix B coming in from the top
                if (r == 0) begin
                    assign mac_col_in[r][c] = col_data_in[c*IN_WIDTH +: IN_WIDTH];
                    assign mac_rst_in[r][c] = ctrl_rst_accumulator[c];
                    assign mac_str_in[r][c] = ctrl_stream_out_rdy[c];
                end else begin
                    assign mac_col_in[r][c] = mac_col_out[r-1][c];
                    assign mac_rst_in[r][c] = mac_rst_out[r-1][c];
                    assign mac_str_in[r][c] = mac_str_out[r-1][c];
                end

                // output routing from right to left and bypass routing for accumulation result
                if (c == COLS - 1) begin
                    assign mac_bypass_in[r][c] = 0;
                end else begin
                    assign mac_bypass_in[r][c] = mac_psum_out[r][c+1];
                end

                // generate MAC unit for each spot in the grid
                mac #(
                    .IN_WIDTH(IN_WIDTH), .IN_FRAC(IN_FRAC),
                    .OUT_WIDTH(OUT_WIDTH), .OUT_FRAC(OUT_FRAC),
                    .MULT_LAT(MULT_LAT), .ADD_LAT(ACC_LAT),
                    .ROWS(ROWS), .COLS(COLS),
                    .ROWS_IDX(r), .COLS_IDX(c)
                ) mac_inst (
                    .clk(clk), .rst(rst),
                    .rst_accumulator_in(mac_rst_in[r][c]),
                    .stream_out_rdy_in(mac_str_in[r][c]),
                    .row_data_in(mac_row_in[r][c]),
                    .col_data_in(mac_col_in[r][c]),
                    .bypass_data_in(mac_bypass_in[r][c]),
                    .row_data_out(mac_row_out[r][c]),
                    .col_data_out(mac_col_out[r][c]),
                    .rst_accumulator_out(mac_rst_out[r][c]),
                    .stream_out_rdy_out(mac_str_out[r][c]),
                    .psum_out(mac_psum_out[r][c])
                );
            end
            // map the leftmost PE column output to the boundary port
            assign row_data_out[r*OUT_WIDTH +: OUT_WIDTH] = mac_psum_out[r][0];
        end
    endgenerate

    

    //TODO: Ctrl unit instantiation
    // generate rst accmulator and bypass enable control signals
    wire [COLS-1:0] ctrl_rst_accumulator;
    wire [COLS-1:0] ctrl_stream_out_rdy;

    ctrl #(
        .IN_WIDTH(IN_WIDTH), .OUT_WIDTH(OUT_WIDTH),
        .ROWS(ROWS), .COLS(COLS),
        .MULT_LAT(MULT_LAT), .ACC_LAT(ACC_LAT)
    ) ctrl_inst (
        .clk(clk), .rst(rst),
        .input_rst_accumulator(rst_accumulator_rdy),
        .input_stream_out_rdy(stream_out_rdy),
        .rst_accumulator(ctrl_rst_accumulator),
        .stream_out_rdy(ctrl_stream_out_rdy)
    );

endmodule
