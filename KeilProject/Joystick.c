#include "Joystick.h"

#define BOTTOMLIMIT	2430
#define UPPERLIMIT 4000

//3021 center
//2300 left or down
//4095 right or up

int JoystickDirection(int x,int y)
{
	if((x < BOTTOMLIMIT) && (y < UPPERLIMIT) && (y > BOTTOMLIMIT))
	{
		return LEFT;
	}
	
	else if((x > UPPERLIMIT) && (y < UPPERLIMIT) && (y > BOTTOMLIMIT))
	{
		return RIGHT;
	}
	
	else if((y < BOTTOMLIMIT) && (x < UPPERLIMIT) && (x > BOTTOMLIMIT))
	{
		return DOWN;
	}
	
	else if((y > UPPERLIMIT) && (x < UPPERLIMIT) && (x > BOTTOMLIMIT))
	{
		return UP;
	}
	
	return CENTER;
}
