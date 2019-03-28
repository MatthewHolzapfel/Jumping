#include "Rectangle.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Rectangle::Type type)
{
	switch (type)
	{
	case Rectangle::Ground:
		return Textures::Rectangle;
		break;
	default:
		return Textures::Default;
	}
}

Rectangle::Rectangle(Type type, const TextureHolder& textures) : mType(type), mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Rectangle::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

