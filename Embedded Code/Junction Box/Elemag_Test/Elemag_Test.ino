//This code is used to test the relay on the junction box board

#define ELEMAGTOG 16


void setup() {
  pinMode(ELEMAGTOG, OUTPUT);
}

void loop() {
  digitalWrite(ELEMAGTOG, 1);
  delay(500);
  digitalWrite(ELEMAGTOG, 0);
  delay(500);
}
