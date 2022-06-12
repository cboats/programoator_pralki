
#ifndef pralka_H
#define pralka_H


#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "komoraPralki.h"
#include "komoraPlyn.h"
#include "pranie.h"

using namespace std;


class pralka {
  bool czyWlaczona;
  int licznikPran;
  vector <komoraPlyn> komoryPlynow;
  vector <komoraPralki> komoryPralki;
  vector <pranie> programyObslugiwane;
  bool czySprawna;
  bool mozliwoscPrania;
  bool mozliwoscPlukania;
  bool mozliwoscWirowania;
  bool pobranieWody;

  public:

  pralka();
  pralka(int x);

  bool get_czyWlaczona();
  int get_licznikPran();
  bool get_czySprawna();
  bool get_mozliwoscPrania();
  bool get_mozliwoscPlukania();
  bool get_mozliwoscWirowania();
  vector <komoraPralki> get_komoryPralki();
  vector <komoraPlyn> get_komoryPlynow();
  void set_czyWlaczona(bool czy);
  void set_licznikPran(int l);
  void set_czySprawna(bool czy);
  void set_mozliwoscPrania(bool czy);
  void set_mozliwoscPlukania(bool czy);
  void set_mozliwoscWirowania(bool czy);
  void set_komoryPlynow(vector <komoraPlyn> k);
  void set_komoryPralki(vector <komoraPralki> k);
  komoraPlyn get_komoryPlynow(int i);
  komoraPralki get_komoryPralki(int i);
  void dostarczWode();
  void aktywujBeben();
  void blokadaDrzwi() ;

  pralka& operator= (const pralka& P);

  ~pralka();

};

#endif
