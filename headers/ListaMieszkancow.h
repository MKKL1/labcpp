//
// Created by krystian on 07.06.2022.
//

#ifndef EKOSYSTEM_LISTAMIESZKANCOW_H
#define EKOSYSTEM_LISTAMIESZKANCOW_H

#include "Identifikator.h"
#include "RejestrMieszkancow.h"

class ListaMieszkancow {
public:
    void init(const UstawieniaSymulacji* ustawieniaSymulacji);
    Identifikator NIEZNANE = RejestrMieszkancow::zarejestrujMieszkanca("Nieznane");
    Identifikator TRUP = RejestrMieszkancow::zarejestrujMieszkanca("Martwe");
    Identifikator SCIANA = RejestrMieszkancow::zarejestrujMieszkanca("Sciana");
    Identifikator PUSTKA = RejestrMieszkancow::zarejestrujMieszkanca("Pustka");
    Identifikator BAKTERIA;
    Identifikator GLON;
    Identifikator GRZYB;
    Identifikator ARCHEA;

    static ListaMieszkancow &pobierzListe() {
        static ListaMieszkancow listaMieszkancow;
        return listaMieszkancow;
    }
};

#endif //EKOSYSTEM_LISTAMIESZKANCOW_H
