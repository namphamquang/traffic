#include "car.h"

Car::Car() 
{
	posX = (SCREEN_WIDTH-40)/2;
	posY = SCREEN_HEIGHT-80;
	status = 0;
}

void Car::HandleEvent(SDL_Event& e) 
{
	switch(e.type)
	{ case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
			case SDLK_LEFT:
			{
					status =LEFT ;
					break;
			}
			case SDLK_RIGHT:
                {
					status =RIGHT ;
					break;
                }
		} break;
		case SDL_KEYUP: {status=0; break;}
	}
}
void Car:: UpdateMove() 
  {
      switch (status)
      {case LEFT:
            {posX -= 10; break;}
      case RIGHT:
           {
               posX += 10; break;
           }

      }

        if (posX < 80)
            posX = 80;
      else  if (posX + 40 > SCREEN_WIDTH - 80)
            posX = SCREEN_WIDTH - 80 - 40;
}


void Car::Render(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCarTexture) 
{
	gCarTexture.Render(posX, posY, gRenderer, currentClip);
}

int Car::GetPosX()
{
	return posX;
}

int Car::GetPosY()
{
	return posY;
}
