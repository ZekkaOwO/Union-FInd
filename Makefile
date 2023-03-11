CXX = g++
CXXFLAGS = -Wall

demo: demo.cpp
	$(CXX) $(CXXFLAGS) -o UnionFind demo.cpp

clean:
	-rm UnionFind