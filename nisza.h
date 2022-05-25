#ifndef NISZA_H
#define NISZA_H

#include "mieszkaniec.h"
#include "srodowisko.h"
#include <iostream>

class Nisza
{

private:
    Mieszkaniec* lokator;

public:
    Nisza();
    Nisza(Nisza& innaNisza);
    ~Nisza();

    Nisza& operator=(Nisza& innaNisza);
    void przyjmijLokatora(Mieszkaniec* lokatorBezdomny);
    Mieszkaniec* oddajLokatora();
    bool zajeta() const {
        return lokator != nullptr;
    }
    RodzajMieszkanca ktoTuMieszka() {
        //std::cout <<"LOKATOR " << lokator << std::endl;
        return zajeta() ? lokator->kimJestes(): PUSTKA;
    }

    bool lokatorZywy() const;

    char jakiSymbol() const;
    //TODO private


private:
    friend void Srodowisko::wykonajAkcje(unsigned int wiersz, unsigned int kolumna);
    ZamiarMieszkanca aktywujLokatora(Sasiedztwo sasiedztwo) {
        return lokator->wybierzAkcje(sasiedztwo);
    }
    Mieszkaniec * wypuscPotomka() {
        return lokator->dajPotomka();
    }
    void przyjmijZdobycz(Mieszkaniec * ofiara) {
        lokator->przyjmijZdobycz(ofiara);
    }
};

#endif // NISZA_H
