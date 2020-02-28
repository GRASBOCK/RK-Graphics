#pragma once

// OpenGL headers
#include <glad/glad.h>

#include "Utility.hh"

namespace RK::Graphics {

class Shader{
private:
	//compile an individual shader by source code
	GLuint compile(GLenum shaderType, const GLchar* source);

	GLuint _program = 0;
public:
	//take a vertex and fragment shader file path to do the complete shader creation process
	Shader(
		const char* vertexShaderSource, 
		const char* fragmentShaderSource, 
		const char* geometryShaderSource = nullptr
	);
	GLuint program();
	//mostly needed for errorchecking
	std::string shaderInfoLog(GLuint shader);
	std::string programInfoLog(GLuint program);
	
};



}


