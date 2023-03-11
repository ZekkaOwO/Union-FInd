/**
 * Class of SetUF, which serves
 * as nodes in UnionFind structure.
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#ifndef SETUF_H
#define SETUF_H

#include <iostream>

template <typename T>
class UnionFind;

template <typename T>
class SetUF {
  friend class UnionFind<T>;

 private:
  T value;
  unsigned rank;
  SetUF *parent;  // a pointer to its parent

 public:
  SetUF(T v) : value(v), rank(0), parent(this) {}
  SetUF(const SetUF &a) : value(a.value), rank(0), parent(this) {}
  SetUF &operator=(const SetUF &a);
  ~SetUF();

  operator T() const { return value; }
};

/**
 *  Overloaed assignment operator.
 **/
template <typename T>
SetUF<T> &SetUF<T>::operator=(const SetUF &a) {
  if (this != &a) {
    this->value = a.value;
    this->rank = 0;
    this->parent = this;
  }
  return *this;
}

template <typename T>
SetUF<T>::~SetUF() {}

#endif