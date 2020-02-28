#pragma once

#include <fstream>

#include "Utility.hh"


char* RK::Graphics::readFile(const char* filePath, size_t* fileSize){
	char * buffer;
	std::ifstream file(filePath, std::ifstream::binary);
	if (file) {
		// get length of file:
		file.seekg(0, file.end);
		size_t length = file.tellg();
		file.seekg(0, file.beg);

		buffer = new char[length];
		// read data as a block:
		file.read(buffer, length);

		if (!file) {
			std::string errorMessage("[readFile] failed to read entire File. Could only read  ");
			errorMessage += file.gcount(); errorMessage += " bytes";
			throw errorMessage;
		}

		file.close();

		if(fileSize)
			*fileSize = length;
	}
	else {
		std::string errorMessage("[readFile] failed to open ");
		errorMessage += filePath;
		throw errorMessage;
	}
	return buffer;
}

std::string RK::Graphics::readTextFile(const char* filePath) {
	size_t fileSize;
	char* buffer = readFile(filePath, &fileSize);
	std::string text = std::string(buffer, fileSize);
	delete[] buffer;
	return text;
}