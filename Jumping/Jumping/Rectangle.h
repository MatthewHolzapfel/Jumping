#pragma once
#include "Entity.h"
#include "Command.h"
#include "ResourceID.h"
#include "TextureHolder.h"
#include <SFML/Graphics/Sprite.hpp>

class Rectangle : public Entity //inherits indirectly SceneNode
{
public:
	enum Type
	{
		Ground,
		Wall,
	};
public:
	Rectangle(Type type, const TextureHolder& textures);
	virtual unsigned int getCategory() const;
	Rectangle();

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};