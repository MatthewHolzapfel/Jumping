#pragma once


#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "SFML\Graphics.hpp"
#include "Category.h"
#include "Rectangle.h"
#include <vector>
#include <set>
#include <memory>
#include <utility>

struct Command;
//{
//	Command();
//	std::function<void(SceneNode &, sf::Time)> action;
//	unsigned int category;
//	//action()
//	//SceneNode&
//};
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
//	SceneNode();

	typedef std::unique_ptr<SceneNode> Ptr;
	typedef std::pair<SceneNode*, SceneNode*> Pair;

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

	void update(sf::Time dt, CommandQueue& commands);

	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;

	void onCommand(const Command& command, sf::Time dt);
	virtual unsigned int getCategory() const;


	enum Action {
		MoveLeft,
		MoveRight,
	};

public:
	SceneNode(Category::Type category = Category::None);

	
	void checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
	void checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	void removeWrecks();
	virtual sf::FloatRect getBoundingRect() const;
	virtual bool isMarkedForRemoval() const;
	virtual bool isDestroyed() const;


private:
	virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
	void updateChildren(sf::Time dt, CommandQueue& commands);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;
	static bool isRealtimeAction(Action action);

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
	Category::Type mDefaultCategory;
};


//bool collision(const SceneNode& lhs, const SceneNode& rhs);
//float distance(const SceneNode& lhs, const SceneNode& rhs); 
//
//template <typename Resource, typename Identifier>
//class ResourceHolder;

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