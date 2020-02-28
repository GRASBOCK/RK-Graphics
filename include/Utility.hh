#pragma once

#include <string>
namespace RK::Graphics {

	char* readFile(const char* filePath, size_t* fileSize = nullptr);
	//returns the text read in the textfile
	std::string readTextFile(const char* filePath);
}