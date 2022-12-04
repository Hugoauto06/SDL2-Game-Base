#include "../include/main.h"

extern RenderWindow window	= RenderWindow("Game Tittle", SCREEN_WIDTH, SCREEN_HEIGHT);
SDL_Texture* textureP		= window.LoadTexture("../assets/spr_player.png");
Player player				= Player(32, 32, 64, 64, textureP);
bool done					= false;

/* Methods */
void InitializeSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void DrawDelegate()
{
	window.Display();
	window.Clear();
}

void UpdateDelegate()
{
	DoInput();
}

/* Cap Frame Rate */
static void capFrameRate(long* then, float* remainder);

static void capFrameRate(long* then, float* remainder)
{
	long wait, frameTime;

	wait = 16 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}


/* Main App */
int main(int argc, char* args[])
{
	InitializeSDL();
	player.animated = true;
	 
	long then;
	float remainder;
	then = SDL_GetTicks();
	remainder = 0;

	while (!done) /* Game Loop */
	{
		UpdateDelegate();
		DrawDelegate();

		capFrameRate(&then, &remainder);
	}
	window.End();
	return 0;
}