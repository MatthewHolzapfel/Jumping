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

			

				sf::Time elapsed = clock.getElapsedTime();
			

				while (window.isOpen())
				{
					
					sf::Event event;
					window.setKeyRepeatEnabled(false);
					while (window.pollEvent(event))
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
							window.close();
							return;

						case sf::Event::KeyReleased:
							clock.restart();
							break;

						}
						//if (elapsed.asSeconds() < 20.0f)
						//	window.close();
						
						//return;
					}

					//update the game
					
					//if (elapsed.asSeconds() < 6.0f)
					//	std::cout << elapsed.asSeconds() << std::endl;
					sf::Time elapsed = clock.getElapsedTime();
					if (elapsed.asSeconds() < 1.0f)
						std::cout << elapsed.asSeconds() << std::endl;


					window.clear();
					window.draw(shape);
					window.draw(sprite);

					window.display();

					//if (elapsed.asSeconds() < 5.0f)
						//window.close();
					//return; 




					

	}
};

	
	void Update() 
	{
		sf::Clock clock;
		sf::Event event;
		
		//while (event.pollEvent)
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
			
		}

		
		//sf::Clock clock;
		//update the game
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() < 1.0f)
			std::cout << elapsed.asSeconds() << std::endl; 
	}


	~Timer()
	{
	};

}; 
	
