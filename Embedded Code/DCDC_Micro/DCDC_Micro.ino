/*************************************/
/*-----------------------------------*/
/******DC-DC Micro Embedded Code******/
/*****Eastern Edge Robotics 2019******/
/*-----------------------------------*/
/*************************************/

//Contributers: Mark Belbin -  

#include <Wire.h>
#include "wiring_private.h"

//Pin Definitions
#define VIOUT1 5
#define VIOUT2 6
#define VIOUT3 7
#define TESTLED 11

//I2C Addresses and Commands
#define DCDC_A        (0x77)      //DCDC A (Micro) address (Default address)
#define DCDC_B        (0x02)      //DCDC B address
#define DCDC_C        (0x03)      //DCDC C address
#define READ_VIN      (0x88)
#define READ_VOUT     (0x8B)
#define READ_IOUT     (0x8C)
#define READ_TEMP     (0x8D)
#define VOUT_MODE     (0x20)


//Define I2C Wire
TwoWire myWire(&sercom3, 22, 23);

uint16_t value;

void setup() {
  //Let DC-DCs "boot", make sure we don't lock up the PMBus
  delay(100);
  
  Serial.begin(115200);

  myWire.begin();
  
  pinPeripheral(22, PIO_SERCOM);
  pinPeripheral(23, PIO_SERCOM);
  
  //Setup Pins, check schematic for more details
  pinMode(VIOUT1, INPUT); 
  pinMode(VIOUT2, INPUT); 
  pinMode(VIOUT3, INPUT); 
  pinMode(TESTLED, OUTPUT); 
}

void loop() {
  myWire.beginTransmission(DCDC_A);
  myWire.write(READ_TEMP);
  myWire.endTransmission(false);

  delayMicroseconds(100);
  
  myWire.requestFrom(DCDC_A, (uint8_t)2, (uint8_t)true);
  if (myWire.available()) {
    value = myWire.read();   //Low byte
    value = ((myWire.read() << 8) | value);   //High byte
  }
  
  Serial.print("Full Word: "); 
  Serial.print(value, HEX);
  Serial.println();
  float actual = convertPMBus_normal(value);
  Serial.print("TEMP: ");
  Serial.println(actual);

  delay(1);

}

float convertPMBus(uint16_t reading) {
  
  int16_t Y = reading & 0b0000011111111111;
  if ((int)Y >= 1024) {
    Y = -(~Y + 1); //Get Y from twos compliment
  }
  
  int16_t N = reading >> 11;
  if ((int)N >= 16) {
   N = ~N + 1;
   N = -(N & 0b0000000000011111);
  }
  
  float value = Y * pow(2, N);
  
  return value;
}

float convertPMBus_VOUT(uint16_t reading) {

  uint16_t V = reading; //No twos compliment here
  
  int16_t N = -9; //Found from VOUT_MODE command, lower 5 bits of the byte sent.
                  //This should be constant for all the DC-DCs at any time.
                  
  float value = V * pow(2, N);
  return value;
}
