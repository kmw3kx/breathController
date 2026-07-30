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

#include "Heavy_breathPrint.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_breathPrint *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_breathPrint_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_breathPrint));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_breathPrint(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_breathPrint_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_breathPrint));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_breathPrint(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_breathPrint_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_breathPrint();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_breathPrint::Heavy_breathPrint(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sSample_init(&sSample_17KliLii);
  numBytes += cDelay_init(this, &cDelay_OVKVjk4K, 0.0f);
  numBytes += cVar_init_f(&cVar_RKimKgTO, 100.0f);
  numBytes += cBinop_init(&cBinop_gerh62IE, 0.0f); // __mul
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_breathPrint::~Heavy_breathPrint() {
  // nothing to free
}

HvTable *Heavy_breathPrint::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_breathPrint::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bFtWTd6O_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_breathPrint::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
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
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_breathPrint::sSample_17KliLii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "print");
}

void Heavy_breathPrint::cSwitchcase_sGLmDJe9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_32XTkm42_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_32XTkm42_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bIza2QEc_sendMessage);
      break;
    }
  }
}

void Heavy_breathPrint::cDelay_OVKVjk4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OVKVjk4K, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OVKVjk4K, 0, m, &cDelay_OVKVjk4K_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_17KliLii, 1, m);
}

void Heavy_breathPrint::cCast_bIza2QEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_32XTkm42_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OVKVjk4K, 0, m, &cDelay_OVKVjk4K_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_17KliLii, 1, m);
}

void Heavy_breathPrint::cMsg_hVIAqQhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E2dilKrQ_sendMessage);
}

void Heavy_breathPrint::cSystem_E2dilKrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZkwFI12P_sendMessage);
}

void Heavy_breathPrint::cVar_RKimKgTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gerh62IE, HV_BINOP_MULTIPLY, 0, m, &cBinop_gerh62IE_sendMessage);
}

void Heavy_breathPrint::cMsg_32XTkm42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OVKVjk4K, 0, m, &cDelay_OVKVjk4K_sendMessage);
}

void Heavy_breathPrint::cBinop_1HE7RiGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OVKVjk4K, 2, m, &cDelay_OVKVjk4K_sendMessage);
}

void Heavy_breathPrint::cBinop_ZkwFI12P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gerh62IE, HV_BINOP_MULTIPLY, 1, m, &cBinop_gerh62IE_sendMessage);
}

void Heavy_breathPrint::cBinop_gerh62IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1HE7RiGk_sendMessage);
}

void Heavy_breathPrint::cReceive_bFtWTd6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hVIAqQhl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RKimKgTO, 0, m, &cVar_RKimKgTO_sendMessage);
  cSwitchcase_sGLmDJe9_onMessage(_c, NULL, 0, m, NULL);
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

int Heavy_breathPrint::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t I0, I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14;

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

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));
    __hv_load_f(inputBuffers[2]+n, VOf(I2));
    __hv_load_f(inputBuffers[3]+n, VOf(I3));
    __hv_load_f(inputBuffers[4]+n, VOf(I4));
    __hv_load_f(inputBuffers[5]+n, VOf(I5));
    __hv_load_f(inputBuffers[6]+n, VOf(I6));
    __hv_load_f(inputBuffers[7]+n, VOf(I7));
    __hv_load_f(inputBuffers[8]+n, VOf(I8));
    __hv_load_f(inputBuffers[9]+n, VOf(I9));
    __hv_load_f(inputBuffers[10]+n, VOf(I10));
    __hv_load_f(inputBuffers[11]+n, VOf(I11));
    __hv_load_f(inputBuffers[12]+n, VOf(I12));
    __hv_load_f(inputBuffers[13]+n, VOf(I13));
    __hv_load_f(inputBuffers[14]+n, VOf(I14));

    

    // process all signal functions
    __hv_sample_f(this, &sSample_17KliLii, VIf(I14), &sSample_17KliLii_sendMessage);

    // save output vars to output buffer
    // no output channels
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_breathPrint::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 15 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(15*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);
  bIn[2] = inputBuffers+(2*n4);
  bIn[3] = inputBuffers+(3*n4);
  bIn[4] = inputBuffers+(4*n4);
  bIn[5] = inputBuffers+(5*n4);
  bIn[6] = inputBuffers+(6*n4);
  bIn[7] = inputBuffers+(7*n4);
  bIn[8] = inputBuffers+(8*n4);
  bIn[9] = inputBuffers+(9*n4);
  bIn[10] = inputBuffers+(10*n4);
  bIn[11] = inputBuffers+(11*n4);
  bIn[12] = inputBuffers+(12*n4);
  bIn[13] = inputBuffers+(13*n4);
  bIn[14] = inputBuffers+(14*n4);

  // define the heavy output buffer for 0 channel(s)
  float **const bOut = NULL;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_breathPrint::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 15 channel(s), uninterleave
  float *const bIn = (float *) hv_alloca(15*n4*sizeof(float));
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+15*j];
    bIn[1*n4+j] = inputBuffers[1+15*j];
    bIn[2*n4+j] = inputBuffers[2+15*j];
    bIn[3*n4+j] = inputBuffers[3+15*j];
    bIn[4*n4+j] = inputBuffers[4+15*j];
    bIn[5*n4+j] = inputBuffers[5+15*j];
    bIn[6*n4+j] = inputBuffers[6+15*j];
    bIn[7*n4+j] = inputBuffers[7+15*j];
    bIn[8*n4+j] = inputBuffers[8+15*j];
    bIn[9*n4+j] = inputBuffers[9+15*j];
    bIn[10*n4+j] = inputBuffers[10+15*j];
    bIn[11*n4+j] = inputBuffers[11+15*j];
    bIn[12*n4+j] = inputBuffers[12+15*j];
    bIn[13*n4+j] = inputBuffers[13+15*j];
    bIn[14*n4+j] = inputBuffers[14+15*j];
  }

  // define the heavy output buffer for 0 channel(s)
  float *const bOut = NULL;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
