#pragma once
#include "Scene Graph.h"

class Rectangle : public Entity //inherits indirectly SceneNode
{


public:
	enum Type
	{
		Ground,
		Wall,
	};
	explicit Rectangle(Type type);
	Rectangle(Type type, const TextureHolder & textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};