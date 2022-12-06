#include "../include/enemy.h"

Enemy::Enemy(int pX, int pY, int pSpriteWidth, int pSpriteHeight, SDL_Texture* pTexture)
	:Entity{ pX, pY, pSpriteWidth, pSpriteHeight, pTexture }
{
	animated = true;
}

void Enemy::Update(Player& pPlayer)
{
	if (DistanceToPoint(pPlayer.x, pPlayer.y) < 512)
	{
		GotoPoint(pPlayer.x, pPlayer.y, ENEMY::SPEED);
	}
}