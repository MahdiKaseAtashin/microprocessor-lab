#include <mega16.h>

static unsigned  int time_count; // 0.5sec counter

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void){  
	// 1 MHz = 1000 kHz
    // 12000 / 8 = 1500 kHz
	// => 1 / 1500 = 0.66 µs
    // 0.66 * 225 = 150 µs
    // 150 * 3333 = 500 ms  
    // 256 – 225 = 31 
        
    TCNT0 = 31;
       ++time_count; /* add 0.5 second counter */
    if (time_count == 3333){
        PORTC.0 = (PORTC.0 ^ 1); /* complement port bit to blink LED */
        time_count = 0; /* reset time counter for next 0.5 second */ 
   }
}

void main(void){
    DDRC = 0x01; /*set lsb for output*/
    /*set timer 0 prescaler to clk/8*/
    TCCR0=0x02;
    TCNT0=31;
    /* unmask Timer 0 overflow interrupt*/
    TIMSK=0x01;
    /* enable interrupts */
    #asm("sei")
    while(1) 
    {

    }
}