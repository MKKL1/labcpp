#ifndef GLON_H
#define GLON_H
#include "organizm.h"
#include "mieszkaniec.h"

class Glon: protected Organizm, public Mieszkaniec
{
public:
    Glon();
    virtual RodzajMieszkanca kimJestes() final;
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);
};

#endif // GLON_H
