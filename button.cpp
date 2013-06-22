#include <msp430x20x2.h> 
//#include  <msp430g2553.h>

#define LED0 BIT0
#define LED1 BIT6 
#define BUTTON BIT3



int main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= (LED0 + LED1); // Set P1.0 to output direction 
// P1.3 must stay at input
P1OUT &= ~(LED0 + LED1); // set P1.0 to 0 (LED OFF)
for(;;){
	while(P1IN==BUTTON){
		P1OUT = LED0;
		volatile unsigned long i = 50000;
		do (i--);			// busy waiting (bad)
		while (i != 0);
	}
	P1OUT = 0;
}
}

