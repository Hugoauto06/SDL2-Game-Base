#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "defs.h"

class RenderWindow
{
public:
	RenderWindow(const char* pTitle, int pW, int pH);

	SDL_Texture* LoadTexture(const char* pFilepath);
	void Blit(SDL_Texture* pTexture, int pX, int pY);
	void RenderEntity(Entity& pEntity);
	void RenderEntity(Entity& pEntity, int pW, int pH);

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