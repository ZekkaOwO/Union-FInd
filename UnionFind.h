/**
 * Class if  UnionFind structure.
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

#include "SetUF.h"

template <typename T>
class UnionFind {
 private:
  std::vector<SetUF<T>> sets;

  /**
   * Helper methods that transfer T to SetUF<T>
   * to be put into sets.
   **/
  std::vector<SetUF<T>> change(std::vector<T> v) {
    std::vector<SetUF<T>> s;
    for (size_t i = 0; i < v.size(); ++i) {
      SetUF<T> temp = SetUF<T>(v.at(i));
      s.push_back(temp);
    }

    return s;
  };

 public:
  UnionFind(const std::vector<T> &singletons);
  ~UnionFind();

  SetUF<T> &find(T node);

  void unionOp(SetUF<T> &, SetUF<T> &);
  void unionOp(T, SetUF<T> &);
  void unionOp(SetUF<T> &, T);
  void unionOp(T, T);
};

/**
 * Constructor that set sets to singletons.
 **/
template <typename T>
UnionFind<T>::UnionFind(const std::vector<T> &singletons)
    : sets(change(singletons)){};

template <typename T>
UnionFind<T>::~UnionFind() {}

/**
 * Function that traverse to the root and return the root
 * of the node, and set the parent of each traversed node to root.
 **/
template <typename T>
SetUF<T> &UnionFind<T>::find(T node) {
  int num = 0;
  for (size_t i = 0; i < this->sets.size(); ++i) {
    if (this->sets.at(i).value == node) {
      num = i;
      break;
    }
  }

  SetUF<T> *root;
  root = &(this->sets.at(num));
  SetUF<T> &temp = this->sets.at(num);

  while (root->parent != root) {
    root = root->parent;
  }

  while (temp.parent != root) {
    SetUF<T> *p = temp.parent;
    temp.parent = root;
    temp = *p;
  }

  return *root;
}

/**
 * Union x and y.
 **/
template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, SetUF<T> &y) {
  SetUF<T> &xRoot = find(x.value);
  SetUF<T> &yRoot = find(y.value);

  if (xRoot == yRoot) {
    return;
  }

  if (xRoot.rank < yRoot.rank) {
    SetUF<T> temp = xRoot;
    xRoot = yRoot;
    yRoot = temp;
  }

  yRoot.parent = &xRoot;
  if (xRoot.rank == yRoot.rank) {
    xRoot.rank = xRoot.rank + 1;
  }
}

/**
 * Union x and y.
 **/
template <typename T>
void UnionFind<T>::unionOp(T x, SetUF<T> &y) {
  SetUF<T> xSet = SetUF<T>(x);
  unionOp(xSet, y);
}

/**
 * Union x and y.
 **/
template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, T y) {
  SetUF<T> ySet = SetUF<T>(y);
  unionOp(x, ySet);
}

/**
 * Union x and y.
 **/
template <typename T>
void UnionFind<T>::unionOp(T x, T y) {
  SetUF<T> xSet = SetUF<T>(x);
  SetUF<T> ySet = SetUF<T>(y);
  unionOp(xSet, ySet);
}

#endif