#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "player.h"
#include "renderWindow.h"

class Enemy : public Entity
{
public:
	Enemy(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture);
	void Update(Player& pPlayer);
private:
	short frame;				// Image Index
	short maxFrames;			// Total Image Indexes (Only used on second Constructor)
	double rotation;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};

