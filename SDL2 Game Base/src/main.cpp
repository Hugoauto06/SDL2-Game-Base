#include "../include/main.h"
using namespace std;

extern RenderWindow window	= RenderWindow("Game Tittle", SCREEN_WIDTH, SCREEN_HEIGHT);
Camera camera				= Camera(0, 0, 640, 480);
SDL_Texture* textureP		= window.LoadTexture("assets/images/spr_player.png");
SDL_Texture* BGTEX			= window.LoadTexture("assets/images/bg.png");
Player player				= Player(32, 128, 64, 64, textureP);
Entity ent					= Entity(256, 256, 64, 64, textureP);
bool done					= false;


/* Methods */
void InitializeSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void UpdateDelegate()
{
	DoInput();
	player.Update();
	camera.FollowPoint(player.x, player.y);

	if (Collision(player.rect, ent.rect))
	{
		cout << "hey";
	}
}

void DrawDelegate()
{
	window.Blit(BGTEX, 0, 0, camera.CameraRect);
	window.RenderEntity(ent, 32, 32, camera.CameraRect);
	window.RenderEntity(player, 32, 32, camera.CameraRect);
	//window.RenderRectangle(player.rect, camera.CameraRect);
	//window.RenderRectangle(ent.rect, camera.CameraRect);
	window.Display();
	window.Clear();
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
