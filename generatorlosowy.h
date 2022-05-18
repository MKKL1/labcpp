#ifndef GENERATORLOSOWY_H
#define GENERATORLOSOWY_H
#include <random>
#include <indeks2d.h>

class GeneratorLosowy
{
private:
    static std::random_device device;
    GeneratorLosowy() {

    }

public:
    static unsigned short losujPomiedzy(unsigned short min, unsigned short max);
    static long losujPomiedzy(long min, long max);
    static int losujOdZeraDo(int max);
    static WektorIndeksow2D indeksyLosowe(unsigned int wiersze, unsigned int kolumny);
};

typedef GeneratorLosowy GEN;
#endif // GENERATORLOSOWY_H
