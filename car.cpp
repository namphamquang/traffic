#include "car.h"

Car::Car() //khởi tạo xe
{
	posX = (SCREEN_WIDTH-40)/2;
	posY = SCREEN_HEIGHT-80;
	status = 0;
}

void Car::HandleEvent(SDL_Event& e) //điều khiển xe
{
	if (e.type == SDL_KEYDOWN)
	{
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
		}
	}
}
void Car:: UpdateMove() //cập nhật vị trí của xe
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


void Car::Render(SDL_Rect* currentClip, SDL_Renderer *gRenderer, LTexture gCarTexture) //vẽ xe
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
