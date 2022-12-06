#pragma once
#include <SDL.h>
#include "renderWindow.h"
#include "gameFunctions.h"
#include "entity.h"

class Player : public Entity
{
public:
	Player(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture);
	void Update();
private:
	short frame;				// Image Index
	short maxFrames;			// Total Image Indexes (Only used on second Constructor)
	double rotation;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};

extern RenderWindow window;