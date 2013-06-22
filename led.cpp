#include  <msp430g2553.h>

#define led0 BIT0
#define led1 BIT6

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer
	P1DIR |= (led0+led1); 				// P1.6 output (green LED)
	P1OUT = led0; 				// LED off

	for (int c=0;true;c++)				// Loop forever
	{
		volatile unsigned long i;
		P1OUT ^= (led0+led1);
		i = 50000;                   	// Delay

		do (i--);			// busy waiting (bad)
		while (i != 0);
	}
}
