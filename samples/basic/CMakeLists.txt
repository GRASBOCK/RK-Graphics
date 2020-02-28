cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(RK_Graphics_Basic)

#global setup. Some compiler flags that I think should always be used
if(MSVC)
	add_compile_options(/W3 /WX)
else()
	add_compile_options(-W -Wall)
endif()

#C and C++
enable_language(CXX)

#files
set(sources "basic.cc")
add_executable(basic ${sources})

#libs
target_link_libraries(basic RK_Graphics)

#install to folder
install(TARGETS basic RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
