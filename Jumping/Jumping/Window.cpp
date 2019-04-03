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


	Platform platform1(nullptr, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(50.0f, 600.0f));
	Platform platform2(nullptr, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(350.0f, 600.0f));

	Platform platform3(nullptr, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(550.0f, 600.0f));
	Platform platform4(nullptr, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(650.0f, 500.0f));
	Platform platform5(nullptr, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(750.0f, 600.0f));

	Platform platform6(nullptr, sf::Vector2f(100.0f, 10.0f), sf::Vector2f(200.0f, 500.0f));
	Platform platform7(nullptr, sf::Vector2f(100.0f, 10.0f), sf::Vector2f(350.0f, 400.0f));
	Platform platform8(nullptr, sf::Vector2f(100.0f, 10.0f), sf::Vector2f(450.0f, 500.0f));

	Platform platform9(nullptr, sf::Vector2f(100.0f, 10.0f), sf::Vector2f(850.0f, 400.0f));
	Platform platform10(nullptr, sf::Vector2f(100.0f, 10.0f), sf::Vector2f(950.0f, 300.0f));
	


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

		platform1.GetCollider().CheckCollision(playerCollRect, 9.5f);
		platform2.GetCollider().CheckCollision(playerCollRect, 9.5f);

		platform3.GetCollider().CheckCollision(playerCollRect, 9.5f);
		platform4.GetCollider().CheckCollision(playerCollRect, 9.5f);
		platform5.GetCollider().CheckCollision(playerCollRect, 9.5f);

		platform6.GetCollider().CheckCollision(playerCollRect, 9.5f);
		platform7.GetCollider().CheckCollision(playerCollRect, 9.5f);
		platform8.GetCollider().CheckCollision(playerCollRect, 9.5f);

		platform9.GetCollider().CheckCollision(playerCollRect, 0.5f);
		platform10.GetCollider().CheckCollision(playerCollRect, 9.5f);

		window.clear();


		window.draw(sprite);

		player.Draw(window);

		platform1.Draw(window);
		platform2.Draw(window);


		platform3.Draw(window);
		platform4.Draw(window);
		platform5.Draw(window);

		platform6.Draw(window);
		platform7.Draw(window);
		platform8.Draw(window);

		platform9.Draw(window);
		platform10.Draw(window);

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

