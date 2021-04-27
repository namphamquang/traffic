#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

#include <math.h>
#include "loadtexture.h"

class Obstacle
{
public:
	Obstacle();
	FreeObstacle();

	void LoadFromFile(std::string path, SDL_Renderer* gRenderer);
	void Move(const int& acceleration);
	void Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip = nullptr);

	int GetSpeed(const int& acceleration);
	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();

	int posX1, posY1;
	int eWidth, eHeight;

	SDL_Texture *ObsTexture;
};

#endif // OBSTACLE_H_INCLUDED
