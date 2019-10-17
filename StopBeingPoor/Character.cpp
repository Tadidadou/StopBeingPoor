#include "Character.h"

Character::Character() {

}

Character::~Character() {

}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_sprite);
}

void Character::Move(float value) {
	// TODO: Animation

	m_position.x += value;
	m_sprite.setPosition(m_position);
}

void Character::SetTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;

	// Load the entire texture file
	if (!m_texture.loadFromFile(filename))
		std::cout << "Error loading texture file : " << filename << std::endl;

	// Set the texture (by default, initialize to idle state) and the position
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(14, 7, 19, 29));
	m_sprite.setPosition(m_position);
}