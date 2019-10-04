#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

void Map::Scroll(float position) {

}

sf::Sprite Map::DrawMap(std::string fileName) {
	sf::Texture texture;
	fileName = TEXTURE_FILES_PREFIX + fileName;
	if (!texture.loadFromFile(fileName, sf::IntRect(10, 10, 50, 50))) {
		std::cout << "Map::DrawMap : Error loading texture file" + fileName << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	return sprite;
}