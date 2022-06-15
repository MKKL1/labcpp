#ifndef USTAWIENIASYMULACJI_H
#define USTAWIENIASYMULACJI_H
#include <map>
#include "UstawieniaOrganizmu.h"

enum AkcjaMieszkanca {POTOMEK, POLOWANIE, ROZKLAD, NIC};

enum Polozenie {P=0, PG=1, G=2, LG=3, L=4, LD=5, D=6, PD=7, NIGDZIE=8 };

class UstawieniaSymulacji
{
public:
    std::map<std::string, UstawieniaOrganizmu> ustawienia;

    void wczytajZPliku(std::string sciezka);
    UstawieniaOrganizmu& znajdzUstawieniaOrganizmu(std::string nazwaOrganizmu);

//private:
//    UstawieniaSymulacji(UstawieniaSymulacji&) {};

protected:
    UstawieniaSymulacji(){}

public:
    static UstawieniaSymulacji & pobierzUstawienia() {
        static UstawieniaSymulacji ustawienia;
        return ustawienia;
    }
};
#endif // USTAWIENIASYMULACJI_H
