#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Timer
{
public:
	Timer() {};

	void Start()
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		sf::Texture test;
		if (!test.loadFromFile("splashscreen.png"))
			std::cout << "ERROR";
		sf::Sprite sprite;
		sprite.setTexture(test);


		sf::Time micro = sf::microseconds(1000);
		sf::Time milli = sf::milliseconds(10);
		sf::Time second = sf::seconds(0.01f);
		std::cout << "Seconds per milliseconds: " << micro.asSeconds() << std::endl;
		std::cout << "Milliseconds per millisecond: " << micro.asMilliseconds() << std::endl;
		std::cout << "Microseconds per millisecond: " << micro.asMicroseconds() << std::endl;
		std::cout << (micro + micro).asSeconds() << std::endl;

		sf::Clock clock;


		while (window.isOpen())
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					return;

				case sf::Event::KeyReleased:
					clock.restart();
					break;
				}
			}

			//update the game
			sf::Time elapsed = clock.getElapsedTime();
			if (elapsed.asSeconds() < 1.0f)
				std::cout << elapsed.asSeconds() << std::endl;

			window.clear();
			window.draw(shape);
			window.draw(sprite);

			window.display();





		}
	};

	~Timer()
	{
	};

};