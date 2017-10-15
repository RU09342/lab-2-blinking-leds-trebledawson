# Introduction
This project consisted of writing a program in C to control an MSP430 microprocessor to allow the control of an offboard LED. The program was primarily developed on the MSP430G2553, and was subsequently ported to the other development boards.

# Basic Functionality
This program functions much the same as the simple blink program. However, instead of sending the output information to the onboard LED pin, the information is sent to an offboard LED, using the same output pin on the processor connected via breadboard or wire to the LED. When using this program, care must be taken to connect the correct pins, regarding both the LED pins and the power pins.
