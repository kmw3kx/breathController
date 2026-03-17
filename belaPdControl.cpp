// belaPdControl.cpp
/*
 * belaControl.cpp
 * Bob Kammauff (kmw3kx)
 *  Created on: 3/17/2026
 *  Allows you to use external code to interface with a custom render.cpp file
 *  for the purpose of using any sensors you like with Bela and libpd. 
 * 
 * This file is meant to be used as a template.
 * 
 * 
*/
#include "belaPdControl.h"

void belaPdControlSetup() {
    // This function is called in render.cpp right at the end of setup(), and is where 
    //you can place any code you want to run in setup().
    #ifdef BELA_PD_CONTROL // // MODIFICATION: add requisite setup code here
        if(!mpr121.begin(1, 0x5A)) 
        {
            rt_printf("Error initialising MPR121\n");
            return false;
        }
        i2cTask = Bela_createAuxiliaryTask(readMPR121, 50, "bela-mpr121");
        
        readIntervalSamples = context->audioSampleRate / readInterval;
        
        // Setup encoder
        gEncoder.setup(kDebouncingSamples, polarity);
        pinMode(context, 0, kEncChA, INPUT);
        pinMode(context, 0, kEncChB, INPUT);
        pinMode(context, 0, kEncChBtn, INPUT);
    #endif // BELA_PD_CONTROL

}
void belaPdControlRender() {
    // This function is called in render.cpp right at the end of render(), and is where 
    //you can place any code you want to run in render().
    #ifdef BELA_PD_CONTROL
        for(unsigned int n = 0; n < context->audioFrames; n++) {
            // Schedule tasks at regular intervals
            if(++readCount >= readIntervalSamples) {
                readCount = 0;
                Bela_scheduleAuxiliaryTask(i2cTask);
            }
            // Read encoder
            bool a = digitalRead(context, n, kEncChA);
            bool b = digitalRead(context, n, kEncChB);
            Encoder::Rotation rot = gEncoder.process(a, b);
            
            if(Encoder::NONE != rot) {
                int position = gEncoder.get();
                libpd_float("encoder_pos", (float)position); //Send to Pd
            }
        }
    #endif // BELA_PD_CONTROL
}

// Auxiliary task to read the I2C board
#ifdef BELA_PD_CONTROL
void readMPR121(void*)
{
    for(int i = 0; i < NUM_TOUCH_PINS; i++) {
        sensorValue[i] = -(mpr121.filteredData(i) - mpr121.baselineData(i));
        sensorValue[i] -= threshold;
        if(sensorValue[i] < 0)
            sensorValue[i] = 0;
    #ifdef DEBUG_MPR121
            rt_printf("%d ", sensorValue[i]);
    #endif
    }
    #ifdef DEBUG_MPR121
        rt_printf("\n");
    #endif
    libpd_float("mpr121", mpr121.touched()); //This sends the float (mpr121.touched()) to a receiver in pd with whatever name you put in the quotes.
}
#endif // BELA_PD_CONTROL   