# Introduction
This project consisted of writing a program in C to control an MSP430 microprocessor to allow the control of an onboard LED. The program was primarily developed on the MSP430G2553, and was subsequently ported to the other development boards.

# Basic Functionality
The introduction to the main() simply initializes the LED output pin, as well as a volatile unsigned integer i that controls software polling delay. Inside the while loop (which runs forever), the LED pin is toggled, and then the program delays for the number of clock cycles indicated by i. 
