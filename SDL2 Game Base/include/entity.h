#pragma once
#include <cmath>
#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"

class Entity
{
public:
	Entity(int pX, int pY, SDL_Texture* pTexture);
	Entity(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture);


	SDL_Texture* GetTexture();
	SDL_Rect GetCurrentFrame();
	SDL_RendererFlip flip;
	void GotoPoint(int pX, int pY, int pSpeed);
	void SetRotation(double pRotation);
	void SetFrame(short pFrame);
	int GetXCurrent();
	double GetRotation();
	short GetMaxFrames();
	short GetFrame();
	bool animated;
	int x, y;
	SDL_Rect rect;				// This Rectangle Is for collision detection

private:
	short frame;				// Image Index
	short maxFrames;			// Total Image Indexes (Only used on second Constructor)
	double rotation;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};