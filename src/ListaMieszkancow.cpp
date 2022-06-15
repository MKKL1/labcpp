#include "ListaMieszkancow.h"
#include "glon.h"
#include "bakteria.h"
#include "grzyb.h"
#include "archea.h"

void ListaMieszkancow::init(const UstawieniaSymulacji *ustawieniaSymulacji) {
    BAKTERIA = RejestrMieszkancow::zarejestrujMieszkanca<Bakteria>("Bakteria", &ustawieniaSymulacji->ustawienia.at("Bakteria"));
    GLON = RejestrMieszkancow::zarejestrujMieszkanca<Glon>("Glon", &ustawieniaSymulacji->ustawienia.at("Glon"));
    GRZYB = RejestrMieszkancow::zarejestrujMieszkanca<Grzyb>("Grzyb", &ustawieniaSymulacji->ustawienia.at("Grzyb"));
    ARCHEA = RejestrMieszkancow::zarejestrujMieszkanca<Archea>("Archea", &ustawieniaSymulacji->ustawienia.at("Archea"));
}