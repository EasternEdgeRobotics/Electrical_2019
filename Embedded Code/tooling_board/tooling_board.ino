/*************************************/
/*-----------------------------------*/
/********Tooling Embedded Code********/
/*****Eastern Edge Robotics 2019******/
/*-----------------------------------*/
/*************************************/

// Contributers: David Drover

#include <Adafruit_Sensor.h> // imu
#include <Adafruit_BNO055.h> // imu
#include <utility/imumaths.h> // imu
#include "MS5837.h" // Pressure
#include <OneWire.h> // Temperature
#include <DallasTemperature.h>// Temperature
#include <Wire.h> // i2c
#include "wiring_private.h" // i2c

// Pin Definitions
#define VMetal 4
#define VPH A5
#define TempData 10
#define EnableA1 9
#define DirA1 14
#define EnableA2 15
#define DirA2 17
#define EnableB1 8
#define DirB1 16
#define EnableB2 19
#define DirB2 28
#define LED 18
#define LED_IN 11
#define SCL_Pin 23
#define SDA_Pin 22

// Global variables
int id;
int dir, dir1, dir2, dir3, dir4; 
int duty, duty1, duty2, duty3, duty4;
int LedDuty;
int tempPH = 0;
int mDetect = 0;
char buf[90];
char hold;
int x;
imu::Vector<3> euler; //primary sensors
imu::Vector<3> accel; //primary sensors
float Temp; //primary sensors
bool gyroSen = true; // Testing gyro
bool pressureSen = true; // Testing pressure
int motors[4] = {EnableA2, EnableB2, EnableA1, EnableB1}; //motors
int dirControl[4] = {DirA2, DirB2, DirA1, DirB1}; //motors
float temperature; // temperature sensor
int rawAvg; // pH sensor
float pH; // pH sensor

// Define one wire communication
OneWire oneWire(TempData);

// Define temperature sensor
DallasTemperature temp(&oneWire);

// Define pressure sensor
MS5837 sensor;

// Define Gyro sensor
Adafruit_BNO055 bno = Adafruit_BNO055();

void returnImuPressureData(int mode = 1);
void changeMotor(int motorNum, int dir, int duty);
void Led(int duty);
void returnSensorData(void);
float calculateTemp(void);
int metal(void);
float ph(double offset);

void setup(void) 
{
  pinPeripheral(11, PIO_TIMER_PWM);
  pinPeripheral(18, PIO_TIMER_PWM);
  pinPeripheral(19, PIO_TIMER_PWM);
  pinPeripheral(22, PIO_SERCOM);
  pinPeripheral(23, PIO_SERCOM);

  analogReadResolution(12); // Sets the ADC to 12 bit mode
  
  Serial.begin(115200);

  if(!sensor.init())
  {
    pressureSen = false;
  }
  
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(997);
  
  if(!bno.begin())
  {
    gyroSen = false;
  }

  temp.begin();

  // Setup pins
  pinMode(VMetal, INPUT); 
  pinMode(VPH, INPUT); 
  pinMode(TempData, INPUT); 
  pinMode(EnableA1, OUTPUT);
  pinMode(DirA1, OUTPUT);
  pinMode(EnableA2, OUTPUT);
  pinMode(DirA2, OUTPUT);
  pinMode(EnableB1, OUTPUT);
  pinMode(DirB1, OUTPUT);
  pinMode(EnableB2, OUTPUT);
  pinMode(DirB2, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED_IN, OUTPUT);
  
  // Ensure nothing run from not being set
  for(int i = 1; i<=4; i++)
  {
    changeMotor(i, 1, 0);
  }
  Led(0);
  for(int i = 0; i < 90; i++)
  {
    buf[i]= ',';
  }
}

void loop(void) 
{
  // Waiting for a serial write
  hold = Serial.read();
  while(hold == 255)
  {   
    if(tempPH == 1 or mDetect == 1)
    {
      returnSensorData();
    }
    else
    {
      if(gyroSen == false)
      {
        Serial.print("gyro not found");
        Serial.flush();
      }
      if(pressureSen == false)
      {
        Serial.print("pressure not found");
        Serial.flush();
      }
      returnImuPressureData();
    }
    hold = Serial.read(); 
  }

  // Serial reading code
  buf[0] = hold;
  x = 1;
  while(x <= 30 and hold != 255)
  {
    delay(4);
    hold = Serial.read();
    while( x == 0 and hold == 255)
    {
      hold = Serial.read();
    }
    buf[x] = hold;
    x++;
  }

  // Decides how to read the input and does the action

  if(buf[2] == 'm' and buf[7] == '1')
  {
    sscanf(buf, "{ motor1:%d, %d, motor2:%d, %d, motor3:%d, %d, motor4:%d, %d, LED:%d, sensorsreading:%d,%d }", &dir1, &duty1, &dir2, &duty2, &dir3, &duty3, &dir4, &duty4, &LedDuty, &tempPH , &mDetect);
    changeMotor(1, dir1, duty1);
    changeMotor(2, dir2, duty2);
    changeMotor(3, dir3, duty3);
    changeMotor(4, dir4, duty4);
    Led(LedDuty);
  }else if(buf[2] == 'm'){
    sscanf(buf, "{ motor:%d, %d, %d }", &id, &dir, &duty);
    changeMotor(id, dir, duty);
  }else if(buf[2] == 'L'){
    sscanf(buf, "{ LED:%d }", &LedDuty);
    Led(LedDuty);
  }else if(buf[2] == 's'){
    sscanf(buf, "{ sensorsreading:%d,%d }", &tempPH , &mDetect);
  }else{
    sscanf(buf, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &dir1, &duty1, &dir2, &duty2, &dir3, &duty3, &dir4, &duty4, &LedDuty, &tempPH, &mDetect);
    changeMotor(1, dir1, duty1);
    changeMotor(2, dir2, duty2);
    changeMotor(3, dir3, duty3);
    changeMotor(4, dir4, duty4);
    Led(LedDuty);
  }
}


// Prints out imu and pressure sensors data
void returnImuPressureData(int mode)
{
  sensor.read();
  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  accel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
  Temp = bno.getTemp();

  Serial.print("P");
  Serial.flush();

  //Serial.print("Pressure:");
  Serial.print(",");
  Serial.flush();
  Serial.print(sensor.pressure());
  Serial.flush(); 
  
  //Serial.print(", TemperaturePS:"); 
  Serial.print(",");
  Serial.flush();
  Serial.print(sensor.temperature());
  Serial.flush(); 
 
  //Serial.print(", GyroX:");
  Serial.print(",");
  Serial.flush();
  Serial.print(euler.x());
  Serial.flush();
  
  //Serial.print(", GyroY:");
  Serial.print(",");
  Serial.flush();
  Serial.print(euler.y());
  Serial.flush();
  
  //Serial.print(", GyroZ:");
  Serial.print(",");
  Serial.flush();
  Serial.print(euler.z());
  Serial.flush();

  //Serial.print(", Accelx:");
  Serial.print(",");
  Serial.flush();
  Serial.print(accel.x());
  Serial.flush(); 

  //Serial.print(", Accely:");
  Serial.print(",");
  Serial.flush();
  Serial.print(accel.y());
  Serial.flush(); 

  //Serial.print(", Accelz:");
  Serial.print(",");
  Serial.flush();
  Serial.print(accel.z());
  Serial.flush(); 

  //Serial.print(", TemperatureIMU:");
  Serial.print(",");
  Serial.flush();
  Serial.println(Temp);
  Serial.flush();
}

// Changes motor turn speed
void changeMotor(int motorNum, int dir, int duty)
{
  //if(motorNum == 2)
  //{
  //  motorNum--;
  //  digitalWrite(dirControl[motorNum], dir);
  //  digitalWrite(motors[motorNum], (1.0*(duty/100.0)));
  //}
  //else
  //{
    motorNum--;
    digitalWrite(dirControl[motorNum], dir);
    analogWrite(motors[motorNum], (256.0*(duty/100.0)));
  //}
}

// Changes the brightness of the leds
void Led(int duty)
{
  duty = (256.0 *(duty / 100.0));
  analogWrite(LED, duty);
  analogWrite(LED_IN, (256 - duty));
}

// Prints out ph, metal and temperature sensor values
void returnSensorData(void)
{
  Serial.print("S");
  Serial.flush();
  
  //Serial.print("temperature:");
  Serial.print(",");
  Serial.flush();
  if(tempPH == 1)
  {
    Serial.print(calculateTemp());
    Serial.flush();
  }else{
    Serial.print("F");
    Serial.flush();
  }
  
  //Serial.print(", Metal:");
  Serial.print(",");
  Serial.flush();
  if(mDetect == 1)
  {
    Serial.print(metal());
    Serial.flush();
  }else{
    Serial.print("F");
    Serial.flush();
  }
  
  //Serial.print(", PH:");
  Serial.print(",");
  Serial.flush();
  if(tempPH == 1)
  {
    Serial.println(ph(2.72));
    Serial.flush();
  }else{
    Serial.println("F");
    Serial.flush();
  }
}

// Calculates temperature
float calculateTemp(void)
{
  delay(40);
  temp.requestTemperatures();
  delay(40);
  temperature = temp.getTempCByIndex(0);
  return temperature;
}

// Says if it is metal or not
int metal(void)
{
  if(analogRead(VMetal) < 100 )
  {
    return 1;
  }
  else
  {
    return 0;    
  }  
}

// Calculates ph level
float ph(double offset)
{
  rawAvg = 0;
  for( int i = 0; i < 4; i++)
  {
    rawAvg += analogRead(VPH);
    delay(5);
  }
  rawAvg /= 4;
  pH = ((3.5 * (rawAvg * (3.3 / 4096.0))) + offset);
  return pH;
}
