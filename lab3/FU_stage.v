`include "define.vh" 

module FU_STAGE(
  input wire                              clk,
  input wire                              reset,
  input wire [`from_DE_to_FU_WIDTH-1:0]    from_DE_to_FU,   
  output wire [`from_FU_to_DE_WIDTH-1:0]   from_FU_to_DE
);
  /////////////////////////////////////////////////////////////////
  //TODO: add your code here to instantiate the external_alu module

  // `define from_DE_to_FU_WIDTH  (`ALUDATABITS+`ALUDATABITS+`ALUOPBITS+`ALUCSRINBITS)

  wire [31:0] OP1, OP2;
  wire [3:0] ALUOP;
  wire [2:0] CSR_ALU_IN;
  wire [31:0] OP3;
  wire [2:0] CSR_ALU_OUT;

  assign {OP1, OP2, ALUOP, CSR_ALU_IN} = from_DE_to_FU;

  external_alu my_external_alu (
    .clk(clk),
    .rst(reset),
    .OP1(OP1),
    .OP2(OP2),
    .OP3(OP3),
    .ALUOP(ALUOP),
    .CSR_ALU_OUT(CSR_ALU_OUT),
    .CSR_ALU_IN(CSR_ALU_IN)
);

  assign from_FU_to_DE = {OP3, CSR_ALU_OUT};

endmodule