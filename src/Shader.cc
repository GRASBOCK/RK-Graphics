#include "Shader.hh"
#include <string>
#include "Exception.hh"

using namespace RK::Graphics;

std::string Shader::shaderInfoLog(GLuint shader) {
	GLsizei infoLogLength;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, (GLint*)&infoLogLength);
	GLchar* infoLog = new GLchar[infoLogLength];
	glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
	return std::string(infoLog, infoLogLength);
}

std::string Shader::programInfoLog(GLuint program) {
	GLsizei infoLogLength;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, (GLint*)&infoLogLength);
	GLchar* infoLog = new GLchar[infoLogLength];
	glGetProgramInfoLog(program, infoLogLength, NULL, infoLog);
	return std::string(infoLog, infoLogLength);
}

GLuint Shader::compile(GLenum shaderType, const GLchar* source) {
	// shader
	GLuint id = glCreateShader(shaderType);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);
	// check for shader compile errors
	int success;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success) {
		std::string shaderTypeWord;
		switch(shaderType){
		case GL_VERTEX_SHADER:
			shaderTypeWord = "VertexShader";
			break;
		case GL_GEOMETRY_SHADER:
			shaderTypeWord = "GeometryShader";
			break;
		case GL_FRAGMENT_SHADER:
			shaderTypeWord = "FragmentShader";
			break;
		default:
			shaderTypeWord = "unknown";
		}
		throw Exception(std::string("[RK::Graphics::Shader::compile] failed to compile " + shaderTypeWord + ". ShaderInfoLog:\n") + shaderInfoLog(id));
	}
	return id;
}

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource, const char* geometryShaderSource) {
	//create vertex shader
	GLuint vertexShader = compile(GL_VERTEX_SHADER, vertexShaderSource);

	//create geometry shader
	GLuint geometryShader = 0;
	if (geometryShaderSource != nullptr) {
		geometryShader = compile(GL_GEOMETRY_SHADER, geometryShaderSource);
	}

	//create fragment shader
	GLuint fragmentShader = compile(GL_FRAGMENT_SHADER, fragmentShaderSource);

	// link shaders
	_program = glCreateProgram();
	glAttachShader(_program, vertexShader);
	if (geometryShaderSource != nullptr)
		glAttachShader(_program, geometryShader);
	glAttachShader(_program, fragmentShader);
	glLinkProgram(_program);

	// check for linking errors
	GLint success;
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success) {
		throw Exception(std::string("[RK::Graphics::Shader::Shader] failed to link shaders. ProgramInfoLog:\n") + programInfoLog(_program));
	}
	glDeleteShader(vertexShader);
	if (geometryShaderSource != nullptr)
		glDeleteShader(geometryShader);
	glDeleteShader(fragmentShader);
}

GLuint Shader::program(){
	return _program;
}