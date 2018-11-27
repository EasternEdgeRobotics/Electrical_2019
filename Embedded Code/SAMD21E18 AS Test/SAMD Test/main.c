/*
 * SAMD Test.c
 *
 * Created: 2018-11-26 11:31:28 PM
 * Author : markb
 */ 


#include "sam.h"


int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    /* Replace with your application code */
	REG_PORT_DIRSET0 = PORT_PA11;
	
    while (1) 
    {
		for (int i=0; i<30000; i++) {}
			
		REG_PORT_OUTSET0 = PORT_PA11;
		
		for (int i=0; i<30000; i++) {}
		
		REG_PORT_OUTCLR0 = PORT_PA11;
    }
}
