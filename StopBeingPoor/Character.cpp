#include "Character.h"

Character::Character() {}

Character::Character(std::string name) {
	m_name = name;
	m_orientation = 0;

	CreateAnimations();
}

Character::~Character() {
}

void Character::Move(float value) {
	m_sprite.setTextureRect(m_currentAnimation.Play());
	m_position.x += value;
	m_sprite.setPosition(m_position);
}

void Character::SetTexture(std::string filename) {
	filename = TEXTURE_FILES_PREFIX + filename;

	// Load the entire texture file
	if (!m_texture.loadFromFile(filename))
		std::cout << "Error loading texture file : " << filename << std::endl;

	// Set the texture (by default, initialize to idle state) and the position
	m_currentAnimationName = "idle";
	m_currentAnimation = *m_animations[m_currentAnimationName];
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_currentAnimation.Play());
	m_sprite.setPosition(m_position);
}

void Character::SetAnimation(std::string name) {
	std::map<std::string, Animation*>::iterator it = m_animations.find(name); // Search name

	// Name not found
	if (it == m_animations.end()) 
		throw(NameNotFoundException("No animation named " + name + " in animation list of character named " + m_name + ". Cancel operation."));

	// Only apply change if new animation is different than current one
	if (name != m_currentAnimationName) {
		m_currentAnimationName = name;
		m_currentAnimation = *m_animations[m_currentAnimationName];
	}
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_sprite, states);
}

void Character::CreateAnimations() {
	//Create the animations set depending on the character's name
	if (m_name == "main") {
		std::vector<sf::IntRect> idleFrames{
			sf::IntRect(14, 7, 19, 29),
			sf::IntRect(66, 6, 19, 28),
			sf::IntRect(115, 6, 19, 28),
			sf::IntRect(163, 7, 21, 29)
		};
		Animation *idleAnimation = new Animation();
		idleAnimation->SetFrames(idleFrames);
		m_animations.insert(std::make_pair("idle", idleAnimation));

		std::vector<sf::IntRect> runningFrames{
			sf::IntRect(67, 45, 19, 28),
			sf::IntRect(116, 46, 20, 27),
			sf::IntRect(166, 48, 20, 25),
			sf::IntRect(217, 45, 22, 28),
			sf::IntRect(266, 46, 19, 27),
			sf::IntRect(316, 48, 20, 25)
		};
		Animation *runningAnimation = new Animation();
		runningAnimation->SetFrames(runningFrames);
		m_animations.insert(std::make_pair("running", runningAnimation));
	}
}