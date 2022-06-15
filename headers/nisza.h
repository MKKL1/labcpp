#ifndef NISZA_H
#define NISZA_H

#include "mieszkaniec.h"
#include "srodowisko.h"

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
    bool zajeta() const {return lokator != nullptr;}
    Identifikator ktoTuMieszka();

    bool lokatorZywy() const;

    char jakiSymbol() const;


private:
    friend void Srodowisko::wykonajAkcje(unsigned int wiersz, unsigned int kolumna);
    friend void Srodowisko::wykonajSkok(unsigned int wiersz, unsigned int kolumna);

    ZamiarMieszkanca aktywujLokatora(Sasiedztwo sasiedztwo) const{
        return lokator->wybierzAkcje(sasiedztwo);
    }
    Mieszkaniec * wypuscPotomka() const{
        return lokator->dajPotomka();
    }
    void przyjmijZdobycz(Mieszkaniec * ofiara) const{
        lokator->przyjmijZdobycz(ofiara);
    }
    bool lokatorMozeSkakac() const {
        return lokator->czyMozeSkakac();
    }
};

#endif // NISZA_H
