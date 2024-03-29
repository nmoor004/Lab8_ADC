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
	DDRA = 0x00; PORTA = 0xFF;   // input
	DDRB = 0xFF; PORTB = 0x00;  // output
	DDRD = 0xFF; PORTD = 0x00; // output
	ADC_init();
	unsigned short my_short = PINA;
	//unsigned char my_char = (char)my_short; // my_char = 0xCD
    /* Insert your solution below */
    while (1) {
	my_short = ADC;
	PORTB = ADC;
	
	if (my_short >= (0x027)) {
		PORTD = 0x01;
	}
	else {
		PORTD = 0x00;
	}
	
	//my_char = (char)(my_short >> 4); // my_char = 0xBC
	//PORTB = ADC;
	//PORTD = my_char;
	

    }
    return 1;
}
