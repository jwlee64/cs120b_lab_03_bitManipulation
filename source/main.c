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
	DDRB = 0x00; PORTB = 0xff;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char cnt;
	unsigned char a;
	unsigned char b;
	unsigned char i;
    /* Insert your solution below */
    while (1) {
	cnt = 0;
	i = 0;
	a = PINA;
	b = PINB;
	while (i < 8)
	{
		if ( (a & 0x01) == 1)
			cnt++;
		if ( (b & 0x01) == 1)
                        cnt++;
		a = a >> 1;
		b = b >> 1;
		i++;
	}
	PORTC = cnt;
    }
    return 1;
}
