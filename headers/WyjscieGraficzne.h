#ifndef EKOSYSTEM_WYJSCIEGRAFICZNE_H
#define EKOSYSTEM_WYJSCIEGRAFICZNE_H


#include "nisza.h"

class WyjscieGraficzne {

protected:
    Srodowisko* srodowisko;

public:
    WyjscieGraficzne(Srodowisko* srodowisko) {this->srodowisko=srodowisko;}
    virtual void krokSymulacji(unsigned long krok) = 0;

};


#endif //EKOSYSTEM_WYJSCIEGRAFICZNE_H
