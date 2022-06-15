#ifndef SASIEDZTWO_H
#define SASIEDZTWO_H

#include "ustawieniasymulacji.h"
#include "Identifikator.h"

class Sasiedztwo
{
private:
    unsigned short sasiad[3][3];
    unsigned short * elementWewnetrzny(Polozenie polozenie);
    static Polozenie losujPolozenie();


public:
    Sasiedztwo();
    Sasiedztwo(Identifikator identifikator);
    void okreslSasiada(Polozenie polozenie, Identifikator rodzaj);

    unsigned short ktoJestSasiadem(Polozenie polozenie);
    unsigned short ile(Identifikator rodzaj) const;

    Polozenie losujSasiada(Identifikator rodzaj);

    static void zmienIndeksyWgPolozenia(Polozenie polozenie,
                                        long & wiersz, long & kolumna);

    static void zmienIndeksyWgPolozenia(Polozenie polozenie,
                                        unsigned int & wiersz,
                                        unsigned int & kolumna);

};

#endif // SASIEDZTWO_H
