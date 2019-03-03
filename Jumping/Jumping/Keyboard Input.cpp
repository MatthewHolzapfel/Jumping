#include "SFML/Graphics.hpp"
#include "Keyboard Input.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SoundEffects.h"

using namespace std;

//sf::Event event;
Player::Player(float speed)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setFillColor(sf::Color::Green);
	body.setPosition(206.0f, 206.0f);

}

void Player::Jump() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Jump Player" << std::endl;
	}

}

void Player::Move(float deltaTime) {

	SoundEffects mySound;
	mySound.SetSoundBuffer("Walking.wav");
	sf::Vector2f movement(0.0f, 0.0f);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();
			
		}
		std::cout << "Move Left" << std::endl;
		movement.x -= speed + deltaTime;
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Right" << std::endl;
		movement.x += speed + deltaTime; 
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {

			mySound.SFX();
		}
		std::cout << "Move Up" << std::endl;
		movement.y -= speed + deltaTime;
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Down" << std::endl;
		movement.y += speed + deltaTime;
		
	}

	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Player::~Player() {

}
	
