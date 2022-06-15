#include <fstream>
#include <sstream>
#include "ustawieniasymulacji.h"
#include <map>

void UstawieniaSymulacji::wczytajZPliku(std::string sciezka) {
    std::ifstream file(sciezka);
    std::string line;
    char fileseparator = ';';
    while(std::getline(file, line))
    {
        std::istringstream linestream(line);
        std::string nazwa;
        UstawieniaOrganizmu ustorg = UstawieniaOrganizmu();
        std::getline(linestream, nazwa, fileseparator);
        ustorg.czytajLinie(linestream, fileseparator);
        ustawienia.insert(std::pair<std::string, UstawieniaOrganizmu>(nazwa, ustorg));
    }
}

UstawieniaOrganizmu &UstawieniaSymulacji::znajdzUstawieniaOrganizmu(std::string nazwaOrganizmu) {
    return ustawienia.at(nazwaOrganizmu);
}
