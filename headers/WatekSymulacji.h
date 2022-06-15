#ifndef EKOSYSTEM_WATEKSYMULACJI_H
#define EKOSYSTEM_WATEKSYMULACJI_H


#include <QThread>
#include "srodowisko.h"

class WatekSymulacji : public QThread{
    Q_OBJECT
private:
    Srodowisko* srodowisko;
    unsigned long maxkrokow = 200;
public:
    WatekSymulacji(Srodowisko* _srodowisko);
    void ustawMaxLiczeKrokow(unsigned long kroki) {maxkrokow = kroki;}
    void run();
signals:
    void krokSymulacji(unsigned long krok);
};


#endif //EKOSYSTEM_WATEKSYMULACJI_H
