#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Timer
{
public:
	Timer() {};

	sf::Time micro = sf::microseconds(1000);
	sf::Time milli = sf::milliseconds(10);
	sf::Time second = sf::seconds(0.01f);
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	sf::Event event;

	void Start();
	
	void Update();

	~Timer(){};

}; 
	
