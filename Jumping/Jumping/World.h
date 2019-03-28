#pragma once
#include "Single.h"

////Composing the world class
/*
class World : private Single<World>
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	void loadTextures(); //Private?

private:
	void buildScene();

private:
	enum Layer
	{
		Background,
		LayerCounter
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCounter> mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Rectangle* mPlayerRectangle;

	: mWindow(window)
		, mWorldView(window.getDefaultView())
		, mWorldBounds(
			0.f,
			0.f,
			mWorldView.getSize().x,
			2000.f)
		, mSpawnPosition(
			mWorldView.getSize().x / 2.f,
			mWorldBounds.height - mWorldView.getSize()
			, mPlayerRectangle(nullptr))
	{
		loadTextures();
		buildScene();
		mWorldView.setCenter(mSpawnPosition);
	}

};*/