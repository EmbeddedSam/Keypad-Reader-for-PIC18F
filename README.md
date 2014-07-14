Keypad Reader for PIC18F 
===============================


This project should be able to get any PIC18F series Microcontroller
read a 12 button digital keypad.

The code works on interrupts, polling every n-seconds, this is changeable and it can
poll from 1ms to (never tested it) but up to around 10 seconds.

Everything is well commented so it should be self explanatory, just look at main.c,
interrupts.c and keyboard_functions.c.

The project is ready to go for the PIC18F8722 running at 10MHz but with a few
simple changes it could run on any other 8 bit PIC.

Getting Started
----------------------------
  To get started make the relevant changes to the definitions "System.h" 
  such as "_XTAL_FREQ" and "RefreshRate" The timing routines will work out
  the right values to send to the timers you just have to change the definitions.
  
  You will also have to change the PORT, LAT and TRIS defintions in system.h 
  This is very specific to your project I have mine setup to use PORTD so I setup
  the rows to use PORTD and change the relevant TRIS register to make it an input/output
  
  The only other thing you will have to change is some of the code in "keypad_functions.c"
  I have set it up to display the keypress on a 7 segment LED controlled by a transistor.
  
  You will have to change the end of "setupPorts()" and also change "process()" it should be 
  self explanatory how I have set it up but your project won't maybe want to use a 7 segment LED.


IF USING ANOTHER PROCESSOR
----------------------------
  You will have to change "configuration_bits.c" and also the defintion in main.c to the processor
  apart from that though it should work as described in Getting started above.
  
  Thanks and enjoy :)

