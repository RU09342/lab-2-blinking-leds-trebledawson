#include <msp430.h>				


/**
 * multiple_blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output
	P1DIR |= 0x40;                  // configure P1.6 as output

	volatile unsigned int i;		// volatile to prevent optimization
	volatile unsigned int j=0;      // idk, same as above line for safety

	while(1)
	{
	    if (j==3)
	    {
	        P1OUT ^= 0x40;
	        j=0;
	    }

	    j++;
	    P1OUT ^= 0x01;				// toggle P1.0
		for(i=10000; i>0; i--);     // delay
	}
}
