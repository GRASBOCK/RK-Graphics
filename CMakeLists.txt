cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(RK_Graphics)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Set an output directory for the binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
message("Will write binaries to ${BIN_DIR}")

#global setup. Some compiler flags that I think should always be used
if(MSVC)
	add_compile_options(/W3 /WX)
else()
	add_compile_options(-Wextra -Wall)
endif()

# Packages
find_package(glfw3 3.3 REQUIRED)
message(STATUS "Found GLFW3 in ${glfw3_INCLUDE_DIR}")
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
#C and C++
enable_language(CXX)

#declare module
set(sources src/Engine.cc src/read_File.cc src/Shader.cc src/glad/glad.c)
add_library(RK_Graphics ${sources})

#libs
target_link_libraries(RK_Graphics glfw OpenGL::GL dl)

#everyone who needs this module will need these headers
target_include_directories(RK_Graphics PUBLIC include)

#source directory that will be added privately
target_include_directories(RK_Graphics PRIVATE src)

#samples
add_subdirectory(samples)


