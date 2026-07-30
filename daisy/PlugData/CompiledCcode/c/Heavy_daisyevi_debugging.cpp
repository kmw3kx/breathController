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

#include "Heavy_daisyevi_debugging.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_daisyevi_debugging *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_daisyevi_debugging_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_daisyevi_debugging));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_daisyevi_debugging(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_daisyevi_debugging_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_daisyevi_debugging));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_daisyevi_debugging(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_daisyevi_debugging_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_daisyevi_debugging();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_daisyevi_debugging::Heavy_daisyevi_debugging(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += cVar_init_s(&cVar_Zm2Pat1h, "floatatom");
  numBytes += cVar_init_f(&cVar_NOqBwqaX, 0.0f);
  numBytes += cSlice_init(&cSlice_lg31cYDx, 1, -1);
  numBytes += cSlice_init(&cSlice_NkPRbycH, 1, -1);
  numBytes += cVar_init_f(&cVar_O1pihn2k, 0.0f);
  numBytes += cIf_init(&cIf_uWhxw3tt, false);
  numBytes += cBinop_init(&cBinop_KRCBfzGU, 0.0f); // __neq
  numBytes += cDelay_init(this, &cDelay_mYoAaCFk, 0.0f);
  numBytes += cVar_init_f(&cVar_MilpZNG6, 500.0f);
  numBytes += cBinop_init(&cBinop_SGEeG2Ze, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_wWFL5OgY, 0.0f);
  numBytes += cPack_init(&cPack_iCrhwlC5, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_kdnrg00G, 1.0f);
  numBytes += cPack_init(&cPack_KEAECYRO, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_nJ5uFdqE, 0.0f);
  numBytes += cVar_init_f(&cVar_W9k9sU3n, 7.0f);
  numBytes += cVar_init_s(&cVar_4MW30nJt, "floatatom");
  numBytes += cIf_init(&cIf_xl7hZcLn, false);
  numBytes += cIf_init(&cIf_cqLTOsbl, false);
  numBytes += cVar_init_f(&cVar_jBa9r0rf, 1.0f);
  numBytes += cBinop_init(&cBinop_5DH3ojSo, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_daisyevi_debugging::~Heavy_daisyevi_debugging() {
  cPack_free(&cPack_iCrhwlC5);
  cPack_free(&cPack_KEAECYRO);
}

HvTable *Heavy_daisyevi_debugging::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_daisyevi_debugging::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Z6gaoZ29_sendMessage);
      break;
    }
    case 0x477CB2C4: { // breath
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KNddIVV6_sendMessage);
      break;
    }
    case 0xBDAEB3AA: { // encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1JBHdvuj_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_daisyevi_debugging::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "breath";
        info->hash = 0x477CB2C4;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "encoder";
        info->hash = 0xBDAEB3AA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_daisyevi_debugging::cVar_Zm2Pat1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_X1RMRmg8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_daisyevi_debugging::cVar_NOqBwqaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5DH3ojSo, HV_BINOP_ADD, 1, m, &cBinop_5DH3ojSo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Zm2Pat1h, 0, m, &cVar_Zm2Pat1h_sendMessage);
}

void Heavy_daisyevi_debugging::cSwitchcase_X1RMRmg8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lg31cYDx, 0, m, &cSlice_lg31cYDx_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NkPRbycH, 0, m, &cSlice_NkPRbycH_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3Subr0cU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qJO2BQlu_sendMessage);
      break;
    }
  }
}

void Heavy_daisyevi_debugging::cSlice_lg31cYDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_O1pihn2k, 0, m, &cVar_O1pihn2k_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_O1pihn2k, 0, m, &cVar_O1pihn2k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cSlice_NkPRbycH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KRCBfzGU, HV_BINOP_NEQ, 1, m, &cBinop_KRCBfzGU_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_O1pihn2k, 1, m, &cVar_O1pihn2k_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KRCBfzGU, HV_BINOP_NEQ, 1, m, &cBinop_KRCBfzGU_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_O1pihn2k, 1, m, &cVar_O1pihn2k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cVar_O1pihn2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 128.0f, 0, m, &cBinop_Zj5Tx7B8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xl7hZcLn, 0, m, &cIf_xl7hZcLn_sendMessage);
}

void Heavy_daisyevi_debugging::cIf_uWhxw3tt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W09dJEtt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_668Bbmbr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cCast_668Bbmbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O1pihn2k, 0, m, &cVar_O1pihn2k_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_W09dJEtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KRCBfzGU, HV_BINOP_NEQ, 1, m, &cBinop_KRCBfzGU_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_KRCBfzGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uWhxw3tt, 1, m, &cIf_uWhxw3tt_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_3Subr0cU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KRCBfzGU, HV_BINOP_NEQ, 0, m, &cBinop_KRCBfzGU_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_qJO2BQlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uWhxw3tt, 0, m, &cIf_uWhxw3tt_sendMessage);
}

void Heavy_daisyevi_debugging::cSwitchcase_dsYmyaXp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Z32SQViw_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Z32SQViw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_koShf6bh_sendMessage);
      break;
    }
  }
}

void Heavy_daisyevi_debugging::cDelay_mYoAaCFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mYoAaCFk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYoAaCFk, 0, m, &cDelay_mYoAaCFk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wWFL5OgY, 0, m, &cVar_wWFL5OgY_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_koShf6bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z32SQViw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYoAaCFk, 0, m, &cDelay_mYoAaCFk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wWFL5OgY, 0, m, &cVar_wWFL5OgY_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_KA5BeiYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6d1ztNoH_sendMessage);
}

void Heavy_daisyevi_debugging::cSystem_6d1ztNoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AfJNijbD_sendMessage);
}

void Heavy_daisyevi_debugging::cVar_MilpZNG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGEeG2Ze, HV_BINOP_MULTIPLY, 0, m, &cBinop_SGEeG2Ze_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_Z32SQViw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYoAaCFk, 0, m, &cDelay_mYoAaCFk_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_kQitPAV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYoAaCFk, 2, m, &cDelay_mYoAaCFk_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_AfJNijbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGEeG2Ze, HV_BINOP_MULTIPLY, 1, m, &cBinop_SGEeG2Ze_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_SGEeG2Ze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kQitPAV4_sendMessage);
}

void Heavy_daisyevi_debugging::cVar_wWFL5OgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_Vq8OhtB3_sendMessage);
}

void Heavy_daisyevi_debugging::cPack_iCrhwlC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0ydehRKj_sendMessage(_c, 0, m);
}

void Heavy_daisyevi_debugging::cVar_kdnrg00G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_v8aUNMK0_sendMessage);
}

void Heavy_daisyevi_debugging::cSend_0ydehRKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_touchout", 0x476D4387, m);
}

void Heavy_daisyevi_debugging::cBinop_v8aUNMK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3uCbYVTN_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_3uCbYVTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iCrhwlC5, 1, m, &cPack_iCrhwlC5_sendMessage);
}

void Heavy_daisyevi_debugging::cPack_KEAECYRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YPnKqkUU_sendMessage(_c, 0, m);
}

void Heavy_daisyevi_debugging::cVar_nJ5uFdqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5F4gneEz_sendMessage);
}

void Heavy_daisyevi_debugging::cVar_W9k9sU3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KEAECYRO, 1, m, &cPack_KEAECYRO_sendMessage);
}

void Heavy_daisyevi_debugging::cSend_YPnKqkUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_ctlout", 0xE5E2A040, m);
}

void Heavy_daisyevi_debugging::cCast_ynCpkbqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W9k9sU3n, 0, m, &cVar_W9k9sU3n_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_xZORfWNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nJ5uFdqE, 0, m, &cVar_nJ5uFdqE_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_5F4gneEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dIRbUy3b_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_dIRbUy3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KEAECYRO, 2, m, &cPack_KEAECYRO_sendMessage);
}

void Heavy_daisyevi_debugging::cVar_4MW30nJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KEAECYRO, 0, m, &cPack_KEAECYRO_sendMessage);
}

void Heavy_daisyevi_debugging::cIf_xl7hZcLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_ycK4FDVQ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_cqLTOsbl, 0, m, &cIf_cqLTOsbl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cBinop_Zj5Tx7B8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xl7hZcLn, 1, m, &cIf_xl7hZcLn_sendMessage);
}

void Heavy_daisyevi_debugging::cIf_cqLTOsbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_4MW30nJt, 0, m, &cVar_4MW30nJt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cBinop_ycK4FDVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cqLTOsbl, 1, m, &cIf_cqLTOsbl_sendMessage);
}

void Heavy_daisyevi_debugging::cVar_jBa9r0rf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ftRP0rLf_sendMessage);
  cSwitchcase_dsYmyaXp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_daisyevi_debugging::cBinop_ftRP0rLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jBa9r0rf, 1, m, &cVar_jBa9r0rf_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_5DH3ojSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NOqBwqaX, 0, m, &cVar_NOqBwqaX_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_azSOl6Hz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5DH3ojSo, HV_BINOP_ADD, 0, m, &cBinop_5DH3ojSo_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_D4TF1rxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5DH3ojSo, HV_BINOP_ADD, 0, m, &cBinop_5DH3ojSo_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_Vq8OhtB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iCrhwlC5, 0, m, &cPack_iCrhwlC5_sendMessage);
}

void Heavy_daisyevi_debugging::cReceive_1JBHdvuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5DH3ojSo, HV_BINOP_ADD, 0, m, &cBinop_5DH3ojSo_sendMessage);
}

void Heavy_daisyevi_debugging::cReceive_KNddIVV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wWFL5OgY, 1, m, &cVar_wWFL5OgY_sendMessage);
}

void Heavy_daisyevi_debugging::cReceive_Z6gaoZ29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KA5BeiYp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MilpZNG6, 0, m, &cVar_MilpZNG6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kdnrg00G, 0, m, &cVar_kdnrg00G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xZORfWNQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ynCpkbqW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jBa9r0rf, 0, m, &cVar_jBa9r0rf_sendMessage);
}



/*
 * Code for expr~ implementation
 * Write out the generic implementation code
 */

 // per class code

 // per object code


/*
 * Context Process Implementation
 */

int Heavy_daisyevi_debugging::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars

  // input and output vars

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    

    // process all signal functions

    // save output vars to output buffer
    // no output channels
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_daisyevi_debugging::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float **const bOut = NULL;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_daisyevi_debugging::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float *const bOut = NULL;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
