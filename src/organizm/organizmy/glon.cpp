#include "glon.h"
#include "generatorlosowy.h"
#include "ustawieniasymulacji.h"
#include "sasiedztwo.h"
#include "ListaMieszkancow.h"
#include <iostream>

static const UstawieniaSymulacji & UST = UstawieniaSymulacji::pobierzUstawienia();
static const ListaMieszkancow & lista = ListaMieszkancow::pobierzListe();
const UstawieniaOrganizmu* Glon::ustawieniaOrganizmu = nullptr;
Identifikator Glon::id;

Glon::Glon():
        Organizm(GeneratorLosowy::losujPomiedzy(ustawieniaOrganizmu->zycieMin, ustawieniaOrganizmu->zycieMax),
                 ustawieniaOrganizmu->limitPosilkow,
                 ustawieniaOrganizmu->kosztPotomka, false) {}

Glon::Glon(const UstawieniaOrganizmu* ustorg) {ustawieniaOrganizmu=ustorg;}

Identifikator Glon::kimJestes(){
    return zywy() ? id : lista.TRUP;
}

Mieszkaniec* Glon::dajPotomka() {
    Mieszkaniec* m = nullptr;
    if(potomek()) m = new Glon();
    return m;
}

void Glon::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr){
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Glon::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.PUSTKA)>0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(lista.PUSTKA));

    if(zywy() && glodny())
        posilek();

    return ZamiarMieszkanca();
}

bool Glon::czyMozeSkakac() {
    return mozeSkakac;
}
