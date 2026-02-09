// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_var_seq.h for the primary calling header

#include "Vadder_var_seq__pch.h"
#include "Vadder_var_seq___024root.h"

VL_ATTR_COLD void Vadder_var_seq___024root___eval_static(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_static\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vadder_var_seq___024root___eval_initial(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_initial\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vadder_var_seq___024root___eval_final(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_final\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__stl(Vadder_var_seq___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadder_var_seq___024root___eval_phase__stl(Vadder_var_seq___024root* vlSelf);

VL_ATTR_COLD void Vadder_var_seq___024root___eval_settle(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_settle\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vadder_var_seq___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("adder_var_seq.v", 29, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadder_var_seq___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__stl(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___dump_triggers__stl\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadder_var_seq___024root___stl_sequent__TOP__0(Vadder_var_seq___024root* vlSelf);

VL_ATTR_COLD void Vadder_var_seq___024root___eval_stl(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_stl\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadder_var_seq___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vadder_var_seq___024root___stl_sequent__TOP__0(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___stl_sequent__TOP__0\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.o_valid = vlSelfRef.adder_var_seq__DOT__o_valid_inner;
    vlSelfRef.o_data = vlSelfRef.adder_var_seq__DOT__o_data_inner;
    vlSelfRef.adder_var_seq__DOT__calcuate_en = (IData)(
                                                        ((3U 
                                                          == (IData)(vlSelfRef.i_valid)) 
                                                         & (IData)(vlSelfRef.i_en)));
}

VL_ATTR_COLD void Vadder_var_seq___024root___eval_triggers__stl(Vadder_var_seq___024root* vlSelf);

VL_ATTR_COLD bool Vadder_var_seq___024root___eval_phase__stl(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___eval_phase__stl\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadder_var_seq___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadder_var_seq___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__ico(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___dump_triggers__ico\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__act(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___dump_triggers__act\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_var_seq___024root___dump_triggers__nba(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___dump_triggers__nba\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadder_var_seq___024root___ctor_var_reset(Vadder_var_seq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_var_seq___024root___ctor_var_reset\n"); );
    Vadder_var_seq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->i_valid = VL_RAND_RESET_I(2);
    vlSelf->i_data = VL_RAND_RESET_I(32);
    vlSelf->o_valid = VL_RAND_RESET_I(1);
    vlSelf->o_data = VL_RAND_RESET_I(17);
    vlSelf->i_en = VL_RAND_RESET_I(1);
    vlSelf->adder_var_seq__DOT__calcuate_en = VL_RAND_RESET_I(1);
    vlSelf->adder_var_seq__DOT__o_data_inner = VL_RAND_RESET_I(17);
    vlSelf->adder_var_seq__DOT__o_valid_inner = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
