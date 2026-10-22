cmake_minimum_required(VERSION 3.16)

project(Stacki_compiler LANGUAGES CXX C)

add_executable(Stacki_compiler src/main.cpp src/lexer.cpp)

install(TARGETS Stacki_compiler RUNTIME DESTINATION bin)
