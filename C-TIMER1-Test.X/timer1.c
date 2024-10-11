#include <xc.h>
#include "timer1.h"

/* Config Timer1 */
void TIMER1_Initialize(void)
{
	/* Timer1 disabled; 16-bit R/W; prescaler=1:8 */
	T1CON = 0x30;
    
    /* Fosc/4 as source clock (16 MHz)*/
	T1CLK = 0x01;   
}

void TIMER1_Delay(void)
{
    
    /* Timer1 counter start at 0x0000h and end at 0xFFFF*/
    
    /* Timer1 enabled */
	T1CON |= 0x01; 
                 
    /* Wait for TMR1IF = 1 */
    while ((PIR3 & 0x10) != 0x10)
          ;
        
    /* Clear TMR1IF bit */
    PIR3 &= 0xEF;
             
    /* Timer1 disabled */
	T1CON &= 0xFE;
}