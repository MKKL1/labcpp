//
// Created by krystian on 13.06.2022.
//

#include "WyswietlaczKonsolowy.h"
#include <iostream>
void WyswietlaczKonsolowy::krokSymulacji(unsigned long krok) {
    strumien << "Krok symulacji: " << krok << std::endl;
    std::string tekst = "";
    for(unsigned int w=0; w< srodowisko->wiersze; w++){
        for(unsigned int k=0; k< srodowisko->kolumny; k++){
            if(k>0) tekst += separator;
            tekst += znaki.at(srodowisko->dajNisze()[w][k].ktoTuMieszka()).first;
        }
        tekst += '\n';
    }

    strumien << tekst << std::endl;

    std::map<Identifikator, std::pair<char, bool>>::iterator it;
    for(it = znaki.begin(); it != znaki.end(); it++) {
        if (it->second.second)
            strumien << it->first.jakaNazwa() << " " << it->second.first << " : " << srodowisko->liczba(it->first) << std::endl;
    }
    strumien << std::endl;
}
