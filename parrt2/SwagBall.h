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

class SwagBall
{
private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
public:
	SwagBall(const sf::RenderWindow& window);
	virtual ~SwagBall();

	const sf::CircleShape getShape() const;

	//Function
	void update();
	void render(sf::RenderTarget& target);
};

