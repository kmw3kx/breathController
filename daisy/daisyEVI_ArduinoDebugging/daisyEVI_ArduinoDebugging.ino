// daisy EVI debugging code
// 7/23/26
// kmw3kx
// Written by Copilot, edited by Bob

// -----------------------------
// Pin assignments
// -----------------------------

// Analog sensors
const int analogPins[3] = {A1, A2, A3}; // breath & joy

// Capacitive sensors (each uses 2 pins: send + receive)
struct CapPins {
  int sensePin;
  int pumpPin;
};
CapPins cap[3] = { // (100k and 1k order)
  {13, 9},   // cap sensor 1, grn (D13) & gry(D9)
  {12, 14},   // cap sensor 2, ylw (D11) & red (D14) 
  {11, 10}   // cap sensor 3, wt  (D10) & Wt (D12)
};

// Encoder
#define ENC_CLK 5
#define ENC_DT  4
#define ENC_SW  3

volatile long encoderCount = 0;
volatile bool encoderMoved = false;

// -----------------------------
// Setup
// -----------------------------
void setup() {
  Serial.begin(115200);

  // Analog pins
  for (int i = 0; i < 3; i++) {
    pinMode(analogPins[i], INPUT);
  }

  // Capacitive sensor pins
  for (int i = 0; i < 3; i++) {
    pinMode(cap[i].sensePin, INPUT);
    pinMode(cap[i].pumpPin, OUTPUT);
  }

  // Encoder pins (external pull-ups assumed)
  pinMode(ENC_CLK, INPUT_PULLUP);
  pinMode(ENC_DT, INPUT_PULLUP);
  pinMode(ENC_SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENC_CLK), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_DT),  encoderISR, CHANGE);
}

// -----------------------------
// Capacitive sensing function
// -----------------------------
// Measures charge time on sensePin.
uint16_t readCap(int sensePin, int pumpPin) {
  uint16_t count = 0;

  // Step 1: Discharge pad through pumpPin
  digitalWrite(pumpPin, LOW);
  delayMicroseconds(100);
  while (digitalRead(sensePin) == HIGH) {
    count++;
    if (count > 65000) break;
  }

  // Step 2: Charge pad through pumpPin
  digitalWrite(pumpPin, HIGH);

  // Step 3: Count until sensePin reads HIGH
  while (digitalRead(sensePin) == LOW) {
    count++;
    if (count > 65000) break;
  }

  return count;
}
// int readCapacitive(int sendPin, int recvPin) {
//   int count = 0;

//   // 1. Discharge the pad by pulling sendPin LOW briefly
//   digitalWrite(sendPin, LOW);
//   delayMicroseconds(5);

//   // 2. Begin charging
//   digitalWrite(sendPin, HIGH);

//   // 3. Count until recvPin rises
//   while (digitalRead(recvPin) == LOW && count < 3000) {
//     count++;
//   }

//   return count;
// }


// -----------------------------
// Encoder interrupt
// -----------------------------


void encoderISR() {
  static int lastCLK = digitalRead(ENC_CLK);

  int clkState = digitalRead(ENC_CLK);
  int dtState  = digitalRead(ENC_DT);

  // Only act on CLK changes
  if (clkState != lastCLK) {
    if (dtState != clkState) encoderCount++;   // clockwise
    else encoderCount--;                       // counter‑clockwise
    encoderMoved = true;
  }

  lastCLK = clkState;
}

// -----------------------------
// Main loop
// -----------------------------
void loop() {
  // Read analog sensors
  int analogVals[3];
  for (int i = 0; i < 3; i++) {
    analogVals[i] = analogRead(analogPins[i]);
  }

  // Read capacitive sensors
  int capVals[3];
  for (int i = 0; i < 3; i++) {
    capVals[i] = readCap(cap[i].sensePin, cap[i].pumpPin);
  }

  // Read encoder button
  bool buttonPressed = (digitalRead(ENC_SW) == LOW);

  // Print everything in one line
  Serial.print("A:");
  Serial.print(analogVals[0]); Serial.print(",");
  Serial.print(analogVals[1]); Serial.print(",");
  Serial.print(analogVals[2]);

  Serial.print("  C:");
  Serial.print(capVals[0]); Serial.print(",");
  Serial.print(capVals[1]); Serial.print(",");
  Serial.print(capVals[2]);

  Serial.print("  ENC:");
  Serial.print(encoderCount);

  Serial.print("  BTN:");
  Serial.print(buttonPressed ? 1 : 0);

  Serial.println();

  delay(10);
}
