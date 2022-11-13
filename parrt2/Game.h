#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<vector>

#include"Player.h"
#include "SwagBall.h"


class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	bool endGame;

	Player player;

	std::vector<SwagBall> swagBalls;
	float spawmTimerMax;
	float spawmTimer;
	int maxSwagBalls;

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
	
	void spawmSwagBalls();
	void update();
	void render();
};

