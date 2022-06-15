#ifndef ZAMIARMIESZKANCA_H
#define ZAMIARMIESZKANCA_H
#include "ustawieniasymulacji.h"

class ZamiarMieszkanca
{
public:
    const AkcjaMieszkanca akcja;
    const Polozenie gdzie;

    ZamiarMieszkanca(AkcjaMieszkanca _akcja = NIC,Polozenie _gdzie = NIGDZIE):akcja(_akcja),gdzie(_gdzie){}
};

#endif // ZAMIARMIESZKANCA_H
