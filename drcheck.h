#ifndef DRCHECK_H_INCLUDED
#define DRCHECK_H_INCLUDED

#include "common.h"
#include "button.h"
#include "obstacle.h"
#include "car.h"

bool Init();
bool LoadMedia();
void Close();

std::string GetHighScoreFromFile(std::string path);

void UpdateHighScore(std::string path,
    const int& score,
    const std::string& old_high_score);

int UpdateGameTimeAndScore(int& time, int& speed, int& score);

void RenderScrollingGround(int& speed,
    const int acceleration,
    LTexture gGroundTexture,
    SDL_Renderer* gRenderer);

void HandlePlayButton(SDL_Event* e,
    Button& PlayButton,
    bool& QuitMenu,
    bool& Play,
    Mix_Chunk* gClick);

void HandleHelpButton(SDL_Event* e,
    SDL_Rect(&gBackButton)[BUTTON_TOTAL],
    Button& HelpButton,
    Button& BackButton,
    LTexture gInstructionTexture,
    LTexture gBackButtonTexture,
    SDL_Renderer* gRenderer,
    bool& Quit_game,
    Mix_Chunk* gClick);

void HandleExitButton(SDL_Event* e,
    Button& ExitButton,
    bool& Quit,
    Mix_Chunk* gClick);

void HandleContinueButton(Button ContinueButton,
    LTexture gContinueButtonTexture,
    SDL_Event* e,
    SDL_Renderer* gRenderer,
    SDL_Rect(&gContinueButton)[BUTTON_TOTAL],
    bool& Game_State, Mix_Chunk* gClick);

void HandlePauseButton(SDL_Event* e,
    SDL_Renderer* gRenderer,
    SDL_Rect(&gContinueButton)[BUTTON_TOTAL],
    Button& PauseButton,
    Button ContinueButton,
    LTexture gContinueButtonTexture,
    bool& game_state,
    Mix_Chunk* gClick);

void GenerateObs(Obstacle& obs1, Obstacle& obs2, Obstacle& obs3, SDL_Renderer* gRenderer);

bool CheckColission(Car car, Obstacle obs);

bool CheckObsColission(Car car, Obstacle obs1, Obstacle obs2, Obstacle obs3);

void DrawPlayerScore(LTexture gTextTexture,
    LTexture gScoreTexture,
    SDL_Color textColor,
    SDL_Renderer* gRenderer,
    TTF_Font* gFont,
    const int& score);

void DrawPlayerHighScore(LTexture gTextTexture,
    LTexture gHighScoreTexture,
    SDL_Color textColor,
    SDL_Renderer* gRenderer,
    TTF_Font* gFont,
    const std::string& HighScore);

void DrawEndGameSelection(LTexture gLoseTexture,
    SDL_Event* e,
    SDL_Renderer* gRenderer,
    bool& Play_Again);


#endif // DRCHECK_H_INCLUDED
