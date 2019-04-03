
#include <SFML/Graphics/Texture.hpp>	
#include <iostream>
#include "Timer.h"
#include "ResourceHolder.h"
#include "Single.h"
#include "Window.h"
#include <SFML/Graphics/Transformable.hpp>

Window::Window(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
	, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, mPlayerRectangle(nullptr)
{
	//loadTextures();
	//buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void Window::update(sf::Time dt)
{
	// Scroll the world, reset player velocity
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	mPlayerRectangle.setVelocity(0.f, 0.f);

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);
	adaptPlayerVelocity();

	// Regular update step, adapt position (correct if outside view)
	mSceneGraph.update(dt, mCommandQueue);
	adaptPlayerPosition();

}


//OLD
/*void Window::Initialize(int width, int height)
{
	sf::RenderWindow& window : mWindow(window)
		, mWorldView(window.getDefaultView())
		, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f) // height
		, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize(), mPlayerAircraft(nullptr) // Y
	{
		loadTextures();
		buildScene();
		mWorldView.setCenter(mSpawnPosition);
	};

	Player player(0.5f);

	sf::Clock clock;
	Timer timer = Timer();
	float deltaTime = 0.0f;

	sf::Texture& background;
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
}*/

///World Class Stuff

CommandQueue& Window::getCommandQueue()
{
	return mCommandQueue;
}

void Window::loadTextures()
{
	//mTextures.load(Textures::Eagle, "Media/Textures/Eagle.png");
	//mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
	//mTextures.load(Textures::Desert, "Media/Textures/Desert.png");
}

//int main()
//{
//	try
//	{
//		Game game;
//		game.run();
//	}
//	catch (std::exception& e)
//	{
//		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
//	}
//}

void Window::buildScene() {

	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();
		mSceneGraph.attachChild(std::move(layer));
	}

	

	sf::Texture& texture = mTextures.get(Textures::Wall);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	std::unique_ptr<Rectangle> leader(new Rectangle(Rectangle::Wall, mTextures));
	mPlayerRectangle = leader.get();
	mPlayerRectangle.setPosition(mSpawnPosition);
	//mPlayerRectangle.setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Background]->attachChild(std::move(leader));
}

void SpriteNode()
{
	/*std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(
		mWorldBounds.left,
		mWorldBounds.top);
	mSceneLayers[Background]
		->attachChild(std::move(backgroundSprite));*/
}

void Window::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}


//void World::run()
//{
//	mWindow.clear();
//	mWorld.draw();
//	mWindow.setView(mWindow.getDefaultView());
//	mWindow.draw(mStatisticsText);
//	mWindow.display();
//}

void Window::adaptPlayerPosition()
{
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayerRectangle.getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerRectangle.setPosition(position);

}

void Window::adaptPlayerVelocity()
{
	sf::Vector2f velocity = mPlayerRectangle.getVelocity();

	// If moving diagonally, reduce velocity (to have always same velocity)
	if (velocity.x != 0.f && velocity.y != 0.f)
		mPlayerRectangle.setVelocity(velocity / std::sqrt(2.f));

	// Add scrolling velocity
	mPlayerRectangle.accelerate(0.f, mScrollSpeed);
}
