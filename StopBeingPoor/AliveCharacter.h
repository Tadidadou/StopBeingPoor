#pragma once

#include "Character.h"
#include "CharacterStats.h"

class AliveCharacter : public Character {
public:
	AliveCharacter(std::string name);
	~AliveCharacter();

private:
	CharacterStats stats;

};
