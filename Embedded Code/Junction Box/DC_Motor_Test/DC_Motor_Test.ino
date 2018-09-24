//Eastern Edge Robotics 2018
//Entire Junction Box system test code

//All GPIO pins listed are tested and verified from the schematic
#define ELEMAGTOG 16
#define PRESSUREDATA 15
#define ATMEGALED 13
#define ACOUSTOG 17
#define FRONTSERVO 5
#define BACKSERVO 3
#define MS1 11
#define MS2 9
#define ENSTEP 7
#define STEPM1 2
#define DIRM1 4
#define STEPM2 19
#define DIRM2 18
#define STEPM3 12
#define DIRM3 14
#define STEPM4 8
#define DIRM4 6

//***************Serial Data RX/TX*****************//
String GetData() {
  bool msgDidEnd = false;
  String data = "";
  int dataLength = 0;
  
  while(!msgDidEnd && dataLength <= 32 && Serial.available() > 0) {
    char currentByte = Serial.read();
    data += currentByte;
    
    if (currentByte == 'e') msgDidEnd = true;
    dataLength += 1;
  }
  return data;
}

void SendData(String data) {
  for (int i=0; i<data.length(); i++) {
   Serial.write(data[i]); 
  }
}

bool dataIsValid(String data) {
    if (data[0] == 'E' && data[1] == 'E' && data[2] == 'R' && data[data.length()-1] == 'e') return true;
    else return false;
}

bool decodeData(String data) {
    //Check for correct message length
    if (data.length() < 32 || data.length() > 32) return false;

    //Set values
    bool motor1 = false;
    bool motor2 = false;
    bool motor3 = false;
    bool motor4 = false;

    if (data[3] == '0') motor1 = false;
    if (data[3] == '1') motor1 = true;

    if (data[4] == '0') motor2 = false;
    if (data[4] == '1') motor2 = true;

    if (data[5] == '0') motor3 = false;
    if (data[5] == '1') motor3 = true;

    if (data[6] == '0') motor4 = false;
    if (data[6] == '1') motor4 = true;

    bool dir1 = false;
    bool dir2 = false;
    bool dir3 = false;
    bool dir4 = false;

    if (data[7] == '0') dir1 = false;
    if (data[7] == '1') dir1 = true;

    if (data[8] == '0') dir2 = false;
    if (data[8] == '1') dir2 = true;

    if (data[9] == '0') dir3 = false;
    if (data[9] == '1') dir3 = true;

    if (data[10] == '0') dir4 = false;
    if (data[10] == '1') dir4 = true;

    int step1 = ((int)data[11]-48)*100 + ((int)data[12]-48)*10 +((int)data[13]-48);
    int step2 = ((int)data[14]-48)*100 + ((int)data[15]-48)*10 +((int)data[16]-48);
    int step3 = ((int)data[17]-48)*100 + ((int)data[18]-48)*10 +((int)data[19]-48);
    int step4 = ((int)data[20]-48)*100 + ((int)data[21]-48)*10 +((int)data[22]-48);

    int servoFront = ((int)data[23]-48)*100 + ((int)data[24]-48)*10 +((int)data[25]-48);
    int servoBack  = ((int)data[26]-48)*100 + ((int)data[27]-48)*10 +((int)data[28]-48);

    int toggleMag      = 0;
    int toggleAcoustic = 1;

    if (data[29] == '0') toggleAcoustic = 0;
    if (data[29] == '1') toggleAcoustic = 1;

    if (data[30] == '0') toggleMag = 0;
    if (data[30] == '1') toggleMag = 1;

    //Set steppers, *servos*, and electromagnet / acoustic pulse]
    enableSteppers();
    turnAllSteppers(motor1, motor2, motor3, motor4, dir1, dir2, dir3, dir4, step1, step2, step3, step4);
    disableSteppers();
    digitalWrite(ACOUSTOG, toggleAcoustic);
    digitalWrite(ELEMAGTOG, toggleMag);
    

    //Debug Prints
    Serial.println("Motor1: " + String(motor1) + " Dir1: " + String(dir1) + " Step1: " + String(step1));
    Serial.println("Motor2: " + String(motor2) + " Dir2: " + String(dir2) + " Step2: " + String(step2));
    Serial.println("Motor3: " + String(motor3) + " Dir3: " + String(dir3) + " Step3: " + String(step3));
    Serial.println("Motor4: " + String(motor4) + " Dir4: " + String(dir4) + " Step4: " + String(step4));
    Serial.println("Front Servo: " + String(servoFront) + " Back Servo: " + String(servoBack));
    Serial.println("Acostic Pulse: " + String(toggleAcoustic) + " Electromagnet: " + String(toggleMag));

    return true;
}

//***************Custom Stepper Functions****************//
//                                                       //
//*******************************************************//

//Turn a stepper by a set amount of steps and in a certain direction, fixed speed
void turnStepper(int motor, int motorDir, int stepCount, int dir) {
  //Set motor direction
  digitalWrite(motorDir, dir);
  delayMicroseconds(1000);

  //Go through steps
  for(int i=0;i<stepCount;i++) {
    digitalWrite(motor, HIGH);
    delayMicroseconds(1000);
    digitalWrite(motor, LOW);
    delayMicroseconds(1000);
  }
}

//Turn a stepper at a desired frequency (Hz)
void turnStepperAtFreq(int motor, int motorDir, int stepCount, int dir, int freq) {
  //Set motor direction
  digitalWrite(motorDir, dir);
  delayMicroseconds(1000);

  //Go through steps
  for(int i=0;i<stepCount;i++) {
    digitalWrite(motor, HIGH);
    delayMicroseconds(int(1000000/(2*freq)));
    digitalWrite(motor, LOW);
    delayMicroseconds(int(1000000/(2*freq)));
  }
}


//Turn a stepper at a desired frequency (Hz)
void turnStepperAtFreqWithDuration(int motor, int motorDir, float duration, int dir, int freq) {
  //Set motor direction
  digitalWrite(motorDir, dir);
  delayMicroseconds(1000);

  int stepCount = int((duration/1000)*freq); 
  Serial.println(stepCount);
  
  //Go through steps
  for(int i=0;i<stepCount;i++) {
    digitalWrite(motor, HIGH);
    delayMicroseconds(int(1000000/(2*freq)));
    digitalWrite(motor, LOW);
    delayMicroseconds(int(1000000/(2*freq)));
  }
}

//Turn all four steppers at desired steps and directions
void turnAllSteppers(bool motor1, bool motor2, bool motor3, bool motor4, bool dir1, bool dir2, bool dir3, bool dir4, int step1, int step2, int step3, int step4) {
  //Determine highest step count
  int highest = step1;
  if (step2 > highest) highest = step2;
  if (step3 > highest) highest = step3;
  if (step4 > highest) highest = step4;

  //Set direction of all steppers
  digitalWrite(DIRM1, dir1);
  digitalWrite(DIRM2, dir2);
  digitalWrite(DIRM3, dir3);
  digitalWrite(DIRM4, dir4);
  delay(1);
  
  //Go through steps
  for (int i=0; i<highest; i++) {
    if (motor1 && (i < step1)) digitalWrite(STEPM1, 0);
    if (motor2 && (i < step2)) digitalWrite(STEPM2, 0);
    if (motor3 && (i < step3)) digitalWrite(STEPM3, 0);
    if (motor4 && (i < step4)) digitalWrite(STEPM4, 0);
    delayMicroseconds(3500);
    
    if (motor1 && (i < step1)) digitalWrite(STEPM1, 1);
    if (motor2 && (i < step2)) digitalWrite(STEPM2, 1);
    if (motor3 && (i < step3)) digitalWrite(STEPM3, 1);
    if (motor4 && (i < step4)) digitalWrite(STEPM4, 1);
    delayMicroseconds(3500);
  }
}

//Enable all motors
void enableSteppers() {
  digitalWrite(ENSTEP, 0);
  delayMicroseconds(1000);
}

//Disable all motors
void disableSteppers() {
  digitalWrite(ENSTEP, 1);
  delayMicroseconds(1000);
}



void setup() {
  Serial.begin(115200);
  
  pinMode(ELEMAGTOG, OUTPUT);
  pinMode(ATMEGALED, OUTPUT);
  pinMode(ACOUSTOG, OUTPUT);
  pinMode(PRESSUREDATA, INPUT);

  pinMode(FRONTSERVO, OUTPUT);
  pinMode(BACKSERVO, OUTPUT);
  
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(ENSTEP, OUTPUT);
  
  pinMode(STEPM1, OUTPUT);
  pinMode(DIRM1, OUTPUT);
  
  pinMode(STEPM2, OUTPUT);
  pinMode(DIRM2, OUTPUT);

  pinMode(STEPM3, OUTPUT);
  pinMode(DIRM3, OUTPUT);
  
  pinMode(STEPM4, OUTPUT);
  pinMode(DIRM4, OUTPUT);

  //Set Stepper Microstepping
  //MS1 = LOW  | MS2 = LOW  | Full Step
  //MS1 = HIGH | MS2 = LOW  | 1/2 Step
  //MS1 = LOW  | MS2 = HIGH | 1/4 Step
  //MS1 = HIGH | MS2 = HIGH | 1/16 Step
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);

  digitalWrite(ACOUSTOG, HIGH);

  delay(100);
}

void loop() {
  delay(300);
  // Clears the trigPin
   digitalWrite(BACKSERVO, LOW);
   delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(BACKSERVO, HIGH);
  delayMicroseconds(10);
  digitalWrite(BACKSERVO, LOW);

  delay(100);

  // Clears the trigPin
   digitalWrite(BACKSERVO, LOW);
   delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(BACKSERVO, HIGH);
  delayMicroseconds(10);
  digitalWrite(BACKSERVO, LOW);

  delay(300);

    // Clears the trigPin
   digitalWrite(BACKSERVO, LOW);
   delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(BACKSERVO, HIGH);
  delayMicroseconds(10);
  digitalWrite(BACKSERVO, LOW);

  delay(500);
}

void turnLeft(int duration_ms) {
  digitalWrite(DIRM1, 0);
  enableSteppers();
  digitalWrite(STEPM1, 0);
  delayMicroseconds(1);
  digitalWrite(STEPM1, 1);
  delayMicroseconds(1);
  
  delay(duration_ms);

  digitalWrite(STEPM1, 0);
  delayMicroseconds(1);
  digitalWrite(STEPM1, 1);
  delayMicroseconds(1);
  digitalWrite(STEPM1, 0);
  delayMicroseconds(1);
  digitalWrite(STEPM1, 1);
  delayMicroseconds(1);
  digitalWrite(STEPM1, 0);
  delayMicroseconds(1);
  digitalWrite(STEPM1, 1);

  disableSteppers();
  delay(10);
}


void turnRight(int duration_ms) {
  digitalWrite(DIRM1, 0);
  enableSteppers();
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  delay(duration_ms);

  disableSteppers();
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  digitalWrite(STEPM1, 0);
  digitalWrite(STEPM1, 1);
  delay(10);
}

