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
	DDRD = 0x00; PORTD = 0xff;
	DDRB = 0xFE; PORTB = 0x00;

    /* Insert your solution below */
    while (1) {
	if ( PIND >=  35) /* Weight is 70+ */ 
		PORTB = 0x02;
	else if ( PIND >= 3) /* Weight is 6+ */
		PORTB = 0x04;
	else 
		PORTB = 0x00;
    }
    return 1;
}
