/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/


/******************************************************************************/
/* Keypad Function Prototypes                                                 */
/******************************************************************************/

unsigned int refreshRateToTimerValue(unsigned int);
void setupPorts(void);
void setupTimers(void);
void process(unsigned char);
void displaySegment(unsigned char number);
