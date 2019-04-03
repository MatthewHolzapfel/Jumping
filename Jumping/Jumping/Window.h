#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Single.h"
#include "Music.h"
#include "Platform.h"
#include "Keyboard Input.h"
#include <SFML/Audio.hpp>
#include "SoundEffects.h"
#include "ResourceHolder.h"
#include "SpriteNode.h"
#include <array>
#include "Rectangle.h"
#include "CommandQueue.h"
#include <SFML/Graphics/Sprite.hpp>

class Window : public Single<Window>
{
private:
	explicit Window(sf::RenderWindow& window);
	//sf::RenderWindow* window;
	friend Single;
	Window();

	void buildScene();
	void loadTextures();
	CommandQueue mCommandQueue;

public:
	sf::RenderWindow* GetWindow() const;
	void Initialize(int width, int height);
	~Window();
	CommandQueue& getCommandQueue();
	void update(sf::Time dt);
	void draw();
	void adaptPlayerPosition();
	void adaptPlayerVelocity();

private:
	enum Layer
	{
		Background,
	
		LayerCount
	};
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Rectangle mPlayerRectangle;
};

class World : SpriteNode {

	/*std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect));

	backgroundSprite->setPosition(
		mWorldBounds.left,
		mWorldBounds.top);

	mSceneLayers[Background]
		->attachChild(std::move(backgroundSprite));*/

};