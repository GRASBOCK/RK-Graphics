#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

namespace RK::Graphics{
	class Engine{
	public:
		Engine();
		~Engine();
		void update();
		GLFWwindow* window;
	private:
		
	};
}