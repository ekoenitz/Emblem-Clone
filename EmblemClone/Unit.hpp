#ifndef UNIT_HPP
#define UNIT_HPP

#include <string>
#include <vector>
#include "Item.hpp"
#include "StatArray.hpp"
#include "Weapon.hpp"
#include "UnitLoadAdaptor.hpp"
#include "UnitOutputAdaptor.hpp"
using namespace std;

//class UnitLoadAdaptor;
//class UnitOutputAdaptor;

class Unit
{
public:
  Unit(int id = 0, bool isPlayer = true) : id(0) { loader.loadUsingID(*this, id, isPlayer); }
  ~Unit() { for (Item* i : inventory) { delete i; }  }

  void applyDamage(int damage);
  void levelUp();
  void showCombatOdds(Unit& target) const;
  void showStats() const;
  void startCombat(Unit& opponent);

  friend class UnitLoadAdaptor;
  friend class UnitOutputAdaptor;
  friend class Weapon;
protected:
  void attack(Unit& target);
  int calcAccuracy() const;
  int calcDamage(const Unit& target) const;
  int calcEvasion() const;
  int calcHitRate(const Unit& target) const;
  bool hitTarget(Unit& target) const;

  UnitLoadAdaptor loader;
  UnitOutputAdaptor outputter;
  static const int INV_LIMIT = 3;
  const int id;

  string name;
  vector<Item*> inventory;
  Weapon* equippedWeapon;

  int xCor;
  int yCor;
  char moveType; // H = horse, F = flying, X = On-foot
  int movement;

  int level;
  int hp;
  StatArray stats;
  StatArray growths;
};

#endif