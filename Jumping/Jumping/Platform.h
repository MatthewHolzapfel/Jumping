#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float resistance, bool movable);
	~Platform();
	float resistance = 0.0f;
	bool isMovable;
	Platform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
};