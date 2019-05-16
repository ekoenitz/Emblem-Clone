#include "UnitLoadAdaptor.hpp"
#include "Unit.hpp"

void UnitLoadAdaptor::loadUsingID(Unit& u, int id, bool isPlayer)
{
  u.name = "Bob";
  u.inventory.push_back(new Weapon(0));
  u.inventory[0]->use(u);

  u.xCor;
  u.yCor;
  u.moveType = 'X'; // H = horse, F = flying, X = On-foot
  u.movement = 5;

  u.level = 1;
  u.hp = 20;
  u.stats["hp"] = 20;
  u.stats["str"] = 10;
  u.stats["def"] = 10;
  u.stats["mag"] = 10;
  u.stats["res"] = 10;
  u.stats["skl"] = 10;
  u.stats["spd"] = 10;
  u.stats["luc"] = 10;

  u.growths["hp"] = 85;
  u.growths["str"] = 30;
  u.growths["def"] = 30;
  u.growths["mag"] = 30;
  u.growths["res"] = 30;
  u.growths["skl"] = 30;
  u.growths["spd"] = 30;
  u.growths["luc"] = 30;
}