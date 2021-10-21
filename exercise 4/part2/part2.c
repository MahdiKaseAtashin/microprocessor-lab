#include <mega16.h>
#include <alcd.h>
#include <stdio.h>

unsigned int hours,minutes,seconds = 0;

void main(void)
{
lcd_init(16);
TIMSK = 0x40;
TIFR = 0x40;
#asm ("sei")
ASSR = 0x08;
TCNT2 = 0x00;
TCCR2 = 0x05;
lcd_puts("00:00:00");
while(1)
{
}
}
interrupt[5] void second_timer_ovf_isr(void)
{    
    char buffer[8];
    seconds++;
    if(seconds==60){
    seconds = 0;
    minutes++;
        if(minutes==60){
        minutes = 0;
        hours++;
        if(hours==24)
             hours = 0;
        }    
    }
    sprintf(buffer, "%02d:%02d:%02d", hours, minutes,seconds);
    lcd_gotoxy(0,0);          
   lcd_puts(buffer);
}
