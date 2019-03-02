#include "Jumping.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Music.h"
#include "Keyboard Input.h"
#include <SFML/Audio.hpp>
#include "SoundEffects.h"


using namespace std;

int main()
{
	if (Jumping::Instance()->Start())
		Jumping::Instance()->Open();

	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML");
	sf::RectangleShape *shape1 = new sf::RectangleShape;
	shape1->setSize(sf::Vector2f(200, 100));
	shape1->setFillColor(sf::Color::Green);
	shape1->setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	shape1->setOrigin(sf::Vector2f(shape1->getSize().x / 2, shape1->getSize().y / 2));
	
	sf::Texture background;
	background.loadFromFile("Background.png");
	sf::Sprite sprite(background);
	sprite.scale(sf::Vector2f(0.5f, 0.5f));

	
	


	Music myMusic;
	myMusic.PlayMusic("MarioBGM.ogg");
	

	;

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{

			Input myInput;
			myInput.jump();
			myInput.move(shape1);

			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		
		window.draw(sprite);
		window.draw(*shape1);
		
		window.display();
		
	}


	

	int a;
	std::cin >> a;
	return 0;
}