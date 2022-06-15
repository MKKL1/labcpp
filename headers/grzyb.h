#ifndef GRZYB_H
#define GRZYB_H
#include "organizm.h"
#include "mieszkaniec.h"
#include "Identifikator.h"
#include "zamiarmieszkanca.h"
#include "sasiedztwo.h"

class Grzyb: protected Organizm, public Mieszkaniec
{
private:
    static Identifikator id;
    static const UstawieniaOrganizmu* ustawieniaOrganizmu;
public:
    Grzyb();
    Grzyb(const UstawieniaOrganizmu* ustorg);
    virtual Identifikator kimJestes() final;
    virtual bool czyMozeSkakac();
    virtual bool czyZywy() {return zywy();}
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);
    virtual void ustawId(Identifikator _id) { id = std::move(_id);}
};

#endif // GRZYB_H
