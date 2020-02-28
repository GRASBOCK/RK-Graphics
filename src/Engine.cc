#include <iostream>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "Engine.hh"
#include "Exception.hh"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

RK::Graphics::Engine::Engine(){
    // Initialize the library
    if (!glfwInit())
        throw Exception("Failed to initialise GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif

    //Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw Exception("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //initialise glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw Exception("Failed to initialise GLAD");
    }

    //basic background color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);    

    
}

RK::Graphics::Engine::~Engine(){
    glfwDestroyWindow(window);

    glfwTerminate();
}

void RK::Graphics::Engine::update(){
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}