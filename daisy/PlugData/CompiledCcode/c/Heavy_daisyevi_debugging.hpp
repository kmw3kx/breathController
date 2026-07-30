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
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvControlIf.h"
#include "HvControlCast.h"
#include "HvControlSlice.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlPack.h"

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
  static void cVar_Zm2Pat1h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NOqBwqaX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_X1RMRmg8_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_lg31cYDx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NkPRbycH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_O1pihn2k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_uWhxw3tt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_668Bbmbr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W09dJEtt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KRCBfzGU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3Subr0cU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qJO2BQlu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dsYmyaXp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_mYoAaCFk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_koShf6bh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KA5BeiYp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6d1ztNoH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MilpZNG6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Z32SQViw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kQitPAV4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AfJNijbD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SGEeG2Ze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wWFL5OgY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_iCrhwlC5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kdnrg00G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_0ydehRKj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v8aUNMK0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3uCbYVTN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_KEAECYRO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nJ5uFdqE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_W9k9sU3n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_YPnKqkUU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ynCpkbqW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xZORfWNQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5F4gneEz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dIRbUy3b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4MW30nJt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_xl7hZcLn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Zj5Tx7B8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_cqLTOsbl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ycK4FDVQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jBa9r0rf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ftRP0rLf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5DH3ojSo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_azSOl6Hz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_D4TF1rxX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vq8OhtB3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1JBHdvuj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KNddIVV6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Z6gaoZ29_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  ControlVar cVar_Zm2Pat1h;
  ControlVar cVar_NOqBwqaX;
  ControlSlice cSlice_lg31cYDx;
  ControlSlice cSlice_NkPRbycH;
  ControlVar cVar_O1pihn2k;
  ControlIf cIf_uWhxw3tt;
  ControlBinop cBinop_KRCBfzGU;
  ControlDelay cDelay_mYoAaCFk;
  ControlVar cVar_MilpZNG6;
  ControlBinop cBinop_kQitPAV4;
  ControlBinop cBinop_AfJNijbD;
  ControlBinop cBinop_SGEeG2Ze;
  ControlVar cVar_wWFL5OgY;
  ControlPack cPack_iCrhwlC5;
  ControlVar cVar_kdnrg00G;
  ControlBinop cBinop_v8aUNMK0;
  ControlBinop cBinop_3uCbYVTN;
  ControlPack cPack_KEAECYRO;
  ControlVar cVar_nJ5uFdqE;
  ControlVar cVar_W9k9sU3n;
  ControlBinop cBinop_5F4gneEz;
  ControlBinop cBinop_dIRbUy3b;
  ControlVar cVar_4MW30nJt;
  ControlIf cIf_xl7hZcLn;
  ControlBinop cBinop_Zj5Tx7B8;
  ControlIf cIf_cqLTOsbl;
  ControlBinop cBinop_ycK4FDVQ;
  ControlVar cVar_jBa9r0rf;
  ControlBinop cBinop_ftRP0rLf;
  ControlBinop cBinop_5DH3ojSo;
  ControlBinop cBinop_Vq8OhtB3;
};

#endif // _HEAVY_CONTEXT_DAISYEVI_DEBUGGING_HPP_
