#include "obstacle.h"

Obstacle::Obstacle() //khởi tạo vật cản
{
	posX1 = 0;
	posY1 = 0;
	eWidth = 0;
	eHeight = 0;
	ObsTexture = nullptr;
}

Obstacle::FreeObstacle() //giải phóng vật cản
{
	posX1 = 0;
	posY1 = 0;
	eWidth = 0;
	eHeight = 0;
	if (ObsTexture != nullptr)
        {
            ObsTexture = nullptr;
        }
}

void Obstacle::LoadFromFile(std::string path, SDL_Renderer* gRenderer) //tải ảnh của vật cản
{
	SDL_Texture* tmpTexture = nullptr;

	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	if (tmpSurface == nullptr)
	{
		LogError("Can not load image.", IMG_ERROR);
	}
	else
	{
		SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, 0, 255, 255));

		tmpTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
		if (tmpTexture == nullptr)
		{
			LogError("Can not create texture from surface.", SDL_ERROR);
		}
		else
		{
			eWidth = tmpSurface->w;
			eHeight = tmpSurface->h;
		}

		SDL_FreeSurface(tmpSurface);
	}

	ObsTexture = tmpTexture;
}

void Obstacle::Move(const int &acceleration) //di chuyển của vật cản với gia tốc
{
	posY1 += OBS_SPEED + acceleration;
	if (posY1  > SCREEN_HEIGHT)
	{
		posY1=-60;
        posX1 = 90 + (rand()%4)*60 ;
	}
}

void Obstacle::Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip) //vẽ vật cản
{
	SDL_Rect renderSpace = { posX1, posY1, eWidth, eHeight };
	if (currentClip != nullptr)
	{
		renderSpace.w = currentClip->w;
		renderSpace.h = currentClip->h;
	}
	SDL_RenderCopy(gRenderer, ObsTexture, currentClip, &renderSpace);
}

int Obstacle::GetSpeed(const int &acceleration) //cập nhật tốc độ
{
	return OBS_SPEED + acceleration;
}

int Obstacle::GetPosX() //vị trí x
{
	return posX1;
}

int Obstacle::GetPosY() //vị trí y
{
	return posY1;
}

int Obstacle::GetWidth() //chiều rộng
{
	return eWidth;
}

int Obstacle::GetHeight() //chiều dài
{
	return eHeight;
}
