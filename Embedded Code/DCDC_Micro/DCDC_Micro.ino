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
#define DCDC_A        (0x01)      //DCDC A (Micro) I2C address
#define DCDC_B        (0x02)      //DCDC B I2C address
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
  myWire.beginTransmission(119);
  myWire.write(READ_TEMP);
  myWire.endTransmission(false);

  delayMicroseconds(100);
  
  myWire.requestFrom(119, (uint8_t)2, (uint8_t)true);
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

  
  /*
  uint8_t readingLOW = myWire.read();  
  uint8_t readingHIGH = myWire.read();  
  Serial.print("Low Byte: "); 
  Serial.print(readingLOW, HEX); 
  Serial.print(" High Byte: "); 
  Serial.print(readingHIGH, HEX);
  Serial.println();
  */

  delay(1);
  
  /*
  delay(500);
  Serial.println("Hey");
  digitalWrite(TESTLED, HIGH);
  
  delay(500);
  Serial.println(analogRead(VIOUT1));
  Serial.println(analogRead(VIOUT2));
  Serial.println(analogRead(VIOUT3));
  digitalWrite(TESTLED, LOW);
  */
}

float convertPMBus_normal(uint16_t reading) {
  
  int16_t Y = reading & 0b0000011111111111;
  if ((int)Y >= 1024) {
    Y = ~Y + 1; //Get Y from twos compliment
    Y = -Y;
  }
  
  int16_t N = reading >> 11;
  if ((int)N >= 16) {
   N = ~N + 1;
   N = N & 0b0000000000011111;
   N = -N;
  }
  
  float value = Y * pow(2, N);
  
  return value;
}

float convertPMBus_VOUT(uint16_t reading) {

  uint16_t V = reading;
  
  int16_t N = -9; //Found from VOUT_MODE command, lower 5 bits of the byte sent.
                  //This should be constant for all the DC-DCs at any time.
                  
  float value = V * pow(2, N);
  return value;
}
