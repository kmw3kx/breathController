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
  numBytes += cVar_init_s(&cVar_NzRBb6M2, "floatatom");
  numBytes += cVar_init_f(&cVar_PHnzQokk, 0.0f);
  numBytes += cSlice_init(&cSlice_dddmaAch, 1, -1);
  numBytes += cSlice_init(&cSlice_yuNWjoAj, 1, -1);
  numBytes += cVar_init_f(&cVar_MwDCbdUs, 0.0f);
  numBytes += cIf_init(&cIf_D9YsdWp7, false);
  numBytes += cBinop_init(&cBinop_N9MUS3Js, 0.0f); // __neq
  numBytes += cDelay_init(this, &cDelay_7WHDvVcx, 0.0f);
  numBytes += cVar_init_f(&cVar_FAgtha45, 500.0f);
  numBytes += cBinop_init(&cBinop_sb9dWUVX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_uS1e7H46, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_daisyevi_debugging::~Heavy_daisyevi_debugging() {
  // nothing to free
}

HvTable *Heavy_daisyevi_debugging::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_daisyevi_debugging::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0Y2Tq3Ew_sendMessage);
      break;
    }
    case 0x477CB2C4: { // breath
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_99LwEanc_sendMessage);
      break;
    }
    case 0xBDAEB3AA: { // encoder
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OBF6QaVt_sendMessage);
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


void Heavy_daisyevi_debugging::cVar_NzRBb6M2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SNFZE86O_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_daisyevi_debugging::cVar_PHnzQokk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uS1e7H46, HV_BINOP_ADD, 1, m, &cBinop_uS1e7H46_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NzRBb6M2, 0, m, &cVar_NzRBb6M2_sendMessage);
}

void Heavy_daisyevi_debugging::cSwitchcase_SNFZE86O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dddmaAch, 0, m, &cSlice_dddmaAch_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yuNWjoAj, 0, m, &cSlice_yuNWjoAj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MWsFuRAF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oLdsC5nY_sendMessage);
      break;
    }
  }
}

void Heavy_daisyevi_debugging::cSlice_dddmaAch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_MwDCbdUs, 0, m, &cVar_MwDCbdUs_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_MwDCbdUs, 0, m, &cVar_MwDCbdUs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cSlice_yuNWjoAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_N9MUS3Js, HV_BINOP_NEQ, 1, m, &cBinop_N9MUS3Js_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_MwDCbdUs, 1, m, &cVar_MwDCbdUs_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_N9MUS3Js, HV_BINOP_NEQ, 1, m, &cBinop_N9MUS3Js_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_MwDCbdUs, 1, m, &cVar_MwDCbdUs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cVar_MwDCbdUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "encoder");
}

void Heavy_daisyevi_debugging::cIf_D9YsdWp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hEg7JWLO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t9ORiaLa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_daisyevi_debugging::cCast_hEg7JWLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N9MUS3Js, HV_BINOP_NEQ, 1, m, &cBinop_N9MUS3Js_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_t9ORiaLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MwDCbdUs, 0, m, &cVar_MwDCbdUs_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_N9MUS3Js_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D9YsdWp7, 1, m, &cIf_D9YsdWp7_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_MWsFuRAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N9MUS3Js, HV_BINOP_NEQ, 0, m, &cBinop_N9MUS3Js_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_oLdsC5nY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D9YsdWp7, 0, m, &cIf_D9YsdWp7_sendMessage);
}

void Heavy_daisyevi_debugging::cSwitchcase_V4QK5aUP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_66lVHwJ2_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_66lVHwJ2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EEnqRmy0_sendMessage);
      break;
    }
  }
}

void Heavy_daisyevi_debugging::cDelay_7WHDvVcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7WHDvVcx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7WHDvVcx, 0, m, &cDelay_7WHDvVcx_sendMessage);
}

void Heavy_daisyevi_debugging::cCast_EEnqRmy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_66lVHwJ2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7WHDvVcx, 0, m, &cDelay_7WHDvVcx_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_RU8V4CF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ywBpKKyH_sendMessage);
}

void Heavy_daisyevi_debugging::cSystem_ywBpKKyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gys504IE_sendMessage);
}

void Heavy_daisyevi_debugging::cVar_FAgtha45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sb9dWUVX, HV_BINOP_MULTIPLY, 0, m, &cBinop_sb9dWUVX_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_66lVHwJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7WHDvVcx, 0, m, &cDelay_7WHDvVcx_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_64EORuyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7WHDvVcx, 2, m, &cDelay_7WHDvVcx_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_gys504IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sb9dWUVX, HV_BINOP_MULTIPLY, 1, m, &cBinop_sb9dWUVX_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_sb9dWUVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_64EORuyH_sendMessage);
}

void Heavy_daisyevi_debugging::cBinop_uS1e7H46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PHnzQokk, 0, m, &cVar_PHnzQokk_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_w1qIgBnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uS1e7H46, HV_BINOP_ADD, 0, m, &cBinop_uS1e7H46_sendMessage);
}

void Heavy_daisyevi_debugging::cMsg_m8AjP9FN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uS1e7H46, HV_BINOP_ADD, 0, m, &cBinop_uS1e7H46_sendMessage);
}

void Heavy_daisyevi_debugging::cReceive_OBF6QaVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uS1e7H46, HV_BINOP_ADD, 0, m, &cBinop_uS1e7H46_sendMessage);
}

void Heavy_daisyevi_debugging::cReceive_99LwEanc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "breath");
}

void Heavy_daisyevi_debugging::cReceive_0Y2Tq3Ew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RU8V4CF5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FAgtha45, 0, m, &cVar_FAgtha45_sendMessage);
  cSwitchcase_V4QK5aUP_onMessage(_c, NULL, 0, m, NULL);
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
