#ifndef terminalUzytkownika_H
#define terminalUzytkownika_H

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "pralka.h"
#include "pranie.h"


class terminalUzytkownika :public pralka, public pranie{

  pralka Pralka;
  pranie Pranie;
  bool czyDziala;
  bool czyMozliwe;
  unsigned int waga;
  bool zakonczonoPranie;

public:

  terminalUzytkownika();

  terminalUzytkownika(pralka &P);
  void zakonczPranie();
  void zakonczPranie(int i,pralka &P);
void manualne(pralka &P);
 void automatyczne(pralka &P);
  void rozpocznijPranie(pralka &P);


};

#endif
