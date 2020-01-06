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

void Random_Init(uint32_t seed)
{
  __asm (
        " LDR R2, =M\n"
        " MOV R0, #1\n"
        " STR R0, [R2]\n");
}

//------------Random32------------
// Return R0= random number
// Linear congruential generator 
// from Numerical Recipes by Press et al.

uint32_t Random32(void)
{
  __asm (
        " LDR R2, =M\n"
        " LDR R0, [R2]\n"
        " LDR R1, =1664525\n"
        " MUL R0, R0, R1\n"
        " LDR R1, =1013904223\n"
        " ADD R0, R1\n"
        " STR R0, [R2]\n");
}
       
//------------Random------------
// Return R0= random number, 0 to 255
// Linear congruential generator 
// from Numerical Recipes by Press et al.

uint32_t Random(void)
{
  __asm (
        " LDR R2, =M\n"
        " LDR R0, [R2]\n"
        " LDR R1, =1664525\n"
        " MUL R0, R0, R1\n"
        " LDR R1, =1013904223\n"
        " ADD R0, R1\n"
        " STR R0, [R2]\n"
        " LSR R0, R0, #24\n");
}
