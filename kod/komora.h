#ifndef komora_H
#define komora_H

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

class komora {
  bool czySprawna;
  int pojemnosc;
  int ID;

public:

  komora();
  komora(int id);

  bool get_czySprawna();
  int get_pojemnosc();
  int get_ID();
  void set_czySprawna(bool czy);
  void set_pojemnosc(int p);
  void set_ID(int id);
};

#endif
