module ctrl #(
    parameter IN_WIDTH = 8,
    parameter OUT_WIDTH = 16,
    parameter ROWS = 4,
    parameter COLS = 4,
    parameter MULT_LAT = 1,
    parameter ACC_LAT = 1
)(
    input clk,
    input rst,
    input input_rst_accumulator,
    input input_stream_out_rdy,
    output [COLS-1:0] rst_accumulator,
    output [COLS-1:0] stream_out_rdy
);

    //TODO: Signal declarations
    reg [COLS-1:0] rst_acc_reg;
    reg [COLS-1:0] stream_out_rdy_reg;
    integer i;


    //TODO: Rst and stream out rdy signal propagation and synchronization logic among different MAC units
    always @(posedge clk) begin
        if (rst) begin
            rst_acc_reg <= 0;
            stream_out_rdy_reg <= 0;
        end else begin
            // Shift register logic: reg[0] represents a 1-cycle delay
            rst_acc_reg[0] <= input_rst_accumulator;
            stream_out_rdy_reg[0] <= input_stream_out_rdy;
            
            for (i = 1; i < COLS - 1; i = i + 1) begin
                rst_acc_reg[i] <= rst_acc_reg[i-1];
                stream_out_rdy_reg[i] <= stream_out_rdy_reg[i-1];
            end
        end
    end

    // Column 0 is directly assigned to remain synchronized with row_data_in (0-cycle delay)
    assign rst_accumulator[0] = input_rst_accumulator;
    assign stream_out_rdy[0]  = input_stream_out_rdy;

    // Columns 1 to COLS-1 are driven by the shift registers (N-cycle delay)
    genvar j;
    generate
        for (j = 1; j < COLS; j = j + 1) begin : ctrl_delays
            assign rst_accumulator[j] = rst_acc_reg[j-1];
            assign stream_out_rdy[j]  = stream_out_rdy_reg[j-1];
        end
    endgenerate
endmodule