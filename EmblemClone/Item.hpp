#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;

class Unit;

class Item
{
public:
  Item(): id(0) {}
  Item(int idNum): id(idNum) {}
  virtual void use(Unit& user) {};

  friend class Unit;
protected:
  const int id;
  string name;
  string description;
};

#endif