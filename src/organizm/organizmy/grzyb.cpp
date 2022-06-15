#include "grzyb.h"
#include "generatorlosowy.h"
#include "ustawieniasymulacji.h"
#include "sasiedztwo.h"
#include "ListaMieszkancow.h"

static const UstawieniaSymulacji & UST = UstawieniaSymulacji::pobierzUstawienia();
static const ListaMieszkancow & lista = ListaMieszkancow::pobierzListe();
const UstawieniaOrganizmu* Grzyb::ustawieniaOrganizmu = nullptr;
Identifikator Grzyb::id;

Grzyb::Grzyb():
        Organizm(GeneratorLosowy::losujPomiedzy(ustawieniaOrganizmu->zycieMin, ustawieniaOrganizmu->zycieMax),
                 ustawieniaOrganizmu->limitPosilkow,
                 ustawieniaOrganizmu->kosztPotomka, true) {}

Grzyb::Grzyb(const UstawieniaOrganizmu* ustorg) {ustawieniaOrganizmu=ustorg;}

Identifikator Grzyb::kimJestes(){
    return zywy() ? id : lista.TRUP;
}

Mieszkaniec* Grzyb::dajPotomka() {
    Mieszkaniec* m = nullptr;
    if(potomek()) m = new Grzyb();
    return m;
}

void Grzyb::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr){
        if(mieszkaniec->kimJestes() == lista.GLON) posilek();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Grzyb::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.PUSTKA)>0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(lista.PUSTKA));

    if(zywy() && paczkujacy() && sasiedztwo.ile(lista.TRUP)>0)
        return ZamiarMieszkanca(ROZKLAD, sasiedztwo.losujSasiada(lista.TRUP));

    return ZamiarMieszkanca();
}

bool Grzyb::czyMozeSkakac() {
    return mozeSkakac;
}
