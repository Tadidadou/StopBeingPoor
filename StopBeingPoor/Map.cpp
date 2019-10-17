#include "Map.h"

Map::Map() {
	m_size = MAP_SIZE_X;
}

Map::~Map() {

}

void Map::Scroll(float moveValue) {
	// Set new position
	m_position += moveValue;


}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_groundTileMap, states);
	target.draw(m_surfaceTileMap, states);
	target.draw(m_backgroundSprite, states);
}

void Map::CreateMap() {
	// TODO: Should automatically create all the elements of the map -> To be called by the constructor
}

// Setters
void Map::SetBackgroundTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;

	if(!m_backgroundTexture.loadFromFile(filename))
		std::cout << "Error loading texture file : " << filename << std::endl;

	m_backgroundSprite.setPosition(0, 0);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	float scaleX = (float) WINDOW_SIZE_X / m_backgroundTexture.getSize().x;
	float scaleY = (float) (WINDOW_SIZE_Y - HEIGHT_OF_GROUND) / m_backgroundTexture.getSize().y;
	m_backgroundSprite.setScale(scaleX, scaleY);
}

void Map::SetGroundTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;

	// Create en fill the tiles tab for the surface
	const int surfSize = MAP_SIZE_X / TILE_SIZE;
	int surfaceTiles[surfSize];
	for (int i = 0; i < surfSize; i++)
		surfaceTiles[i] = 47;

	// Load the corresponding texture
	if (!m_surfaceTileMap.load(filename, sf::Vector2u(TILE_SIZE, TILE_SIZE / 2), surfaceTiles, MAP_SIZE_X / TILE_SIZE, 1, 0, WINDOW_SIZE_Y - HEIGHT_OF_GROUND))
		std::cout << "Error loading texture file : " << filename << std::endl;

	// Create and fill the tiles tab for the ground
	const int groundSize = (MAP_SIZE_X / TILE_SIZE) * ((HEIGHT_OF_GROUND / TILE_SIZE) + 1);
	int groundTiles[groundSize];
	for (int i = 0; i < groundSize; i++)
		groundTiles[i] = 3;

	// Load the corersponding texture
	if(!m_groundTileMap.load(filename, sf::Vector2u(TILE_SIZE, TILE_SIZE), groundTiles, MAP_SIZE_X / TILE_SIZE, (HEIGHT_OF_GROUND / TILE_SIZE) + 1, 0, WINDOW_SIZE_Y - HEIGHT_OF_GROUND)) 
		std::cout << "Error loading texture file" + filename << std::endl;
}