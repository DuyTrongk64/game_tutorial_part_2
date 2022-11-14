#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

enum SwagBallTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class SwagBall
{
private:
	sf::CircleShape shape;
	int type;

	void initShape(const sf::RenderWindow& window);
public:
	SwagBall(const sf::RenderWindow& window, int type);
	virtual ~SwagBall();
	//Accessor
	const sf::CircleShape getShape() const;
	const int& getType() const;

	//Function
	void update();
	void render(sf::RenderTarget& target);
};

