#include "Enemy.h"
#include "SFML/Graphics.hpp"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SoundEffects.h"

using namespace std;
Enemy::Enemy(sf::Texture* texture, sf::Vector2f position, float speed)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(25.0f, 25.0f));
	body.setPosition(position);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

void Enemy::Move(float deltaTime) {
	this->bottom = false;
	velocity.y = 0.0f;
	velocity.x = 0.0f;
	bool moving = true;
	
	turnTime += deltaTime;
	if (turnTime > 3.0f) {
		moveRight = !moveRight;
		turnTime -= 3.0f;
	}
	if (moveRight) {
		velocity.x += speed;
	}
	else {
		velocity.x -= speed;
	}

	velocity.y += 2.5f * 981.0f * deltaTime;

	//body.move(movement);
	body.move(velocity*deltaTime);
	
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemy::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
		
	}

}









Enemy::~Enemy()
{
}
