#ifndef pranie_H
#define pranie_H

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>


class pranie {
  bool czyMozliwe;
  int wirowanie;
  bool plukanie;
  int temperatura;
  int komoraID;
  std::vector <bool> uzyciePlynow;
  bool czyPranie;
  bool czyPranieWstepne;

  public:

  pranie();

  pranie(int w, bool p, int t, int kID, std::vector <bool> uP, bool cP, bool cPW);

  bool get_czyMozliwe();
  int get_wirowanie();
  bool get_plukanie();
  int get_temperatura();
  int get_komoraID();
  bool get_czyPranie();
  std::vector <bool> get_uzyciePlynow();
  bool get_czyPranieWstepne();
  void set_czyMozliwe(bool czy);
  void set_wirowanie(int w);
  void set_plukanie(bool p);
  void set_temperatura(int t);
  void set_komoraID(int k);
  void set_czyPranie(bool czy);
  void set_uzyciePlynow(std::vector <bool> u);
  void set_czyPranieWstepne(bool czy);
  ~pranie();

};

#endif
