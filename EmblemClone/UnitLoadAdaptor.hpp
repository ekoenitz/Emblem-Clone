#ifndef ULA_HPP
#define ULA_HPP

class Unit;

class UnitLoadAdaptor
{
public:
  UnitLoadAdaptor() {}
  void loadUsingID(Unit& u, int id = 0, bool isPlayer = true);
};

#endif
