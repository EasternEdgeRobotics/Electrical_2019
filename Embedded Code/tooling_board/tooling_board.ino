/*************************************/
/*-----------------------------------*/
/********Tooling Embedded Code********/
/*****Eastern Edge Robotics 2019******/
/*-----------------------------------*/
/*************************************/

//Contributers: David Drover

#include <Adafruit_Sensor.h> //imu
#include <Adafruit_BNO055.h> //imu
#include <utility/imumaths.h> //pressure
#include "MS5837.h" //pressure
#include <OneWire.h> //Temperature
#include <DallasTemperature.h>//Temperature
#include <Wire.h> //i2c
#include "wiring_private.h" //i2c

//Pin Definitions
#define VMetal 4
#define VPH 5
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


int motors[4] = {EnableA1, EnableA2, EnableB1, EnableB2};
int dirControl[4] = {DirA1, DirA2, DirB1, DirB2};
int dir1, dir2, dir3, dir4; 
int duty1, duty2, duty3, duty4;
int LedDuty;
int sensors = 0;
imu::Vector<3> euler;
imu::Vector<3> accel;
float Temp;

//Define one wire comunication
OneWire oneWire(TempData);

//Define temperature sensor
DallasTemperature temp(&oneWire);

//Define I2C Wire
TwoWire myWire(&sercom3, SDA_Pin, SCL_Pin);

//Define pressure sensor
MS5837 sensor;

//Define Gyro sensor
Adafruit_BNO055 bno = Adafruit_BNO055();

void returnImuPressureData(int mode = 1);
void changeMotor(int motorNum, int dir, int duty);
void Led(int duty);
void returnSensorData(void);
float calculateTemp(void);
String metal(void);
float ph(void);


void setup(void) 
{

  analogReadResolution(12); // sets the ADC to 12 bit mode
  
  Serial.begin(115200);

  myWire.begin();

  pinPeripheral(SDA_Pin, PIO_SERCOM);
  pinPeripheral(SCL_Pin, PIO_SERCOM);  

  sensor.init();
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(997);
  
  bno.begin();

  temp.begin();

  //Setup pins
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
  
  //ensure nothing run from not being set
  for(int i = 1; i<=4; i++)
  {
    changeMotor(i, 1, 0);
  }
  Led(0);

}

void loop(void) 
{
  while(Serial.read() == -1)
  {
    if(sensors == 1)
    {
      returnImuPressureData(2);
      returnSensorData();
    }else{
      returnImuPressureData();
    }
  }
  char buf[90];
  String input = Serial.readString();
  input.toCharArray(buf, 90);
  int n = sscanf(buf, "{ motor1:%d, %d, motor2:%d, %d, motor3:%d, %d, motor4:%d, %d, LED:%d, sensorsreading:%d }", &dir1, &duty1, &dir2, &duty2, &dir3, &duty3, &dir4, &duty4, &LedDuty, &sensors);
  changeMotor(1, dir1, duty1);
  changeMotor(2, dir2, duty2);
  changeMotor(3, dir3, duty3);
  changeMotor(4, dir4, duty4);
  Led(LedDuty);
}

void returnImuPressureData(int mode)
{
  sensor.read();
  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  Temp = bno.getTemp();

  Serial.print("{ ");
  //Serial.print("Pressure:"); 
  Serial.print(sensor.pressure()); 
  
  //Serial.print(", TemperaturePS:"); 
  Serial.print(", ");
  Serial.print(sensor.temperature()); 
 
  //Serial.print(", GyroX:");
  Serial.print(", ");
  Serial.print(euler.x());
  
  //Serial.print(", GyroY:");
  Serial.print(", ");
  Serial.print(euler.y());
  
  //Serial.print(", GyroZ:");
  Serial.print(", ");
  Serial.print(euler.z());

  //Serial.print(", Accelx:");
  Serial.print(", ");
  Serial.print(accel.x()); 

  //Serial.print(", Accely:");
  Serial.print(", ");
  Serial.print(accel.y()); 

  //Serial.print(", Accelz:");
  Serial.print(", ");
  Serial.print(accel.z()); 

  //Serial.print(", TemperatureIMU:");
  Serial.print(", ");
  Serial.print(Temp);

  if(mode == 1)
  {
    Serial.print(" }");
  }else{
    Serial.print(", ");
  }
}

void changeMotor(int motorNum, int dir, int duty)
{
  digitalWrite(dirControl[(motorNum - 1)], dir);
  analogWrite(motors[(motorNum - 1)], (255.0*(duty/100.0)));
}

void Led(int duty)
{
  analogWrite(LED, (255.0*(duty/100.0)));
}

void returnSensorData(void)
{
  //Serial.print("temperature:");
  Serial.print(calculateTemp());

  //Serial.print(", Metal:");
  Serial.print(", ");
  Serial.print(metal());

  //Serial.print(", PH:");
  Serial.print(", ");
  Serial.print(ph());

  Serial.print(" }");
}

float calculateTemp(void)
{
  temp.requestTemperatures();
  float temperature = temp.getTempCByIndex(0);
  return temperature;
}

String metal(void)
{
  if(analogRead(VMetal) > 2054)
  {
    return "true";
  }else{
    return "false";    
  }
}

float ph(void)
{
  int raw = analogRead(VPH);
  float ph = 0.0;
  return ph;
}
