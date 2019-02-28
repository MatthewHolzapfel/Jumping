#include "Jumping.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Music.h"
#include "Keyboard Input.h"
#include <SFML/Audio.hpp>

int main()
{
	if (Jumping::Instance()->Start())
		Jumping::Instance()->Open();

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML");
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(200,100));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(window.getSize().x/2, window.getSize().y / 2));
	shape.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
	

	Music myMusic;
	myMusic.PlayMusic("MarioBGM.ogg");

	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{

			Input myInput;
			myInput.jump();

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	

	int a;
	std::cin >> a;
	return 0;
}