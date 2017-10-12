#include <msp430.h>


/**
 * blink.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings
    P1SEL = 0x00;
    P1DIR |= 0x01;                  // configure P1.0 as output
    P1DIR &= 0xFD;                  // configure P1.1 as input
    P1REN |= 0x02;
    P1OUT |= 0x02;

    while(1)
    {
        if ((P1IN &= 0x02) & 0x02)
        {
            P1OUT &= 0xFE;
        }

        else
        {
            P1OUT |= 0x01;
        }
    }
}
