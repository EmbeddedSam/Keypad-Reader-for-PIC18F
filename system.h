/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Change all these values for your project */

/* Microcontroller MIPs (FCY) */
#define p18f8722           //Write p18f8722 or your own if added.
#define _XTAL_FREQ         10000000L  //ONLY 10MHz confirmed working.. have a go
#define FCY              _XTAL_FREQ/4
#define RefreshRate      20  //this is going to depend on your keypad, its in ms
                             //set it to anything you want, 1-16000 approx

//DEFINITIONS FOR OUR INPUTS

#define RowA             PORTDbits.RD0    //1  PINS ON KEYPAD
#define RowB             PORTDbits.RD1    //2
#define RowC             PORTDbits.RD2    //8
#define RowD             PORTDbits.RD3    //7

//Config (TRIS) registers for inputs
#define RowA_TRIS        TRISDbits.TRISD0
#define RowB_TRIS        TRISDbits.TRISD1
#define RowC_TRIS        TRISDbits.TRISD2
#define RowD_TRIS        TRISDbits.TRISD3

//DEFINITIONS FOR OUR OUTPUTS

#define Col1             LATDbits.LATD4   //3
#define Col2             LATDbits.LATD5   //4
#define Col3             LATDbits.LATD6   //5

//Config (TRIS) registers for outputs
#define Col1_TRIS        TRISDbits.TRISD4
#define Col2_TRIS        TRISDbits.TRISD5
#define Col3_TRIS        TRISDbits.TRISD6

//USEFUL OTHER DEFINITIONS
#define IN               1
#define OUT              0

#define ON               1
#define OFF              0

#define forever          1


/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

void ConfigInterrupts(void);
void ConfigPortPins(void);



