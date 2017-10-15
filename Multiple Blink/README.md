# Introduction
This project consisted of writing a program in C to control an MSP430 microprocessor to allow the control of multiple onboard LEDs. The program was primarily developed on the MSP430G2553, and was subsequently ported to the other development boards.

# Basic Functionality
The introduction in the main() consists of setting the LED pins to output. It also initializes two counter variables, i and j. i serves as a timer control, utilizing the onboard clock to consistently poll the variable to check whether the for loop has completed. The j variable simply serves as an LED regulator, toggling the second LED once for every three toggles of the first LED. 
