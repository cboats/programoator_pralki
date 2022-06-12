
#include "pralka.h"

using namespace std;


  pralka::pralka() {}

pralka::pralka(int x) {
    this->czyWlaczona = true;
    this->licznikPran = 1;

    for(int i = 0; i < 7; i++) {
      this->komoryPlynow.push_back(komoraPlyn(i,1));
      this->komoryPlynow[i].set_ID(i);
      this->komoryPlynow[i].set_czySprawna(true);
      this->komoryPlynow[i].set_pojemnosc(5);

    }

    for(int i = 0; i < 2; i++) {
      this->komoryPralki.push_back(komoraPralki(i,0));
      this->komoryPralki[i].set_ID(i);
      this->komoryPralki[i].set_czyUzywana(false);
      this->komoryPralki[i].set_czySprawna(true);
      this->komoryPralki[i].set_pojemnosc(5);
      
    }
    this->czySprawna = true;
    this->mozliwoscPrania = true;
    this->mozliwoscPlukania = true;
    this->mozliwoscWirowania = true;

  }

bool pralka::get_czyWlaczona() {
    return this->czyWlaczona;
  }

int pralka::get_licznikPran() {
    return this->licznikPran;
  }

bool pralka::get_czySprawna() {
    return this->czySprawna;
  }

bool pralka::get_mozliwoscPrania() {
    return this->mozliwoscPrania;
  }

bool pralka::get_mozliwoscPlukania() {
    return this->mozliwoscPlukania;
  }

bool pralka::get_mozliwoscWirowania() {
    return this->mozliwoscWirowania;
  }

vector <komoraPralki> pralka::get_komoryPralki() {
    return this->komoryPralki;
  }

vector<komoraPlyn> pralka::get_komoryPlynow() {
    return this->komoryPlynow;
  }

void pralka::set_czyWlaczona(bool czy) {
    this->czyWlaczona = czy;
    if(czy == true) cout << "pralka jest wlaczona " << endl;
    else if(czy == false) cout << "pralka jest wylaczona " << endl;
  }

void pralka::set_licznikPran(int l) {
    this->licznikPran = l;
    cout << " pozostalo " << l << "pran do konserwacji" << endl;
  }

void pralka::set_czySprawna(bool czy) {
    this->czySprawna = czy;
    if(czy == true) cout << "pralka jest sprawna " << endl;
    else if(czy == false) cout << "pralka jest niesprawna " << endl;
  }

void pralka::set_mozliwoscPrania(bool czy) {
    this->mozliwoscPrania = czy;
    if(czy == true) cout << "jest mozliwosc prania " << endl;
    else if(czy == false) cout << "nie ma mozliwosci prania " << endl;
  }

void pralka::set_mozliwoscPlukania(bool czy) {
    this->mozliwoscPlukania = czy;
    if(czy == true) cout << "jest mozliwosc plukania " << endl;
    else if(czy == false) cout << "nie ma mozliwosci plukania " << endl;

  }

void pralka::set_mozliwoscWirowania(bool czy) {
    this->mozliwoscWirowania = czy;
    if(czy == true) cout << "jest mozliwosc wirowania " << endl;
    else if(czy == false) cout << "nie ma mozliwosci wirowania " << endl;
  }

void pralka::set_komoryPlynow(vector <komoraPlyn> k) {
    this->komoryPlynow.assign(k.begin(), k.begin() + k.size());
  }

void pralka::set_komoryPralki(vector <komoraPralki> k) {
    this->komoryPralki.assign(k.begin(), k.begin() + k.size());
  }

komoraPlyn pralka::get_komoryPlynow(int i) {
    return this->komoryPlynow[i];
  }

komoraPralki pralka::get_komoryPralki(int i) {
    return this->komoryPralki[i];
  }

void pralka::dostarczWode() {
    for(int i = 0; i < this->komoryPralki.size(); i++) {
      cout << "szukam komory do wody" << endl;
      if(this->komoryPralki[i].get_czyUzywana() == true) {
        cout << "dostarczam wody do komory " << i << " ." << endl;
        this->komoryPralki[i].set_czyMaWode(true);
        break;
      }

    }
  }

void pralka::aktywujBeben() {
    for(int i = 0; i < this->komoryPralki.size(); i++) {
      if(this->komoryPralki[i].get_czyUzywana() == true) {
        cout << "aktywuje bęben " << i << " ." << endl;
        this->komoryPralki[i].set_czyAktywowana(true);
        break;
      }

    }
  }

void pralka::blokadaDrzwi() {
    for(int i = 0; i < this->komoryPralki.size(); i++) {
      if(this->komoryPralki[i].get_czyUzywana() == true) {
        cout << "blokuje drzwi komory " << i << " ." << endl;
        this->komoryPralki[i].set_czyZablokowana(true);
        break;
      }

    }
  }

pralka& pralka::operator= (const pralka& P) {
    this->czyWlaczona = P.czyWlaczona;
    this->licznikPran = P.licznikPran;
    this->komoryPlynow.assign(P.komoryPlynow.begin(), P.komoryPlynow.begin() + P.komoryPlynow.size());
    this->komoryPralki.assign(P.komoryPralki.begin(), P.komoryPralki.begin() + P.komoryPralki.size());
    this->czySprawna = P.czySprawna;
    this->mozliwoscPrania = P.mozliwoscPrania;
    this->mozliwoscPlukania = P.mozliwoscPlukania;
    this->mozliwoscWirowania = P.mozliwoscWirowania;
    return *this;
  }

pralka::~pralka() { // tu coś jeszcze
    this->komoryPlynow.clear();
    this->komoryPralki.clear();
    this->czyWlaczona = false;
  }
