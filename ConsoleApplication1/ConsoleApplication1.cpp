// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

int Engine_Init();
int Engine_Generator_Map();
// MAP DEFINITION
//  Container[Layer][X][Y]
int MemoryMap[4][256][256];

int _tmain(int argc, _TCHAR* argv[])
{
	int debug_EngineInit;
	int debug_MainMenu;
	bool run;
	run = true;

	// GRAPHICS INITIALIZATION
	SDL_Surface* LoadingScreen = NULL;
		//		USER INTERFACE LAYERS
	SDL_Surface* UI = NULL;
	SDL_Surface* UIoverlay = NULL;
		//		Players
	SDL_Surface* PlayerImg[2];
		//		MAIN INTERFACES
	SDL_Surface* Screen = NULL;
	SDL_Window* win = nullptr;

	// FONT INITIALIZATION
	TTF_Font* Font = NULL;
	
	// PLAYER DATA
	struct CharStat
	{
		int Max;
		int Min;
		int Current;
		int Previous;
	};
	struct CharLocation
	{
		int X;
		int Y;
		int PreviousX;
		int PreviousY;
	};

	struct PLAYER
	{
		std::string Name;
		CharStat HP;
		CharStat MP;
		CharStat XP;
		CharLocation Loc;

	};


	SDL_Color colorWhite = { 255, 255, 255 };
	SDL_Color colorBlack = { 0, 0, 0 };


	Font = TTF_OpenFont("C:\\DEV\\FONTS\\georgia.ttf", 24);
	win = SDL_CreateWindow("MAIN", 0, 0, 1280, 720, SDL_WINDOW_FULLSCREEN);
	Screen = SDL_GetWindowSurface(win);

	// EVENT HANDLER INITIALIZATION
	SDL_Event e;

	// debug_EngineInit = Engine_Init();

			//Error Handler
	LoadingScreen = IMG_Load("C:\\DEV\\IMAGES\\Init.jpg");
	if (LoadingScreen == NULL)
	{
		printf("Error Loading Image Init.jpg");
		return -1;
	}
	if (Font == NULL)
	{
		printf("Error Loading Font: Georgia");
		return -2;
	}

	while (run)
	{
		Screen = SDL_GetWindowSurface(win);
		SDL_BlitSurface(LoadingScreen, NULL, Screen, NULL);
		SDL_UpdateWindowSurface( win );
	

		if (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				run = false;
			}
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				run = false;
			}
		}
	}

	return 0;
}

int Engine_Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		printf(SDL_GetError());
		return 1;
	}
	SDL_Window *win = nullptr;
	win = SDL_CreateWindow("MAIN", 0, 0, 1280, 720, SDL_WINDOW_FULLSCREEN);
	if (win == nullptr)
	{
		printf(SDL_GetError());
		return 1;
	}
	

}

int Engine_Main_Menu()
{
	return 0;
}

int Engine_Generator_Map()
{
	//Sets Layer 0 of Map to 1 (GRASS)
	for (int tmpx; tmpx >= 256; tmpx++)
	{
		for (int tmpy; tmpy >= 256; tmpy++)
		{
			MemoryMap[0][tmpx][tmpy] = 1;
		}
	}
	return 0;
}

int Engine_Renderer_Map()
{
	return 0;
}

int Engine_Renderer_UI()
{
	return 0;
}

int Engine_Renderer_Players()
{
	return 0;
}

int Engine_Renderer_Enemies()
{
	return 0;
}