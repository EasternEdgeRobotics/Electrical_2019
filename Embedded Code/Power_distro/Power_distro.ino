/*************************************/
/*-----------------------------------*/
/**Power Distribution Embedded Code***/
/*****Eastern Edge Robotics 2019******/
/*-----------------------------------*/
/*************************************/

//Contributers: David Drover


//Pin Definitions
#define VIOUT1 2
#define VIOUT2 11
#define VIOUT3 3
#define VIOUT4 10
#define VIOUT5 4
#define VIOUT6 9
#define VIOUT7 5
#define VIOUT8 8
#define VIOUT9 6
#define VIOUT10 7
#define LED 14

float calculateCurrent(int channel, int channelNum);

float zeroVoltage [10] = {1625.02,  //channel 1 zero amp voltage
                          1628.64,  //channel 2 zero amp voltage
                          1630.66,  //channel 3 zero amp voltage
                          1630.66,  //channel 4 zero amp voltage
                          1632.28,  //channel 5 zero amp voltage
                          1632.66,  //channel 6 zero amp voltage
                          1636.50,  //channel 7 zero amp voltage
                          1634.69,  //channel 8 zero amp voltage
                          1633.66,  //channel 9 zero amp voltage
                          1650.0}; //channel 10 zero amp voltage

void setup() 
{
  pinMode(VIOUT1, INPUT);
  pinMode(VIOUT2, INPUT);
  pinMode(VIOUT3, INPUT);
  pinMode(VIOUT4, INPUT);
  pinMode(VIOUT5, INPUT);
  pinMode(VIOUT6, INPUT);
  pinMode(VIOUT7, INPUT);
  pinMode(VIOUT8, INPUT);
  pinMode(VIOUT9, INPUT);
  pinMode(VIOUT10, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  analogReadResolution(12); // sets the ADC to 12 bit mode
}

void loop() 
{
  digitalWrite(LED, HIGH); //so LED won't start being on
  while(Serial.read() == -1);
  if(Serial.read() > -1)
  {
    digitalWrite(LED, LOW); // signal data is starting to be sent
    
    Serial.print("{ ");
    
    Serial.print("fore-star-horz:");
    Serial.print(calculateCurrent(VIOUT1,1));
    
    Serial.print(", fore-port-horz:");
    Serial.print(calculateCurrent(VIOUT2,2));
    
    Serial.print(", fore-star-vert:");
    Serial.print(calculateCurrent(VIOUT3,3));
    
    Serial.print(", aft-star-horz:");
    Serial.print(calculateCurrent(VIOUT4,4));
    
    Serial.print(", fore-port-vert:");
    Serial.print(calculateCurrent(VIOUT5,5));
    
    Serial.print(", aft-port-vert:");
    Serial.print(calculateCurrent(VIOUT6,6));
    
    Serial.print(", aft-star-vert:");
    Serial.print(calculateCurrent(VIOUT7,7));
    
    Serial.print(", aft-port-horz:");
    Serial.print(calculateCurrent(VIOUT8,8));
    
    Serial.print(", PI/Switch/Tooling:");
    Serial.print(calculateCurrent(VIOUT9,9));

    //current chip not installed on pcb
    /*Serial.print(", Blank:");
    Serial.print(calculateCurrent(VIOUT10,10));*/
  
    Serial.println(" }");
    
    delay(100);
    digitalWrite(LED, HIGH); //signals data is done being sent
  }
}


float calculateCurrent(int channel, int channelNum)
{
  int raw = analogRead(channel);
  float voltage = (raw / 4096.0) * 3300.0; // Gets you mV
  float amps = ((voltage - zeroVoltage[(channelNum - 1)]) / 45.0); //45mv/A
  return amps;
}
