#ifndef GENERATORLOSOWY_H
#define GENERATORLOSOWY_H
#include <random>
#include "indeks2d.h"

class GeneratorLosowy
{
private:
    static std::random_device device;
    GeneratorLosowy() = default;

public:
    template<class T> static T losujPomiedzy(T min, T max);
    static unsigned short losujPomiedzy(unsigned short min, unsigned short max);
    template<class T> static T losujOdZeraDo(T max);
    static WektorIndeksow2D indeksyLosowe(unsigned int wiersze, unsigned int kolumny);



};

typedef GeneratorLosowy GEN;
#endif // GENERATORLOSOWY_H
