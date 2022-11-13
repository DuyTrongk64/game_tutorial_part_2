#pragma once

#include"SwagBall.h"

class Player
{
private:
	sf::RectangleShape shape;

	float movementSpeed;
	int hp;
	int hpMax;
	int points;

	void initVasriables();
	void initShape();
public:
	Player(float x = 0.f, float y= 0.f);
	virtual ~Player();

	const sf::RectangleShape& getShape() const;

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget*target);
};

