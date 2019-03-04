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
	sprite.scale(sf::Vector2f(0.5f, 0.5f));


	Platform platform1(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(800.0f, 400.0f));
	Platform platform2(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(400.0f, 400.0f));

	Music myMusic;
	myMusic.PlayMusic("MarioBGM.ogg");



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
		player.Move(deltaTime);

		platform1.GetCollider().CheckCollision(playerCollRect, 0.5f);
		platform2.GetCollider().CheckCollision(playerCollRect, 0.5f);

		window.clear();


		window.draw(sprite);

		player.Draw(window);

		platform1.Draw(window);
		platform2.Draw(window);

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

