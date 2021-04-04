#include "Character.h"

Character::Character()
{
	posX = (SCREEN_WIDTH-40)/2;
	posY = SCREEN_HEIGHT-80;

	status = 0;
}



void Character::HandleEvent(SDL_Event& e, Mix_Chunk *gJump)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_LEFT:
			{

					Mix_PlayChannel(MIX_CHANNEL, gJump, NOT_REPEATITIVE);
					status =LEFT ;
					break;

			}
			case SDLK_RIGHT:
                {

					Mix_PlayChannel(MIX_CHANNEL, gJump, NOT_REPEATITIVE);
					status =RIGHT ;
					break;

			}
		}
	}
}
void Character:: UpdateMove()
  {
      if (status == LEFT)
            {posX -= 3;}
      else  if (status ==RIGHT)
           {
               posX += 3;
           }


        if (posX < 80)
            posX = 80;
      else  if (posX + 40 > SCREEN_WIDTH - 80)
            posX = SCREEN_WIDTH - 80 - 40;
}


void Character::Render(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCharacterTexture)
{
	gCharacterTexture.Render(posX, posY, gRenderer, currentClip);
}

int Character::GetPosX()
{
	return posX;
}

int Character::GetPosY()
{
	return posY;
}
