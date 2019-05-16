#ifndef UOA_HPP
#define UOA_HPP

class Unit;

class UnitOutputAdaptor
{
public:
  UnitOutputAdaptor() {}
  void outputStats(const Unit& u) const;
  void outputCombatOdds(const Unit& attacker, const Unit& defender) const;
};

#endif
