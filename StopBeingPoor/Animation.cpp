#include "Animation.h"

Animation::Animation() {
	m_currentFrame = 0;

	m_updateTime = 1.0f / ANIMATION_SPEED;
	m_timeSinceLastFrame = 0.0f;
	m_firstCall = true;
}

Animation::~Animation() {

}

sf::IntRect Animation::Play() {
	if (m_frames.size() == 0) {
		throw std::length_error("The frames vector is empty");
	}

	// Advance time and add the elapsed time to timeSinceLastFrame
	m_currentTimestamp = std::clock();// / CLOCKS_PER_SEC;

	// Ignore elapsed time if first call
	if (m_firstCall) {
		m_timeSinceLastFrame = 0.0f;
		m_lastCallTimestamp = m_currentTimestamp;
		m_firstCall = false; // Not first call anymore
	}
	else {
		m_timeSinceLastFrame += (m_currentTimestamp - m_lastCallTimestamp) / CLOCKS_PER_SEC;
		m_lastCallTimestamp = m_currentTimestamp;
	}

	// Next frame
	if (m_timeSinceLastFrame >= m_updateTime) {
		m_currentFrame++;
		m_timeSinceLastFrame = 0; 

		// Check animation end
		if (m_currentFrame >= m_frames.size()) {
			m_currentFrame = 0; // Reset frame progression
			m_firstCall = true; // Next passage will be the first call of a new animation

			/* TODO : return something to alert the end of the animation
			(like a specific rectint or set a variable to true and get it on the other side, I don't fucking care) */
		}
	}

	return m_frames[m_currentFrame];
}