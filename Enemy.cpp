#include "Enemy.h"

Enemy::Enemy()
{
	posX = 80+(rand()%4)*60 +(60-40)/2;
	posY = rand()%4;
}





void Enemy::Move(const int& acceleration)
{
	posY += (1 + acceleration);

    posX = 80+(rand()%4)*60 +(60-40)/2;
}

void Enemy::Renderx(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gEnemyTexture)
{
	gEnemyTexture.Render(posX, posY, gRenderer, currentClip);
}

int Enemy::GetPosX()
{
	return posX;
}

int Enemy:: GetPosY()
{
	return posY;
}
