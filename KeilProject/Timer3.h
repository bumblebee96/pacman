#ifndef __TIMER3INTS_H__ // do not include more than once
#define __TIMER3INTS_H__

// ***************** Timer0_Init ****************
// Activate Timer0 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq)
// Outputs: none
void Timer3_Init(void(*task)(void), uint32_t period);

#endif // __TIMER2INTS_H__
