#include "../include/player.h"

/* Constructor */
Player::Player(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture)
	:Entity{ pX, pY, pSpriteWidth, pSpriteHeight, pTexture }
{
	animated = false;
}

/* Methods */
void Player::Update()
{
	short hsp = ((-window.left) + window.right) * PLAYER_MOVESPEED;
	short vsp = ((-window.up) + window.down) * PLAYER_MOVESPEED;

	x += hsp;
	y += vsp;

	if ((hsp != 0 && vsp != 0) || (hsp != 0 || vsp != 0))
	{
		animated = true;
	}
	else
	{
		animated = false;
	}

	rect.x = x;
	rect.y = y;
}

/* Propities */