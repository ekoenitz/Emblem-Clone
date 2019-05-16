#include "UnitOutputAdaptor.hpp"
#include "Unit.hpp"

#include <iostream>
using namespace std;

void UnitOutputAdaptor::outputStats(const Unit& u) const
{
  cout << "HP: " << u.hp << '/' << u.stats["hp"] << endl;
  cout << "Str: " << u.stats["str"] << endl;
  cout << "Def: " << u.stats["def"] << endl;
  cout << "Mag: " << u.stats["mag"] << endl;
  cout << "Res: " << u.stats["res"] << endl;
  cout << "Skl: " << u.stats["skl"] << endl;
  cout << "Spd: " << u.stats["spd"] << endl;
  cout << "Luc: " << u.stats["luck"] << endl;
}

void UnitOutputAdaptor::outputCombatOdds(const Unit& attacker, const Unit& defender) const
{
  cout << "     " << attacker.name << " vs. " << defender.name << endl;
  cout << "Hit: " << attacker.calcHitRate(defender) << ' ' << defender.calcHitRate(attacker) << endl;
  cout << "Dmg: " << attacker.calcDamage(defender) << ' ' << defender.calcDamage(attacker) << endl;
}