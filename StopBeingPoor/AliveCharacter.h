#pragma once

#include "Character.h"
#include "CharacterStats.h"

class AliveCharacter : public Character {
public:
	AliveCharacter();
	~AliveCharacter();

private:
	CharacterStats stats;

};
