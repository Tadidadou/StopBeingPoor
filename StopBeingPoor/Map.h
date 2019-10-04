#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Constants.h"

class Map {
public:
	Map();
	~Map();

	void Scroll(float position);
	void CreateMap();

	// Setters
	void SetGroundTexture(std::string filename);
	void SetPosition(float newPos) { this->position = newPos; }

	// Getters
	float GetPosition() { return this->position; }
	sf::Sprite GetGroundSprite() { return this->groundSprite; }

private:
	unsigned int size;
	float position;
	sf::Texture groundTexture;
	sf::Sprite groundSprite;

};