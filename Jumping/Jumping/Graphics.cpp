/*
#include <SFML/Graphics.hpp>

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <assert.h>

using namespace std;


//Testing SFML
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);

while (window.isOpen())
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	window.clear();
	window.draw(shape);
	window.display();
} */