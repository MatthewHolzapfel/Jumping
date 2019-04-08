#pragma once
#include <SFML\Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Collider & other, float push, bool movable);
	bool bottomCollider(Collider& other);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return sf::Vector2f(body.getSize() / 2.0f); }
	sf::FloatRect getBounds() { return body.getLocalBounds(); }

private:
	sf::RectangleShape& body;
};

