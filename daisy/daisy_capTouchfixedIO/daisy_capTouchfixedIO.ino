const int inPin = 11;   // touch pad (never changes mode)
const int outPin  = 10;   // stays OUTPUT forever


uint16_t readCap(int sensePin, int pumpPin) {
  uint16_t count = 0;

  // Step 1: Discharge pad through pumpPin
  digitalWrite(pumpPin, LOW);
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

void setup() {
  Serial.begin(115200);
  pinMode(inPin, INPUT);   // never changes
  pinMode(outPin, OUTPUT);   // never changes
}

void loop() {
  uint16_t value = readCap(inPin, outPin);
  Serial.println(value);
  delay(5);
}
