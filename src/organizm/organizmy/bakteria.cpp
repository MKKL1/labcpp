#include "bakteria.h"
#include "generatorlosowy.h"
#include "ustawieniasymulacji.h"
#include "ListaMieszkancow.h"

static const UstawieniaSymulacji & UST = UstawieniaSymulacji::pobierzUstawienia();
static const ListaMieszkancow & lista = ListaMieszkancow::pobierzListe();
const UstawieniaOrganizmu* Bakteria::ustawieniaOrganizmu = nullptr;
Identifikator Bakteria::id;

Bakteria::Bakteria():
        Organizm(GeneratorLosowy::losujPomiedzy(ustawieniaOrganizmu->zycieMin, ustawieniaOrganizmu->zycieMax),
                 ustawieniaOrganizmu->limitPosilkow,
                 ustawieniaOrganizmu->kosztPotomka, true) {}

Bakteria::Bakteria(const UstawieniaOrganizmu* ustorg) {ustawieniaOrganizmu=ustorg;}

Identifikator Bakteria::kimJestes(){
    return zywy() ? id : lista.TRUP;
}

Mieszkaniec* Bakteria::dajPotomka() {
    Mieszkaniec* m = nullptr;
    if(potomek()) m = new Bakteria();
    return m;
}

void Bakteria::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr){
        Identifikator r = mieszkaniec->kimJestes();
        if(r == lista.GLON || r == lista.GRZYB) posilek();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Bakteria::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.PUSTKA)>0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(lista.PUSTKA));

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.GLON)>0)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(lista.GLON));

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.BAKTERIA)>0)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(lista.BAKTERIA));

    return ZamiarMieszkanca();
}

bool Bakteria::czyMozeSkakac() {
    return mozeSkakac;
}
