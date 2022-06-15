#include "archea.h"
#include "generatorlosowy.h"
#include "ustawieniasymulacji.h"
#include "ListaMieszkancow.h"

static const UstawieniaSymulacji & UST = UstawieniaSymulacji::pobierzUstawienia();
static const ListaMieszkancow & lista = ListaMieszkancow::pobierzListe();
const UstawieniaOrganizmu* Archea::ustawieniaOrganizmu = nullptr;
Identifikator Archea::id;

Archea::Archea():
        Organizm(GeneratorLosowy::losujPomiedzy(ustawieniaOrganizmu->zycieMin, ustawieniaOrganizmu->zycieMax),
                 ustawieniaOrganizmu->limitPosilkow,
                 ustawieniaOrganizmu->kosztPotomka, true) {}

Archea::Archea(const UstawieniaOrganizmu* ustorg) {ustawieniaOrganizmu=ustorg;}

Identifikator Archea::kimJestes(){
    return zywy() ? id : lista.TRUP;
}

Mieszkaniec* Archea::dajPotomka() {
    Mieszkaniec* m = nullptr;
    if(potomek()) m = new Archea();
    if(stanLicznikaPosilkow() >= 2) dynamic_cast<Organizm *>(m)->mozeSkakac = false;
    return m;
}

void Archea::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr){
        Identifikator r = mieszkaniec->kimJestes();
        if(r == lista.GLON || r == lista.GRZYB) posilek();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Archea::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.PUSTKA)>0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(lista.PUSTKA));

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.GLON)>0)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(lista.GLON));

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.ARCHEA)>1)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(lista.ARCHEA));

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.ARCHEA)>1)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(lista.ARCHEA));

    return ZamiarMieszkanca();
}

bool Archea::czyMozeSkakac() {
    return mozeSkakac;
}
