#pragma once
#include <cmath>
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(int pX, int pY, SDL_Texture* pTexture);
	Entity(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture);

	SDL_Texture* GetTexture();	
	SDL_Rect GetCurrentFrame();
	SDL_Rect GetRect();
	void SetRotation(double pRotation);
	void SetFrame(short pFrame);
	int GetXCurrent();
	double GetRotation();
	short GetMaxFrames();
	short GetFrame();
	bool animated;
	int x, y;
private:
	short frame;				// Image Index
	short maxFrames;			// Total Image Indexes (Only used on second Constructor)
	double rotation;
	SDL_Rect rect;				// This Rectangle Is for collision detection
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};