#include  <msp430.h>

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer
	P1DIR = 0x01;//40; 				// P1.6 output (green LED)
	P1OUT = 0; 				// LED off

	for (int c=0;true;c++)				// Loop forever
	{
		volatile unsigned long i;
		if(c%2==0){P1DIR = 0x01;P1OUT = 0x01;}else{P1DIR = 0x40;P1OUT = 0x40;}
		i = 99999;                   	// Delay

		do (i--);			// busy waiting (bad)
		while (i != 0);
	}
}
