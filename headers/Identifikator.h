//
// Created by krystian on 07.06.2022.
//

#ifndef EKOSYSTEM_IDENTIFIKATOR_H
#define EKOSYSTEM_IDENTIFIKATOR_H

#include <string>

class Identifikator {
private:
    unsigned short id;
    std::string nazwa;
public:
    Identifikator(unsigned short id = 0, std::string nazwa = ""):id(id),nazwa(nazwa) {}

    bool operator==(const Identifikator& a) const {
        return this->id==a.id;
    }
    bool operator!=(const Identifikator& a) const {
        return this->id!=a.id;
    }
    bool operator<( const Identifikator& a) const
    {
        return this->id<a.id;
    }

    unsigned short jakieId() const {return id;}
    std::string jakaNazwa() const {return nazwa;}
};


#endif //EKOSYSTEM_IDENTIFIKATOR_H
