#include "Animation.h"

Animation::Animation() {
	m_currentFrame = 0;
}

Animation::~Animation() {

}

sf::IntRect Animation::GetNextFrame() {
	if (m_frames.size() == 0) {
		throw std::length_error("The frames vector is empty");
	}

	if (m_currentFrame >= m_frames.size())
		m_currentFrame = 0;

	return m_frames[m_currentFrame++];
}