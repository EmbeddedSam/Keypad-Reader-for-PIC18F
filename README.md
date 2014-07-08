Keypad Reader for PIC18F 
===============================


This project should be able to get any PIC18F series Microcontroller
with an 8-bit wide port to read a 12 button digital keypad.

The project is ready to go for either the PIC18F8722 or the PIC18F4520
but with some simple changes can work with any other device.

IF USING 18F4520 or 18F8722
----------------------------
  To get started make the relevant changes to "System.h"


IF USING ANOTHER PROCESSOR
----------------------------
  There are some things you are going to need to change.. as you can see in
  system.h at the bottom there are some #ifdef's defined for the 2 choices
  of processor.

  You will need to make your own ifdef for your processor.. containing the
  relevant configurations and options.

  There are 2 more places that the ifdefs will be needed to be changed and that
  is in all of the functions inside "system.c" and in "configurationbits.c"

  If you look inside the ifdefs in these 2 files it should be clear what they
  do and what you will need to change to get it working on your processor..

  So for example if I wanted to get this going on an PIC18F4550 I would first
  go to system.h and define it at the top as p18f4550..

  Then I would go to the bottom of system.h and make an ifdef use case for the
  p18f4550, leaving the other 2 ifdefs intact..

  I would then go into system.c and add my own ifdef to all the functions and
  finally create an ifdef in the configuration bits file.. that is all.

  Thanks and enjoy :)

