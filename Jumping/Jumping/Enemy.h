#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "SoundEffects.h"
#include "Collider.h"
class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2f position, float speed);
	~Enemy();
	void Move(float deltaTime);
	bool isPlaying = false;
	bool bottom = false;
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	bool moveRight = true;
	

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
	float speed;
	float turnTime = 0.0f;
	sf::Vector2f velocity;
	





};

