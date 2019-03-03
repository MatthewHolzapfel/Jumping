#include "stdafx.h"
#include <iostream>
#include <string>
#include <SFML/System/Time.hpp>
#include "Timer.h"

using namespace std;

void Timer::Start()
{
	std::cout << "Seconds per milliseconds: " << micro.asSeconds() << std::endl;
	std::cout << "Milliseconds per millisecond: " << micro.asMilliseconds() << std::endl;
	std::cout << "Microseconds per millisecond: " << micro.asMicroseconds() << std::endl;
	std::cout << (micro + micro).asSeconds() << std::endl;
	Timer::Update();
}

void Timer::Update()
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Space)
		{
			std::cout << "Jump Player" << std::endl;
		}
		break;

	case sf::Event::Closed:
		//window.close();
		return;

	case sf::Event::KeyReleased:
		clock.restart();
		break;

	}

	elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() < 1.0f)
		std::cout << elapsed.asSeconds() << std::endl;


	if (sf::Event::Closed)
		Timer::~Timer();
	else
	{
		Timer::Update();
	}
}