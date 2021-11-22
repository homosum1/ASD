
# kompilator
CXX = g++

#flagi
CXXFLAGS = -Wall -O0 -std=c++14 -pedantic

all: Generator.x ArrayList.x

Generator.x : Generator.cpp
	$(CXX) $(CXXFLAGS)  -o $@ $<

LinkedList.x : ArrayList.cpp ArrayList.hpp
	$(CXX) $(CXXFLAGS)  -o $@ $<
