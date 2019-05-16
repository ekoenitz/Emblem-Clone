#ifndef STATARRAY_HPP
#define STATARRAY_HPP

#include <string>
using namespace std;

class StatArray {
public:
  StatArray() {}
  StatArray(int hp, int str, int def, int mag, int res, int skl, int spd, int luc);

  int& operator[] (char* s); // Input must be at least TWO chars in length
  int operator[] (char* s) const;
private:
  static const int SIZE = 8;
  int stats[SIZE];
};

#endif
