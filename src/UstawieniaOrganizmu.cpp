#include "UstawieniaOrganizmu.h"

void UstawieniaOrganizmu::czytajLinie(std::istringstream &istringstream, char delimiter) {
    zycieMin = czytajUstawienie(istringstream, delimiter);
    zycieMax = czytajUstawienie(istringstream, delimiter);
    kosztPotomka = czytajUstawienie(istringstream, delimiter);
    limitPosilkow = czytajUstawienie(istringstream, delimiter);
}

unsigned short UstawieniaOrganizmu::czytajUstawienie(std::istringstream &istringstream, char delimiter) {
    std::string tmp;
    std::getline(istringstream, tmp, delimiter);
    return static_cast<unsigned short>(std::strtoul(tmp.c_str(), nullptr, 0));
}