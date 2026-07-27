/*
 * MIT License
 *
 * Copyright (c) 2021 Electrosmith
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef __JSON2DAISY_PROTODAISYEVI_H__
#define __JSON2DAISY_PROTODAISYEVI_H__

#include "daisy_seed.h"
#include "dev/codec_ak4556.h"
#include "dev/oled_ssd130x.h"

#define ANALOG_COUNT 3

namespace json2daisy {



struct DaisyProtodaisyevi {

  /** Initializes the board according to the JSON board description
   *  \param boost boosts the clock speed from 400 to 480 MHz
   */
  void Init(bool boost=true)
  {
    som.Configure();
    som.Init(boost);

    // Gate ins
    capin1.Init(som.GetPin(13), true);
    capin2.Init(som.GetPin(12), true);
    capin3.Init(som.GetPin(11), true);

    // Rotary encoders
    encoder.Init(som.GetPin(5), som.GetPin(4), som.GetPin(3), som.AudioCallbackRate());

    // Single channel ADC initialization
    cfg[0].InitSingle(som.GetPin(15));
    cfg[1].InitSingle(som.GetPin(16));
    cfg[2].InitSingle(som.GetPin(17));
    som.adc.Init(cfg, ANALOG_COUNT);

    // AnalogControl objects
    breath.Init(som.adc.GetPtr(0), som.AudioCallbackRate(), false, false);
    joyx.Init(som.adc.GetPtr(1), som.AudioCallbackRate(), false, false);
    joyy.Init(som.adc.GetPtr(2), som.AudioCallbackRate(), false, false);

    // Gate outs
    capout1.Init(som.GetPin(9), daisy::GPIO::Mode::OUTPUT, daisy::GPIO::Pull::NOPULL);
    capout2.Init(som.GetPin(14), daisy::GPIO::Mode::OUTPUT, daisy::GPIO::Pull::NOPULL);
    capout3.Init(som.GetPin(10), daisy::GPIO::Mode::OUTPUT, daisy::GPIO::Pull::NOPULL);

    // Display

        daisy::OledDisplay<daisy::SSD130x4WireSpi128x64Driver>::Config display_config;
        display_config.driver_config.transport_config.Defaults();

        display.Init(display_config);
          display.Fill(0);
          display.Update();


    som.adc.Start();
  }

  /** Handles all the controls processing that needs to occur at the block rate
   *
   */
  void ProcessAllControls()
  {
    breath.Process();
    joyx.Process();
    joyy.Process();
    encoder.Debounce();
  }

  /** Handles all the maintenance processing. This should be run last within the audio callback.
   *
   */
  void PostProcess()
  {

  }

  /** Handles processing that shouldn't occur in the audio block, such as blocking transfers
   *
   */
  void LoopProcess()
  {

  }

  /** Sets the audio sample rate
   *  \param sample_rate the new sample rate in Hz
   */
  void SetAudioSampleRate(size_t sample_rate)
  {
    daisy::SaiHandle::Config::SampleRate enum_rate;
    if (sample_rate >= 96000)
      enum_rate = daisy::SaiHandle::Config::SampleRate::SAI_96KHZ;
    else if (sample_rate >= 48000)
      enum_rate = daisy::SaiHandle::Config::SampleRate::SAI_48KHZ;
    else if (sample_rate >= 32000)
      enum_rate = daisy::SaiHandle::Config::SampleRate::SAI_32KHZ;
    else if (sample_rate >= 16000)
      enum_rate = daisy::SaiHandle::Config::SampleRate::SAI_16KHZ;
    else
      enum_rate = daisy::SaiHandle::Config::SampleRate::SAI_8KHZ;
    som.SetAudioSampleRate(enum_rate);
    breath.SetSampleRate(som.AudioCallbackRate());
    joyx.SetSampleRate(som.AudioCallbackRate());
    joyy.SetSampleRate(som.AudioCallbackRate());
    encoder.SetUpdateRate(som.AudioCallbackRate());
  }

  /** Sets the audio block size
   *  \param block_size the new block size in words
   */
  inline void SetAudioBlockSize(size_t block_size)
  {
    som.SetAudioBlockSize(block_size);
  }

  /** Starts up the audio callback process with the given callback
   *
   */
  inline void StartAudio(daisy::AudioHandle::AudioCallback cb)
  {
    som.StartAudio(cb);
  }

  /** This is the board's "System On Module" */
  daisy::DaisySeed som;
  daisy::AdcChannelConfig cfg[ANALOG_COUNT];

  // I/O Components
  daisy::AnalogControl breath;
  daisy::AnalogControl joyx;
  daisy::AnalogControl joyy;
  daisy::Encoder encoder;
  daisy::GateIn capin1;
  daisy::GateIn capin2;
  daisy::GateIn capin3;
  daisy::GPIO capout1;
  daisy::GPIO capout2;
  daisy::GPIO capout3;
  daisy::OledDisplay<daisy::SSD130x4WireSpi128x64Driver> display;
  daisy::MidiUartHandler midi;

};

} // namspace json2daisy

#endif // __JSON2DAISY_PROTODAISYEVI_H__
