/*************************************/
/*-----------------------------------*/
/******DC-DC Micro Embedded Code******/
/*****Eastern Edge Robotics 2019******/
/*-----------------------------------*/
/*************************************/

/*Contributers: Mark Belbin - 
 *              David Drover 
 */

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
#define READ_VIN      (0x88)      //Read Word (2 Bytes)
#define READ_VOUT     (0x8B)      //Read Word (2 Bytes)
#define READ_IOUT     (0x8C)      //Read Word (2 Bytes)
#define READ_TEMP     (0x8D)      //Read Word (2 Bytes)
#define VOUT_MODE     (0x20)      //Read Byte (1 Byte)


//Define I2C Wire
TwoWire myWire(&sercom3, 22, 23);

float ReadWord(uint8_t device,uint8_t action);
float ReadByte(uint8_t device,uint8_t action);
float convertPMBus_Word(uint16_t reading);
float convertPMBus_Byte(uint16_t reading);
float calculateCurrent(int channelNum);
void printDCDC(char DCDC);

String DCDC_NAME [3] = { "DC-DC_A::", ", DC-DC_B::", ", DC-DC_C::" };
uint8_t DCDC_ADR [3] = { DCDC_A, DCDC_B, DCDC_C };
int channelPin [3] = { VIOUT1, VIOUT2, VIOUT3 };
float zeroVoltage [3] = {1668.92,  //channel 1 zero amp voltage
                         1671.64,  //channel 2 zero amp voltage
                         1671.64}; //channel 3 zero amp voltage

                    
void setup() {
  //Let DC-DCs "boot", make sure we don't lock up the PMBus
  delay(100);
  
  Serial.begin(115200);

  analogReadResolution(12); // sets the ADC to 12 bit mode

  myWire.begin();
  
  pinPeripheral(22, PIO_SERCOM);
  pinPeripheral(23, PIO_SERCOM);
  
  //Setup Pins, check schematic for more details
  pinMode(VIOUT1, INPUT); 
  pinMode(VIOUT2, INPUT); 
  pinMode(VIOUT3, INPUT); 
  pinMode(TESTLED, OUTPUT); 
}

void loop() 
{
  digitalWrite(TESTLED, HIGH); //so LED won't start being on
  while(Serial.read() == -1);
  if(Serial.read() > -1)
  {
    digitalWrite(TESTLED, LOW); // signal data is starting to be sent

    Serial.print("{ ");

    //prints info on each DCDC
    printDCDC('A');
    printDCDC('B');
    printDCDC('C');

    Serial.print(" }");
    
    delay(100);
    digitalWrite(TESTLED, HIGH); //signals data is done being sent
  }


// Mark's test code  
/*  myWire.beginTransmission(DCDC_A);
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
  float actual = convertPMBus_Word(value);
  Serial.print("TEMP: ");
  Serial.println(actual);

  delay(1);*/

}



//convert bytes into number to be printed
float ReadWord(uint8_t device,uint8_t action)
{
  uint16_t bytes;
  myWire.beginTransmission(device);
  myWire.write(action);
  myWire.endTransmission(false);

  delayMicroseconds(100);
  
  myWire.requestFrom(device, (uint8_t)2, (uint8_t)true);
  if (myWire.available()) {
    bytes = myWire.read();   //Low byte
    bytes = ((myWire.read() << 8) | bytes);   //High byte
  }
  return convertPMBus_Word(bytes);
}

//converts a byte into a number to be printed
float ReadByte(uint8_t device,uint8_t action)
{
  uint16_t bytes;
  myWire.beginTransmission(device);
  myWire.write(action);
  myWire.endTransmission(false);

  delayMicroseconds(100);
  
  myWire.requestFrom(device, (uint8_t)2, (uint8_t)true);
  if (myWire.available()) {
    bytes = myWire.read();   //Low byte
    bytes = ((myWire.read() << 8) | bytes);   //High byte
  }
  return convertPMBus_Byte(bytes);
}

//pm bus convertion for words
float convertPMBus_Word(uint16_t reading) {
  
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

//pm bus convertion for bytes
float convertPMBus_Byte(uint16_t reading) {

  uint16_t V = reading; //No twos compliment here
  
  int16_t N = -9; //Found from VOUT_MODE command, lower 5 bits of the byte sent.
                  //This should be constant for all the DC-DCs at any time.
                  
  float value = V * pow(2, N);
  return value;
}

//calculates current from current sensing chips
float calculateCurrent(int channelNum)
{
  int raw = analogRead(channelPin[channelNum]);
  float voltage = (raw / 4096.0) * 3300.0; // Gets you mV
  float amps = ((voltage - zeroVoltage[channelNum]) / 45.0); //45mv/A
  return amps;
}

//prints info on the dc dc
void printDCDC(char DCDC)
{
  uint8_t address = DCDC_ADR[(DCDC - 65)];    
  Serial.print(DCDC_NAME[(DCDC - 65)]);
  Serial.print(" Current:");
  Serial.print(calculateCurrent((DCDC - 65)));
  Serial.print(", VIN:");
  Serial.print(ReadWord( address, READ_VIN ));
  Serial.print(", VOUT:");
  Serial.print(ReadWord( address, READ_VOUT ));
  Serial.print(", IOUT:");
  Serial.print(ReadWord( address, READ_IOUT ));
  Serial.print(", TEMP:");
  Serial.print(ReadWord( address, READ_TEMP ));
  Serial.print(", VOUT_MODE:");
  Serial.print(ReadByte( address, VOUT_MODE ));
}
