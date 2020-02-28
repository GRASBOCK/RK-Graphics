#include "Texture.hh"

#include "Exception.hh"

//popular image loader
#ifndef STB_IMAGE_IMPLEMENTATION
	#define STB_IMAGE_IMPLEMENTATION
	#include "stb_image.h"
#endif

using namespace RK::Graphics;

Texture::Texture(const char* filePath){
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int nrChannels;
	stbi_set_flip_vertically_on_load(1);
	unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);
	if(data){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}else{
		throw Exception(std::string("[RK::Graphics::Texture::Texture] Failed to load texture \'") + filePath + '\'');
	}stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
	unit = GL_TEXTURE0;
}

void Texture::use(){
	if(unit >= GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS){
		throw Exception(std::string("[RK::Graphics::Texture::use]Texture unit ") + std::to_string(unit) + " is too large. Max = " + std::to_string(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS));
	}
	glBindTexture(GL_TEXTURE_2D, id);
}

glm::ivec2 Texture::getTextureDimensions(){
	return glm::ivec2(width, height);
}