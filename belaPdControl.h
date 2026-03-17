// belaPdControl.h
/*
 * belaControl.h
 * Bob Kammauff (kmw3kx)
 *  Created on: 3/17/2026
 *  Allows you to use external code to interface with a custom render.cpp file
 *  for the purpose of using any sensors you like with Bela and libpd. 
 * 
 * This file is meant to be used as a template. If this is no longer a template
 * say what it does in the next comment block:
*/

/*
 * What was I made for: I need to use a MPR121 capacitive touch sensor and a rotary encoder with Bela and libpd,
 * but the default render.cpp file doesn't have any code to interface with those sensors. This also allows me to edit 
 * parameters while working in the Bela IDE, since it doesn't let you edit pd patches. 
*/

//This file is nice and easy; it just initializes the variables and libraries that you need to use in render.cpp, 
//and is included in render.cpp right before setup(), meaning that it will deal with initialization of any variables
// or libraries that you need to use in render.cpp. All functions initialized here will be defined in belaPdControl.cpp, including:
void belaPdControlSetup(); //this is the function that will be called in render.cpp at the end of the setup() function
//You will put whatever code you would normally put in the setup() function, and it will be called right after the Pd patch is loaded.

void belaPdControlRender(); //this is the function that will be called in render.cpp at the end of the render() function
//This is where you can put any code that you would normally put in the render() function.

// you can also mass exclude this code if you'd like by commenting out the #define BELA_PD_CONTROL below:
#define BELA_PD_CONTROL // comment this out
// this will undefine the BELA_PD_CONTROL flag and thus exclude all codethat is marked by `#ifdef BELA_PD_CONTROL` 
// Include what you need to initialize here:
#ifdef BELA_PD_CONTROL
#include "I2C_MPR121.h" // for capacitive touch sensor
#include <libraries/Encoder/Encoder.h> // for rotary encoder

// How many pins there are
#define NUM_TOUCH_PINS 12
// Define this to print data to terminal (possibly broken)
#undef DEBUG_MPR121

// Change this to change how often the MPR121 & encoder is read (in Hz)
int readInterval = 50;
// Change this threshold to set the minimum amount of touch
int threshold = 40;

// This array holds the continuous sensor values
int sensorValue[NUM_TOUCH_PINS];

// Encoder setup
Encoder gEncoder;
unsigned int kEncChA = 0;
unsigned int kEncChB = 1;
unsigned int kEncChBtn = 2;
unsigned int kDebouncingSamples = 15;
Encoder::Polarity polarity = Encoder::ANY;

// More setup classes

I2C_MPR121 mpr121;			// Object to handle MPR121 sensing
AuxiliaryTask i2cTask;		// Auxiliary task to read I2C
AuxiliaryTask encoderTask;	// Auxiliary task to read encoder
int readCount = 0;			// How long until we read again...
int readIntervalSamples = 0; // How many samples between reads

void readMPR121(void*); // Auxiliary task to read MPR121 sensor values
#endif // BELA_PD_CONTROL

