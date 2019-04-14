#include "Window.h"
#include <SFML/Graphics/Texture.hpp>	
#include <iostream>
#include "Timer.h"
Window::Window()
{}

void Window::Initialize(int width, int height)
{
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML");

	

	sf::Clock clock;
	Timer timer = Timer();
	float deltaTime = 0.01f;//Temporary!

	sf::Texture background;
	background.loadFromFile("Background.png");
	sf::Sprite sprite(background);
	sprite.scale(sf::Vector2f(0.53f, 0.55f));

	sf::Texture playerSprite;
	playerSprite.loadFromFile("BoxBoy.png");
	Player player(&playerSprite, 50.0f, 70.0f);

	sf::Texture building;
	building.loadFromFile("Building.jpg");

	sf::Texture steelBeam;
	steelBeam.loadFromFile("Platform.png");

	sf::Texture danger;
	danger.loadFromFile("Danger.jpg");

	sf::Texture enemySprite;
	enemySprite.loadFromFile("Robot.jpg");
	

	Enemy enemy1(&enemySprite, sf::Vector2f(170.0f, 500.0f), 10.0f);
	Enemy enemy2(&enemySprite, sf::Vector2f(320.0f, 400.0f), 10.0f);
	Enemy enemy3(&enemySprite, sf::Vector2f(420.0f, 500.0f), 10.0f);
	Enemy enemy4(&enemySprite, sf::Vector2f(640.0f, 350.0f), 10.0f);
	Enemy enemy5(&enemySprite, sf::Vector2f(325.0f, 600.0f), 10.0f);

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

			Player myInput(&playerSprite, 1.5f, 200.0f);
			myInput.Jump();


			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}

		}

		Collider playerCollRect = player.GetCollider();
		sf::Vector2f direction;
		
		for (int i = 0; i < sizeof(platformList)/sizeof(Platform); i++)
		{
			if (platformList[i].GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}

		for (int i = 0; i < sizeof(platformList) / sizeof(Platform); i++)
		{
			if (platformList[i].GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}

		for (int i = 0; i < sizeof(enemy1) / sizeof(Enemy); i++)
		{
			if (enemy1.GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}

		for (int i = 0; i < sizeof(enemy2) / sizeof(Enemy); i++)
		{
			if (enemy2.GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}

		for (int i = 0; i < sizeof(enemy3) / sizeof(Enemy); i++)
		{
			if (enemy3.GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}

		for (int i = 0; i < sizeof(enemy4) / sizeof(Enemy); i++)
		{
			if (enemy4.GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}


		for (int i = 0; i < sizeof(enemy5) / sizeof(Enemy); i++)
		{
			if (enemy5.GetCollider().CheckCollision(playerCollRect, direction, platformList[i].resistance, platformList[i].isMovable))
			{
				player.bottom = platformList[i].GetCollider().bottomCollider(playerCollRect);
			}
		}










		Collider enemyCollRect1 = enemy1.GetCollider();
		Collider enemyCollRect2 = enemy2.GetCollider();
		Collider enemyCollRect3 = enemy3.GetCollider();
		Collider enemyCollRect4 = enemy4.GetCollider();
		Collider enemyCollRect5 = enemy5.GetCollider();

		sf::Vector2f Edirection;

		for (int i = 0; i < sizeof(platformList) / sizeof(Platform); i++)
		{
			if (platformList[i].GetCollider().CheckCollision(enemyCollRect1, Edirection, platformList[i].resistance, platformList[i].isMovable))
			{
				enemy1.bottom = platformList[i].GetCollider().bottomCollider(enemyCollRect1);
			}

			if (platformList[i].GetCollider().CheckCollision(enemyCollRect2, Edirection, platformList[i].resistance, platformList[i].isMovable))
			{
				enemy2.bottom = platformList[i].GetCollider().bottomCollider(enemyCollRect2);
			}

			if (platformList[i].GetCollider().CheckCollision(enemyCollRect3, Edirection, platformList[i].resistance, platformList[i].isMovable))
			{
				enemy3.bottom = platformList[i].GetCollider().bottomCollider(enemyCollRect3);
			}

			if (platformList[i].GetCollider().CheckCollision(enemyCollRect4, Edirection, platformList[i].resistance, platformList[i].isMovable))
			{
				enemy4.bottom = platformList[i].GetCollider().bottomCollider(enemyCollRect4);
			}

			if (platformList[i].GetCollider().CheckCollision(enemyCollRect5, Edirection, platformList[i].resistance, platformList[i].isMovable))
			{
				enemy5.bottom = platformList[i].GetCollider().bottomCollider(enemyCollRect5);
			}
		}




		
		player.Move(deltaTime);

		enemy1.Move(deltaTime, 5);
		enemy2.Move(deltaTime, 4);
		enemy3.Move(deltaTime, 6);
		enemy4.Move(deltaTime, 3);
		enemy5.Move(deltaTime, 9);

		window.clear();


		window.draw(sprite);

		player.Draw(window);
		enemy1.Draw(window);
		enemy2.Draw(window);
		enemy3.Draw(window);
		enemy4.Draw(window);
		enemy5.Draw(window);
		
		

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

