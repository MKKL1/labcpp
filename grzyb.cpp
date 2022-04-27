#include "grzyb.h"
#include "generatorlosowy.h"
#include "ustawieniasymulacji.h"
#include "sasiedztwo.h"

static const UstawieniaSymulacji & UST = UstawieniaSymulacji::pobierzUstawienia();

Grzyb::Grzyb():
    Organizm(GeneratorLosowy::losujPomiedzy(UST.grzybZycieMin, UST.grzybZycieMax),
             UST.grzybLimitPosilkow,
             UST.grzybKosztPotomka),
    Mieszkaniec(UST.znakGrzyb){}

RodzajMieszkanca Grzyb::kimJestes() {
    return zywy() ? GRZYB : TRUP;
}

Mieszkaniec* Grzyb::dajPotomka() {
    Mieszkaniec* m = nullptr;
    if(potomek()) m = new Grzyb();
    return m;
}

void Grzyb::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr){
        //TODO
        RodzajMieszkanca r = mieszkaniec->kimJestes();
        if(r == GLON) posilek();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Grzyb::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if(zywy() && paczkujacy() && sasiedztwo.ile(PUSTKA)>0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));

    if(zywy() && paczkujacy() && sasiedztwo.ile(TRUP)>0)
        return ZamiarMieszkanca(ROZKLAD, sasiedztwo.losujSasiada(TRUP));

    if(!zywy() && symbol != UST.znakTrup)
        symbol = UST.znakTrup;

    return ZamiarMieszkanca();
}
