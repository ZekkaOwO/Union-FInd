/**
 * Main function and examples.
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#include <iostream>
#include <vector>

#include "Graph.h"
using namespace std;

class Student {
  friend ostream &operator<<(ostream &strm, const Student &stud) {
    return strm << "student(" << stud.id << ", " << stud.name << ")";
  }
  friend bool operator==(const Student &lhs, const Student &rhs) {
    return lhs.id == rhs.id;
  }
  friend bool operator!=(const Student &lhs, const Student &rhs) {
    return !(lhs == rhs);
  }

 public:
  Student() = default;
  Student(int id, string name) : id(id), name(name) {}

 private:
  int id;
  string name;
};

class Car {
  friend ostream &operator<<(ostream &strm, const Car &car) {
    return strm << "Car(" << car.id << ", " << car.brand << ")";
  }
  friend bool operator==(const Car &lhs, const Car &rhs) {
    return lhs.id == rhs.id;
  }
  friend bool operator!=(const Car &lhs, const Car &rhs) {
    return !(lhs == rhs);
  }

 public:
  Car() = default;
  Car(int id, string brand) : id(id), brand(brand) {}

 private:
  int id;
  string brand;
};

int main() {
  Student marc(0, "Marc");
  Student kyle(1, "Kyle");
  Student hemant(2, "Hemant");
  Student shanmathi(3, "Shanmathi");
  Student kate(4, "Kate");

  vector<Student> vertices{marc, kyle, hemant, shanmathi, kate};
  vector<Edge<Student>> edges{
      {marc, kyle}, {marc, hemant}, {kyle, shanmathi}, {kyle, kate}};
  Graph<Student> graph(vertices, edges);
  // No cycle
  if (graph.containsCycle())
    cout << "The graph contains a cycle" << endl;
  else
    cout << "The graph does not contain a cycle" << endl;

  cout << "Adding an edge to the current graph" << endl;
  graph.addEdge({hemant, shanmathi});

  // cycle
  if (graph.containsCycle())
    cout << "The graph contains a cycle" << endl;
  else
    cout << "The graph does not contain a cycle" << endl;

  // Two additional examples
  Car bwm(0, "BWM");
  Car audi(1, "Audi");
  Car benz(2, "Benz");
  Car maserati(3, "Maserati");
  Car jeep(4, "Jeep");
  Car porsche(5, "Porsche");
  Car lexus(6, "Lexus");
  Car lincoln(7, "Lincoln");
  Car tesla(8, "Tesla");
  Car rollsRoyce(9, "Rolls-Royce");
  Car ferrari(10, "Ferrari");
  Car rover(11, "Land Rover");
  Car astonMartin(12, "Aston Martin");
  Car maybach(13, "Maybach");
  Car cadillac(14, "Cadillac");

  // Example 1 (Cycle of 5 nodes)
  vector<Car> cars1{bwm, audi, benz, maserati, jeep};
  vector<Edge<Car>> carEdges1{{bwm, audi},
                              {bwm, benz},
                              {audi, maserati},
                              {audi, jeep},
                              {benz, maserati}};
  Graph<Car> carGraph1(cars1, carEdges1);

  // Example 2 (full binary tree of height 3)
  vector<Car> cars2{bwm,     audi,  benz,        maserati, jeep,
                    porsche, lexus, lincoln,     tesla,    rollsRoyce,
                    ferrari, rover, astonMartin, maybach,  cadillac};
  vector<Edge<Car>> carEdges2{
      {bwm, audi},         {bwm, benz},       {audi, maserati},
      {audi, jeep},        {benz, porsche},   {benz, lexus},
      {maserati, lincoln}, {maserati, tesla}, {jeep, rollsRoyce},
      {jeep, ferrari},     {porsche, rover},  {porsche, astonMartin},
      {lexus, maybach},    {lexus, cadillac}};
  Graph<Car> carGraph2(cars2, carEdges2);

  // cycle
  if (carGraph1.containsCycle())
    cout << "Car graph 1 contains a cycle" << endl;
  else
    cout << "Car graph 1 does not contain a cycle" << endl;

  // Full binary tree of height 3
  if (carGraph2.containsCycle())
    cout << "Car graph 2 contains a cycle" << endl;
  else
    cout << "Car graph 2 does not contain a cycle" << endl;
}