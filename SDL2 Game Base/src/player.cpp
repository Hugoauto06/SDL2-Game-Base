#include "../include/player.h"

/* Constructor */
Player::Player(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture)
	:Entity{ pX, pY, pSpriteWidth, pSpriteHeight, pTexture }
{
	animated = false;
}

/* Methods */


/* Propities */