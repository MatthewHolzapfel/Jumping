#pragma once
#include "ResourceID.h"
#include <assert.h>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class TextureHolder
{
public:
	void load(Textures::ID id, const std::string& filename);

	sf::Texture& get(Textures::ID id);

	const sf::Texture& get(Textures::ID id) const;

private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};