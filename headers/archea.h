//
// Created by krystian on 13.06.2022.
//

#ifndef EKOSYSTEM_ARCHEA_H
#define EKOSYSTEM_ARCHEA_H

#include "organizm.h"
#include "mieszkaniec.h"
#include "zamiarmieszkanca.h"
#include "UstawieniaOrganizmu.h"

class Archea: protected Organizm, public Mieszkaniec
{
private:
    static Identifikator id;
    static const UstawieniaOrganizmu* ustawieniaOrganizmu;
public:
    Archea();
    Archea(const UstawieniaOrganizmu* ustorg);
    virtual Identifikator kimJestes() final;
    virtual bool czyMozeSkakac();
    virtual bool czyZywy() {return zywy();}
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec* dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec* mieszkaniec);
    virtual void ustawId(Identifikator _id) { id = std::move(_id);}
};


#endif //EKOSYSTEM_ARCHEA_H
