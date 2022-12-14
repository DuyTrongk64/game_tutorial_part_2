#include "Game.h"


void Game::initVariables()
{
	this->endGame = false;
	this->spawmTimerMax = 10.f;
	this->spawmTimer = this->spawmTimerMax;
	this->maxSwagBalls = 10;
	this->points = 0;
	
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800,600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf")) 
	{
		std::cout << "ERROR::GAME::INITFONT::CAN'T LOAD FONT!" << "\n";
	}
}

void Game::initText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);
	
	//End game text
	this->endgameText.setFont(this->font);
	this->endgameText.setFillColor(sf::Color::Red);
	this->endgameText.setCharacterSize(64);
	this->endgameText.setPosition(sf::Vector2f(20, 300));
	this->endgameText.setString("END GAME");
}

//Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}


//Functions

const bool Game::running() const
{
	return this->window->isOpen() /* && this->endGame == false*/;
}

const int Game::randBallType() const
{
	int type = SwagBallTypes::DEFAULT;

	int randValue = rand() % 100 + 1;
	if (randValue > 60 && randValue <= 80)
		type = SwagBallTypes::DAMAGING;
	if (randValue > 80 && randValue <= 100)
		type = SwagBallTypes::HEALING;
	return 0;
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

void Game::updatePlayer()
{
	this->player.update(this->window);

	if (this->player.getHp() <= 0)
		this->endGame = true;
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
			this->swagBalls.push_back(SwagBall(*this->window,this->randBallType()));
			this->spawmTimer = 0.f;
		}
	}
}

void Game::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			switch (this->swagBalls[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				this->points++;
				break;
			case SwagBallTypes::DAMAGING:
				this->player.takeDamage(5);
				break;
			case SwagBallTypes::HEALING:
				this->player.gainHealth(1);
				break;
			}
			
			//Remove the ball
			this->swagBalls.erase(this->swagBalls.begin() + 1);
		}
	}
	
}

void Game::updateGui()
{
	std::stringstream ss;
	
	ss << "Points: " << this->points << "\n"
		<< "Health: " << this->player.getHp() << "/" << this->player.getHpMax() << "\n";
	this->guiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();
	
	if (this->endGame == false)
	{
	this->spawmSwagBalls();
	this->updatePlayer();
	this->updateCollision();
	this->updateGui();
	}
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
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

	//Render gui
	this->renderGui(this->window);

	//Render end text
	if (this->endGame == true)
		this->window->draw(this->endgameText);
	this->window->display();
}
