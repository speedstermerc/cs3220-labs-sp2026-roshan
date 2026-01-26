`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

// dummy implementation, please replace with your own

module module_hierarchy ( 
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);

    wire carry_middle;
    
    add16 low_adder (
        .a(a[15:0]),
        .b(b[15:0]),
        .cin(1'b0),          // The very first carry-in is 0
        .sum(sum[15:0]),
        .cout(carry_middle)   // This "output" goes into the middle wire
    );

    wire dont_care;

    add16 high_adder (
        .a(a[31:16]),
        .b(b[31:16]),
        .cin(carry_middle),
        .sum(sum[31:16]),
        .cout(dont_care)
    );


    // assign sum = 32'd0;

endmodule

//module add16 ( input[15:0] a, input[15:0] b, input cin, output[15:0] sum, output cout );

module add1 ( input a, input b, input cin,   output sum, output cout );

    // assign sum = (~cin & ~a & b) | (~cin & a & ~b) | (cin & ~a & ~b) | (cin & a & b);
    // use the xor trick for cleaner code.
    assign sum = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);


// cin a b      sum cout
// 0   0 0      0    0
// 0   0 1      1    0
// 0   1 0      1    0
// 0   1 1      0    1
// 1   0 0      1    0
// 1   0 1      0    1
// 1   1 0      0    1
// 1   1 1      1    1
endmodule