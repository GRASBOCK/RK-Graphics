#pragma once

#include <exception>
#include <string>

namespace RK::Graphics{
	
class Exception : public std::exception
{
	std::string _msg;

	public: 
	Exception(std::string message) : _msg(message){};

	virtual const char* what() const throw(){
		return _msg.c_str();
	}
};

}

