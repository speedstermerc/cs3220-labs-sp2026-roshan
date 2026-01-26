`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

// dummy implementation, please replace with your own
module fsm ( 
    input clk,    // Clocks are used in sequential circuits
    input reset,
    input seq,
    output detected );// seq detector 1101, once detected, output 1 for 1 clock cycle

    reg [2:0] state, next_state;

    localparam START = 3'd0,
        A     = 3'd1,
        B     = 3'd2,
        C     = 3'd3,
        D     = 3'd4;

    always @(posedge clk) begin
        if (reset) begin
            state <= START;
        end else begin
            state <= next_state;
        end
    end

    always @(*) begin
        case (state)
            START: next_state = seq ? A : START;
            A: next_state = seq ? B : START;
            B: next_state = seq ? B : C;
            C: next_state = seq ? D : START;
            D: next_state = seq ? B : START;
        endcase
    end

    assign detected = (state == D);
    
endmodule