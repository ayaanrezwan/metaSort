CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: sort

sort: main.cpp
	$(CXX) $(CXXFLAGS) -o sort main.cpp

clean:
	rm -f sort