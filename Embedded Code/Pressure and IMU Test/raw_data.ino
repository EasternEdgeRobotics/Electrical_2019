#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "MS5837.h"

MS5837 sensor;
Adafruit_BNO055 bno = Adafruit_BNO055();

void setup() {
  SerialUSB.begin(9600);
  Wire.begin();
  sensor.init();
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(997);
  bno.begin();

}

void loop() {
  sensor.read();
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  float Temp = bno.getTemp();

  SerialUSB.print("{Pressure:"); 
  SerialUSB.print(sensor.pressure()); 
  
  SerialUSB.print(", TemperaturePS:"); 
  SerialUSB.print(sensor.temperature()); 
 
  SerialUSB.print(", GyroX:");
  SerialUSB.print(euler.x());
  
  SerialUSB.print(", GyroY:");
  SerialUSB.print(euler.y());
  
  SerialUSB.print(", GyroZ:");
  SerialUSB.print(euler.z());

  SerialUSB.print(", Accelx:");
  SerialUSB.print(accel.x()); 

  SerialUSB.print(", Accely:");
  SerialUSB.print(accel.y()); 

  SerialUSB.print(", Accelz:");
  SerialUSB.print(accel.z()); 

  SerialUSB.print(", TemperatureIMU:");
  SerialUSB.print(Temp);

  SerialUSB.println("}");

  //delay(1000);

}
