// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Last Modified: 3/6/2015 
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "tm4c123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
void ADC_Init(void)
{
	//Enable PE1-2 to be an input that samples an anolog signal
	SYSCTL_RCGCGPIO_R |= 0x10;
	for(int i = 0; i < 2; i++){};
	GPIO_PORTE_DIR_R &= ~0x06;
	GPIO_PORTE_AFSEL_R |= 0x06;
	GPIO_PORTE_DEN_R &= ~0x06;
	GPIO_PORTE_AMSEL_R |= 0x06;
	
	
	
	SYSCTL_RCGCADC_R |= 0x01;
	for(int i = 0; i < 2; i++){};
	ADC0_PC_R = 0x01;
	ADC0_SSPRI_R = 0x0123;
	ADC0_ACTSS_R &= ~0x000C;
	ADC0_EMUX_R &= ~0xFF00;
	ADC0_SSMUX3_R = (ADC0_SSMUX3_R & 0xFFFFFFF0) + 1;	//uses channel 1
	ADC0_SSMUX2_R = (ADC0_SSMUX2_R & 0xFFFFFFF0) + 2;	//uses channel 2
	ADC0_SSCTL3_R = 0x0006;
	ADC0_SSCTL2_R = 0x0006;
	ADC0_IM_R &= ~0x000C;
	ADC0_ACTSS_R |= 0x000C;
}

//------------ADC_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
int ADC_In_X(void)
{
	int result;
	ADC0_PSSI_R = 0x0008;
	while((ADC0_RIS_R & 0x08) == 0)
	{
	}
	result = ADC0_SSFIFO3_R & 0xFFF;
	ADC0_ISC_R = 0x0008;
	
  return result; // remove this, replace with real code
}

int ADC_In_Y()
{
	int result;
	ADC0_PSSI_R = 0x0004;
	while((ADC0_RIS_R & 0x04) == 0)
	{
	}
	result = ADC0_SSFIFO2_R & 0xFFF;
	ADC0_ISC_R = 0x0004;
	
  return result; // remove this, replace with real code
}
