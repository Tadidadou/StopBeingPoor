#pragma once

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"

class Character : public sf::Drawable {
public:
	Character();
	~Character();

	void Move(float value);
	void SetTexture(std::string filename);

	// Setters
	void SetPosition(sf::Vector2f pos) { m_position = pos; };

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::string m_name;
	std::vector<sf::IntRect> m_frames;

	// Maybe create an Animation class containing an id and a vector of frames
	// and keep in Character a dico of animations ?

	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

};
