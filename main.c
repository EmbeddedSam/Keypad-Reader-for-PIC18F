#include <xc.h>
#include "system.h"
#include <plib/timers.h>
#include "system.h"
#include "keypad_functions.h"

unsigned int TimerValue;
unsigned char KeyPressed;
unsigned char KeypadCode[4] = { 1, 2, 3, 4 }; //Change this to anything you want
unsigned char codeRead[100];

void main(void)
{
    setupPorts();
    setupTimers();
    ei();     // enable all interrupts

    while(forever){
        if(KeyPressed){
            process(KeyPressed);
        }}

    //use automatic roll over in the interrupt with a global increment
    //Check columns in order, dont let the interrupt fire again until column 2 has
    //been checked
}


