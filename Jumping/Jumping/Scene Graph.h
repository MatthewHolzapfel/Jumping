#pragma once


#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "SFML\Graphics.hpp"
#include "Category.hpp"
#include "Rectangle.h"

#include <map>
#include <vector>
#include <set>
#include <memory>
#include <utility>
#include <functional>


//Texture Holder 
namespace Textures
{
	enum ID { Background, Rectangle};
}

class TextureHolder
{
public:
	void load(Textures::ID id, const std::string& filename);
	sf::Texture& get(Textures::ID id);
	const sf::Texture& get(Textures::ID id) const;

//private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap; 
};






struct Command
{
	Command();
	std::function<void(SceneNode &, sf::Time)> action;
	unsigned int category;
	//action()
	//SceneNode&
};
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	//Command commmand;

	

	typedef std::unique_ptr<SceneNode> Ptr;
	typedef std::pair<SceneNode*, SceneNode*> Pair;

	
	


	enum Action {
		MoveLeft,
		MoveRight,
	};

	
	


public:
	SceneNode();

	explicit				SceneNode(Category::Type category = Category::None);

	void					attachChild(Ptr child);
	Ptr						detachChild(const SceneNode& node);

	void					update(sf::Time dt, CommandQueue& commands);

	sf::Vector2f			getWorldPosition() const;
	sf::Transform			getWorldTransform() const;

	void					onCommand(const Command& command, sf::Time dt);
	virtual unsigned int	getCategory() const;

	void					checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
	void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	void					removeWrecks();
	virtual sf::FloatRect	getBoundingRect() const;
	virtual bool			isMarkedForRemoval() const;
	virtual bool			isDestroyed() const;
	
	//void update(sf::Time dt);


private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
	void					updateChildren(sf::Time dt, CommandQueue& commands);

	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	void					drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;
	static bool isRealtimeAction(Action action);

private:
	std::vector<Ptr>		mChildren;
	SceneNode*				mParent;
	Category::Type			mDefaultCategory;
};

bool collision(const SceneNode& lhs, const SceneNode& rhs);
float distance(const SceneNode& lhs, const SceneNode& rhs); 

////Entity stuff

class Entity : public SceneNode
{
public:
	explicit Entity();
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const; 

private:
	sf::Vector2f mVelocity; 
};




namespace Textures
{
	enum ID
	{
		Rectangle,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

///Sprite Node stuff

class SpriteNode : public SceneNode
{
public:
	explicit SpriteNode(const sf::Texture& texture);
	SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	sf::Sprite mSprite;
};

////Composing the world class

class World : private sf::NonCopyable
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
		
};

 /*
class GameObject {
public:
	GameObject() { parent = NULL; }
	GameObject(void);

	void SetTransform(const Matrix4 &matrix) {transform = matrix;}
	Matrix4 GetTransform() { return transform; }
	Matrix4 GetWorldTransform() { return GetWorldTransform; }

	void SetParent(GameObject& p) { parent = s; }
	void AddChild(GameObject* s);

	virtual void Update(float msec);

protected:
	GameObject* parent;
	Matrix4 worldTransform;
	Matrix4 transform;
	std::vector<GameObject*> children;
}; */