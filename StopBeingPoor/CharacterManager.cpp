#include "CharacterManager.h"

CharacterManager::CharacterManager() {
	m_characters = new std::map<std::string, Character>;
}

CharacterManager::~CharacterManager() {
	delete m_characters;
}

void CharacterManager::LoadDataFile(std::string filename) {
	// TODO : load file content
}

void CharacterManager::CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos) {
	Character new_character(name); // Create a generic character...

	// ... and specialise it depending on the character type param
	switch (characterType)
	{
	case NPC:
		new_character = Npc(name);
		break;
	case ALIVE:
		new_character = AliveCharacter(name);
		break;
	default:
		new_character = Character(name);
		break;
	}

	// Set texture, position and add to the characters list
	new_character.SetTexture(textureFilename);
	new_character.SetPosition(pos);
	m_characters->insert({ name, new_character });
}

void CharacterManager::CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos, std::map<std::string, Animation> animations) {
	CreateCharacter(textureFilename, name, characterType, pos);
	m_characters[name].SetAnimations(animations);
}

void CharacterManager::CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos, std::map<std::string, Animation> animations, CharacterStats stats) {
	CreateCharacter(textureFilename, name, characterType, pos);
	m_characters[name].SetAnimations(animations);
	//m_characters[name].SetStats(stats);
}

/*void CharacterManager::DrawCharacters(sf::RenderTarget& target) {
	for each (std::pair<std::string, Character* pair in m_characters)
		target.draw(pair.second);
}*/