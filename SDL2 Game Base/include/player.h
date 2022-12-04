#pragma once
#include "entity.h"
#include "renderWindow.h"

class Player : public Entity
{
public:
	Player(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture);
	void Update();
private:
	short frame;				// Image Index
	short maxFrames;			// Total Image Indexes (Only used on second Constructor)
	double rotation;
	SDL_Rect rect;				// This Rectangle Is for collision detection
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};

extern RenderWindow window;