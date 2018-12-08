void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  delay(250);
  Serial.println("Hey");
  digitalWrite(14, HIGH);
  
  delay(250);
  Serial.println(analogRead(2));
  Serial.println(analogRead(3));
  Serial.println(analogRead(4));
  Serial.println(analogRead(5));
  Serial.println(analogRead(6));
  Serial.println(analogRead(7));
  Serial.println(analogRead(8));
  Serial.println(analogRead(9));
  Serial.println(analogRead(10));
  Serial.println(analogRead(11));
  digitalWrite(14, LOW);
}
