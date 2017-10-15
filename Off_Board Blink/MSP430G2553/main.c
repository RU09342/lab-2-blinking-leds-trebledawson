#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR |= BIT0;             // Set P1.0 to output direction
    P1DIR |= BIT6;             // Set P1.6 to output direction

    while(1)
	{
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= BIT0; 	// Toggle P1.0 
		P1OUT ^= BIT6; 	// Toggle P1.6 

		i = 10000;      // Software delay
		do i--;
		while(i != 0)
		{}
		
        P1OUT ^= BIT6; 	// Toggle P1.6
        
        i = 10000;		// Software delay
        do i--;
        while(i != 0);
	}
}
