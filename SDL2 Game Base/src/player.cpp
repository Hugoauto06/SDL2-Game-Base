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

	x = SDL_clamp(x, 0, ROOM_WIDTH);
	y = SDL_clamp(y, 0, ROOM_HEIGHT);
	if (hsp != 0)
	{
		if (hsp > 0)
		{
			flip = SDL_FLIP_NONE;
		}
		if (hsp < 0)
		{
			flip = SDL_FLIP_HORIZONTAL;
		}
	}

	if ((hsp != 0 && vsp != 0) || (hsp != 0 || vsp != 0))
	{
		animated = true;
	}
	else
	{
		animated = false;
	}

	if (health <= 0)
	{
		//
		//std::cout << "died";
	}

	rect.x = x-32; // Center Collision Mask (offset)
	rect.y = y-32; // Center Collision Mask (offset)
	
	/*
		The Player Size is 64 x 64, so to center the image/collision-mask
	*/
}

/* Propities */