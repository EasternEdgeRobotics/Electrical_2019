//Eastern Edge Robotics 2018
//Acoustic Tx Code


void setup() {
  
  pinMode(5, OUTPUT);

  delay(100);
}

void loop() {
  delay(300);
  // Clears the trigPin
   digitalWrite(5, LOW);
   delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);

  delay(100);

  // Clears the trigPin
   digitalWrite(5, LOW);
   delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);

  delay(300);

    // Clears the trigPin
   digitalWrite(5, LOW);
   delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);

  delay(500);
}
