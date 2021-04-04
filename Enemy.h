#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "loadtexture.h"
#include "Game_Base.h"
#define ENEMY_MAX_HEIGHT 300
#define ENEMY_MIN_HEIGHT 330

#define ENEMY_POSITION_RANGE 250
#define ENEMY1_RANGE 100
#define ENEMY2_RANGE 350
#define ENEMY3_RANGE 500

const int LANE_WIDTH =60;

class Enemy
{
public:


	Enemy();




	void Move(const int& acceleration);


	void Renderx(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gEnemyTexture);

	int GetPosX();

	int GetPosY();

private:
	int posX, posY;

};
#endif // ENEMY_H_INCLUDED
