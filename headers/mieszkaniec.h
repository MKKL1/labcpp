//
// Created by krystian on 04.06.2022.
//

#ifndef EKOSYSTEM_MIESZKANIEC_H
#define EKOSYSTEM_MIESZKANIEC_H


#include "ustawieniasymulacji.h"
#include "sasiedztwo.h"
#include "zamiarmieszkanca.h"

class Mieszkaniec
{
public:
    Mieszkaniec() {}
    virtual ~Mieszkaniec() {};
    virtual Identifikator kimJestes() = 0;
    virtual bool czyMozeSkakac() = 0;
    virtual bool czyZywy() = 0;
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo) =0;
    virtual Mieszkaniec * dajPotomka() = 0;
    virtual void przyjmijZdobycz(Mieszkaniec * mieszkaniec) = 0;
    virtual void ustawId(Identifikator _id) = 0;
};


#endif //EKOSYSTEM_MIESZKANIEC_H
