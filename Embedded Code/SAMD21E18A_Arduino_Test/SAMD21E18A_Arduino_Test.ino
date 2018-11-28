void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  delay(500);
  Serial.println("Hey");
  int current1 = analogRead(5);
  int current2 = analogRead(6);
  digitalWrite(11, HIGH);
  
  delay(500);
  Serial.println(current1);
  Serial.println(current2);
  digitalWrite(11, LOW);
}
