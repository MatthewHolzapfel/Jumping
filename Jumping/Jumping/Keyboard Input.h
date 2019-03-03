#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "SoundEffects.h"
#include "Collider.h"
//#define MAX_NUMBER_OF_ITEMS 3

class Player
{
public:
	Player( float speed);
	~Player();
	void Jump();
	void Move(float deltaTime);
	bool isPlaying = false;
	SoundEffects mySound;
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
	float speed;
	
	
};