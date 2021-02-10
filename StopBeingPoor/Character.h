#pragma once

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "Constants.h"
#include "Animation.h"
#include "Exceptions\NameNotFound.h"

class Character : public sf::Drawable {
public:
	Character();
	Character(std::string name);
	~Character();

	void Move(float value);

	// Setters
	void SetTexture(std::string filename);
	void SetPosition(sf::Vector2f pos) { m_position = pos; };
	void SetAnimationsSet(std::map<std::string, Animation*> animations) { m_animations = animations; };
	void SetAnimation(std::string name);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void CreateAnimations();

	std::string m_name;
	unsigned int m_orientation; // 0 (default) = right | 1 = left
	std::map<std::string, Animation*> m_animations; 
	Animation m_currentAnimation;
	std::string m_currentAnimationName;
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
