#include "Weapon.hpp"
#include "Unit.hpp"

#include <string>
using namespace std;

void Weapon::initUsingID(int id)
{
  name = "Iron Sword";
  description = "A basic sword.  High accuracy, low power.";
  type = 'S';
  power = 3;
  range = 1;
  accuracy = 90;
  evasionPenalty = 0;
  critRate = 0;
}

void Weapon::use(Unit& user)
{
  user.equippedWeapon = this;
}