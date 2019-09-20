#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Map {
public:
	Map();
	~Map();

	void Scroll(float position);
	sf::Sprite DrawMap(std::string fileName);

private:
	unsigned int size;
	float position;

};