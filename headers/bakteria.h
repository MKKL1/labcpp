#ifndef BAKTERIA_H
#define BAKTERIA_H
#include "organizm.h"
#include "mieszkaniec.h"
#include "zamiarmieszkanca.h"
#include "UstawieniaOrganizmu.h"

class Bakteria: protected Organizm, public Mieszkaniec
{
private:
    static Identifikator id;
    static const UstawieniaOrganizmu* ustawieniaOrganizmu;
public:
    Bakteria();
    Bakteria(const UstawieniaOrganizmu* ustorg);
    virtual Identifikator kimJestes() final;
    virtual bool czyMozeSkakac();
    virtual bool czyZywy() {return zywy();}
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);
    virtual void ustawId(Identifikator _id) { id = std::move(_id);}
};

#endif // BAKTERIA_H
