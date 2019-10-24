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
	unsigned char my_char = (char)my_short; // my_char = 0xCD
	//unsigned short max_light = 0x00;
	//unsigned short min_light = 0xFF;
    /* Insert your solution below */
    while (1) {
	my_short = ADC;
	/*if (my_short > max_light) {
		max_light = my_short;
	} 

	if (my_short < min_light) {
		min_light = my_short;
	}*/
	
	my_char = (char)(my_short >> 4); // my_char = 0xBC
	PORTB = ADC;
	PORTD = my_char;
	

    }
    return 1;
}
