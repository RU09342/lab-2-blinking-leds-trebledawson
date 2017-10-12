#include <msp430g2553.h>


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1SEL = 0x00;
	P1DIR |= 0x01;					// configure P1.0 as output
	P1DIR &= 0xF7;                  // configure P1.3 as input
	P1REN |= 0x08;

	while(1)
	{
	    if ((P1IN &= 0x08) & 0x08)
	    {
	        P1OUT &= 0xFE;
	    }

	    else
	    {
	        P1OUT |= 0x01;
	    }
	}
}
