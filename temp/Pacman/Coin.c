#include "Coin.h"
#include "tm4c123gh6pm.h"

void CoinInit()
{
	//make E0 an input
	SYSCTL_RCGCGPIO_R |= 0x10;
	for(int i = 0; i < 2; i++){};
	GPIO_PORTE_DIR_R &= ~0x01;
	GPIO_PORTE_AFSEL_R &= ~0x01;
	GPIO_PORTE_DEN_R |= 0x01;
	GPIO_PORTE_AMSEL_R &= ~0x01;
}

int Paid()
{
	//return input at E0
	int data = GPIO_PORTE_DATA_R & 0x01;
	return data;
}
