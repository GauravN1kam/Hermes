
# Compiler and flags
CXX = g++
CXXFLAGS = -I./include -Wall -Wextra -std=c++17

# Targets and dependencies
all: hermes

hermes: ./src/server.o ./src/hermes.o
	$(CXX) $^ -o $@

./src/server.o: ./src/server.cpp ./include/server.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

./src/hermes.o: ./src/hermes.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f ./src/*.o hermes

