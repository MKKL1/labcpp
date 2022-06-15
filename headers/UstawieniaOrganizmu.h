//
// Created by krystian on 11.06.2022.
//

#ifndef EKOSYSTEM_USTAWIENIAORGANIZMU_H
#define EKOSYSTEM_USTAWIENIAORGANIZMU_H

#include <sstream>

class UstawieniaOrganizmu {
public:
    unsigned short zycieMin,zycieMax,kosztPotomka,limitPosilkow;
    UstawieniaOrganizmu() {};
    void czytajLinie(std::istringstream &istringstream, char delimiter);

private:
    static unsigned short czytajUstawienie(std::istringstream &istringstream, char delimiter);
};

#endif //EKOSYSTEM_USTAWIENIAORGANIZMU_H
