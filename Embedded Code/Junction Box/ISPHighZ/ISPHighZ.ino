//Upload this to the Atmega328p when you want to upload code to the ATtiny!!!
//Sets the ISP pins to high impedence so the programmer doesn't get confused

void setup() {
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  delay(500);
}
