#ifndef SASIEDZTWO_H
#define SASIEDZTWO_H

#include <ustawieniasymulacji.h>

class Sasiedztwo
{
private:
    RodzajMieszkanca sasiad[3][3];
    RodzajMieszkanca * elementWewnetrzny(Polozenie polozenie);
    static Polozenie losujPolozenie();

public:
    Sasiedztwo(RodzajMieszkanca rodzaj = NIEZNANE);
    void okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj);

    RodzajMieszkanca ktoJestSasiadem(Polozenie polozenie);
    unsigned short ile(RodzajMieszkanca rodzaj) const;

    Polozenie losujSasiada(RodzajMieszkanca rodzaj);

    static void zmienIndeksyWgPolozenia(Polozenie polozenie,
                                        long & wiersz, long & kolumna);
    static void zmienIndeksyWgPolozenia(Polozenie polozenie,
                                        unsigned short & wiersz,
                                        unsigned short & kolumna);

};

#endif // SASIEDZTWO_H
