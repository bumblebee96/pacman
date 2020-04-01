#include "print.h"
#include "ST7735.h"

//-----------------------LCD_OutDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: R0 (call by value) 32-bit unsigned number
// Output: none
// Invariables: This function must not permanently modify registers R4 to R11
void LCD_OutDec(uint32_t data)
{
  if(data < 10)
    ST7735_OutChar(data);

  LCD_OutDec(data/10);
  LCD_OutDec(data%10);
}

// -----------------------LCD _OutFix----------------------
// Output characters to LCD display in fixed-point format
// unsigned decimal, resolution 0.001, range 0.000 to 9.999
// Inputs:  R0 is an unsigned 32-bit number
// Outputs: none
// E.g., R0=0,    then output "0.000 "
//       R0=3,    then output "0.003 "
//       R0=89,   then output "0.089 "
//       R0=123,  then output "0.123 "
//       R0=9999, then output "9.999 "
//       R0>9999, then output "*.*** "
// Invariables: This function must not permanently modify registers R4 to R11
void LCD_OutFix(uint32_t data)
{
  char str[5] = "*.***";

  if(9999 < data)
    ST7735_OutString(str);

  str[4] = data%10;
  data = data/10;

  str[3] = data%10;
  data = data/10;

  str[2] = data%10;
  data = data/10;

  str[0] = data%10;

  ST7735_OutString(str);
}
