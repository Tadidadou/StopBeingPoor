#pragma once

class Map {
public:
	Map();
	~Map();

	void Scroll(float position);

private:
	unsigned int size;
	float position;

};