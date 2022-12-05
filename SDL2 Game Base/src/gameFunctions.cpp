#include "../include/gameFunctions.h"
/*
	I was trying to make a function Global like
	the MathF Functions in the whole program, so
	i dont have to make a class and instantiate it
*/

bool Collision(SDL_Rect rectA, SDL_Rect rectB)
{
	if (rectA.x >= rectB.x && rectA.y >= rectB.y && rectA.x < (rectB.x + rectB.w) && rectA.y < (rectB.y + rectB.h))
	{
		return true;
	}
	else
	{
		return false;
	}
}