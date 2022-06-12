#ifndef terminalSerwisanta_H
#define terminalSerwisanta_H

#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "pralka.h"
#include "pranie.h"




class terminalSerwisanta :public pralka, public pranie {

  bool pelnoscPlynow;
  bool sprawnoscKomorPralki;
  bool sprawnoscKomorPlynow;
  bool sprawnoscModulu;
  pralka Pralka;

public:

  terminalSerwisanta();

  terminalSerwisanta (pralka &P);
  void napraw(pralka &P);
  void sprawdzSprawnosci(pralka &P);

};

#endif
