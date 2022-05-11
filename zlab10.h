#ifndef ZLAB10_H
#define ZLAB10_H

#import <vector>
#import <set>
#import <map>

class ZLab10
{
public:
    void wektor();
    template <class T> void wyswietlWektor(std::vector<T> wektor);
    template <class T> void wyswietlZbior(std::set<T> zbior, bool full = false);
    void wektor_sortowanie();
    void zbior();
    void mapa();
};

#endif // ZLAB10_H
