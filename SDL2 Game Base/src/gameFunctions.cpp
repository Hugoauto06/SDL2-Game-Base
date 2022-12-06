#include "../include/gameFunctions.h"
/*
	This are Global Fuctions, kinda like the
	Math Functions, you can call them everywhere
	by including the "gameFunctions.h" header.

	Use them wisely :D
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