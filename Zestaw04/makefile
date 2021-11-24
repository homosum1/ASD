
# kompilator
CXX = g++

#flagi
CXXFLAGS = -Wall -O0 -std=c++14 -pedantic

all: Generator.x ArrayList.x CursorList.x

Generator.x : Generator.cpp
	$(CXX) $(CXXFLAGS)  -o $@ $<

ArrayList.x : ArrayList.cpp ArrayList.hpp
	$(CXX) $(CXXFLAGS)  -o $@ $<

CursorList.x : CursorList.cpp ArrayList.hpp CursorList.hpp
	$(CXX) $(CXXFLAGS)  -o $@ $<
