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
	sf::Sprite DrawMap(std::string fileName);

private:
	unsigned int size;
	float position;
	/*sf::Texture groundTexture;
	sf::Sprite */

};