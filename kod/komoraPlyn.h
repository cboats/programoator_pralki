#ifndef komoraPlyn_H
#define komoraPlyn_H

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "komora.h"


class komoraPlyn: public komora {
  int ID;
  bool czyPelna;
  int pojemnosc;
  bool czySprawna;

  public:

  komoraPlyn();
  komoraPlyn(int id, bool czy);

  int get_ID();
  bool get_czyPelna();
  int get_pojemnosc();
  bool get_czySprawna();
  void set_ID(int id);
  void set_czyPelna(bool p);
  void set_pojemnosc(int p);
  void set_czySprawna(bool czy);
};



#endif
