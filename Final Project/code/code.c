#include <mega16.h>

unsigned char sensd;

forward (void){
PORTC=0b001010;
}

left (void){
PORTC=0b001001;
}

right (void){
PORTC=0b000110;
}

void main(void){
	PORTB=0x00;
	DDRB=0x00;
	PORTC=0x00;
	DDRC=0x0F;
	PORTD=0x00;
	DDRD=0x00;
	TCCR0=0x00;
	TCNT0=0x00;
	TCCR1A=0x00;
	TCCR1B=0x00;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;
	ASSR=0x00;
	TCCR2=0x00;
	TCNT2=0x00;
	OCR2=0x00;
	MCUCR=0x00;
	TIMSK=0x00;
	ACSR=0x80;
	SFIOR=0x00;while (1){
	sensd=0b00011111;
	sensd=PIND&sensd;
	if(sensd==0b00000100)
		forward();
	if(sensd==0b00001110)
		forward();
	if(sensd==0b00001100)
		right();
	if(sensd==0b00001000)
		right();
	if(sensd==0b00010000)
		right();
	if(sensd==0b00011000)
		right();
	if(sensd==0b00011100)
		right();
	if(sensd==0b00000001)
		left();
	if(sensd==0b00000011)
		left();
	if(sensd==0b00000111)
		left();
	if(sensd==0b00000110)
		left();
	if(sensd==0b00000010)
		left();
	if(sensd==0b11111011)
		forward();
	if(sensd==0b11110001)
		forward();
	if(sensd==0b11110011)
		right();
	if(sensd==0b11110111)
		right();
	if(sensd==0b11101111)
		right();
	if(sensd==0b11100111)
		right();
	if(sensd==0b11100011)
		right();
	if(sensd==0b11111110)
		left();
	if(sensd==0b11111100)
		left();
	if(sensd==0b11111000)
		left();
	if(sensd==0b11111001)
		left();
	if(sensd==0b11111101)
		left();
	};
}