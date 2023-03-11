# <center> Union Find </center>

## Description

This is a program that contains a Union Find data structure, which can be used to test if there are cycles in graphs.

## Class

There are three class in the program: <br/><br/>
***SetUF***: Serves as the element (node) in UnionFind. It has a generic value, a numbe called rank and a pointer to its parent as its private member variables.<br/><br/>
***UnionFind***: A Union Find data structure. It has a vector called sets which contains SetUF<T> as its pirvate member variables, and is friend with SetUF.<br/><br/>
***Graph***: A graph data structure.<br/><br/>


## Functions 

### Class SetUF

***SetUF(T v)***: A Parametrized constructor, which set the value of the SetUF to v, rank to 0 and parent to itself.<br/><br/>
***SetUF(const SetUF &a)***: A copy constructor, which set the value of the SetUF to value of a, rank to 0 and parent to itself.<br/><br/>
***SetUF& operator=(const SetUF &a)***: Overloaded assignment operator.<br/><br/>

### Class UnionFind

***UnionFind(const std::vector<T> &singletons)***: A Parametrized constructor, which set the variable *sets* to singletons.<br/><br/>
***SetUF<T>& find(T node)***: Traverse to the root and return the root of the node, and set the parent of each traversed node to root.<br/><br/>
***UnionFind(const std::vector<T> &singletons)***: A Parametrized constructor, which set the variable *sets* to singletons.<br/><br/>
***void unionOp(SetUF<T> &x, SetUF<T> &y)***: Union x and y.<br/>
***void unionOp(T x, SetUF<T> &y)***: Union x and y.<br/>
***void unionOp(SetUF<T> &x, T y)***: Union x and y.<br/>
***void unionOp(T x, T y)***: Union x and y.<br/>


### Class Graph

***Graph(std::vector<T> v, std::vector<Edge> e)***: A Parametrized constructor, which set the variable *vertices* to v and *edges* to e.<br/><br/>
***void addEdge(Edge e)***: Add a new edge to *edges*.<br/><br/>
***bool containsCycle()***: Return true if the graph contains a cycle, otherwise false.<br/><br/>

### demo.cpp

Main function that contains examples.


## Compile

Using the command ***make*** to compile, and ***make clean*** to
delete the executable file.

## How to run it

After compling, there will be a file named ***"UnionFind"***. Once it comes up, 
using ***./UnionFind*** to run it.

