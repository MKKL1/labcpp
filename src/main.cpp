#include <iostream>

#include "nisza.h"
#include "grzyb.h"
#include "glon.h"
#include "bakteria.h"
#include "RejestrMieszkancow.h"
#include "ListaMieszkancow.h"
#include "WyswietlaczKonsolowy.h"
#include "archea.h"
#include "WyswietlaczOkienkowy.h"
#include "WatekSymulacji.h"
#include <unistd.h>
#include <QApplication>

#include <chrono>
#include <thread>


using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    string sciezkaPlikuUstawien;
    while(true)
    {
        switch(getopt(argc, argv, "c:h"))
        {
            case 'c':
                sciezkaPlikuUstawien = optarg;
                continue;
            case 'h':
                cout << "-c PATH" << endl << " PATH - sciezka do pliku konfiguracyjnego" << endl;
                break;
        }
        break;
    }

    static UstawieniaSymulacji & ust = UstawieniaSymulacji::pobierzUstawienia();
    ust.wczytajZPliku(sciezkaPlikuUstawien);
    static ListaMieszkancow & lista = ListaMieszkancow::pobierzListe();
    lista.init(&ust);

    Srodowisko ekoSystem(12,12);
    ekoSystem.lokuj(new Glon(), 0, 10);
    ekoSystem.lokuj(new Grzyb(), 1, 10);
    ekoSystem.lokuj(new Grzyb(), 2, 10);
    ekoSystem.lokuj(new Bakteria(), 1, 11);
    ekoSystem.lokuj(new Bakteria(), 0, 0);
    ekoSystem.lokuj(new Glon(), 3, 3);
    ekoSystem.lokuj(new Grzyb(), 2, 6);
    ekoSystem.lokuj(new Grzyb(), 3, 6);
    ekoSystem.lokuj(new Grzyb(), 8, 6);
    ekoSystem.lokuj(new Grzyb(), 10, 6);
    ekoSystem.lokuj(new Grzyb(), 11, 6);
    ekoSystem.lokuj(new Grzyb(), 11, 4);
    ekoSystem.lokuj(new Grzyb(), 11, 2);
    ekoSystem.lokuj(new Archea(), 11, 1);

//    WyswietlaczKonsolowy wyswietlaczKonsolowy = WyswietlaczKonsolowy(&ekoSystem);
//    wyswietlaczKonsolowy.dodajZnak(lista.BAKTERIA, '@');
//    wyswietlaczKonsolowy.dodajZnak(lista.GLON, '*');
//    wyswietlaczKonsolowy.dodajZnak(lista.GRZYB, '#');
//    wyswietlaczKonsolowy.dodajZnak(lista.TRUP, '+');
//    wyswietlaczKonsolowy.dodajZnak(lista.ARCHEA, '0');
//    wyswietlaczKonsolowy.dodajZnak(lista.PUSTKA, '_', false);
//
//    for(unsigned long i = 0; i < 200 && !ekoSystem.martwy(); i++){
//        wyswietlaczKonsolowy.krokSymulacji(i);
//        ekoSystem.wykonajKrokSymulacji();
//        std::cin.ignore(true);
//    }

    auto w = WyswietlaczOkienkowy(&ekoSystem);
    w.dodajStyl(lista.BAKTERIA, QBrush(Qt::yellow));
    w.dodajStyl(lista.GLON, QBrush(Qt::green));
    w.dodajStyl(lista.GRZYB, QBrush(Qt::red));
    w.dodajStyl(lista.TRUP, QBrush(Qt::black));
    w.dodajStyl(lista.ARCHEA, QBrush(Qt::darkYellow));
    w.dodajStyl(lista.PUSTKA, QBrush(Qt::white), false);
    w.show();

    WatekSymulacji watek(&ekoSystem);
    QObject::connect(&watek, SIGNAL(krokSymulacji(ulong)),
                     &w, SLOT(krokSymulacji(ulong)));

    watek.start();
    cout << endl;
    return app.exec();
}
