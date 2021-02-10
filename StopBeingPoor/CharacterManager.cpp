#include "CharacterManager.h"

CharacterManager::CharacterManager() {
	m_characters = std::map<std::string, Character*>();
}

CharacterManager::~CharacterManager() {
	//delete m_characters;
}

void CharacterManager::LoadDataFile(std::string filename) {
	// TODO : load file content
}

void CharacterManager::CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos) {
	//Character new_character(name); // Create a generic character...
	Character* new_character = new Character(name);

	// ... and specialise it depending on the character type param
	switch (characterType)
	{
	case NPC:
		*new_character = Npc(name);
		break;
	case ALIVE:
		*new_character = AliveCharacter(name);
		break;
	default:
		*new_character = Character(name);
		break;
	}

	// Set texture, position and add to the characters list
	new_character->SetTexture(textureFilename);
	new_character->SetPosition(pos);
	m_characters.insert({ name, new_character });
	m_charNames.push_back(name);
}

void CharacterManager::CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos, std::map<std::string, Animation*> animations) {
	CreateCharacter(textureFilename, name, characterType, pos);
	m_characters[name]->SetAnimationsSet(animations);
}

void CharacterManager::CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos, std::map<std::string, Animation*> animations, CharacterStats stats) {
	CreateCharacter(textureFilename, name, characterType, pos);
	m_characters[name]->SetAnimationsSet(animations);
	//m_characters[name]->SetStats(stats);
}

void CharacterManager::Move(float value) {
	for each (std::pair<std::string, Character*> pair in m_characters) {
		Character* character = pair.second;
		character->Move(value);
	}
}

void CharacterManager::SetCharacterAnimation(std::string char_name, std::string anim_name) {
	try {
		m_characters[char_name]->SetAnimation(anim_name);
	}
	catch (NameNotFoundException e) {
		std::cout << e.what() << std::endl;
	}
}

void CharacterManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for each (std::pair<std::string, Character*> pair in m_characters) {
		Character* character = pair.second;
		target.draw(*character);
	}
}