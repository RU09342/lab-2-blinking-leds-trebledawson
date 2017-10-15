#include <msp430g2553.h>

int LED_SEL = 0;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P1DIR |= (BIT0 + BIT6);			// Configure P1.0 and P1.6 as output
	P1OUT &= ~(BIT0 + BIT6); 		// Set P1.0 and P1.6 as default off
    P1DIR &= ~BIT3;            // Set P1.3 to input
    P1REN |= BIT3;            // Set P1.3 resistor enable...
    P1OUT |= BIT3;            // ...to pullup resistor
    P1IE |= BIT3;             // Set P1.3 as interrupt pin
    
    __enable_interrupt();		// Enable interrupts

	while(1)
	{
	    if ((P1IN &= BIT3) & BIT3) // If button is pressed...
	    {
	        switch (LED_SEL)		// Based on currently selected LED
	        {
				case 0:
					P1OUT |= BIT0; // Turn on LED 1
					break;
				case 1:
					P1OUT |= BIT6; // Turn on LED 2
					break;
			}
	    }
	    else // If button is not pressed
	    {
	        P1OUT &= ~(BIT0 + BIT6); // Turn off both LEDs
	    }
	}
}

#pragma vector=PORT1_VECTOR   // Define interrupt vector, in this case Port 1
__interrupt void button_press(void) // Define interrupt function that runs whenever interrupt is detected
{

    P1IE &= !BIT3; // Turn off P1.3 interrupt
    LED_SEL = !LED_SEL;	// Toggle LED selection
    TA0CTL = TASSEL_1 + MC_1 + TACLR; // Set Timer A0 to ACLK, up mode
    TA0CCR0 = 1000;  // Count to ~10 ms
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void button_debounce_timer(void)
{
    TA0CTL = MC_0;            // Halt timer
    TA0R = 0;                 // Reset count register
    P1IE |= BIT3;             // Enable interrupt code
    P1IFG = ~BIT3;            // Disable interrupt flag to re-enable interrupt
}
