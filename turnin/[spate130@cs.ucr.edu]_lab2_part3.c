/*	Author: spate130
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #3
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
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00;
	unsigned char tempA = 0x00;
	unsigned char cntavail = 0x00;

    	/* Insert your solution below */
    while (1) {
	tempA = PINA & 0x0F;
	if( tempA == 0x00){
		cntavail = 4;
	}
	else if (tempA == 0x01 || tempA == 0x02 || tempA == 0x04 || tempA == 0x08) {
		cntavail = 3;
	}
	else if(tempA == 0x03 || tempA == 0x06 || tempA == 0x0C || tempA == 0x05 || tempA == 0x0A || tempA == 0x09 ) {
		cntavail = 2;
	}
	else if(tempA == 0x07 || tempA == 0x0E || tempA == 0x0D || tempA == 0x0B){
		cntavail = 1;
	}
	else if (tempA == 0x0F){
		cntavail = 0x80;
	}

	PORTC = cntavail;


    }
    return 1;
}
