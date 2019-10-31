#pragma once

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"
#include "Animation.h"

class Character : public sf::Drawable {
public:
	Character();
	Character(std::string name);
	~Character();

	void Move(float value);
	void SetTexture(std::string filename);

	// Setters
	void SetPosition(sf::Vector2f pos) { m_position = pos; };

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::string m_name;
	unsigned int m_orientation; // 0 (default) = right | 1 = left
	Animation runningAnimation; // Vector of animation or different animation objects ?
	/* Idea : One vector of animations (created in the constructor)
	One current animation and one next animation possibly empty 
	Once current is done, we play next if there is one or go back to idle */
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

};
