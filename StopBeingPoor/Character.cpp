#include "Character.h"

Character::Character() {}

Character::Character(std::string name) {
	m_name = name;
	m_orientation = 0;

	runningAnimation = Animation();
}

Character::~Character() {
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_sprite, states);
}

void Character::Move(float value) {
	// TODO: Animation
	m_sprite.setTextureRect(runningAnimation.Play());
	m_position.x += value;
	m_sprite.setPosition(m_position);
}

void Character::SetTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;

	// Load the entire texture file
	if (!m_texture.loadFromFile(filename))
		std::cout << "Error loading texture file : " << filename << std::endl;

	// Set the texture (by default, initialize to idle state) and the position
	std::vector<sf::IntRect> runningFrames{
		sf::IntRect(67, 45, 19, 28),
		sf::IntRect(116, 46, 20, 27),
		sf::IntRect(166, 48, 20, 25),
		sf::IntRect(217, 45, 22, 28),
		sf::IntRect(266, 46, 19, 27),
		sf::IntRect(316, 48, 20, 25)
	};

	runningAnimation.SetFrames(runningFrames);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(runningAnimation.Play());
	m_sprite.setPosition(m_position);
}