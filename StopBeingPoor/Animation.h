#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <stdexcept>

class Animation {
public:
	Animation();
	~Animation();

	void SetFrames(std::vector<sf::IntRect> frames) { m_frames = frames; }
	sf::IntRect GetNextFrame();

private:
	std::vector<sf::IntRect> m_frames;
	unsigned int m_currentFrame;

};
