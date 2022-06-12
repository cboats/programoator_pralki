#include "komora.h"

using namespace std;


komora::komora() {}

komora::komora(int id) {
    this->ID = id;
    this->czySprawna = true;
    this->pojemnosc = 5;
  }

bool komora::get_czySprawna() {
    return this->czySprawna;
  }

int komora::get_pojemnosc() {
    return this->pojemnosc;
  }

int komora::get_ID() {
    return this->ID;
  }

void komora::set_czySprawna(bool czy) {
    this->czySprawna = czy;
  }

void komora::set_pojemnosc(int p) {
    this->pojemnosc = p;
  }

void komora::set_ID(int id) {
    this->ID = id;
  }
