#include "../include/renderWindow.h"

/* Constructor */
RenderWindow::RenderWindow(const char* pTitle, int pW, int pH)
{
	window = SDL_CreateWindow(
		pTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		pW, pH, SDL_WINDOW_RESIZABLE
	);

	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_SOFTWARE
	);
}

/* Methods */
SDL_Texture* RenderWindow::LoadTexture(const char* pFilepath)
{
	SDL_Texture* _texture = NULL;
	_texture = IMG_LoadTexture(renderer, pFilepath);

	if (_texture == NULL)
	{
		std::cout << "Error loading " << pFilepath << std::endl;
	}

	return _texture;
}

void RenderWindow::Blit(SDL_Texture* pTexture, int pX, int pY)
{
	SDL_Point _size;
	SDL_QueryTexture(pTexture, NULL, NULL, &_size.x, &_size.y);

	SDL_Rect _dst;
	_dst.x = pX;
	_dst.y = pY;
	_dst.w = _size.x;
	_dst.h = _size.y;

	SDL_RenderCopy(renderer, pTexture, NULL, &_dst);
}

void RenderWindow::RenderEntity(Entity& pEntity)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = pEntity.GetRect().w;
	src.h = pEntity.GetRect().h;

	SDL_Rect dst;
	dst.x = pEntity.x;
	dst.y = pEntity.y;
	dst.w = pEntity.GetRect().w;
	dst.h = pEntity.GetRect().h;

	SDL_RenderCopyEx(renderer, pEntity.GetTexture(), &src, &dst, pEntity.GetRotation(), NULL, SDL_FLIP_NONE);
}

void RenderWindow::RenderEntity(Entity& pEntity, int pW, int pH) // Animated Entity
{
	SDL_Rect dst;
	dst.x = pEntity.x;
	dst.y = pEntity.y;
	dst.w = pEntity.GetRect().w;
	dst.h = pEntity.GetRect().h;

	SDL_Rect _rect;
	_rect.x = pEntity.GetXCurrent();
	_rect.y = 0;
	_rect.w = 64;
	_rect.h = 64;

	if (pEntity.animated)
	{
		if (pEntity.GetFrame() != pEntity.GetMaxFrames() - 1)
		{
			pEntity.SetFrame(pEntity.GetFrame() + 1);
		}
		else
		{
			pEntity.SetFrame(0);
		}
	}

	SDL_RenderCopyEx(renderer, pEntity.GetTexture(), &_rect, &dst, pEntity.GetRotation(), NULL, SDL_FLIP_NONE);
}

void RenderWindow::Display()
{
	SDL_SetRenderDrawColor(renderer, 64, 68, 88, 255);
	SDL_RenderPresent(renderer);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::End()
{
	SDL_DestroyWindow(window);
}