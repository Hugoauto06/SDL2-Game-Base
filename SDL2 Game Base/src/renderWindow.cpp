#include "../include/renderWindow.h"

/* Constructor */
RenderWindow::RenderWindow(const char* pTitle, int pW, int pH)
{
	window = SDL_CreateWindow(
		pTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		pW, pH, SDL_WINDOW_MOUSE_FOCUS	
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

void RenderWindow::Blit(SDL_Texture* pTexture, int pX, int pY, SDL_Rect pCameraRect)
{
	SDL_Point _size;
	SDL_QueryTexture(pTexture, NULL, NULL, &_size.x, &_size.y);

	SDL_Rect _dst = { pX - pCameraRect.x, pY - pCameraRect.y, _size.x, _size.y};

	SDL_RenderCopy(renderer, pTexture, NULL, &_dst);
}

void RenderWindow::RenderRectangle(SDL_Rect pRect, SDL_Rect pCameraRect)
{
	SDL_Rect _rect = {pRect.x - pCameraRect.x, pRect.y - pCameraRect.y, pRect.w, pRect.y};

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &_rect);
}

void RenderWindow::RenderEntity(Entity& pEntity, SDL_Rect pCameraRect)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = pEntity.rect.w;
	src.h = pEntity.rect.h;

	SDL_Rect dst = { pEntity.x - pCameraRect.x, pEntity.y - pCameraRect.y, pEntity.rect.w, pEntity.rect.h };

	SDL_RenderCopyEx(renderer, pEntity.GetTexture(), &src, &dst, pEntity.GetRotation(), NULL, pEntity.flip);
}

void RenderWindow::RenderEntity(Entity& pEntity, int pW, int pH, SDL_Rect pCameraRect) // Animated Entity
{
	SDL_Rect dst = { pEntity.x - (pW) - pCameraRect.x, pEntity.y - (pH) - pCameraRect.y, pEntity.rect.w, pEntity.rect.h};

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

	SDL_RenderCopyEx(renderer, pEntity.GetTexture(), &_rect, &dst, pEntity.GetRotation(), NULL, pEntity.flip);
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
	SDL_DestroyRenderer(renderer);
}

void RenderWindow::SaveScreenshot()
{
	const Uint32 format = SDL_PIXELFORMAT_ARGB8888;
	const int width = 640;
	const int height = 400;

	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
	SDL_RenderReadPixels(renderer, NULL, format, surface->pixels, surface->pitch);
	SDL_SaveBMP(surface, "screenshot.bmp");
	SDL_FreeSurface(surface);
}