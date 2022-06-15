//
// Created by krystian on 15.06.2022.
//

#include "WatekSymulacji.h"
#include <iostream>

void WatekSymulacji::run() {
    for(unsigned long i = 0; i < maxkrokow && !srodowisko->martwy(); i++){
        srodowisko->wykonajKrokSymulacji();
        std::cin.ignore(true);
        emit krokSymulacji(i);
    }
}

WatekSymulacji::WatekSymulacji(Srodowisko* _srodowisko):srodowisko(_srodowisko) {}
