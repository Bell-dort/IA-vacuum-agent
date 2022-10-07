cmake_minimum_required(VERSION 3.13)
project(IA-vacuum-agent)
set(CMAKE_CXX_STANDARD 14)
add_executable(IA-vacuum-agent src/main.cpp src/Environment.cpp src/Square.cpp src/Display.cpp header/Includes.h src/VacuumAgent.cpp header/VacuumAgent.h src/Sensor.cpp header/Sensor.h src/Actuators.cpp header/Actuators.h src/State.cpp header/State.h header/Action.h src/Node.cpp header/Node.h src/GraphSearchStrategy.cpp header/GraphSearchStrategy.h)