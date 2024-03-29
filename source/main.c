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
	DDRA = 0xFF; PORTA = 0x00;   // output
	DDRB = 0x00; PORTB = 0xFF;  // input
	DDRD = 0xFF; PORTD = 0x00; // output
	ADC_init();
	unsigned short my_short = PINA;
	//unsigned char my_char = (char)my_short; // my_char = 0xCD
	unsigned short max_light = 0x00;
	unsigned short min_light = 0xFF;
	unsigned short max_88 = ;
	unsigned short max_78 = ;
	unsigned short max_68 = ;
	unsigned short max_58 = ;
	unsigned short max_48 = ;
	unsigned short max_38 = ;
	unsigned short max_28 = ;
	unsigned short max_18 = ; 
	//Make sure to calc these values later next Wed or something
    /* Insert your solution below */
    while (1) {
	my_short = ADC;

	
	if (my_short >= max_18) {
		PORTB = 0x01;
	}
	else if (my_short >= max_28) {
		PORTB = 0x03;
	}
	else if (my_short >= max_38) {
		PORTB = 0x07;
	}
	else if (my_short >= max_48) {
		PORTB = 0x0F;
	}
	else if (my_short >= max_58) {
		PORTB = 0x1F;
	}
	else if (my_short >= max_68) {
		PORTB = 0x3F;
	}
	else if (my_short >= max_78) {
		PORTB = 0x7F;
	}
	else if (my_short >= max_88) {
		PORTB = 0xFF;
	}

	

    }
    return 1;
}
