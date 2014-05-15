// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
#include "entities.h" // defines structures for players, enemies, items and spells

int Map[4][128][128];
bool MainLoop;
bool UpdateScreen;
bool keyReset;

sf::RenderWindow screen(sf::VideoMode(1280, 720), "Init...");
sf::Font font;
sf::Text text("INITIALIZING...", font, 24);
sf::Texture Tile[4];
sf::Sprite Sprite[4];
sf::Sprite gMap[4][32][32];
sf::Sprite gPlayer[4];

player LocalPlayer;
void Init_Map();
void Render_Map_TXT();
void Handler_Input();

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Initialization started...\n"; 
	MainLoop = true;
	cout << "Initializing Map...\n";
	Init_Map();
	cout << "Initializing LocalPlayer...\n";
	LocalPlayer.name = "Player1";
	LocalPlayer.x = 16;
	LocalPlayer.y = 16;
	UpdateScreen = true;
	font.loadFromFile("georgia.ttf");
	Tile[0].loadFromFile("MEDIA/IMAGES/TEXTURES/0.JPG");
	Tile[1].loadFromFile("MEDIA/IMAGES/TEXTURES/GRASS.JPG");
	Tile[2].loadFromFile("MEDIA/IMAGES/TEXTURES/WATER.JPG");
	Sprite[0].setTexture(Tile[0], true);
	Sprite[1].setTexture(Tile[1], true);

	text.setColor(sf::Color::White);
	
	while (MainLoop)
	{
		Handler_Input();
		if (UpdateScreen == true)
			{
				//Render_Map_TXT();
			screen.clear();
			Render_Map_TXT();
			Handler_Input();
			screen.draw(text);
			screen.display();
			}
			//SDL_Delay(1000);

	}
	return 0;
}

void Init_Map()
{
	for (int tmpx = 0; tmpx <= 128; tmpx++)
	{
		for (int tmpy = 0; tmpy <= 128; tmpy++)
		{
			Map[0][tmpx][tmpy] = 1;
			if (tmpx == 0) { Map[0][tmpx][tmpy] = 2; }
			if (tmpx == 128) { Map[0][tmpx][tmpy] = 2; }
			if (tmpy == 0) { Map[0][tmpx][tmpy] = 2; }
			if (tmpy == 128) { Map[0][tmpx][tmpy] = 2; }
		}
	}
}

void Render_Map_TXT()
{
	text.setString("");
	for (int tmpy = (LocalPlayer.y-16); tmpy <= (LocalPlayer.y+16); tmpy++)
	{
		for (int tmpx = (LocalPlayer.x-16); tmpx <= (LocalPlayer.x+16); tmpx++)
		{
			if (tmpx >= 0)
			{
				if (tmpy >= 0)
				{

					if (Map[0][tmpx][tmpy] == 1)
					{
						//text.setString(text.getString()+"G");
						gMap[0][tmpx][tmpy].setPosition(tmpx * 32, tmpy * 32);
						gMap[0][tmpx][tmpy].setTexture(Tile[1], true);
						screen.draw(gMap[0][tmpx][tmpy]);

					}
					if (Map[0][tmpx][tmpy] == 2)
					{
						//text.setString(text.getString() + "W");
						gMap[0][tmpx][tmpy].setPosition(tmpx * 32, tmpy * 32);
						gMap[0][tmpx][tmpy].setTexture(Tile[2], true);
						screen.draw(gMap[0][tmpx][tmpy]);
					}
				}
			}
		}
		//text.setString(text.getString() + "\n");
	}
	gPlayer[0].setPosition(LocalPlayer.x*32,LocalPlayer.y*32);
	gPlayer[0].setTexture(Tile[0], true);
	screen.draw(gPlayer[0]);
	text.setString("x:" + to_string(LocalPlayer.x) + " y:" + to_string(LocalPlayer.y)+"\n");

	UpdateScreen = false;
}

void Handler_Input()
{
	// cout << "DBG: Func HANDLER_INPUT called;\n";
	if (keyReset == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { LocalPlayer.x = LocalPlayer.x - 1; keyReset = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { LocalPlayer.x = LocalPlayer.x + 1; keyReset = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { LocalPlayer.y = LocalPlayer.y - 1; keyReset = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { LocalPlayer.y = LocalPlayer.y + 1; keyReset = true; }
	}
	bool tmpkeypush=false;
	if (keyReset == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { tmpkeypush = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { tmpkeypush = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { tmpkeypush = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { tmpkeypush = true; }
		if (tmpkeypush == false) { keyReset = false; UpdateScreen = true; }
	}
}