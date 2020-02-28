cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(RK_Graphics_Quads)

#global setup. Some compiler flags that I think should always be used
if(MSVC)
	add_compile_options(/W3 /WX)
else()
	add_compile_options(-W -Wall)
endif()

#C and C++
enable_language(CXX)

#files
set(sources "quads.cc")
add_executable(quads ${sources})

#libs
target_link_libraries(quads RK_Graphics)

#install to folder
install(TARGETS quads RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
