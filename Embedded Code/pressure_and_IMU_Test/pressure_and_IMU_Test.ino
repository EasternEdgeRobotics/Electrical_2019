#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055_default.h>
#include <utility/imumaths.h>
#include "MS5837_default.h"

MS5837 sensor;
Adafruit_BNO055 bno = Adafruit_BNO055();
float Temp;
imu::Vector<3> accel;
imu::Vector<3> euler;

void setup() {
  SerialUSB.begin(115200);
  Wire.begin();
  sensor.init();
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(997);
  bno.begin();
}

void loop() {
  sensor.read();
  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  Temp = bno.getTemp();

  //SerialUSB.print("Pressure:"); 
  SerialUSB.print(sensor.pressure()); 

  //SerialUSB.print(", TemperaturePS:");
  SerialUSB.print(",");
  SerialUSB.print(sensor.temperature()); 

  //SerialUSB.print(", GyroX:");
  SerialUSB.print(",");
  SerialUSB.print(euler.x());

  //SerialUSB.print(", GyroY:");
  SerialUSB.print(",");
  SerialUSB.print(euler.y());

  //SerialUSB.print(", GyroZ:");
  SerialUSB.print(",");
  SerialUSB.print(euler.z());

  //SerialUSB.print(", Accelx:");
  SerialUSB.print(",");
  SerialUSB.print(accel.x()); 

  //SerialUSB.print(", Accely:");
  SerialUSB.print(",");
  SerialUSB.print(accel.y()); 

  //SerialUSB.print(", Accelz:")
  SerialUSB.print(",");;
  SerialUSB.print(accel.z()); 

  //SerialUSB.print(", TemperatureIMU:");
  SerialUSB.print(",");
  SerialUSB.println(Temp);

}
