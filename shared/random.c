//Random number generator;
// Linear congruential generator 
// from Numerical Recipes by Press et al.
// Jonathan Valvano
//
// How to use: 
// 1) call Random_Init once with a seed
//     Random_Init(1);
//     Random_Init(NVIC_CURRENT_R);
// 2) call Random over and over to get a new random number
//   n = Random();    // 32 bit number
//   m = (Random()>>24)%60; // a number from 0 to 59

#include "random.h"

static uint32_t _seed;

void Random_Init(uint32_t seed)
{
  _seed = seed;
}

//------------Random32------------
// Return R0= random number
// Linear congruential generator 
// from Numerical Recipes by Press et al.
uint32_t Random32(void)
{
  uint32_t output = _seed*1664525 + 1013904223;
  _seed = output;

  return output;
}
       
//------------Random------------
// Return R0= random number, 0 to 255
// Linear congruential generator 
// from Numerical Recipes by Press et al.

uint32_t Random(void)
{
  uint32_t output = _seed*1664525 + 1013904223;
  uint32_t mask = 0x000000FF;
  _seed = output;

  return output & mask;
}
