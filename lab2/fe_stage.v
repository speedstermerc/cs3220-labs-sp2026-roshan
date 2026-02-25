 `include "define.vh" 


module FE_STAGE(
  input wire clk,
  input wire reset,
  input wire [`from_DE_to_FE_WIDTH-1:0] from_DE_to_FE,
  input wire [`from_AGEX_to_FE_WIDTH-1:0] from_AGEX_to_FE,   
  input wire [`from_MEM_to_FE_WIDTH-1:0] from_MEM_to_FE,   
  input wire [`from_WB_to_FE_WIDTH-1:0] from_WB_to_FE, 
  output wire [`FE_latch_WIDTH-1:0] FE_latch_out
);

  `UNUSED_VAR (from_MEM_to_FE)
  `UNUSED_VAR (from_WB_to_FE)

  // I-MEM
  (* ram_init_file = `IDMEMINITFILE *)
  reg [`DBITS-1:0] imem [`IMEMWORDS-1:0];
 
  initial begin
      $readmemh(`IDMEMINITFILE , imem);
  end

  // Display memory contents with verilator 
  /*
  always @(posedge clk) begin
    for (integer i=0 ; i<`IMEMWORDS ; i=i+1) begin
        $display("%h", imem[i]);
    end
  end
  */

  /* pipeline latch */ 
  reg [`FE_latch_WIDTH-1:0] FE_latch;  // FE latch 
  wire valid_FE;
   
  `UNUSED_VAR(valid_FE)
  reg [`DBITS-1:0] PC_FE_latch; // PC latch in the FE stage   // you could use a part of FE_latch as a PC latch as well 
  
  reg [`DBITS-1:0] inst_count_FE; /* for debugging purpose */ 
  
  wire [`DBITS-1:0] inst_count_AGEX; /* for debugging purpose. resent the instruction counter */ 

  wire [`INSTBITS-1:0] inst_FE;  // instruction value in the FE stage 
  wire [`DBITS-1:0] pcplus_FE;  // pc plus value in the FE stage 
  wire stall_pipe_FE; // signal to indicate when a front-end needs to be stall
  
  wire [`FE_latch_WIDTH-1:0] FE_latch_contents;  // the signals that will be FE latch contents 
  
  // reading instruction from imem 
  assign inst_FE = imem[PC_FE_latch[`IMEMADDRBITS-1:`IMEMWORDBITS]];  // this code works. imem is stored 4B together 
  
  // wire to send the FE latch contents to the DE stage 
  assign FE_latch_out = FE_latch; 
 

  // This is the value of "incremented PC", computed in the FE stage
  assign pcplus_FE = PC_FE_latch + `INSTSIZE;
  
   
   // the order of latch contents should be matched in the decode stage when we extract the contents. 
  assign FE_latch_contents = {
                                valid_FE, 
                                inst_FE, 
                                PC_FE_latch, 
                                pcplus_FE, // please feel free to add more signals such as valid bits etc. 
                                inst_count_FE,
                                 // if you add more bits here, please increase the width of latch in VX_define.vh 
                                pht_index,
                                predicted_pc
                                };
  /////////////////////////////////////////
  // CHANGES FOR LAB 2 BRANCH PREDICTION //
  /////////////////////////////////////////
  // Branch History Register line of 8 bits
  reg [9:0] BHR;
  // Pattern History Table 256 entries, each containing 2 bits
  reg [1:0] PHT [1023:0];
  // 0, 1, 2, or 3, going from Strongly not taken to Strongly taken
  // Branch Target Buffer 16 entries, contains valid bit, tag field, and target addres
  reg         BTB_valid  [63:0];
  reg [23:0]  BTB_tag    [63:0]; //PC_FE_last[31:6]
  reg [31:0]  BTB_target [63:0];
  integer i;

  // **TODO: Complete the rest of the pipeline 
  //assign stall_pipe_FE = 1;   // you need
  wire br_mispred_AGEX;  
  wire [`DBITS-1:0] br_target_AGEX;
  wire is_branch_or_jump_AGEX;
  wire actual_taken_AGEX;
  wire [`DBITS-1:0] PC_AGEX;
  wire [9:0] pht_index_AGEX;

  assign {
    stall_pipe_FE
  } = from_DE_to_FE[0]; 

  assign {
    br_mispred_AGEX,
    br_target_AGEX,
    is_branch_or_jump_AGEX,
    actual_taken_AGEX,
    PC_AGEX,
    pht_index_AGEX
  } = from_AGEX_to_FE;

  /////////////////////////////////////////
  // CHANGES FOR LAB 2 BRANCH PREDICTION //
  /////////////////////////////////////////
  wire [9:0] pht_index = PC_FE_latch[11:2] ^ BHR; 
  wire [5:0] btb_index = PC_FE_latch[7:2];
  wire [23:0] btb_tag_candidate = PC_FE_latch[31:8];
  
  wire btb_hit = BTB_valid[btb_index] && (BTB_tag[btb_index] == btb_tag_candidate);
  //hitting doesn't gaurantee we hit the right branch instruction... could be a collision, could be wrong.
  wire predict_taken = (PHT[pht_index] >= 2'b10); // 10 or 11 means taken
  
  wire make_prediction = btb_hit && predict_taken;
  wire [31:0] predicted_pc = make_prediction ? BTB_target[btb_index] : pcplus_FE;


  always @ (posedge clk) begin
    /* you need to extend this always block */
    if (reset) begin 
      PC_FE_latch <= `STARTPC;
      inst_count_FE <= 1;  /* inst_count starts from 1 for easy human reading. 1st fetch instructions can have 1 */ 
      
      /////////////////////////////////////////
      // CHANGES FOR LAB 2 BRANCH PREDICTION //
      /////////////////////////////////////////
      // BHR initialized to all 0s
      BHR <= 10'b0;
      // Initialize all PHT entries to 1
      for (i = 0; i < 1024; i = i + 1) begin
          PHT[i] = 2'b11;
      end
      
      // Initialize all BTB valid bits to 0
      for (i = 0; i < 64; i = i + 1) begin
          BTB_valid[i] = 1'b0;
      end
      end 
    else if (br_mispred_AGEX)
      PC_FE_latch <= br_target_AGEX;
    else if (stall_pipe_FE) 
      PC_FE_latch <= PC_FE_latch; 
    else begin 
      PC_FE_latch <= predicted_pc; 
      inst_count_FE <= inst_count_FE + 1; 
    end
    if (is_branch_or_jump_AGEX) begin
      // Update BHR
      BHR <= {BHR[8:0], actual_taken_AGEX};

      // Update PHT saturation
      if (actual_taken_AGEX) begin
          if (PHT[pht_index_AGEX] != 2'b11)
              PHT[pht_index_AGEX] <= PHT[pht_index_AGEX] + 1;
      end else begin
          if (PHT[pht_index_AGEX] != 2'b00)
              PHT[pht_index_AGEX] <= PHT[pht_index_AGEX] - 1;
      end

      // Update BTB
      BTB_valid[PC_AGEX[7:2]]  <= 1'b1;
      BTB_tag[PC_AGEX[7:2]]    <= PC_AGEX[31:8];
      BTB_target[PC_AGEX[7:2]] <= br_target_AGEX;
    end 
  end
  

  always @ (posedge clk) begin
    if (reset) begin 
      FE_latch <= '0; 
    end else begin 
      if (br_mispred_AGEX)
        FE_latch <= '0;
      else if (stall_pipe_FE)
        FE_latch <= FE_latch; 
      else 
        FE_latch <= FE_latch_contents; 
    end  
  end

endmodule
