#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TileMap : public sf::Drawable, public sf::Transformable
{
public :
	TileMap();
	~TileMap();

	// TODO: Optimisation : overload to pass directly a texture, which will prevent to load the same file several times
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, unsigned int offset_x, unsigned int offset_y);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

};
