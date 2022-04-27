#ifndef GRZYB_H
#define GRZYB_H
#include "mieszkaniec.h"
#include "organizm.h"

class Grzyb: protected Organizm, public Mieszkaniec
{
public:

    Grzyb();
    virtual RodzajMieszkanca kimJestes() final;
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);

};

#endif // GRZYB_H
