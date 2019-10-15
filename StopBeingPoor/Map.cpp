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
}

void Map::CreateMap() {
	// TODO: Should automatically create all the elements of the map -> To be called by the constructor
}

// Setters
void Map::SetGroundTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;

	const int surfaceTiles[] = 
	{
		47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47
	};

	if (!m_surfaceTileMap.load(filename, sf::Vector2u(TILE_SIZE, 8), surfaceTiles, 16, 1, 0, WINDOW_SIZE_Y - HEIGHT_OF_GROUND))
		std::cout << "Error loading texture file" + filename << std::endl;

	const int groundTiles[] =
	{
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13
	};

	if(!m_groundTileMap.load(filename, sf::Vector2u(TILE_SIZE, TILE_SIZE), groundTiles, 16, 8, 0, WINDOW_SIZE_Y - HEIGHT_OF_GROUND)) 
		std::cout << "Error loading texture file" + filename << std::endl;
}