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
