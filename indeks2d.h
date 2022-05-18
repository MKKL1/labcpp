#ifndef INDEKS2D_H
#define INDEKS2D_H
#include <iostream>
#include <vector>

class Indeks2D
{
public:
    unsigned int wiersz, kolumna;
    Indeks2D(unsigned int _w=0,unsigned int _k=0):wiersz(_w),kolumna(_k){}
};

typedef std::vector<Indeks2D> WektorIndeksow2D;
#endif // INDEKS2D_H
