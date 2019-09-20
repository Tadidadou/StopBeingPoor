#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

void Map::Scroll(float position) {

}

sf::Sprite Map::DrawMap(std::string fileName) {
	sf::Texture map;
	if (!map.loadFromFile(fileName, sf::IntRect(10, 10, 600, 600))) {
		std::cout << "Map::DrawMap : Error loading texture file" + fileName << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(map);

	return sprite;
}