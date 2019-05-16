#include "Unit.hpp"
#include "PlayerUnit.hpp"
#include "Weapon.hpp"
#include "StatArray.hpp"

#include <iostream>
using namespace std;

int main()
{
  PlayerUnit p;
  Unit e;
  p.showStats();
  p.showCombatOdds(e);
  cout << endl << endl;
  p.levelUp();
  p.startCombat(e);
  p.showStats();
  cin.get();
}