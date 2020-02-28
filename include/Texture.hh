#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace RK::Graphics{

	class Texture{
	private:
		int width = 0, height = 0;
	public:
		unsigned int id = 0;
		GLenum unit = GL_TEXTURE0;
		Texture(const char* filePath);
		void use();
		glm::ivec2 getTextureDimensions();
	};

}

