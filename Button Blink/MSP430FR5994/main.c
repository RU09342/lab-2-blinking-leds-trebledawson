//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430fr5994.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1SEL0 = 0x00;
    P5SEL0 = 0x00;
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P5DIR &= 0x20;
    P5REN |= 0x20;
    P5OUT |= 0x20;

    while(1)
    {
        if ((P5IN &= 0x20) & 0x20)
        {
            P1OUT &= 0xFE;
        }
        else
        {
            P1OUT |= 0x01;
        }
    }
}
