#pragma once
#include <iostream>
#include <exception>

class NameNotFoundException : public std::exception {
public:
	NameNotFoundException(const std::string msg) {
		m_msg = msg;
	}

	virtual const char* what() const throw() {
		return m_msg.c_str();
	}

protected:
	std::string m_msg;
};