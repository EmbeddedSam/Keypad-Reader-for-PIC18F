#include <xc.h>
#include "system.h"
#include <plib/timers.h>
#include "system.h"
#include "keypad_functions.h"

extern unsigned int TimerValue;
extern unsigned char KeyPressed;
unsigned char column = 1;

void interrupt TimerOverflow()
{
    if(INTCONbits.TMR0IF == 1)
    {
        if(column == 1){
            //Checking all column 1 buttons
            Col1 = ON;
            Col2 = OFF;
            Col3 = OFF;

            if(RowA)
            {
                while(RowA){}; //waits for it to go low
                KeyPressed = 1;
            }
            else if(RowB)
            {
               while(RowB){}; //waits for it to go low
               KeyPressed = 4;
            }
            else if(RowC)
            {
               while(RowC){}; //waits for it to go low
               KeyPressed = 7;
            }
            else if(RowD)
            {
               while(RowD){}; //waits for it to go low
               KeyPressed = 'R';
            }
            column = 2;
        }
        else if(column == 2){
            //Checking all column 2 buttons
            Col1 = OFF;
            Col2 = ON;
            Col3 = OFF;

            if(RowA)
            {
               while(RowA){}; //waits for it to go low
               KeyPressed = 2;
            }
            else if(RowB)
            {
               while(RowB){}; //waits for it to go low
               KeyPressed = 5;
            }
            else if(RowC)
            {
               while(RowC){}; //waits for it to go low
               KeyPressed = 8;
            }
            else if(RowD)
            {
               while(RowD){}; //waits for it to go low
               KeyPressed = 'Z';
            }
            column = 3;
        }
        else if(column == 3){

            //Checking all column 3 buttons
            Col1 = OFF;
            Col2 = OFF;
            Col3 = ON;

            if(RowA)
            {
               while(RowA){}; //waits for it to go low
               KeyPressed = 3;
            }
            else if(RowB)
            {
               while(RowB){}; //waits for it to go low
               KeyPressed = 6;
            }
            else if(RowC)
            {
               while(RowC){}; //waits for it to go low
               KeyPressed = 9;
            }
            else if(RowD)
            {
               while(RowD){}; //waits for it to go low
               KeyPressed = 'G';
            }
            column = 1;
        }

        INTCONbits.TMR0IF = 0;
        WriteTimer0(TimerValue); //Please use HEX. Decimal don't work
    }
}