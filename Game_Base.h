#ifndef GAME_BASE_H_INCLUDED
#define GAME_BASE_H_INCLUDED

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
#include <math.h>
#include <stdlib.h>
using namespace std;
#define SDL_ERROR 1
#define IMG_ERROR 2
#define MIX_ERROR 3
#define TTF_ERROR 4

#define MIX_CHANNEL -1

#define TIME_MAX 1000

#define MAX_HEIGHT 250

#define BASE_OFFSET_SPEED 0

#define SPEED_INCREASEMENT 2
#define SCORE_INCREASEMENT 1
#define TIME_INCREASEMENT 1
#define FRAME_INCREASEMENT 1

#define GROUND_SPEED 5
#define ENEMY_SPEED 5
#define MAX_ENEMY_WIDTH 100


#define SLOW_FRAME_CHAR 4
#define SLOW_FRAME_ENEMY 4

#define IS_REPEATITIVE -1
#define NOT_REPEATITIVE 0

#define SMALL_BUTTON 1
#define COMMON_BUTTON 2

const std::string WINDOW_TITLE = "Traffic";

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;

const int COMMON_BUTTON_WIDTH = 75;
const int COMMON_BUTTON_HEIGHT = 49;
const int SMALL_BUTTON_WIDTH = 75;
const int SMALL_BUTTON_HEIGHT = 49;

const int PLAY_BUTON_POSX = 170;
const int PLAY_BUTTON_POSY= 200;
const int HELP_BUTTON_POSX = 170;
const int HELP_BUTTON_POSY = 300;
const int EXIT_BUTTON_POSX = 170;
const int EXIT_BUTTON_POSY = 400;
const int BACK_BUTTON_POSX = 31;
const int BACK_BUTTON_POSY = 29;
const int PAUSE_BUTTON_POSX = 31;
const int PAUSE_BUTTON_POSY = 29;
const int CONTINUE_BUTTON_POSX = 31;
const int CONTINUE_BUTTON_POSY = 29;



const int RUNNING_FRAMES = 6;


const int BACKGROUND_SPEED=2;
enum ButtonSprite
{
	BUTTON_MOUSE_OUT = 0,
	BUTTON_MOUSE_OVER = 1,
	BUTTON_TOTAL = 2
};

void LogError(std::string msg, int error_code = SDL_ERROR);

#endif // GAME_BASE_H_INCLUDED
