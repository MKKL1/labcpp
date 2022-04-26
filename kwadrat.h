#ifndef KWADRAT_H
#define KWADRAT_H
#include "prostokat.h"
#include "obliczenia.h"

class Kwadrat : public Prostokat, public Obliczenia
{
public:
    Kwadrat(double bok =0, string nazwa = "?"):Prostokat(bok,bok,nazwa){}

    //Dziedziczone
    string doTekstu();
    double promienKolaWgPola();
    double promenOkreguWgObwodu();
};

#endif // KWADRAT_H
