#include "Game_Base.h"
#include "drawandcheck.h"
#include "loadtexture.h"
#include "Button.h"
#include "Character.h"
#include "Enemy.h"

const std::string LAYER[7] = {
	"background.png",
	"background.png",
	"background.png",
	"background.png",
	"background.png",
	"background.png",
	"background.png",

};

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Color textColor = { 0, 0, 0 };
TTF_Font* gFont = nullptr;
Mix_Music* gMusic = nullptr;
Mix_Music* gMenuMusic = nullptr;
Mix_Chunk* gClick = nullptr;
Mix_Chunk* gJump = nullptr;
Mix_Chunk* gLose = nullptr;

SDL_Rect gPlayButton[BUTTON_TOTAL];
SDL_Rect gHelpButton[BUTTON_TOTAL];
SDL_Rect gExitButton[BUTTON_TOTAL];
SDL_Rect gBackButton[BUTTON_TOTAL];
SDL_Rect gPauseButton[BUTTON_TOTAL];
SDL_Rect gContinueButton[BUTTON_TOTAL];
SDL_Rect gPlayAgainButton[BUTTON_TOTAL];
SDL_Rect gCharacterClips;
SDL_Rect gEnemyClips;

LTexture gMenuTexture;
LTexture gInstructionTexture;
LTexture gBackgroundTexture[BACKGROUND_LAYER];
LTexture gCharacterTexture;
LTexture gEnemyTexture;
LTexture gGroundTexture;
LTexture gPlayButtonTexture;
LTexture gHelpButtonTexture;
LTexture gExitButtonTexture;
LTexture gBackButtonTexture;
LTexture gPauseButtonTexture;
LTexture gContinueButtonTexture;
LTexture gLoseTexture;
LTexture gText1Texture;
LTexture gScoreTexture;
LTexture gText2Texture;
LTexture gHighScoreTexture;

Button PlayButton(PLAY_BUTON_POSX, PLAY_BUTTON_POSY);
Button HelpButton(HELP_BUTTON_POSX, HELP_BUTTON_POSY);
Button ExitButton(EXIT_BUTTON_POSX, EXIT_BUTTON_POSY);
Button BackButton(BACK_BUTTON_POSX, BACK_BUTTON_POSY);
Button PauseButton(PAUSE_BUTTON_POSX, PAUSE_BUTTON_POSY);
Button ContinueButton(CONTINUE_BUTTON_POSX, CONTINUE_BUTTON_POSY);

Character character;
Enemy enemy;
int main(int argc, char* argv[])
{
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!LoadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool Quit_Menu = false;
			bool Play_Again = false;

			Mix_PlayMusic(gMenuMusic, IS_REPEATITIVE);
			while (!Quit_Menu)
			{
				SDL_Event e_mouse;
				while (SDL_PollEvent(&e_mouse) != 0)
				{
					if (e_mouse.type == SDL_QUIT)
					{
						Quit_Menu = true;
					}

					bool Quit_Game = false;
					HandlePlayButton(&e_mouse, PlayButton, Quit_Menu, Play_Again, gClick);

					HandleHelpButton(&e_mouse, gBackButton,
									 HelpButton, BackButton,
									 gInstructionTexture, gBackButtonTexture,
									 gRenderer, Quit_Game, gClick);

					HandleExitButton(&e_mouse, ExitButton, Quit_Menu, gClick);

					if (Quit_Game == true)
					{
						return 0;
					}
				}

				gMenuTexture.Render(0, 0, gRenderer);

				SDL_Rect* currentClip_Play = &gPlayButton[PlayButton.currentSprite];
				PlayButton.Render(currentClip_Play, gRenderer, gPlayButtonTexture);

				SDL_Rect* currentClip_Help = &gHelpButton[HelpButton.currentSprite];
				HelpButton.Render(currentClip_Help, gRenderer, gHelpButtonTexture);

				SDL_Rect* currentClip_Exit = &gExitButton[ExitButton.currentSprite];
				ExitButton.Render(currentClip_Exit, gRenderer, gExitButtonTexture);

				SDL_RenderPresent(gRenderer);
			}

			while (Play_Again)
			{
				srand(time(NULL));
				int time = 0;
				int score = 0;
				int acceleration = 0;
				int frame_Character = 0;
				int frame_Enemy = 0;
				std::string highscore = GetHighScoreFromFile("high_score.txt");

				SDL_Event e;
                SDL_Rect* currentClip_Enemy = nullptr;


							currentClip_Enemy = &gEnemyClips;
							enemy.Renderx(currentClip_Enemy, gRenderer, gEnemyTexture);
				           Mix_PlayMusic(gMusic, IS_REPEATITIVE);


				int OffsetSpeed_Ground = BASE_OFFSET_SPEED;
				std::vector <double> OffsetSpeed_Bkgr(7, 5);

				bool Quit = false;
				bool Game_State = true;
				while (!Quit)
				{
					if (Game_State)
					{
						UpdateGameTimeAndScore(time, acceleration, score);

						while (SDL_PollEvent(&e) != 0)
						{
							if (e.type == SDL_QUIT)
							{
								Quit = true;
								Play_Again = false;
							}

							HandlePauseButton(&e, gRenderer, gContinueButton,
								PauseButton, ContinueButton,
								gContinueButtonTexture, Game_State, gClick);

							character.HandleEvent(e, gJump);
						}
						SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
						SDL_RenderClear(gRenderer);

						RenderScrollingBackground(OffsetSpeed_Bkgr, acceleration,gBackgroundTexture, gRenderer);



						character.UpdateMove();
						SDL_Rect* currentClip_Character = nullptr;


							currentClip_Character = &gCharacterClips;
							character.Render(currentClip_Character, gRenderer, gCharacterTexture);




						enemy.Move(acceleration);
						enemy.Renderx(currentClip_Enemy, gRenderer, gEnemyTexture);
//
					//	enemy2.Move(acceleration);
						//enemy2.Render(gRenderer);

						//SDL_Rect* currentClip_Enemy = &gEnemyClips[frame_Enemy / SLOW_FRAME_ENEMY];
						//enemy3.Move(acceleration);
						//enemy3.Render(gRenderer,currentClip_Enemy);


						SDL_Rect* currentClip_Pause = &gPauseButton[PauseButton.currentSprite];
						PauseButton.Render(currentClip_Pause, gRenderer, gPauseButtonTexture);


						DrawPlayerScore(gText1Texture, gScoreTexture, textColor, gRenderer, gFont, score);
						DrawPlayerHighScore(gText2Texture, gHighScoreTexture, textColor, gRenderer, gFont, highscore);

						/*if (CheckEnemyColission(character,
							enemy1, enemy2, enemy3,
							currentClip_Character, currentClip_Enemy))
						{
							Mix_PauseMusic();
							Mix_PlayChannel(MIX_CHANNEL, gLose, NOT_REPEATITIVE);
							UpdateHighScore("high_score.txt", score, highscore);
							Quit = true;
						}

*/
						SDL_RenderPresent(gRenderer);

						ControlCharFrame(frame_Character);
						ControlEnemyFrame(frame_Enemy);
					}
				}

				DrawEndGameSelection(gLoseTexture, &e, gRenderer, Play_Again);
				if (!Play_Again)
				{
					//enem.freeEnemy();
					cout<<"x"<<endl;

				}
			}
		}
	}
	Close();

	return 0;
}


bool Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO) < 0)
	{
		LogError("Can not initialize SDL.", SDL_ERROR);
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering not enabled!";
		}

		gWindow = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			LogError("Can not create window", SDL_ERROR);
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				LogError("Can not create renderer", SDL_ERROR);
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					LogError("Can not initialize SDL_image", IMG_ERROR);
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool LoadMedia()
{
	bool success = true;

	gMusic = Mix_LoadMUS("sound/bkgr_audio.wav");
	if (gMusic == nullptr)
	{
		LogError("Failed to load background music", MIX_ERROR);
		success = false;
	}

	gMenuMusic = Mix_LoadMUS("sound/menu_audio.wav");
	if (gMenuMusic == nullptr)
	{
		LogError("Failed to load menu music", MIX_ERROR);
		success = false;
	}

	gClick = Mix_LoadWAV("sound/mouse_click.wav");
	if (gClick == nullptr)
	{
		LogError("Failed to load mouse click sound", MIX_ERROR);
		success = false;
	}

	gJump = Mix_LoadWAV("sound/move_sound.ogg");
	if (gJump == nullptr)
	{
		LogError("Failed to load jumping sound", MIX_ERROR);
		success = false;
	}

	gLose = Mix_LoadWAV("sound/lose_sound.wav");
	if (gLose == nullptr)
	{
		LogError("Failed to load lose sound", MIX_ERROR);
		success = false;
	}

	else
	{
		gFont = TTF_OpenFont("font/pixel_font.ttf", 28);
		if (gFont == NULL)
		{
			LogError("Failed to load font", MIX_ERROR);
			success = false;
		}
		else
		{
			if (!gText1Texture.LoadFromRenderedText("Your score: ", gFont, textColor, gRenderer))
			{
				std::cout << "Failed to render text1 texture" << std::endl;
				success = false;
			}

			if (!gText2Texture.LoadFromRenderedText("High score: ", gFont, textColor, gRenderer))
			{
				std::cout << "Failed to render text2 texture" << std::endl;
				success = false;
			}

			if (!gMenuTexture.LoadFromFile("imgs/background/menu.png", gRenderer))
			{
				std::cout << "Failed to load menu image" << std::endl;
				success = false;
			}

			if (!gInstructionTexture.LoadFromFile("imgs/background/instruction.jpg", gRenderer))
			{
				std::cout << "Failed to load instruction image" << std::endl;
				success = false;
			}

			if (!gPlayButtonTexture.LoadFromFile("imgs/button/play_button.png", gRenderer))
			{
				std::cout << "Failed to load play_button image" << std::endl;
				success = false;
			}
			else
			{
				for (int i = 0; i < BUTTON_TOTAL; ++i)
				{
					gPlayButton[i].x = 75 * i;
					gPlayButton[i].y = 0;
					gPlayButton[i].w = 75;
					gPlayButton[i].h = 49;
				}
			}

			if (!gHelpButtonTexture.LoadFromFile("imgs/button/help_button.png", gRenderer))
			{
				std::cout << "Failed to load help_button image" << std::endl;
				success = false;
			}
			else
			{
				for (int i = 0; i < BUTTON_TOTAL; ++i)
				{
					gHelpButton[i].x = 75 * i;
					gHelpButton[i].y = 0;
					gHelpButton[i].w = 75;
					gHelpButton[i].h = 49;
				}
			}

			if (!gBackButtonTexture.LoadFromFile("imgs/button/back_button.png", gRenderer))
			{
				std::cout << "Failed to load back_button image" << std::endl;
				success = false;
			}
			else
			{
				for (int i = 0; i < BUTTON_TOTAL; ++i)
				{
					gBackButton[i].x = 50 * i;
					gBackButton[i].y = 0;
					gBackButton[i].w = 50;
					gBackButton[i].h = 39;
				}
			}

			if (!gExitButtonTexture.LoadFromFile("imgs/button/exit_button.png", gRenderer))
			{
				std::cout << "Failed to load exit_button image" << std::endl;
				success = false;
			}
			else
			{
				for (int i = 0; i < BUTTON_TOTAL; ++i)
				{
					gExitButton[i].x = 75 * i;
					gExitButton[i].y = 0;
					gExitButton[i].w = 75;
					gExitButton[i].h = 49;
				}
			}

			if (!gPauseButtonTexture.LoadFromFile("imgs/button/pause_button.png", gRenderer))
			{
				std::cout << "Failed to load pause_button image " << std::endl;
				success = false;
			}
			else
			{
				for (int i = 0; i < BUTTON_TOTAL; ++i)
				{
					gPauseButton[i].x = 22 * i;
					gPauseButton[i].y = 0;
					gPauseButton[i].w = 22;
					gPauseButton[i].h = 34;
				}
			}

			if (!gContinueButtonTexture.LoadFromFile("imgs/button/continue_button.png", gRenderer))
			{
				std::cout << "Failed to load continue_button image " << std::endl;
				success = false;
			}
			else
			{
				for (int i = 0; i < BUTTON_TOTAL; ++i)
				{
					gContinueButton[i].x = 22 * i;
					gContinueButton[i].y = 0;
					gContinueButton[i].w = 22;
					gContinueButton[i].h = 34;
				}
			}

			for (int i = 0; i < BACKGROUND_LAYER; ++i)
			{
				if (!gBackgroundTexture[i].LoadFromFile(LAYER[i].c_str(), gRenderer))
				{
					std::cout << "Failed to load background image" << std::endl;
					success = false;
				}
			}

			if (!gGroundTexture.LoadFromFile("imgs/background/ground.png", gRenderer))
			{
				std::cout << "Failed to load ground image" << std::endl;
				success = false;
			}

			if (!gCharacterTexture.LoadFromFile("car.png", gRenderer))
			{
				std::cout << "Failed to load character_run image." << std::endl;
				success = false;
			}
			else
			{
				gCharacterClips.x = 0;
				gCharacterClips.y = 0;
				gCharacterClips.w = 40;
				gCharacterClips.h = 60;

			}
            if (!gEnemyTexture.LoadFromFile("imgs/enemy/obstacles.png", gRenderer))
			{
				std::cout << "Failed to load character_run image." << std::endl;
				success = false;
			}
			else
			{
				gEnemyClips.x = 0;
				gEnemyClips.y = 0;
				gEnemyClips.w = 40;
				gEnemyClips.h = 60;

			}
			if (!gLoseTexture.LoadFromFile("imgs/background/lose.png", gRenderer))
			{
				std::cout << "Failed to load lose image." << std::endl;
				success = false;
			}

		}
	}
	return success;
}

void Close()
{
	gMenuTexture.Free();
	gInstructionTexture.Free();
	gCharacterTexture.Free();
	gGroundTexture.Free();
	gPlayButtonTexture.Free();
	gHelpButtonTexture.Free();
	gExitButtonTexture.Free();
	gBackButtonTexture.Free();
	gPauseButtonTexture.Free();
	gContinueButtonTexture.Free();
	gLoseTexture.Free();
	gText1Texture.Free();
	gScoreTexture.Free();
	gText2Texture.Free();
	gHighScoreTexture.Free();

	for (int i = 0; i < BACKGROUND_LAYER; ++i)
	{
		gBackgroundTexture[i].Free();
	}

	Mix_FreeMusic(gMusic);
	Mix_FreeMusic(gMenuMusic);
	Mix_FreeChunk(gClick);
	Mix_FreeChunk(gLose);
	Mix_FreeChunk(gJump);
	gMusic = nullptr;
	gMenuMusic = nullptr;
	gClick = nullptr;
	gLose = nullptr;
	gJump = nullptr;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
