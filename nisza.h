#ifndef NISZA_H
#define NISZA_H

#include "mieszkaniec.h"

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
    RodzajMieszkanca ktoTuMieszka() {
        return zajeta() ? lokator->kimJestes(): PUSTKA;
    }

    bool lokatorZywy() const;

    char jakisSymbol() const;
//TODO
};

#endif // NISZA_H
