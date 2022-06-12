#include "pranie.h"

using namespace std;


pranie::pranie() {}

pranie::pranie(int w, bool p, int t, int kID, vector <bool> uP, bool cP, bool cPW) {
    cout << "ustawiam wirowanie na " << w << "obrotow" << endl;
    this->wirowanie = w;
    if(p == true) cout << "wlaczam plukanie " << endl;
    else if(p == false) cout << "nie wlaczam plukania " << endl;
    this->plukanie = p;
    this->czyPranie = cP;
    if(cP == true) cout << "wlaczam funkcje prania wlasciwego " << endl;
    else if(cP == false) cout << "nie wlaczam funkcji prania wlasciwego" << endl;
    cout << "ustawiam temperature na " << t << "sstopni C" << endl;
    this->temperatura = t;
    this->komoraID = kID;
    this->czyMozliwe = true;

    for(int i=0; i<uP.size(); i++) {
      this->uzyciePlynow.push_back(uP[i]);
    }
    if(cPW == true) cout << "wlaczam pranie wstepne " << endl;
    else if(cPW == false) cout << "nie wlaczam prania wstepnego " << endl;
    this->czyPranieWstepne = cPW;

    cout << "rozpoczynam proces prania" << endl;
  }

bool pranie::get_czyMozliwe() {
    return this->czyMozliwe;
  }

int pranie::get_wirowanie() {
    return this->wirowanie;
  }

bool pranie::get_plukanie() {
    return this->plukanie;
  }

int pranie::get_temperatura() {
    return this->temperatura;
  }

int pranie::get_komoraID() {
    return this->komoraID;
  }

bool pranie::get_czyPranie() {
    return this->czyPranie;
  }

vector <bool> pranie::get_uzyciePlynow() {
    return this->uzyciePlynow;
  }

bool pranie::get_czyPranieWstepne() {
    return this->czyPranieWstepne;
  }

void pranie::set_czyMozliwe(bool czy) {
    this->czyMozliwe = czy;
    if(czy == true) cout << "ppranie jest mozliwe  " << endl;
    else if(czy == false) cout << "pranie nie jest mozliwe" << endl;
  }

void pranie::set_wirowanie(int w) {
    this->wirowanie = w;
    cout << "ustawiono wirowanie: " << w << endl;
  }

void pranie::set_plukanie(bool p) {
    this->plukanie = p;
    cout << "ustawiono plukanie: " << p << endl;
  }

void pranie::set_temperatura(int t) {
    this->temperatura = t;
    cout << "ustawiono temperature: " << t << endl;
  }

void pranie::set_komoraID(int k) {
    this->komoraID = k;
    cout << "uzywam " << k << " komory" << endl;
  }

void pranie::set_czyPranie(bool czy) {
    this->czyPranie = czy;
    if(czy == true) cout << "ustawiono funkcje prania " << endl;
    else if(czy == false) cout << "wylaczono funkcje prania" << endl;
  }

void pranie::set_uzyciePlynow(vector <bool> u) {
    this->uzyciePlynow.assign(u.begin(), u.begin() + u.size());
    for(int i = 0; i < this->uzyciePlynow.size(); i++) {
      if(uzyciePlynow[i] == true) {
        switch (i) {
          case 0: {
            cout << "uzywam plynu do plukania" << endl;
            break;
          }
          case 1: {
            cout << "uzywam plynu do kolorowych ubran" << endl;
            break;
          }
          case 2: {
            cout << "uzywam plynu do czarnych ubran" << endl;
            break;
          }
          case 3: {
            cout << "uzywam plynu do bialych ubran" << endl;
            break;
          }
          case 4: {
            cout << "uzywam plynu antyalergicznego" << endl;
            break;
          }
          case 5: {
            cout << "uzywam plynu delikatnego" << endl;
            break;
          }
          case 6: {
            cout << "uzywam plynu do dezynfekcji" << endl;
            break;
          }
        }

      }
    }
  }

void pranie::set_czyPranieWstepne(bool czy) {
    this->czyPranieWstepne = czy;
    if(czy == true) cout << "ustawiono pranie wstepne " << endl;
    else if(czy == false) cout << "wylaczono pranie wstepne" << endl;
  }

  pranie::~pranie() {
    this->uzyciePlynow.clear();
  }
