#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include "loadtexture.h"

#define LEFT 1
#define RIGHT 2

class Car
{
public:

	Car();

	void HandleEvent(SDL_Event& e);
    void UpdateMove();
	void Move();
	void Render(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCarTexture);

	int GetPosX();
	int GetPosY();

private:
	int posX, posY;
	int status;
};

#endif // CAR_H_INCLUDED
