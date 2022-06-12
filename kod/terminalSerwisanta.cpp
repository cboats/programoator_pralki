
#include "terminalSerwisanta.h"

using namespace std;

terminalSerwisanta::terminalSerwisanta() {}

terminalSerwisanta::terminalSerwisanta (pralka &P) {
    Pralka = P;
    vector<komoraPralki> komoraP;
    for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
      komoraP.push_back(this->Pralka.get_komoryPralki(j));
    }
    for(int i = 0; i < komoraP.size(); i++) {
      if(komoraP[i].get_czySprawna() == false) {
        sprawnoscKomorPralki = false;
      }
      else sprawnoscKomorPralki = true;
    }
    vector<komoraPlyn> komora;
    for(int j = 0; j < this->Pralka.get_komoryPlynow().size(); j++) {
      komora.push_back(this->Pralka.get_komoryPlynow(j));
    }

    for(int i = 0; i < this->Pralka.get_komoryPlynow().size(); i++) {
      if(komora[i].get_czySprawna() == false) {
        sprawnoscKomorPlynow = false;
      }
      else sprawnoscKomorPlynow = true;
    }

    if(this->Pralka.get_czySprawna() == false) {
      sprawnoscModulu = false;
    }
    else sprawnoscModulu = true;
    P = this->Pralka;
  }

void terminalSerwisanta::napraw(pralka &P) {
    this->Pralka = P;
    if(sprawnoscKomorPralki == false) {
      vector<komoraPralki> komora;
      for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
        komora.push_back(this->Pralka.get_komoryPralki(j));
      }
      for(int i = 0; i < this->Pralka.get_komoryPralki().size(); i++) {
        if(komora[i].get_czySprawna() == false) {
          cout << "naprawiam komore nr " << i <<" pralki" << endl;
          this->Pralka.get_komoryPralki(i).set_czySprawna(true);

        }
      }
    }

    if(sprawnoscKomorPlynow == false) {
      vector<komoraPlyn> komora;
      for(int j = 0; j < this->Pralka.get_komoryPlynow().size(); j++) {
        komora.push_back(this->Pralka.get_komoryPlynow(j));
      }
      for(int i = 0; i < this->Pralka.get_komoryPlynow().size(); i++) {
        if(komora[i].get_czySprawna() == false) {
          cout << "naprawiam komore nr " << i <<" plynow" << endl;
          this->Pralka.get_komoryPlynow(i).set_czySprawna(true);

        }
      }
    }

    if(sprawnoscModulu == false) {
      cout << "naprawiam pralke" << endl;
      this->Pralka.set_czySprawna(true);
    }

    if(this->Pralka.get_licznikPran() <= 0) {
      cout << "naprawiam licznik "<< endl;
      this->Pralka.set_licznikPran(5);
    }

    for(int j = 0; j < this->Pralka.get_komoryPlynow().size(); j++) {
      this->Pralka.get_komoryPlynow(j).set_pojemnosc(5);
    }

    P = this->Pralka;

  }

void terminalSerwisanta::sprawdzSprawnosci(pralka &P) {
    this->Pralka = P;
    if(sprawnoscKomorPralki == false) {
      vector<komoraPralki> komora;
      for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
        komora.push_back(this->Pralka.get_komoryPralki(j));
      }
      for(int i = 0; i < Pralka.get_komoryPralki().size(); i++) {
        if(komora[i].get_czySprawna() == false) {
          cout << "trzeba naprawic komore nr " << i <<" pralki" << endl;
        }
      }
    }
    else if(sprawnoscKomorPralki == true) {
      cout << "komory pralki sa sprawne" << endl;
    }

    if(sprawnoscKomorPlynow == false) {
      vector<komoraPlyn> komora;
      for(int j = 0; j < this->Pralka.get_komoryPlynow().size(); j++) {
        komora.push_back(this->Pralka.get_komoryPlynow(j));
      }
      for(int i = 0; i < this->Pralka.get_komoryPlynow().size(); i++) {
        if(komora[i].get_czySprawna() == false) {
          cout << "trzeba naprawic komore nr " << i <<" plynow" << endl;
        }
      }
    }
    else if(sprawnoscKomorPlynow == true) {
      cout << "komory plynow sa sprawne " << endl;
    }

    if(sprawnoscModulu == false) {
      cout << "trzeba naprawic pralke" << endl;
    }
    else if(sprawnoscModulu == true) {
      cout << "modul jest sprawny" << endl;
    }

    cout << "pozostalo " << this->Pralka.get_licznikPran() << " pran" << endl;
  }
