#include <xc.h>
#include "system.h"
#include <plib/timers.h>
#include "system.h"
#include "keypad_functions.h"

unsigned int TimerValue;
unsigned int KeyPressed;

void main(void)
{
    setupPorts();
    setupTimers();
    ei();     // This is like fliping the master switch to enable interrupt

    if(KeyPressed)
    {
        processIt();
    }

    while(1){}
}



