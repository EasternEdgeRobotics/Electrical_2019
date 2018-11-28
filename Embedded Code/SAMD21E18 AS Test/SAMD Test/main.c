/*
 * SAMD Test.c
 *
 * Created: 2018-11-26 11:31:28 PM
 * Author : markb
 * Eastern Edge Robotics 2018-2019
 */ 


#include "sam.h"
#include "delay.h"

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    //PA11 is the test LED for EER's current 2019 boards
	REG_PORT_DIRSET0 = PORT_PA11;
	
    while (1) 
    {
		//Delay a bit
		//for (int i=0; i<30000; i++) {}
		delay_us(10000);
		REG_PORT_OUTSET0 = PORT_PA11;
		
		//for (int i=0; i<30000; i++) {}
		delay_us(10000);
		REG_PORT_OUTCLR0 = PORT_PA11;
    }
}
