#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include "Item.hpp"
using namespace std;

class Unit;

class Weapon : public Item
{
public:
  Weapon() {}
  Weapon(int idNum) : Item(idNum) { initUsingID(id); }
  void initUsingID(int id);
  void use(Unit& user);

  friend class Unit;
protected:
  char type; //S = Slashing, P = Piercing, B = Bludgeoning, M = stats["mag"]
  int power;
  int range;
  int accuracy;
  int evasionPenalty;
  int critRate;
};

#endif
