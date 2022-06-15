#ifndef GLON_H
#define GLON_H
#include <utility>

#include "sasiedztwo.h"
#include "mieszkaniec.h"
#include "organizm.h"

class Glon: protected Organizm, public Mieszkaniec
{
private:
    static Identifikator id;
    static const UstawieniaOrganizmu* ustawieniaOrganizmu;
public:
    Glon();
    Glon(const UstawieniaOrganizmu* ustorg);
    virtual Identifikator kimJestes() final;
    virtual bool czyMozeSkakac();
    virtual bool czyZywy() {return zywy();}
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);
    virtual void ustawId(Identifikator _id) { id = std::move(_id);}

};

#endif // GLON_H
