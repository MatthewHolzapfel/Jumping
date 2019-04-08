#include "Window.h"
#include <SFML/Graphics/Texture.hpp>	
#include <iostream>
#include "Timer.h"
Window::Window()
{}

void Window::Initialize(int width, int height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML");

	Player player(0.5f);

	sf::Clock clock;
	Timer timer = Timer();
	float deltaTime = 0.0f;

	sf::Texture background;
	background.loadFromFile("Background.png");
	sf::Sprite sprite(background);
	sprite.scale(sf::Vector2f(0.53f, 0.55f));

	sf::Texture building;
	building.loadFromFile("Building.jpg");

	sf::Texture steelBeam;
	steelBeam.loadFromFile("Platform.png");

	sf::Texture danger;
	danger.loadFromFile("Danger.jpg");

	Platform platformList[25] = {
	Platform(&building, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(50.0f, 600.0f), 500.0f, false),
	Platform(&building, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(350.0f, 600.0f), 500.0f, false),
	Platform(&building, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(550.0f, 600.0f), 500.0f, false),
	Platform(&building, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(650.0f, 500.0f), 500.0f, false),
	Platform(&building, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(750.0f, 600.0f), 500.0f, false),

	Platform(&steelBeam, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(200.0f, 500.0f), 500.0f, false),
	Platform(&steelBeam, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(350.0f, 400.0f), 500.0f, false),
	Platform(&steelBeam, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(450.0f, 500.0f), 500.0f, false),
	Platform(&steelBeam, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(950.0f, 300.0f), 500.0f, false),

	Platform(&danger, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(850.0f, 400.0f), 0.5f, true)
	};





	Music myMusic;
	myMusic.PlayMusic("Point of Clash.ogg");



	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			Player myInput(1.5f);
			myInput.Jump();


			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}

		}

		Collider playerCollRect = player.GetCollider();
		
		for (int i = 0; i < sizeof(platformList)/sizeof(Platform); i++)
		{
			if (platformList[i].GetCollider().CheckCollision(playerCollRect, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}
		
		player.Move(deltaTime);

		window.clear();


		window.draw(sprite);

		player.Draw(window);

		for (int i = 0; i < sizeof(platformList)/sizeof(Platform); i++)
		{
			platformList[i].Draw(window);
		}

		window.display();

		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() < 1.0f)
			std::cout << elapsed.asSeconds() << std::endl;

	}
}

sf::RenderWindow* Window::GetWindow() const
{
	return window;
}

