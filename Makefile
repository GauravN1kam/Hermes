# Compiler and flags
CXX = cl
CXXFLAGS = -I./include -Wall -Wextra -std=c++17

# Targets and dependencies
all: hermes

hermes: ./src/server.obj ./src/hermes.obj
	$(CXX) $^ -o $@

./src/server.o: ./src/server.cpp ./include/server.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

./src/hermes.o: ./src/hermes.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f ./src/*.o hermes

