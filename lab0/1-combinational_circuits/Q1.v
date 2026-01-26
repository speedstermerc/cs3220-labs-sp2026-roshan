`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps
/* This time scale thing is for the simulator only.
It tells the simulator how to handle time.

1 ns is the time unit. If I wrote "#5" Tells the simulator
to wait 5 ns.

10 ps defines how much percision/rounding happens with regard
to the time. 10 ps = 0.01 ns. Meaning, my delays can be as specific
as 5.01, but not 5.001
*/

// dummy implementation, please replace with your own
module combinational_circuits ( 
    input p1a, p1b, p1c, p1d, p1e, p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );

    //make intermediate values (called wires)
    wire and_gate_1;
    wire and_gate_2;
    wire and_gate_3;
    wire and_gate_4;

    //p1y
    assign and_gate_1 = p1a & p1c & p1b;
    assign and_gate_2 = p1f & p1e & p1d;
    assign p1y = and_gate_1 | and_gate_2;

    //p2y
    assign and_gate_3 = p2a & p2b;
    assign and_gate_4 = p2c & p2d;
    assign p2y = and_gate_3 | and_gate_4;


    // this is how verilog represents specific bit values:
    // so, 4'b1101 is a 4 bit binary value
    //EXAMPLE: assign p1y = 1'b0;
endmodule

// module combinational_circuits ( 
//     input p1a, p1b, p1c, p1d, p1e, p1f,
//     output p1y,
//     input p2a, p2b, p2c, p2d,
//     output p2y );

//     //p1y
//     assign p1y = (p1a & p1c & p1b) | (p1f & p1e & p1d);

//     //p2y
//     assign p2y = (p2a & p2b) | (p2c & p2d);

//     // this is how verilog represents specific bit values:
//     // so, 4'b1101 is a 4 bit binary value
//     //EXAMPLE: assign p1y = 1'b0;
// endmodule