
void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, 0);
  delay(1000);
  digitalWrite(4, 1);
  delay(1000);
}
