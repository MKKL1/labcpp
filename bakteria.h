#ifndef BAKTERIA_H
#define BAKTERIA_H
#include "mieszkaniec.h"
#include "organizm.h"

class Bakteria: protected Organizm, public Mieszkaniec
{
public:
    Bakteria();
    virtual RodzajMieszkanca kimJestes() final;
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);

};

#endif // BAKTERIA_H
