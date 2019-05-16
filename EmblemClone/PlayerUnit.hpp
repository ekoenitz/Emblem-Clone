#ifndef PUNIT_HPP
#define PUNIT_HPP

#include "Unit.hpp"
#include "UnitLoadAdaptor.hpp"

class PlayerUnit : public Unit
{
public:
  PlayerUnit(int idNum = 0): Unit(idNum, true) {}

  friend class UnitLoadInterface;
protected:
  int exp;
};

#endif
