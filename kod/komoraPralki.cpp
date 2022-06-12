
#include "komora.h"
#include "komoraPralki.h"

using namespace std;


komoraPralki::komoraPralki() {}

komoraPralki::komoraPralki(int id, bool u): komora(id){
    this->czyUzywana = u;
  }

int komoraPralki::get_ID() {
    return this->ID;
  }

int komoraPralki::get_pojemnosc() {
    return this->pojemnosc;
  }

bool komoraPralki::get_czySprawna() {
    return this->czySprawna;
  }

bool komoraPralki::get_czyUzywana() {
    return this->czyUzywana;
  }

void komoraPralki::set_ID(int id) {
    this->ID = id;
  }

void komoraPralki::set_pojemnosc(int p) {
    this->pojemnosc = p;
  }

void komoraPralki::set_czySprawna(bool czy) {
    this->czySprawna = czy;
  }

void komoraPralki::set_czyUzywana(bool czy) {
    this->czyUzywana = czy;
  }

bool komoraPralki::get_czyMaWode() {
    return this->czyMaWode;
  }

void komoraPralki::set_czyMaWode(bool czy) {
    this->czyMaWode = czy;
    if(czy == true) cout << "komora " << this->ID << " ma wode" << endl;
    else if(czy == false) cout << "od teraz komora " << this->ID << "nie ma wody" << endl;
  }

bool komoraPralki::get_czyZablokowana() {
    return this->czyZablokowana;
  }

void komoraPralki::set_czyZablokowana(bool czy) {
    this->czyZablokowana = czy;
    if(czy == true) cout << "komora " << this->ID << " jest zablokowana" << endl;
    else if(czy == false) cout << "od teraz komora " << this->ID << "jest odblokowana" << endl;
  }

bool komoraPralki::get_czyAktywowana() {
    return this->czyAktywowana;
  }

void komoraPralki::set_czyAktywowana(bool czy) {
    this->czyAktywowana = czy;
    if(czy == true) cout << "komora " << this->ID << " jest aktywowana" << endl;
    else if(czy == false) cout << "od teraz komora " << this->ID << "jest dezaktywowana" << endl;
  }
