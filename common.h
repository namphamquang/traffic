#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

#define SDL_ERROR 1
#define IMG_ERROR 2
#define MIX_ERROR 3
#define TTF_ERROR 4

#define MIX_CHANNEL -1
#define TIME_MAX 1000

#define SPEED_INCREASEMENT 2
#define SCORE_INCREASEMENT 1
#define TIME_INCREASEMENT 1
#define FRAME_INCREASEMENT 1

#define BACKGROUND_SPEED 5
#define OBS_SPEED 5

#define IS_REPEATITIVE -1
#define NOT_REPEATITIVE 0

#define SMALL_BUTTON 1
#define COMMON_BUTTON 2

const std::string WINDOW_TITLE = "Traffic";

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;

const int COMMON_BUTTON_WIDTH = 75;
const int COMMON_BUTTON_HEIGHT = 50;
const int SMALL_BUTTON_WIDTH = 45;
const int SMALL_BUTTON_HEIGHT = 50;

const int PLAY_BUTON_POSX = 160;
const int PLAY_BUTTON_POSY= 300;
const int HELP_BUTTON_POSX = 160;
const int HELP_BUTTON_POSY = 400;
const int EXIT_BUTTON_POSX = 160;
const int EXIT_BUTTON_POSY = 500;
const int BACK_BUTTON_POSX = 15;
const int BACK_BUTTON_POSY = 29;
const int PAUSE_BUTTON_POSX = 31;
const int PAUSE_BUTTON_POSY = 29;
const int CONTINUE_BUTTON_POSX = 31;
const int CONTINUE_BUTTON_POSY = 29;

const int TEXT_1_POSX = 260;
const int TEXT_1_POSY = 20;
const int TEXT_2_POSX = 260;
const int TEXT_2_POSY = 60;
const int SCORE_POSX = 350;
const int SCORE_POSY = 20;
const int HIGH_SCORE_POSX = 350;
const int HIGH_SCORE_POSY = 60;

enum ButtonSprite
{
	BUTTON_MOUSE_OUT = 0,
	BUTTON_MOUSE_OVER = 1,
	BUTTON_TOTAL = 2
};

void LogError(std::string msg, int error_code = SDL_ERROR);

#endif // COMMON_H_INCLUDED
