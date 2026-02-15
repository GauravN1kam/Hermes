cmake_minimum_required(VERSION 4.0.1)
project(Hermes VERSION 1.0.0 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
   	Hermes 
		src/json_parser.cpp
		src/server.cpp
    src/hermes.cpp
)

