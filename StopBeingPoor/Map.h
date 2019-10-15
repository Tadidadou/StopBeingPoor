#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TileMap.h"
#include "Constants.h"

class Map : public sf::Drawable {
public:
	Map();
	~Map();

	void Scroll(float moveValue);
	void CreateMap();

	// Setters
	void SetGroundTexture(std::string filename);
	void SetPosition(float newPos) { m_position = newPos; }

	// Getters
	float GetPosition() { return m_position; }

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	unsigned int m_size;
	float m_position;

	// TODO: TileMap[] 
	TileMap m_groundTileMap;
	TileMap m_surfaceTileMap;
};