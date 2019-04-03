#include "SpriteNode.h"
#include "Window.h"
#include <SFML/Graphics/RenderTarget.hpp>

SpriteNode::SpriteNode(const sf::Texture& texture) : mSprite(texture)
{
	
}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect) : mSprite(texture, textureRect)
{

}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}



/*void SpriteNode::SpriteNode() {
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(
		mWorldBounds.left,
		mWorldBounds.top);
	mSceneLayers[Background]
		->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Rectangle> leader(
		new Rectangle(Rectangle::Rectangle, mTextures));
	mPlayerRectangle = leader.get();
	mPlayerRectangle->setPosition(mSpawnPosition);
	mPlayerRectangle->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Rectangle]->attachChild(std::move(leader));

	std::unique_ptr<Rectangle> leftEscort(
		new Rectangle(Rectangle::Rectangle, mTextures));
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerRectangle->attachChild(std::move(leftEscort));
}
*/