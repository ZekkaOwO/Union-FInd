/**
 * Class of graph.
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <utility>
#include <vector>

#include "UnionFind.h"

template <typename T>
using Edge = std::pair<T, T>;

template <typename T>
class Graph {
  using Edge = std::pair<T, T>;

 private:
  std::vector<T> vertices;  // vertices of graph
  std::vector<Edge> edges;  // edges of graph

 public:
  Graph(std::vector<T> v, std::vector<Edge> e) : vertices(v), edges(e) {}
  // Function that add a new edge to the graph.
  void addEdge(Edge e) { edges.push_back(e); };
  bool containsCycle();
};

/**
 * Function that check if the graph contains a cycle.
 * If the roots of the two vertices in the edge are the same,
 * that means there is a cycle, and the function will return true.
 * Otherwise return false.
 **/
template <typename T>
bool Graph<T>::containsCycle() {
  UnionFind<T> uFind(vertices);
  for (Edge &e : edges) {
    SetUF<T> &xRoot = uFind.find(e.first);
    SetUF<T> &yRoot = uFind.find(e.second);
    if (xRoot == yRoot) return true;
    uFind.unionOp(xRoot, yRoot);
  }
  return false;
}

#endif