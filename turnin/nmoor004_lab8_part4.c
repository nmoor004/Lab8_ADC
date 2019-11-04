/*	Author: nmoor004
 *  Partner(s) Name: 
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

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	   // ADEN: enables analog-to-digital conversion
	  // ADSC: starts the first conversion
	 // ADATE enables auto-triggering
	// Since we are in Free Running mode, a new conversion will trigger whenever the previous conversion completes
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;   // output
	DDRB = 0xFF; PORTB = 0x00;  // input
	DDRD = 0xFF; PORTD = 0x00; // output
	ADC_init();
	unsigned short my_short = PINA;
	//unsigned char my_char = (char)my_short; // my_char = 0xCD

	unsigned short max_88 = 0x30;
	unsigned short max_78 = 0x2E;
	unsigned short max_68 = 0x2C;
	unsigned short max_58 = 0x27;
	unsigned short max_48 = 0x25;
	unsigned short max_38 = 0x22;
	unsigned short max_28 = 0x21;
	unsigned short max_18 = 0x20; 
	//Make sure to calc these values later next Wed or something
    /* Insert your solution below */
    while (1) {
	my_short = ADC;

	
	if (my_short >= max_88) {
		PORTB = 0xFF;
	}
	else if (my_short >= max_78) {
		PORTB = 0x7F;
	}
	else if (my_short >= max_68) {
		PORTB = 0x3F;
	}
	else if (my_short >= max_58) {
		PORTB = 0x1F;
	}
	else if (my_short >= max_48) {
		PORTB = 0x0F;
	}
	else if (my_short >= max_38) {
		PORTB = 0x07;
	}
	else if (my_short >= max_28) {
		PORTB = 0x04;
	}
	else if (my_short >= max_18) {
		PORTB = 0x01;
	}
	else {
		PORTB = 0x00;
	}

	

    }
    return 1;
}
