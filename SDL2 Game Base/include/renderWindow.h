#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "defs.h"
#include "camera.h"

class RenderWindow
{
public:
	RenderWindow(const char* pTitle, int pW, int pH);
	SDL_Texture* LoadTexture(const char* pFilepath);
	void Blit(SDL_Texture* pTexture, int pX, int pY, SDL_Rect pCameraRect);
	void RenderRectangle(SDL_Rect pRect, SDL_Rect pCameraRect);
	void RenderEntity(Entity& pEntity, SDL_Rect pCameraRect);
	void RenderEntity(Entity& pEntity, int pW, int pH, SDL_Rect pCameraRect);

	void SaveScreenshot();

	void Display();
	void Clear();
	void End();

	/* Inputs */
	bool up;
	bool down;
	bool left;
	bool right;
	bool click;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};