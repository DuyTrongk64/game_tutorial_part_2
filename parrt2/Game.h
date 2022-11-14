#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<vector>
#include<sstream>

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
	int points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endgameText;

	std::vector<SwagBall> swagBalls;
	float spawmTimerMax;
	float spawmTimer;
	int maxSwagBalls;

	void initVariables();
	void initWindow();
	void initFonts();
	void initText();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors
	const bool& getEndGame() const;
	const int randBallType() const;
	//Modifiers
	
	//Functions
	const bool running() const;
	
	void pollEvents();
	void updatePlayer();
	void spawmSwagBalls();
	void updateCollision();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};

