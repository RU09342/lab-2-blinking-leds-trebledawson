# Introduction
This project consisted of writing a program in C to control an MSP430 microprocessor to allow the control of an onboard LED with an onboard button. The program was primarily developed on the MSP430G2553, and was subsequently ported to the other development boards.

# Basic Functionality
The introduction in the main() consists of setting the LED pins to output, and the button pin to input. The input pin is controlled with a pullup resistor, i.e. the default "off" value of the pin is high. When the button is pressed and P1.3 input is asserted low, the LED output is asserted high, turning on the LED. When the button is released, the LED output is asserted low, turning off the LED.

# Extra Functionality - Color Select
In the MSP430G2553 code, there is extra functionality. When the button is pressed, a new variable that determines the selected LED is toggled, and this value is then passed to the LED toggle code. Each time the button is pressed, the selection variable is toggled, alternating between the onboard LEDs.
