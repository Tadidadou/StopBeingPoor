#include "Map.h"

Map::Map() {
	size = MAP_SIZE_X;
}

Map::~Map() {

}

void Map::Scroll(float position) {
	// Move the ground sprite to the current position
	groundSprite.setPosition(position, HEIGHT_OF_GROUND);

	// Move rest of the map
}

void Map::CreateMap() {
	// TODO: Should automatically draw all the elements of the map -> To be called by the constructor
}

// Setters
void Map::SetGroundTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;
	if (!this->groundTexture.loadFromFile(filename, sf::IntRect(0, 0, size, HEIGHT_OF_GROUND))) {
		std::cout << "Error loading texture file" + filename << std::endl;
	}

	// TODO in the same function ?
	this->groundSprite.setTexture(groundTexture);
	this->groundSprite.setPosition(position, HEIGHT_OF_GROUND);
}