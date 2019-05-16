#include "Unit.hpp"
#include "UnitOutputAdaptor.hpp"

#include <cstdlib>
using namespace std;

/******************************
      Public Functions
*******************************/
void Unit::applyDamage(int damage)
{
  hp -= damage;
  if (hp < 0)
  {
    hp = 0;
  }
}

void Unit::levelUp()
{
  // In retrospect, stats and growths should've been stored 
  // in an array that could be indexed with strings...
  int statRoll = rand() % 100;
  if (statRoll <= growths["hp"])
  {
    stats["hp"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["str"])
  {
    stats["str"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["def"])
  {
    stats["def"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["mag"])
  {
    stats["mag"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["res"])
  {
    stats["res"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["skl"])
  {
    stats["skl"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["spd"])
  {
    stats["spd"]++;
  }

  statRoll = rand() % 100;
  if (statRoll <= growths["luc"])
  {
    stats["luc"]++;
  }
}

void Unit::showCombatOdds(Unit& target) const
{
  outputter.outputCombatOdds(*this, target);
}

void Unit::showStats() const
{
  outputter.outputStats(*this);
}

void Unit::startCombat(Unit& opponent)
{
  attack(opponent);
  opponent.attack(*this);
  if (stats["spd"] - 5 >= opponent.stats["spd"])
  {
    attack(opponent);
  }
  else if (opponent.stats["spd"] - 5 >= stats["spd"])
  {
    opponent.attack(*this);
  }
}

/******************************
      Protected Functions
*******************************/
void Unit::attack(Unit& target)
{
  if (hitTarget(target))
  {
    target.applyDamage(calcDamage(target));
  }
}

int Unit::calcAccuracy() const
{
  return equippedWeapon->accuracy + stats["skl"] * 3 + stats["luc"];
}

int Unit::calcDamage(const Unit& target) const
{
  if (equippedWeapon->type == 'M')
  {
    return stats["mag"] + equippedWeapon->power - target.stats["res"];
  }
  else
  {
    return stats["str"] + equippedWeapon->power - target.stats["def"];
  }
}

int Unit::calcEvasion() const
{
  return stats["spd"] * 3 + stats["luc"] - equippedWeapon->evasionPenalty;
}

int Unit::calcHitRate(const Unit& target) const
{
  return calcAccuracy() - target.calcEvasion();
}

bool Unit::hitTarget(Unit& target) const
{
  int hitRate = calcHitRate(target);
  // Weapon triangle calculation here
  int attackRoll = rand() % 100 + rand() % 100;
  attackRoll /= 2;

  if (attackRoll <= hitRate)
  {
    return true;
  }
  else
  {
    return false;
  }
}