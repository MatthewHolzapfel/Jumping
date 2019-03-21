#include "Scene Graph.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
/*
SceneNode::SceneNode(Category::Type category)
	: mChildren()
	, mParent(nullptr)
	, mDefaultCategory(category)
{

}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	updateCurrent(dt, commands);
	updateChildren(dt, commands);
}

void SceneNode::updateCurrent(sf::Time, CommandQueue&)
{
	//do nothing by default
}

void SceneNode::updateChildren(sf::Time dt, CommandQueue& commands)
{
	
	FOREACH(Ptr& child, mChildren)
		child->update(dt, commands);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//apply transform of current node
	states.transform *= getTransform();

	//Draw node and children with changed transform
	drawCurrent(target, states);
	drawChildren(target, states); 


}

void SceneNode::drawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	//do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	FOREACH(const Ptr& child, mChildren)
		child->draw(target, states);
}

void SceneNode::drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const
{
	sf::FloatRect rect = getBoundingRect();
	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2f(rect.left, rect.top));
	shape.setSize(sf::Vector2f(rect.width, rect.height));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(1.f);
	target.draw(shape); 
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;

	return transform;
}

void SceneNode::onCommand(const Command& command, sf::Time dt)
{
	//command current node, if category matches
	if (command.category & getCategory())
		command.action(*this, dt);

	//command children
	FOREACH(Ptr& child, mChildren)
	child->onCommand(command, dt);
}

unsigned int SceneNode::getCategory() const
{
	return mDefaultCategory;
}

void SceneNode::checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs)
{
	checkNodeCollision(sceneGraph, collisionPairs);

	FOREACH(Ptr& child, sceneGraph.mChildren)
		checkSceneCollision(*child, collisionPairs);
}

void SceneNode::checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs)
{
	if (this != &node && collision(*this, node) && !isDestroyed() && !node.isDestroyed())
		collisionPairs.insert(std::minmax(this, &node));

	FOREACH(Ptr& child, mChildren)
		child->checkNodeCollision(node, collisionPairs);
}

void SceneNode::removeWrecks()
{
	// Remove all children which request so
	auto wreckfieldBegin = std::remove_if(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::isMarkedForRemoval));
	mChildren.erase(wreckfieldBegin, mChildren.end());

	// Call function recursively for all remaining children
	std::for_each(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::removeWrecks));
}

sf::FloatRect SceneNode::getBoundingRect() const
{
	return sf::FloatRect();
}

bool SceneNode::isMarkedForRemoval() const
{
	// By default, remove node if entity is destroyed
	return isDestroyed();
}

bool SceneNode::isDestroyed() const
{
	// By default, scene node needn't be removed
	return false;
}

bool collision(const SceneNode& lhs, const SceneNode& rhs)
{
	return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}

float distance(const SceneNode& lhs, const SceneNode& rhs)
{
	return length(lhs.getWorldPosition() - rhs.getWorldPosition());
}

*/
///ATTEMPT 2^^^^

///////////////




/*
#include "SceneGraph.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;





//Scene Graph

class SceneNode
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
};


void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
};

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) -> bool {
		return p.get() == &node;
	});

	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};


void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	sf::RenderWindow window();
	SceneNode::Ptr node();


	//	sf::Transformable::getTransform();
	states.transform *= getTransform();
	drawCurrent(target, states);

	for (auto itr = mChildren.begin();
		itr != mChildren.end(); ++itr)
	{
		(*itr)->draw(target, states);
	}

	for (const Ptr& child : mChildren)
	{
		child->draw(target, states);
	}




}

/*class Sprite : public Entity
{
public:
	explicit Sprite(Type type);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};

void Sprite::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
} */

/*void drawChildren()
{
	for (const Ptr& child : mChildren)
	{
		child->draw(target, states);
	}

}*/





/*void GameObject::Update(float msec) {
	if (parent) {
		worldTransform = parent->worldTransform * transform;
	}

	else {
		worldTransform = transform;
	}

	for (vector<GameObject*>::iterator i = children.begin(); i != children.end(); ++i) {
		(*i)->Update(msec);
	}
} */
