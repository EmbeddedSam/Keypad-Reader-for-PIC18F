/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Change all these values for your project */

/* Microcontroller MIPs (FCY) */
#define p18f8722         //either write p18f4520 or p18f8722 or your own if added.
#define SYS_FREQ         10000000L  //ONLY 10MHz confirmed working.. have a go
#define FCY              SYS_FREQ/4
#define RefreshRate      10

#define RowA             RD0    //1  PINS ON KEYPAD
#define RowB             RD1    //2
#define RowC             RD7    //8
#define RowD             RD6    //7

#define Col1             LATD2  //3
#define Col2             LATD3  //4
#define Col3             LATD4  //5

#define IN               1
#define OUT              0

#define ON               1
#define OFF              0


/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

void ConfigInterrupts(void);
void ConfigPortPins(void);

void interrupt isr(void);

void ClsUSART(void);
void OpnUSART(void);

void OpenTmr0(void);

