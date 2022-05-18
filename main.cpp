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

    Srodowisko ekoSystem(8,12);
    ekoSystem.lokuj(new Glon(), 0, 10);
    ekoSystem.lokuj(new Glon(), 1, 10);
    ekoSystem.lokuj(new Glon(), 1, 13);
    ekoSystem.lokuj(new Glon(), 1, 11);
    ekoSystem.lokuj(new Glon(), 0, 0);
    ekoSystem.lokuj(new Glon(), 3, 3);
    ekoSystem.lokuj(new Glon(), 2, 6);

    for(unsigned long i = 0;i < 200 && !ekoSystem.martwy(); i++){
        //system("clear");
        cout << "Krok symulacji: " << i << endl << ekoSystem.doTekstu() << endl;

        //cin.ignore(true);
        cout << "A";
        //cin.get();
        cout << "A";
        ekoSystem.wykonajKrokSymulacji();
        cout << "A";
    }
    cout << "out";
    cout << endl;
    return 0;
}
