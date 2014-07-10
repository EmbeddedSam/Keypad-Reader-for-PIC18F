#include <xc.h>
#include "system.h"
#include <plib/timers.h>
#include "system.h"
#include "keypad_functions.h"

extern unsigned int TimerValue;
extern unsigned int KeyPressed;

void interrupt TimerOverflow()
{
    if(INTCONbits.TMR0IF == 1)
    {
        LATF0 = ~LATF0;

        LATDbits.LATD3 = 1; //Drive column 2 high
        if(PORTD >= 1)
        {
            KeyPressed = 1;
        }

        INTCONbits.TMR0IF = 0;
        WriteTimer0(TimerValue); //Please use HEX. Decimal don't work
    }
}