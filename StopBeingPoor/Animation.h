#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <ctime>
#include "Constants.h"

class Animation {
public:
	Animation();
	~Animation();

	void SetFrames(std::vector<sf::IntRect> frames) { m_frames = frames; }
	sf::IntRect Play();

private:
	std::vector<sf::IntRect> m_frames;
	unsigned int m_currentFrame;
	float m_updateTime;
	float m_timeSinceLastFrame;
	float m_lastCallTimestamp;
	float m_currentTimestamp;
	bool m_firstCall;
};
