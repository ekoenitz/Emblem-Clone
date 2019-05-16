#include "StatArray.hpp"

#include <cctype>
#include <string>
using namespace std;

StatArray::StatArray(int hp, int str, int def, int mag, int res, int skl, int spd, int luc) {
  stats[0] = hp;
  stats[1] = str;
  stats[2] = def;
  stats[3] = mag;
  stats[4] = res;
  stats[5] = skl;
  stats[6] = spd;
  stats[7] = luc;
}

int& StatArray::operator[] (char* s) {
  switch (tolower(s[1])) {
  case 'p': // HP and SPD
    if (tolower(s[0]) == 'h') {
      return stats[0];
    }
    else {
      return stats[6];
    }
    break;
  case 't': // STR
    return stats[1];
    break;
  case 'e': // DEF and RES
    if (tolower(s[0]) == 'd') {
      return stats[2];
    }
    else {
      return stats[4];
    }
    break;
  case 'a': // MAG
    return stats[3];
    break;
  case 'k': // SKL
    return stats[5];
    break;
  default: // LUC
    return stats[7];
    break;
  }
}

int StatArray::operator[] (char* s) const {
  switch (tolower(s[1])) {
  case 'p': // HP and SPD
    if (tolower(s[0]) == 'h') {
      return stats[0];
    }
    else {
      return stats[6];
    }
    break;
  case 't': // STR
    return stats[1];
    break;
  case 'e': // DEF and RES
    if (tolower(s[0]) == 'd') {
      return stats[2];
    }
    else {
      return stats[4];
    }
    break;
  case 'a': // MAG
    return stats[3];
    break;
  case 'k': // SKL
    return stats[5];
    break;
  default: // LUC
    return stats[7];
    break;
  }
}