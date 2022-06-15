//
// Created by krystian on 13.06.2022.
//

#ifndef EKOSYSTEM_WYSWIETLACZKONSOLOWY_H
#define EKOSYSTEM_WYSWIETLACZKONSOLOWY_H


#include "WyjscieGraficzne.h"
#include <map>
#include <string>
#include <utility>
#include <iostream>
/**
 * Ten wyświetlacz pozwala na wypisane ekosystemu na podanym strumieniu
 * <br>Przykład <br>
 * Krok symulacji: 0<br>
@ _ _ _ _ _ _ _ _<br>
_ _ _ _ _ _ _ _ _<br>
_ _ _ _ _ _ # _ _<br>
_ _ _ * _ _ # _ _<br>
_ _ _ _ _ _ _ _ _<br>
_ _ _ _ _ _ _ _ _<br>
<br>
Martwe + : 0<br>
Bakteria @ : 1<br>
Glon * : 1<br>
Grzyb # : 2<br>
 */
class WyswietlaczKonsolowy: public WyjscieGraficzne {
private:
    std::map<Identifikator, std::pair<char, bool>> znaki;
    char separator = ' ';
    std::basic_ostream<char>& strumien;
public:
    /**
     * @param srodowisko wskażnik do symulowanego ekosystemu
     * @param strumienwyjsciowy strumien na którym wyświetlany jest ekosystem
     */
    WyswietlaczKonsolowy(Srodowisko* srodowisko, std::basic_ostream<char>& strumienwyjsciowy = std::cout):
        WyjscieGraficzne(srodowisko),strumien(strumienwyjsciowy){}
    /**
     * Wysyła do strumienia ekosystem jako byte. Używać przed kolejnym krokiem symulacji
     * @param krok liczba porządkowy kroku symulacji
     */
    virtual void krokSymulacji(unsigned long krok);
    /**
     * Ustawia gotową mape znaków
     * @see #ustawZnaki(std::map<Identifikator, std::pair<char, bool>>&)
     */
    void ustawZnaki(std::map<Identifikator, std::pair<char, bool>>& _znaki) {znaki = _znaki;}
    /**
     * Dodaje pojedyńczy znak do mapy
     * @param id Identyfikator mieszkańca (ListaMieszkancow::?)
     * @param znak znak mieszkańca
     * @param wyswietlanie czy ma wyświetlić liczbę danych mieszkańców
     */
    void dodajZnak(Identifikator id, char znak, bool wyswietlanie = true){
        znaki.insert(std::pair<Identifikator,std::pair<char, bool>>(
                    id,
                    std::pair<char, bool>(znak, wyswietlanie)));
    };
    /**
     * @param _separator znak oddzielający kolumny
     */
    void ustawSeparator(char _separator) {separator = _separator;}
};


#endif //EKOSYSTEM_WYSWIETLACZKONSOLOWY_H
