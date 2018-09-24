
void setup() {
  pinMode(12, INPUT);
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println("Serial Initialized...");
}

void loop() {
    Serial.println(digitalRead(12));
    delay(100);
}
