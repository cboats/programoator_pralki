

#include "terminalUzytkownika.h"

using namespace std;


terminalUzytkownika::terminalUzytkownika() {}

terminalUzytkownika::terminalUzytkownika(pralka &P) {
    this->Pralka = P;
    this->czyDziala = true; //lub ustawianie losowe
    this->czyMozliwe = true; //lub ustawianie losowe
    this->waga = rand()%5; //lub ustawi sie losowe
    this->zakonczonoPranie = false;
  }

void terminalUzytkownika::zakonczPranie() {
    cout << "zakonczono pranie, wylaczam" << endl;
    this->zakonczonoPranie  = true;
    this->waga = 0;
  }

void terminalUzytkownika::zakonczPranie(int i, pralka &P) {
    this->zakonczonoPranie = true;
    this->Pralka.get_komoryPralki(i).set_czyMaWode(false);
    cout << "odpompowuje wode"  << endl;
    this->Pralka.get_komoryPralki(i).set_czyAktywowana(false);
    cout << "dezaktywowano komore " << endl;
    this->Pralka.get_komoryPralki(i).set_czyZablokowana(false);
    cout << "odblokowano komore "  <<endl;
    cout << "mozna wyciagnac pranie" << endl;
    this->waga = 0;
    this->Pralka.get_komoryPralki(i).set_czyUzywana(false);
    //cout << "zakonczono pranie, wylaczam" << endl;
    int licznik = this->Pralka.get_licznikPran();
    this->Pralka.set_licznikPran(licznik - 1);
    cout << "licznik pran po zakonczeniu prania w zakonczPranie: " << this->Pralka.get_licznikPran() << endl;
    P = this->Pralka;
  }
void terminalUzytkownika::manualne(pralka &P) {
  cout << "wybierz parametry prania: " << endl;
  cout << "wirowanie w zakresie 0 - 1000:" << endl;
  int w;
  cin >> w;
  while(w < 0 || w > 1000) {
    cout << "niepoprawne parametry wirowania, wprowadz ponownie 0 - 1000: "<<endl;
    cin >> w;
  }

  cout << "plukanie 0/1: " << endl;
  bool p;
  cin >> p;
  while(p!=1 && p!=0) {
    cout << "niepoprawne włączenie płukania, wybierz ponownie 0 / 1 : " <<endl;
    cin >> p;
  }

  cout << "czy pranie wlasciwe 0/1: "<< endl;
  bool cP;
  cin >> cP;
  while(cP!=1 && cP!=0) {
    cout << "niepoprawne włączenie prania właściwego, wybierz ponownie 0 / 1: "<<endl;
    cin >> cP;
  }

  int t;
  if(cP == true) {
    cout << "temperatura w zakresie 0 - 90 'C: "<< endl;
    cin >> t;
    while(t < 0 || t > 90) {
      cout << "niepoprawna temperatura, wpisz ponownie z zakresu 0 - 90 C': " << endl;
      cin >> t;
    }
  }

  else if(cP == false) t = 0;

  cout << "czy pranie wstepne 0/1: "<< endl;
  bool cPW;
  cin >> cPW;
  while(cPW!=1 && cPW!=0) {
    cout << "niepoprane włączenie prania wstępnego, wybierz ponownie 0 / 1: " <<endl;
    cin >> cPW;
  }


  cout << "wybierz płyny do użycia: " << endl;
  cout << "0 - do płukania" << endl << "1 - do kolorowych" << endl << "2 - do czarnych" << endl << "3 - do białych"<< endl;
  cout << "4 - antyalergiczny" << endl << "5 - delikanty" << endl << "6 - dezynfekcja" << endl << "7 - przejdz dalej" << endl;
  vector <bool> uP;
  vector <komoraPlyn> plyny;
  int i = 0;
  while(i != 7) {
    cin >> i;
    while(i < 0 || i > 7) {
      cout << "niepoprawny wybór komory, wybierz ponownie z płynów 0 - 6 lub 7 by przejść dalej: " << endl;
      cin >> i;
    }
    if (i == 7) break;
    cout << "uzywam plynu " << i << endl;
    plyny.push_back(komoraPlyn(i,true));
  }

  for(int j = 0; j < 7; j++) {
    uP.push_back(false);
  }

  for(int j = 0; j < plyny.size(); j++) {
    uP[plyny[j].get_ID()] = true;
  }

  vector<komoraPralki> komory;
  for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
    komory.push_back(this->Pralka.get_komoryPralki(j));
  }
  for(int j =0; j < komory.size(); j++) {
    if(komory[j].get_czyUzywana() == false && this->waga <= komory[j].get_pojemnosc()) {
      this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
      komory[j].set_czyUzywana(true);
      this->Pralka.set_komoryPralki(komory);
      this->Pralka.dostarczWode();
      this->Pralka.aktywujBeben();
      this->Pralka.blokadaDrzwi();
      for(int k = 0; k < uP.size(); k++) {
        if(uP[k] == true) {
          int p = this->Pralka.get_komoryPlynow(k).get_pojemnosc();
          this->Pralka.get_komoryPlynow(k).set_pojemnosc(p - 1);
        }
      }
      this->Pranie.~pranie();
      zakonczPranie(komory[j].get_ID(),P);

      j = komory.size();
      plyny.clear();
      komory.clear();

    }
    if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)) {
      cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
      zakonczPranie();
      plyny.clear();
      komory.clear();

    }
  }

 }

void terminalUzytkownika::automatyczne(pralka &P) {
   cout << "wybierz program prania: "<<endl;
   cout << "0 - pranie codzienne" << endl << "1 - delikatne" << endl << "2 - intensywne" << endl;
   cout << "3 - antyalergiczne" << endl << "4 - płukanie" << endl << "5 - wirowanie" << endl;
   int x;
   cin >> x;
   while(x < 0 || x > 5) {
     cout << "niepoprawny wybór programu prania, wybierz ponownie z programów 0 - 5: " << endl;
     cin >> x;
   }
   switch (x) {
     case 0: {
       int w = 800;
       bool p = true;
       int t = 40;
       bool cP = true;
       bool cPW = false;
       vector <bool> uP;
       vector <komoraPlyn> plyny;
       plyny.push_back(komoraPlyn(0,true));
       plyny.push_back(komoraPlyn(1,true));


       for(int j = 0; j < 7; j++) {
         uP.push_back(false);
       }

       for(int j = 0; j < plyny.size(); j++) {
         uP[plyny[j].get_ID()] = true;
       }

       vector<komoraPralki> komory;

       for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
         komory.push_back(this->Pralka.get_komoryPralki(j));
       }
       for(int j =0; j < komory.size(); j++) {
         if(komory[j].get_czyUzywana() == false && this->waga <= komory[j].get_pojemnosc()) {
           this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
           komory[j].set_czyUzywana(true);
           this->Pralka.set_komoryPralki(komory);
           this->Pralka.dostarczWode();
           this->Pralka.aktywujBeben();
           this->Pralka.blokadaDrzwi();
           this->Pranie.~pranie();
           zakonczPranie(komory[j].get_ID(),P);

           j = komory.size();
           plyny.clear();
           komory.clear();

         }
         if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)) {
           cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
           zakonczPranie();
           plyny.clear();
           komory.clear();

         }
       }
       break;
     }

     case 1:{
       int w = 600;
       bool p = false;
       int t = 30;
       bool cP = true;
       bool cPW = false;
       vector <bool> uP;
       vector <komoraPlyn> plyny;
       plyny.push_back(komoraPlyn(0,true));
       plyny.push_back(komoraPlyn(5,true));



       for(int j = 0; j < 7; j++) {
         uP.push_back(false);
       }

       for(int j = 0; j < plyny.size(); j++) {
         uP[plyny[j].get_ID()] = true;
       }

       vector<komoraPralki> komory;
       for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
         komory.push_back(this->Pralka.get_komoryPralki(j));
       }
       for(int j =0; j < komory.size(); j++) {
         if(komory[j].get_czyUzywana() == false && this->waga <= komory[j].get_pojemnosc()) {
           this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
           komory[j].set_czyUzywana(true);
           this->Pralka.set_komoryPralki(komory);
           this->Pralka.dostarczWode();
           this->Pralka.aktywujBeben();
           this->Pralka.blokadaDrzwi();
           this->Pranie.~pranie();
           zakonczPranie(komory[j].get_ID(),P);

           j = komory.size();
           plyny.clear();
           komory.clear();

         }
         if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)){
           cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
           zakonczPranie();
           plyny.clear();
           komory.clear();

         }
       }
       break;
     }

     case 2: {
       int w = 1000;
       bool p = true;
       int t = 60;
       bool cP = true;
       bool cPW = true;
       vector <bool> uP;
       vector <komoraPlyn> plyny;
       plyny.push_back(komoraPlyn(0,true));
       plyny.push_back(komoraPlyn(1,true));
       plyny.push_back(komoraPlyn(6,true));


       for(int j = 0; j < 7; j++) {
         uP.push_back(false);
       }

       for(int j = 0; j < plyny.size(); j++) {
         uP[plyny[j].get_ID()] = true;
       }

       vector<komoraPralki> komory;
       for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
         komory.push_back(this->Pralka.get_komoryPralki(j));
       }
       for(int j =0; j < komory.size(); j++) {
         if(komory[j].get_czyUzywana() == false && this->waga <= komory[j].get_pojemnosc()) {
           this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
           komory[j].set_czyUzywana(true);
           this->Pralka.set_komoryPralki(komory);
           this->Pralka.dostarczWode();
           this->Pralka.aktywujBeben();
           this->Pralka.blokadaDrzwi();
           this->Pranie.~pranie();
           zakonczPranie(komory[j].get_ID(),P);

           j = komory.size();
           plyny.clear();
           komory.clear();

         }
         if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)) {
           cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
           zakonczPranie();
           plyny.clear();
           komory.clear();

         }
       }
       break;
     }

     case 3: {
       int w = 800;
       bool p = true;
       int t = 40;
       bool cP = true;
       bool cPW = true;
       vector <bool> uP;
       vector <komoraPlyn> plyny;
       plyny.push_back(komoraPlyn(0,true));
       plyny.push_back(komoraPlyn(4,true));
       plyny.push_back(komoraPlyn(5,true));



       for(int j = 0; j < 7; j++) {
         uP.push_back(false);
       }

       for(int j = 0; j < plyny.size(); j++) {
         uP[plyny[j].get_ID()] = true;
       }

       vector<komoraPralki> komory;
       for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
         komory.push_back(this->Pralka.get_komoryPralki(j));
       }
       for(int j =0; j < komory.size(); j++) {
         if(komory[j].get_czyUzywana() == false && this->waga <= komory[j].get_pojemnosc()) {
           this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
           komory[j].set_czyUzywana(true);
           this->Pralka.set_komoryPralki(komory);
           this->Pralka.dostarczWode();
           this->Pralka.aktywujBeben();
           this->Pralka.blokadaDrzwi();
           this->Pranie.~pranie();
           zakonczPranie(komory[j].get_ID(),P);

           j = komory.size();
           plyny.clear();
           komory.clear();

         }
         if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)) {
           cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
           zakonczPranie();
           plyny.clear();
           komory.clear();

         }
       }
       break;
     }

     case 4: {
       int w = 0;
       bool p = true;
       int t = 40;
       bool cP = false;
       bool cPW = false;
       vector <bool> uP;
       vector <komoraPlyn> plyny;
       plyny.push_back(komoraPlyn(0,true));



       for(int j = 0; j < 7; j++) {
         uP.push_back(false);
       }

       for(int j = 0; j < plyny.size(); j++) {
         uP[plyny[j].get_ID()] = true;
       }

       vector<komoraPralki> komory;
       for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
         komory.push_back(this->Pralka.get_komoryPralki(j));
       }
       for(int j =0; j < komory.size(); j++) {
         if(komory[j].get_czyUzywana() == false && this->waga <= komory[j].get_pojemnosc()) {
           this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
           komory[j].set_czyUzywana(true);
           this->Pralka.set_komoryPralki(komory);
           this->Pralka.dostarczWode();
           this->Pralka.aktywujBeben();
           this->Pralka.blokadaDrzwi();
           this->Pranie.~pranie();
           zakonczPranie(komory[j].get_ID(),P);

           j = komory.size();
           plyny.clear();
           komory.clear();

         }
         if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)) {
           cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
           zakonczPranie();
           plyny.clear();
           komory.clear();
         }
       }
       break;
     }

     case 5: {
       int w = 1000;
       bool p = false;
       int t = 40;
       bool cP = false;
       bool cPW = false;
       vector <bool> uP;

       for(int j = 0; j < 7; j++) {

         uP.push_back(false);

      }

      vector<komoraPralki> komory;
      for(int j = 0; j < this->Pralka.get_komoryPralki().size(); j++) {
        komory.push_back(this->Pralka.get_komoryPralki(j));
      }
       for(int j =0; j < komory.size(); j++) {
         if(komory[j].get_czyUzywana() == false) {
           this->Pranie = pranie(w,p,t,komory[j].get_ID(),uP,cP,cPW);
           komory[j].set_czyUzywana(true);
           this->Pralka.set_komoryPralki(komory);
           this->Pralka.dostarczWode();
           this->Pralka.aktywujBeben();
           this->Pralka.blokadaDrzwi();
           this->Pranie.~pranie();
           zakonczPranie(komory[j].get_ID(),P);
           j = komory.size();
           komory.clear();
         }
         if((this->waga > komory[j].get_pojemnosc()) && (j = komory.size()-1)) {
           cout << "za duże pranie, nie zmieści się w żadnej komorze, nie można wykonać prania." << endl;
           zakonczPranie();
           komory.clear();
         }
       }
       break;
     }
   }
 }

void terminalUzytkownika::rozpocznijPranie(pralka &P) {

    cout << "czy ustawienia manualne czy automatyczne? <m/a>" << endl;
    char m;
    cin >> m;
    if(m == 'm') {
      manualne(P);
    }
    else if(m == 'a') {
      automatyczne(P);
    }
  }
