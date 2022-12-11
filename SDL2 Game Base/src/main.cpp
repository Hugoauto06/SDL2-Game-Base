#include "../include/main.h"
using namespace std;

extern RenderWindow window	= RenderWindow("Game Tittle", SCREEN_WIDTH, SCREEN_HEIGHT);
Camera camera				= Camera(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
SDL_Texture* textureP		= window.LoadTexture("assets/images/spr_player.png");
SDL_Texture* textureE		= window.LoadTexture("assets/images/spr_enemy.png");
SDL_Texture* BGTEX			= window.LoadTexture("assets/images/bg.png");
Player player				= Player(32, 128, 64, 64, textureP);
Enemy ent					= Enemy(256, 256, 64, 64, textureE);
Enemy ent2					= Enemy(1024, 1024, 64, 64, textureE);
bool done					= false;

//vector<Entity> entities;
unordered_map<int, Entity*> emtityMap;

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
	ent.Update(player);
	ent2.Update(player);
	camera.FollowPoint(player.x, player.y);
}

void DrawDelegate()
{
	window.Blit(BGTEX, 0, 0, camera.CameraRect);

	for (auto& X : emtityMap)
	{
		window.RenderEntity(*X.second, 32, 32, camera.CameraRect);
	}

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
	emtityMap.emplace(0, &player);
	emtityMap.emplace(1, &ent);
	emtityMap.emplace(2, &ent2);

	InitializeSDL();
	 
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
