/*	Author: spate130
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00; // Configure port C's 8 pins as inputs,
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs,

	unsigned char tempA = 0x00;
    	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
    	unsigned char tempD = 0x00;
	unsigned char weight = 0x00;

	/* Insert your solution below */
    while (1) {
	
	    tempA = PINA; tempB = PINB; tempC = PINC;
	
	    weight = tempA + tempB + tempC;

	    if(weight >= 140){
		tempD = tempD | 0x01;
	    }

	    if(tempA >= tempC){
		if((tempA -tempC) > 80){
			tempD = tempD | 0x02;
		}
	    }
	    else if(tempC > tempA){
		if((tempC - tempA) > 80){
			tempD = tempD | 0x02;
		}
	    }

	    weight = weight & 0xFC;

	    tempD = tempD + weight;

	    PORTD = tempD;

    }
    return 1;
}
