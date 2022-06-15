#include "generatorlosowy.h"
#include <algorithm>

std::random_device GeneratorLosowy::device;

template <class T>
T GeneratorLosowy::losujPomiedzy(T min, T max) {
    if(min>max) {
        T t = min;
        min = max;
        max = t;
    }
    std::uniform_int_distribution<T> dist(min,max);

    return dist(GeneratorLosowy::device);
}

unsigned short GeneratorLosowy::losujPomiedzy(unsigned short min, unsigned short max) {
    if(min>max) {
        unsigned short t = min;
        min = max;
        max = t;
    }
    std::uniform_int_distribution<unsigned short> dist(min,max);

    return dist(GeneratorLosowy::device);
}

template <class T>
T GeneratorLosowy::losujOdZeraDo(T max) {
    std::uniform_int_distribution<T> dist(0, max);
    return dist(GeneratorLosowy::device);
}

WektorIndeksow2D GeneratorLosowy::indeksyLosowe(unsigned int wiersze, unsigned int kolumny) {
    WektorIndeksow2D indeksy;
    for(unsigned int w=0; w < wiersze; w++)
        for(unsigned int k=0; k < kolumny; k++)
            indeksy.push_back(Indeks2D(w,k));

    std::random_shuffle(indeksy.begin(), indeksy.end(),GeneratorLosowy::losujOdZeraDo<int>);
    return indeksy;
}
