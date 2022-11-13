#include "Game.h"


void Game::initVariables()
{
	this->endGame = false;
	this->spawmTimerMax = 10.f;
	this->spawmTimer = this->spawmTimerMax;
	this->maxSwagBalls = 10;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800,600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Functions

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type) 
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::spawmSwagBalls()
{
	//Timer
	if (this->spawmTimer < this->spawmTimerMax)
		this->spawmTimer += 1.f;
	else
	{
		if(this->swagBalls.size() < this->maxSwagBalls)
		{
			this->swagBalls.push_back(SwagBall(*this->window));
			this->spawmTimer = 0.f;
		}
	}
}

void Game::update()
{
	this->pollEvents();

	this->spawmSwagBalls();
	this->player.update(this->window);
}

void Game::render()
{
	this->window->clear();

	//Renser stuff
	this->player.render(this->window);

	for (auto i :this->swagBalls)
	{
		i.render(*this->window);
	}
	this->window->display();
}
