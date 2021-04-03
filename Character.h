#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "loadtexture.h"

#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define RUN	0

class Character
{
public:
	static const int JUMP_SPEED = 8;
	static const int FALL_SPEED = 8;

	Character();



	void HandleEvent(SDL_Event& e, Mix_Chunk *gJump);
    void UpdateMove();
	void Move();


	void Render(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCharacterTexture);

	int GetPosX();

	int GetPosY();

private:
	int posX, posY;

	int status;
};


#endif // CHARACTER_H_INCLUDED
