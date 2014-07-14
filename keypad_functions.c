#include <xc.h>
#include "system.h"
#include <plib/timers.h>
#include "system.h"
#include "keypad_functions.h"

extern unsigned int TimerValue;
extern unsigned char KeypadCode[4];
extern unsigned char codeRead[100];
extern unsigned char KeyPressed;
int i = 0; //increment for key changed
int x = 0; //increment to find out whats being pressed
unsigned char lastKey = 0;

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
    //Converts whatever you define in system.h to a timer0 value
    float ins_time, ms_time, time;
    unsigned int timerValue;
    ins_time = 1024.00/_XTAL_FREQ;  //4 * prescaler(256) as it takes 4 TCY
    ms_time = refresh/1000.00;    //Converting it into ms
    time = ms_time/ins_time;
    timerValue = 65535 - (unsigned int)time;    //16 bit rollover
    return timerValue;
}

void setupPorts(void)
{
    //Keypad port setup
    RowA_TRIS = IN;  //RowA
    RowB_TRIS = IN;  //RowB
    RowC_TRIS = IN;  //RowC
    RowD_TRIS = IN;  //RowD

    Col1_TRIS = OUT; //Col1
    Col2_TRIS = OUT; //Col2
    Col3_TRIS = OUT; //Col3

    //Indicator LED setup, this is just specific to my project
    TRISF = OUT; //Make PORTF Inputs, 7 segment works by making a transistor high
    //and then making combinations of port pins low to light LEDs
    LATF = 0xFF;

    TRISHbits.TRISH1 = OUT; //Transistor for 7 segment
    LATH1 = 0; //PNP transistor so needs a zero;
}

void process(unsigned char key)
{
    //You could do anything with the key I have chosen to display the keys on
    //A 7 segment LED attached to PORT F but this is just an example.

    KeyPressed = 0; //turn off flag
    displaySegment(key);
    
    codeRead[x] = key; //This is just to debug so I can see what keys have been
    //pressed...
    x ++;

    if(key == KeypadCode[i])
    {
        i++;
        if(i == 4){
            i = 0;
            LATF = 0x00;
        }
    }
    else{
        i = 0;
    }

}

void displaySegment(unsigned char number)
{
    if(number == 1){
        LATF = 0xF5; //display 1 on leds
    }
    else if(number == 2){
        LATF = 0x4C; //display 2 on leds
    }
    else if(number == 3){
        LATF = 0x64; //display 3 on leds
    }
    else if(number == 4){
        LATF = 0x35; //display 4 on leds
    }
    else if(number == 5){
        LATF = 0x26; //display 5 on leds
    }
    else if(number == 6){
        LATF = 0x06; //display 6 on leds
    }
    else if(number == 7){
        LATF = 0xF4; //display 7 on leds
    }
    else if(number == 8){
        LATF = 0x04; //display 8 on leds
    }
    else if(number == 9){
        LATF = 0x34; //display 9 on leds
    }
    else if(number == 'Z'){
        LATF = 0x84; //display 0 on leds
    }
    else if(number == 'R'){
        LATF = 0x9E; //display R on leds
    }
    else if(number == 'G'){
        LATF = 0x24; //display G on leds
    }
    else{
        LATF = 0xFF;
    }
}

