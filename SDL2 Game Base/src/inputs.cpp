#include "../include/inputs.h"

void DoKeyUp(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{

		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_W:
			window.up = false;
			break;

		case SDL_SCANCODE_S:
			window.down = false;
			break;

		case SDL_SCANCODE_A:
			window.left = false;
			break;

		case SDL_SCANCODE_D:
			window.right = false;
			break;
		}
	}
}

void DoKeyDown(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_W:
			window.up = true;
			break;

		case SDL_SCANCODE_S:
			window.down = true
				;
			break;

		case SDL_SCANCODE_A:
			window.left = true;
			break;

		case SDL_SCANCODE_D:
			window.right = true;
			break;
		}
	}
}

void DoInput(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEBUTTONUP:
			window.click = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			int xMouse, yMouse;
			SDL_GetMouseState(&xMouse, &yMouse);

			window.click = true;

			break;

		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			DoKeyDown(&event.key);
			break;

		case SDL_KEYUP:
			DoKeyUp(&event.key);
			break;

		default:
			break;
		}
	}
}