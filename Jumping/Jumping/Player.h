#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "SoundEffects.h"
#include "Collider.h"
//#define MAX_NUMBER_OF_ITEMS 3

class Player
{
public:
	Player(float speed, float jumpHeight);
	~Player();
	void Jump();
	void Move(float deltaTime);
	bool isPlaying = false;
	bool bottom = false;
	SoundEffects mySound;
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
	float speed;
	
	sf::Vector2f velocity;
	bool canJump = true;
	float jumpHeight;
};