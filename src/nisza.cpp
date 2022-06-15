#include "nisza.h"
#include "ListaMieszkancow.h"

static const ListaMieszkancow & lista = ListaMieszkancow::pobierzListe();

Nisza::Nisza() :lokator(nullptr) {}

Nisza::Nisza(Nisza & innaNisza) {
    if(innaNisza.zajeta()) {
        lokator = innaNisza.lokator;
        innaNisza.lokator = nullptr;
    } else
        lokator = nullptr;
}

Identifikator Nisza::ktoTuMieszka(){
    return zajeta() ? lokator->kimJestes(): lista.PUSTKA;
}

Nisza::~Nisza() {
    delete lokator;
}

Nisza &Nisza::operator=(Nisza &innaNisza) {
    Mieszkaniec * tmp = lokator;
    lokator = innaNisza.lokator;
    innaNisza.lokator = tmp;
    return *this;
}

void Nisza::przyjmijLokatora(Mieszkaniec *lokatorBezdomny) {
    if(!zajeta()) {
        lokator = lokatorBezdomny;
        lokatorBezdomny = nullptr;
    }
}

Mieszkaniec *Nisza::oddajLokatora() {
    Mieszkaniec * tmp = nullptr;
    if(zajeta()) {
        tmp = lokator;
        lokator = nullptr;
    }

    return tmp;
}

bool Nisza::lokatorZywy() const
{
    return lokator != nullptr && lokator->czyZywy();
}
