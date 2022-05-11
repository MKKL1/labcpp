#include <iostream>
#include "zlab02.h"
#include "prostokat.h"
#include "ustawieniasymulacji.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"

#include "nisza.h"
#include "grzyb.h"
#include "glon.h"
#include "bakteria.h"

#include "zlab09.h"
#include "zlab10.h"

static Nisza n1, n2, n3;

using namespace std;

string nazwaRodzaju(RodzajMieszkanca rodzaj) {
    switch(rodzaj) {
        case GLON: return "GLON";
        case GRZYB: return "GRZYB";
        case BAKTERIA: return "BAKTERIA";
        case PUSTKA: return "PUSTKA";
        case SCIANA: return "ŚCIANA";
        case TRUP: return "TRUP";
        case NIEZNANE: return "NIEZNANE";
   }
}
static char sep = UstawieniaSymulacji::pobierzUstawienia().znakSeparator;

void wyswietlNisze()
{
    cout << n1.jakiSymbol() << sep
    << n2.jakiSymbol() << sep
    << n3.jakiSymbol() << endl;
}

int main()
{

//    ZLab10 zlab10;
//    zlab10.wektor();
//    zlab10.wektor_sortowanie();
//    zlab10.zbior();
//    zlab10.mapa();
    Prostokat p(2,3,"Prostokat");
    cout << p.doTekstu() << endl;
    p++;
    cout << p.doTekstu()<< endl;
    cout << !p<< endl;
//    ZLab09 zlab;
//    zlab.rozmiary();
//    zlab.skalar();
//    zlab.tablica1D();
//    zlab.tablica2D(3, 5);

//    zlab.referencja();
    /*
    cout << "Puste nisze: ";
    wyswietlNisze();

    cout << "Lokowanie mieszkańców: ";
    n1.przyjmijLokatora(new Glon());
    n3.przyjmijLokatora(new Grzyb());
    wyswietlNisze();

    cout << "Przesuwanie lokatorów: ";
    n2 = n1;
    wyswietlNisze();

    cout << "Przesuwanie lokatorów:";
    n3 = n2;
    wyswietlNisze();

    cout << endl;
    return 0;

    */

    /*
    Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

    cout << "Przeglad sasiedztwa: " << endl;

    for(int i=0; i<8; i++) {
        Polozenie p = static_cast<Polozenie>(i);

        RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);

        cout << "polozenie=" << p << " rodzaj=" << nazwaRodzaju(r) << endl;
    }
    cout << endl << "Policzenie sasiadow okreslonego rodzaju" << endl
         << " glony=" << sasiedztwo.ile(GLON) << endl
         << " grzyby=" << sasiedztwo.ile(GRZYB) << endl
         << " trupy=" << sasiedztwo.ile(TRUP) << endl;

    cout << endl << "Wylosowanie sasiada:" << endl
         << "glon -> " << sasiedztwo.losujSasiada(GLON) << endl
         << "pustka -> " << sasiedztwo.losujSasiada(PUSTKA) << endl
         << "trup -> " << sasiedztwo.losujSasiada(TRUP) << endl;

    long wiersz, kolumna;
    cout << endl << "Zmiana indeksow [5][7] wg polozenia" << endl;

    for(int i=0; i<8;i++) {
        Polozenie p = static_cast<Polozenie>(i);
        wiersz = 5;
        kolumna = 7;

        Sasiedztwo::zmienIndeksyWgPolozenia(p, wiersz, kolumna);

        cout << " polozenia: " << p << " ->[" << wiersz << "][" << kolumna << "]" << endl;

    }

    cout << endl;
    */

    //Lab 04
    /*UstawieniaSymulacji & UST1 = UstawieniaSymulacji::pobierzUstawienia();


    UstawieniaSymulacji & UST2 = UstawieniaSymulacji::pobierzUstawienia();

    UST1.glonZycieMin = 10;
    cout << UST1.glonZycieMin<< " " << UST2.glonZycieMin << endl;

    cout << UST1.poprawnySeparator(' ') << endl;

    cout << endl << "losowanie od 0 do 5" << endl;
    for(int i = 0; i<10; i++)
        cout << GEN::losujOdZeraDo(5) << endl;

    cout << endl << "losowanie od 0 do 3" << endl;
    for(int i = 0; i<10; i++)
        cout << GEN::losujOdZeraDo(3) << endl;

    cout << endl << "losowanie od -2 do 2 long" << endl;
    for(int i = 0; i<10; i++)
        cout << GEN::losujPomiedzy(-2L, 2L) << endl;

    cout << endl << "losowanie od 2 do 6 unsigned short" << endl;
    unsigned short min=2, max = 6;
    for(int i = 0; i<10; i++)
        cout << GEN::losujPomiedzy(min, max) << endl;

    */

    //Lab 03
    /*
    Prostokat prostokat1(20, 5,"nazwa");
    Prostokat prostokat2(25.4, 2.2,"prostokat 2");
    cout.precision(2);
    cout << prostokat1.doTekstu() << endl;
    cout << prostokat2.doTekstu() << endl;

    prostokat1 = prostokat2;

    cout << prostokat1.doTekstu() << endl;
    cout << prostokat2.doTekstu() << endl;
    */

    /*Lab 02
    cout << "Laboratoria test2" << endl;
    ZLab02 lab02;
    lab02.menu();
    */
    return 0;
}
