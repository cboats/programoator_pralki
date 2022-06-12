
#include "komora.h"
#include "komoraPlyn.h"

using namespace std;

komoraPlyn::komoraPlyn() {}

komoraPlyn::komoraPlyn(int id, bool czy):komora(id) {
    this->czyPelna = czy;
  }


int komoraPlyn::get_ID() {
    return this->ID;
  }


bool komoraPlyn::get_czyPelna() {
    return this->czyPelna;
  }

int komoraPlyn::get_pojemnosc() {
    return this->pojemnosc;
  }

bool komoraPlyn::get_czySprawna() {
    return this->czySprawna;
  }

void komoraPlyn::set_ID(int id) {
    this->ID = id;
  }

void komoraPlyn::set_czyPelna(bool p) {
    this->czyPelna = p;
  }

void komoraPlyn::set_pojemnosc(int p) {
    this->pojemnosc = p;
  }

void komoraPlyn::set_czySprawna(bool czy) {
    this->czySprawna = czy;
  }
