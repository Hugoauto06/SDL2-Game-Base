#pragma once

#include <iostream>
#include <SDL.h>
#include "defs.h"

class Camera
{
public:
	Camera(int pX, int pY, int pW, int pH);
	void FollowPoint(int pX, int pY);
	SDL_Rect CameraRect;
};