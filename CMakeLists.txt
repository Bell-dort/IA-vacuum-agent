cmake_minimum_required(VERSION 3.13)
project(IA-vacuum-agent)
set(CMAKE_CXX_STANDARD 14)
add_executable(IA-vacuum-agent src/main.cpp src/Environnement.cpp src/Square.cpp src/Display.cpp header/Includes.h src/vacuumAgent.cpp header/vacuumAgent.h)