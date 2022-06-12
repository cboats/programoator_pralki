#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "komora.h"
#include "komoraPlyn.h"
#include "komoraPralki.h"
#include "pralka.h"
#include "pranie.h"
#include "terminalSerwisanta.h"
#include "terminalUzytkownika.h"

using namespace std;


int main() {

  srand(time(NULL));


  cout << "włączono pralkę!" << endl;
  pralka Pralka(2);

  char t = 0;

  while(t != 'w') {
    while((Pralka.get_czySprawna() == true) && (Pralka.get_licznikPran() > 0) && (Pralka.get_czyWlaczona() == true)) {
      cout << "chcesz wejsc w tryb serwisanta? <t/n> \n żeby wylaczyć pralke nacisnij w" << endl;
      cin >> t;
      if(t == 'w') break;
      if(t == 't') {
        cout << "podaj haslo: " << endl;
        int haslo;
        cin >> haslo;
        while (haslo != 1234) {
          cout << "bledne haslo, wpisz ponownie: "<< endl;
          cin >> haslo;
        }
        terminalSerwisanta serwisant = terminalSerwisanta(Pralka);
        serwisant.sprawdzSprawnosci(Pralka);
        serwisant.napraw(Pralka);
      }

      else {
        terminalUzytkownika uzytkownik = terminalUzytkownika(Pralka);
        uzytkownik.rozpocznijPranie(Pralka);
        uzytkownik.zakonczPranie();
        cout << "licznik pran w main po zakonczeniu prania " << Pralka.get_licznikPran() << endl;
      }
    }
    if(t == 'w') break;
    cout << "pralka zepsuta, wezwij serwisanta" << endl;
    int haslo;
    cin >> haslo;
    while (haslo != 1234) {
      cout << "bledne haslo, potrzebny serwisant, wpisz ponownie: "<< endl;
      cin >> haslo;
    }

    terminalSerwisanta serwisant = terminalSerwisanta(Pralka);
    serwisant.sprawdzSprawnosci(Pralka);
    serwisant.napraw(Pralka);
  }
}
