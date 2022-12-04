#pragma once
#include "entity.h"

class Player : public Entity
{
public:
	Player(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture);
	void Update();
private:
};