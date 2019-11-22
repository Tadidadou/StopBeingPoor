#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "AliveCharacter.h"
#include "Npc.h"
#include "Animation.h"
#include "CharacterStats.h"

enum CharacterType
{
	NPC,
	ALIVE,
	GENERAL
};

// Class containing a vector of character entities and creates the animations of these entities from a data file
class CharacterManager {
public :
	CharacterManager();
	~CharacterManager();

	// Loads the file and stores the content inside data string
	void LoadDataFile(std::string filename); 
	// Create a character and add it to the list
	void CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos);
	void CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos, std::map<std::string, Animation> animations);
	void CreateCharacter(std::string name, std::string textureFilename, CharacterType characterType, sf::Vector2f pos, std::map<std::string, Animation> animations, CharacterStats stats);
	// TODO : Automatically create & init all characters from a data file

	// Calls the draw() function of each stored Character
	//void DrawCharacters(sf::RenderTarget& target);

	Character* GetCharacter(std::string name) { return m_characters[name]; }

private :

	std::string m_data;
	std::map<std::string, Character> *m_characters;

};
