//Eastern Edge Robotics 2018
//Mark Belbin
//ATtiny code for the junction box
//Generates a 50% square wave to drive an acoustic transducer 

#include <avr/io.h>

const int freq = 40000;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  cli();
  /*
  //Set timer control registers to 0
  TCCR0A = 0;
  TCCR0B = 0;

  //Set prescalling to 1
  TCCR0B |= (1 << CS00);

  //Enable clear timer on compare match (CTC) mode
  TCCR0A |= (1 << WGM01);

  //Set compare register
  //For square waves:
  //OCR0A = 8MHz/(f*2) - 1
  //Numbers > 255 are not permitted
  OCR0A = 100;
  
  //disable overflow interrupt, enable compare match interrupt
  TIMSK |=  (1 << OCIE0A);
  */
  TIMSK &= ~(1 << TOIE0);
  sei();
}

ISR(TIMER0_COMPA_vect) {
  PORTB ^= (1 << PB3);
}

void loop() {

  if (digitalRead(4) == LOW) {
    for(int i=0; i<15000; i++) {
        PORTB |= (1 << PB3);
        delayMicroseconds(6);
        PORTB &= ~(1 << PB3);
        delayMicroseconds(6);
     }
  }
}
