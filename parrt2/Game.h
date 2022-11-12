#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include"Player.h"


class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	bool endGame;

	Player player;

	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors

	//Modifiers
	
	//Functions
	const bool running() const;
	void pollEvents();
	
	void update();
	void render();
};

