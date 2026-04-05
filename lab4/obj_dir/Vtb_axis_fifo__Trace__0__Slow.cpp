// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_axis_fifo__Syms.h"


VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_init_sub__TOP__tb_axis_fifo__0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_init_sub__TOP__0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_init_sub__TOP__0\n"); );
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+77,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tb_axis_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_axis_fifo___024root__trace_init_sub__TOP__tb_axis_fifo__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_init_sub__TOP__tb_axis_fifo__0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_init_sub__TOP__tb_axis_fifo__0\n"); );
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBit(c+77,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"AXIS_DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"DATA_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"write_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"din_0_rsc_dat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+80,0,"din_0_rsc_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"din_0_rsc_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"dout_0_rsc_dat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+83,0,"dout_0_rsc_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"dout_0_rsc_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"din_0_rsc_dat_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"din_0_rsc_vld_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"dout_0_rsc_rdy_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+14,0,"cycle_count_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declBus(c+19,0,"in_0_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+20,0,"out_0_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+91,0,"f_in_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+92,0,"f_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("axis_fifo_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+88,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"AXIS_DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+77,0,"wr_aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"wr_rstn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"wr_axis_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,0,"wr_axis_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"wr_axis_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"rd_aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"rd_rstn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"rd_axis_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+84,0,"rd_axis_vld",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"rd_axis_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"wr_ptr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"wr_ptr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"wr_ptr_gray_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+2,0,"wr_ptr_gray_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+23,0,"wr_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"rd_ptr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rd_ptr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"rd_ptr_gray_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"rd_ptr_gray_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"rd_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+27,0,"wr_ptr_gray_sync1_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+28,0,"wr_ptr_gray_sync2_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+29,0,"rd_ptr_gray_sync1_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+30,0,"rd_ptr_gray_sync2_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+31,0,"wr_rst_sync1_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"wr_rst_sync2_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"wr_rst_sync3_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"rd_rst_sync1_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"rd_rst_sync2_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"rd_rst_sync3_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declQuad(c+37+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 32,0);
    }
    tracep->popPrefix();
    tracep->declQuad(c+69,0,"mem_read_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+71,0,"mem_read_data_valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"mem_read_data_valid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+6,0,"mem_write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+72,0,"rd_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+74,0,"rd_axis_vld_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"rd_axis_vld_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"store_output",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_init_top(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_init_top\n"); );
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_axis_fifo___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_axis_fifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_axis_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_register(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_register\n"); );
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_axis_fifo___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_axis_fifo___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_axis_fifo___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_axis_fifo___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_const_0_sub_0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_const_0\n"); );
    // Body
    Vtb_axis_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_axis_fifo___024root*>(voidSelf);
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_axis_fifo___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_const_0_sub_0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_const_0_sub_0\n"); );
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+87,(0x00000020U),32);
    bufp->fullIData(oldp+88,(4U),32);
    bufp->fullIData(oldp+89,(0x00000400U),32);
    bufp->fullIData(oldp+90,(0x00000200U),32);
    bufp->fullIData(oldp+91,(vlSymsp->TOP__tb_axis_fifo.__PVT__f_in_0),32);
    bufp->fullIData(oldp+92,(vlSymsp->TOP__tb_axis_fifo.__PVT__f_out_0),32);
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_full_0_sub_0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_full_0\n"); );
    // Body
    Vtb_axis_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_axis_fifo___024root*>(voidSelf);
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_axis_fifo___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_axis_fifo___024root__trace_full_0_sub_0(Vtb_axis_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axis_fifo___024root__trace_full_0_sub_0\n"); );
    Vtb_axis_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+1,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_ptr_next),5);
    bufp->fullCData(oldp+2,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_ptr_gray_next),5);
    bufp->fullCData(oldp+3,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_ptr_next),5);
    bufp->fullCData(oldp+4,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_ptr_gray_next),5);
    bufp->fullBit(oldp+5,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem_read_data_valid_next));
    bufp->fullQData(oldp+6,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem_write_data),33);
    bufp->fullBit(oldp+8,(((IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__store_output)
                            ? (IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem_read_data_valid_reg)
                            : (IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_axis_vld_reg))));
    bufp->fullBit(oldp+9,(((~ (IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__empty)) 
                           & (IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__store_output))));
    bufp->fullBit(oldp+10,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__store_output));
    bufp->fullIData(oldp+11,(vlSymsp->TOP__tb_axis_fifo.__PVT__din_0_rsc_dat_reg),32);
    bufp->fullBit(oldp+12,(vlSymsp->TOP__tb_axis_fifo.__PVT__din_0_rsc_vld_reg));
    bufp->fullBit(oldp+13,(vlSymsp->TOP__tb_axis_fifo.__PVT__dout_0_rsc_rdy_reg));
    bufp->fullWData(oldp+14,(vlSymsp->TOP__tb_axis_fifo.__PVT__cycle_count_reg),129);
    bufp->fullIData(oldp+19,(vlSymsp->TOP__tb_axis_fifo.__PVT__in_0_ptr),32);
    bufp->fullIData(oldp+20,(vlSymsp->TOP__tb_axis_fifo.__PVT__out_0_ptr),32);
    bufp->fullCData(oldp+21,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_ptr_reg),5);
    bufp->fullCData(oldp+22,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_ptr_gray_reg),5);
    bufp->fullCData(oldp+23,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_addr_reg),5);
    bufp->fullCData(oldp+24,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_ptr_reg),5);
    bufp->fullCData(oldp+25,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_ptr_gray_reg),5);
    bufp->fullCData(oldp+26,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_addr_reg),5);
    bufp->fullCData(oldp+27,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_ptr_gray_sync1_reg),5);
    bufp->fullCData(oldp+28,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_ptr_gray_sync2_reg),5);
    bufp->fullCData(oldp+29,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_ptr_gray_sync1_reg),5);
    bufp->fullCData(oldp+30,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_ptr_gray_sync2_reg),5);
    bufp->fullBit(oldp+31,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_rst_sync1_reg));
    bufp->fullBit(oldp+32,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_rst_sync2_reg));
    bufp->fullBit(oldp+33,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_rst_sync3_reg));
    bufp->fullBit(oldp+34,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_rst_sync1_reg));
    bufp->fullBit(oldp+35,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_rst_sync2_reg));
    bufp->fullBit(oldp+36,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_rst_sync3_reg));
    bufp->fullQData(oldp+37,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[0]),33);
    bufp->fullQData(oldp+39,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[1]),33);
    bufp->fullQData(oldp+41,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[2]),33);
    bufp->fullQData(oldp+43,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[3]),33);
    bufp->fullQData(oldp+45,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[4]),33);
    bufp->fullQData(oldp+47,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[5]),33);
    bufp->fullQData(oldp+49,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[6]),33);
    bufp->fullQData(oldp+51,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[7]),33);
    bufp->fullQData(oldp+53,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[8]),33);
    bufp->fullQData(oldp+55,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[9]),33);
    bufp->fullQData(oldp+57,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[10]),33);
    bufp->fullQData(oldp+59,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[11]),33);
    bufp->fullQData(oldp+61,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[12]),33);
    bufp->fullQData(oldp+63,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[13]),33);
    bufp->fullQData(oldp+65,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[14]),33);
    bufp->fullQData(oldp+67,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem[15]),33);
    bufp->fullQData(oldp+69,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem_read_data_reg),33);
    bufp->fullBit(oldp+71,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__mem_read_data_valid_reg));
    bufp->fullQData(oldp+72,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_data_reg),33);
    bufp->fullBit(oldp+74,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__rd_axis_vld_reg));
    bufp->fullBit(oldp+75,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__full));
    bufp->fullBit(oldp+76,(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__empty));
    bufp->fullBit(oldp+77,(vlSelfRef.clk));
    bufp->fullBit(oldp+78,(vlSelfRef.reset));
    bufp->fullIData(oldp+79,(vlSymsp->TOP__tb_axis_fifo.din_0_rsc_dat),32);
    bufp->fullBit(oldp+80,(vlSymsp->TOP__tb_axis_fifo.din_0_rsc_rdy));
    bufp->fullBit(oldp+81,(vlSymsp->TOP__tb_axis_fifo.din_0_rsc_vld));
    bufp->fullIData(oldp+82,(vlSymsp->TOP__tb_axis_fifo.dout_0_rsc_dat),32);
    bufp->fullBit(oldp+83,(vlSymsp->TOP__tb_axis_fifo.dout_0_rsc_rdy));
    bufp->fullBit(oldp+84,(vlSymsp->TOP__tb_axis_fifo.dout_0_rsc_vld));
    bufp->fullBit(oldp+85,((1U & (~ (IData)(vlSelfRef.reset)))));
    bufp->fullBit(oldp+86,((((~ (IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__full)) 
                             & (IData)(vlSymsp->TOP__tb_axis_fifo.din_0_rsc_vld)) 
                            & ((~ (IData)(vlSymsp->TOP__tb_axis_fifo.__PVT__axis_fifo_inst__DOT__wr_rst_sync3_reg)) 
                               & (IData)(vlSymsp->TOP__tb_axis_fifo.din_0_rsc_rdy)))));
}
