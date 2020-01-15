/*	Author: jlee434
 *  Partner(s) Name: Shiyou Wang
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRA = 0x00; PORTA = 0xff;
	DDRC = 0xff; PORTC = 0x00;

	unsigned char a;
	unsigned char c;
    /* Insert your solution below */
    while (1) {
		a = PINA & 0x0f;
		if ( a >= 13 ){
			c = 0x3f; //0011 1111
		}
		else if ( a >= 10 ){
			c = 0x3e; //0011 1110
		}
		else if ( a >= 7 ){
			c = 0x3c; //0011 1100
		}
		else if ( a >= 5 ){
			c = 0x38; //0011 1000
		}
		else if ( a >= 3 ){
			c = 0x70; //0111 0000
		}
		else if ( a >= 1 ){
			c = 0x60; //0110 0000
		}
		else {
			c = 0x40; //0100 0000
		}
		PORTC = c;
    }
    return 1;
}
