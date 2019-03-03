#include "Window.h"
#include <SFML/Graphics/Texture.hpp>	
#include "Music.h"
#include "Jumping.h"
#include <iostream>

Window::Window()
{}

void Window::Initialize(int _width, int _height)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::RenderWindow window(sf::VideoMode(_width, _height), "SFML");

	Music myMusic;

	myMusic.PlayMusic("MarioBGM.ogg");

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

sf::RenderWindow* Window::GetWindow() const
{
	return window;
}

