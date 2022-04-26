#ifndef ZAMIARMIESZKANCA_H
#define ZAMIARMIESZKANCA_H
#include "ustawieniasymulacji.h"
//TODO oddzielny plik dla każdego enuma ?

class ZamiarMieszkanca
{
public:
    ZamiarMieszkanca();
    const AkcjaMieszkanca akcja;
    const Polozenie gdzie;

    ZamiarMieszkanca(AkcjaMieszkanca _akcja = NIC,Polozenie _gdzie = NIGDZIE)
        :akcja(_akcja),gdzie(_gdzie){}
};

#endif // ZAMIARMIESZKANCA_H
