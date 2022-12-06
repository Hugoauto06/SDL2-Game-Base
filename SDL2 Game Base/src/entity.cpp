#include "../include/entity.h"

/* Constructor */
Entity::Entity(int pX, int pY, SDL_Texture* pTexture)
	:x(pX), y(pY), texture(pTexture)
{
	SDL_Point _size;
	SDL_QueryTexture(pTexture, NULL, NULL, &_size.x, &_size.y);

	rect.x		= pX-64;
	rect.y		= pY-64;
	rect.w		= _size.x;
	rect.h		= _size.y;

	frame		= 0;
	animated	= false;
	flip		= SDL_FLIP_NONE;
}

Entity::Entity(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture)
	:x(pX), y(pY), texture(pTexture)
{
	SDL_Point _size;
	SDL_QueryTexture(pTexture, NULL, NULL, &_size.x, &_size.y);

	rect.x			= pX-pSpriteWidth;
	rect.y			= pY-pSpriteHeight;
	rect.w			= pSpriteWidth;
	rect.h			= pSpriteHeight;

	currentFrame.x	= 0;
	currentFrame.y	= 0;
	currentFrame.w	= pSpriteWidth;
	currentFrame.w	= pSpriteHeight;

	frame			= 0;
	maxFrames		= floor(_size.x / pSpriteWidth);
	animated		= false;
	flip			= SDL_FLIP_NONE;
}

/* Methods */
void Entity::GotoPoint(int pX, int pY, int pSpeed)
{
	if (x < pX)
	{
		x += pSpeed;
	}
	if (x > pX)
	{
		x -= pSpeed;
	}
	if (y < pY)
	{
		y += pSpeed;
	}
	if (y > pY)
	{
		y -= pSpeed;
	}

	rect.x = x - 64;
	rect.y = y - 64;
}

/* Propities */
SDL_Texture* Entity::GetTexture()
{
	return texture;
}

void Entity::SetRotation(double pRotation)
{
	rotation = pRotation;
}

double Entity::GetRotation()
{
	return rotation;
}

short Entity::GetFrame()
{
	return frame;
}

void Entity::SetFrame(short pFrame)
{
	frame = pFrame;
	currentFrame.x = currentFrame.w * frame;
}

short Entity::GetMaxFrames()
{
	return maxFrames;
}

int Entity::GetXCurrent()
{
	return currentFrame.x;
}
