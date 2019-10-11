#include "Map.h"

Map::Map() {
	m_size = MAP_SIZE_X;
}

Map::~Map() {

}

void Map::Scroll(float position) {
	// Set new position
	m_position = position;

	// Move the ground sprite to the current position
	m_groundSprite.setPosition(position, WINDOW_SIZE_Y - HEIGHT_OF_GROUND);

	// Move rest of the map
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_groundSprite, states);
}

void Map::CreateMap() {
	// TODO: Should automatically create all the elements of the map -> To be called by the constructor
}

// Setters
void Map::SetGroundTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;
	if (!m_groundTexture.loadFromFile(filename, sf::IntRect(0, 0, m_size, HEIGHT_OF_GROUND))) {
		std::cout << "Error loading texture file" + filename << std::endl;
	}

	// TODO in the same function ?
	m_groundSprite.setTexture(m_groundTexture);
	m_groundSprite.setPosition(m_position, WINDOW_SIZE_Y - HEIGHT_OF_GROUND);
}