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

#ifndef _HEAVY_CONTEXT_BREATHPRINT_HPP_
#define _HEAVY_CONTEXT_BREATHPRINT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlSystem.h"
#include "HvControlDelay.h"
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvSignalSample.h"
#include "HvControlPrint.h"
#include "HvControlCast.h"

class Heavy_breathPrint : public HeavyContext {

 public:
  Heavy_breathPrint(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_breathPrint();

  const char *getName() override { return "breathPrint"; }
  int getNumInputChannels() override { return 15; }
  int getNumOutputChannels() override { return 0; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

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
  static void sSample_17KliLii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_sGLmDJe9_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_OVKVjk4K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bIza2QEc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hVIAqQhl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_E2dilKrQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RKimKgTO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_32XTkm42_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1HE7RiGk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZkwFI12P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gerh62IE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bFtWTd6O_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalSample sSample_17KliLii;
  ControlDelay cDelay_OVKVjk4K;
  ControlVar cVar_RKimKgTO;
  ControlBinop cBinop_1HE7RiGk;
  ControlBinop cBinop_ZkwFI12P;
  ControlBinop cBinop_gerh62IE;
};

#endif // _HEAVY_CONTEXT_BREATHPRINT_HPP_
