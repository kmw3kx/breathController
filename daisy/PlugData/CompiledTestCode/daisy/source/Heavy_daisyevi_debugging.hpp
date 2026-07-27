/**
 * Copyright (c) 2026 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_DAISYEVI_DEBUGGING_HPP_
#define _HEAVY_CONTEXT_DAISYEVI_DEBUGGING_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvControlIf.h"
#include "HvControlSlice.h"
#include "HvControlPrint.h"
#include "HvControlCast.h"
#include "HvControlSystem.h"
#include "HvControlVar.h"
#include "HvControlDelay.h"

class Heavy_daisyevi_debugging : public HeavyContext {

 public:
  Heavy_daisyevi_debugging(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_daisyevi_debugging();

  const char *getName() override { return "daisyevi_debugging"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 0; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BREATH = 0x477CB2C4, // breath
        ENCODER = 0xBDAEB3AA, // encoder
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;


  /*
  * Code for expr~ implementation
  * Write out the generic header code
  */

  // per class code

  // per object code


  // static sendMessage functions
  static void cVar_NzRBb6M2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PHnzQokk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SNFZE86O_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_dddmaAch_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yuNWjoAj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MwDCbdUs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_D9YsdWp7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hEg7JWLO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t9ORiaLa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N9MUS3Js_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MWsFuRAF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oLdsC5nY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_V4QK5aUP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_7WHDvVcx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EEnqRmy0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RU8V4CF5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ywBpKKyH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FAgtha45_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_66lVHwJ2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_64EORuyH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gys504IE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sb9dWUVX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uS1e7H46_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w1qIgBnq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m8AjP9FN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OBF6QaVt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_99LwEanc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0Y2Tq3Ew_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  ControlVar cVar_NzRBb6M2;
  ControlVar cVar_PHnzQokk;
  ControlSlice cSlice_dddmaAch;
  ControlSlice cSlice_yuNWjoAj;
  ControlVar cVar_MwDCbdUs;
  ControlIf cIf_D9YsdWp7;
  ControlBinop cBinop_N9MUS3Js;
  ControlDelay cDelay_7WHDvVcx;
  ControlVar cVar_FAgtha45;
  ControlBinop cBinop_64EORuyH;
  ControlBinop cBinop_gys504IE;
  ControlBinop cBinop_sb9dWUVX;
  ControlBinop cBinop_uS1e7H46;
};

#endif // _HEAVY_CONTEXT_DAISYEVI_DEBUGGING_HPP_
