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
#include "zlab12.h"

#include "indeks2d.h"

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

int main()
{

//    ZLab12 zlab12;
//    zlab12.strumienTekstowy();
//    cout << endl;
//    zlab12.zapisTekstowyDoPliku("/home/student/plik.txt");
//    cout << endl;
//    zlab12.odczytPlikuTekstowego("/home/student/plik.txt");
//    cout << endl;
//    zlab12.zapisBinarnyDoPliku("/home/student/binarny.bin");
//    cout << endl;
//    zlab12.odczytPlikuBinarnego("/home/student/binarny.bin");

    Srodowisko ekoSystem = Srodowisko::czytajZPliku("start.txt");
    for(
        unsigned long i = 0;i < 200 && !ekoSystem.martwy(); i++){
        //system("clear");
        cout << "Krok symulacji: " << i << endl << ekoSystem.doTekstu() << endl;

        cin.ignore(true);
        ekoSystem.wykonajKrokSymulacji();
    }
    cout << "out";
    cout << endl;

    return 0;
}
