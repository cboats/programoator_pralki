#ifndef komoraPralki_H
#define komoraPralki_H

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "komora.h"


class komoraPralki : public komora{
  int ID;
  bool czySprawna;
  bool czyUzywana;
  int pojemnosc;
  bool czyMaWode;
  bool czyZablokowana;
  bool czyAktywowana;

public:

  komoraPralki();
  komoraPralki(int id, bool u);

  int get_ID();
  int get_pojemnosc();
  bool get_czySprawna();
  bool get_czyUzywana();
  void set_ID(int id);
  void set_pojemnosc(int p);
  void set_czySprawna(bool czy);
  void set_czyUzywana(bool czy);
  bool get_czyMaWode();
  void set_czyMaWode(bool czy);
  bool get_czyZablokowana();
  void set_czyZablokowana(bool czy);
  bool get_czyAktywowana();
  void set_czyAktywowana(bool czy);
};

#endif
