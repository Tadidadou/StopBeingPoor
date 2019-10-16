#include "TileMap.h"

TileMap::TileMap() {

}

TileMap::~TileMap() {

}

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height, unsigned int offset_x, unsigned int offset_y) {
	// Loading tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// Redimension the vertex array to contain all level
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4); // x4 because there are 4 vertices per quad (and each corner has 4 vertices, one per adjacent quad)

	// Fill the vertex array with one quad per tile
	for (unsigned int i = 0; i < width; i++)
		for (unsigned int j = 0; j < height; j++) {
			// Get the current tile number
			int tileNum = tiles[i + j * width];

			// Deduce its position in the tileset texture
			int tu = tileNum % (m_tileset.getSize().x / tileSize.x); // WTF ?
			int tv = tileNum / (m_tileset.getSize().x / tileSize.x);

			// Get a pointer to the quad to be defined in the vertex array
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4]; // 4 vertices per quad

			// Define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x + offset_x, j * tileSize.y + offset_y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x + offset_x, j * tileSize.y + offset_y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x + offset_x, (j + 1) * tileSize.y + offset_y);
			quad[3].position = sf::Vector2f(i * tileSize.x + offset_x, (j + 1) * tileSize.y + offset_y);

			// Define its 4 texture coordinate
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform(); // Apply transform
	states.texture = &m_tileset; // Apply texture
	target.draw(m_vertices, states); // Draw vertex array
}