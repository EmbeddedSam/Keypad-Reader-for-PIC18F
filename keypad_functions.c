#include <xc.h>
#include "system.h"
#include <plib/timers.h>
#include "system.h"
#include "keypad_functions.h"

extern unsigned int TimerValue;

void setupTimers(void)
{
    TimerValue = refreshRateToTimerValue(RefreshRate); //change

    unsigned char Timer0Config = TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256;
    OpenTimer0(Timer0Config);
    WriteTimer0(TimerValue); //Please use HEX. Decimal don't work

    INTCONbits.TMR0IF = 0; //reset Interrupt Flag
}

unsigned int refreshRateToTimerValue(unsigned int refresh)
{
    float ins_time, ms_time, time;
    unsigned int timerValue;

    ins_time = 1024.00/SYS_FREQ;  //4 * prescaler(256) as it takes 4 TCY
    ms_time = refresh/1000.00;    //Converting it into ms
    time = ms_time/ins_time;
    timerValue = 65535 - (unsigned int)time;    //16 bit rollover

    return timerValue;
}

void setupPorts(void)
{
    TRISFbits.TRISF0 = 0; //set RF0 as output
    TRISFbits.TRISF2 = 0; //set RF0 as output

    TRISDbits.TRISD0 = IN;  //RowA
    TRISDbits.TRISD1 = IN;  //RowB
    TRISDbits.TRISD6 = IN;  //RowD
    TRISDbits.TRISD7 = IN;  //RowC

    TRISDbits.TRISD2 = OUT; //Col1
    TRISDbits.TRISD3 = OUT; //Col2
    TRISDbits.TRISD4 = OUT; //Col3

    LATF0 = 1;         //Make RF0 high when the program starts
}

void processIt(void)
{

}

