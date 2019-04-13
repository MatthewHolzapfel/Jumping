#include "SFML/Graphics.hpp"
#include "Player.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SoundEffects.h"

using namespace std;

//sf::Event event;
Player::Player(sf::Texture* texture, float speed, float jumpHeight)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	body.setSize(sf::Vector2f(25.0f, 25.0f));
	//body.setFillColor(sf::Color::Black);
	body.setPosition(50.0f, 550.0f);
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);

}

void Player::Jump() {

	

}

void Player::Move(float deltaTime) {
	this->bottom = false;
	velocity.y = 0.0f;
	velocity.x = 0.0f;
	


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

			if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {
				mySound.SetSoundBuffer("Walking.wav");
				mySound.SFX();
			}

			std::cout << "Move Left" << std::endl;
			velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {
			mySound.SetSoundBuffer("Walking.wav");
			mySound.SFX();
		}

	std::cout << "Move Right" << std::endl;
	velocity.x += speed;

	}
	
	//Jump();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		std::cout << "Jump Player" << std::endl;
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		//canJump = true;
	}
	else {
		canJump = true;
		velocity.y = 0.0f;
	}
	

	velocity.y += 2.5f * 981.0f * deltaTime;

	//body.move(movement);
	body.move(velocity*deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
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
			canJump = true;
		}
		else if (direction.y > 0.0f)
		{
			velocity.y = 0.0f;
			canJump = false;
		}

}

Player::~Player() {

}
	
