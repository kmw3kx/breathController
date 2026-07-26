// Basic capacitive sensing on a single Arduino pin
// No external libraries required

const int sensePin = 13;     // Touch electrode
const int sendPin  = 9;     // Drive pin (optional but improves stability)

long readCapacitance() {
  long count = 0;

  // 1. Discharge the sense pin
  pinMode(sensePin, OUTPUT);
  digitalWrite(sensePin, LOW);
  delayMicroseconds(5);

  // 2. Charge through sendPin
  pinMode(sensePin, INPUT);        // High impedance
  digitalWrite(sendPin, HIGH);     // Start charging the electrode

  // 3. Count until the sense pin reads HIGH
  while (digitalRead(sensePin) == LOW) {
    count++;
    if (count > 30000) break;      // Safety cap
  }

  // 4. Discharge again
  pinMode(sensePin, OUTPUT);
  digitalWrite(sensePin, LOW);

  return count;
}

void setup() {
  Serial.begin(115200);
  pinMode(sendPin, OUTPUT);
  digitalWrite(sendPin, LOW);
}

void loop() {
  long cap = readCapacitance();
  Serial.println(cap);
  delay(10);
}