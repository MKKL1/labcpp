//
// Created by krystian on 06.06.2022.
//

#ifndef EKOSYSTEM_REJESTRMIESZKANCOW_H
#define EKOSYSTEM_REJESTRMIESZKANCOW_H
#include <utility>

#include "mieszkaniec.h"
#include "UstawieniaOrganizmu.h"

class RejestrMieszkancow {
private:
    static unsigned short id;
public:
    static Identifikator zarejestrujMieszkanca(std::string name) {
        Identifikator identifikator = Identifikator(++id, std::move(name));
        return std::move(identifikator);
    }

    template<class T> static Identifikator zarejestrujMieszkanca(std::string name, const UstawieniaOrganizmu *ustawieniaOrganizmu) {
        Mieszkaniec* mieszkaniec = new T(ustawieniaOrganizmu);
        Identifikator newid = Identifikator(++id, std::move(name));
        mieszkaniec->ustawId(newid);
        delete mieszkaniec;
        return std::move(newid);
    }

};


#endif //EKOSYSTEM_REJESTRMIESZKANCOW_H
