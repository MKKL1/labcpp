#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include <string>
#include <iostream>
using namespace std;
class Prostokat
{
protected:
    string nazwa;
    double bok1, bok2;
    bool poprawny;
    double obwod, pole;

    bool czyPoprawny(double bok1, double bok2);
    void obliczObwod();
    void obliczPole();

public:
    Prostokat(double a=1, double b=2, string n = "?");
    ~Prostokat();
    //TODO
    //std::ostream& operator<<(std::ostream& strumien, Prostokat& prostokat);
    //istream& operator>>(istream& strumien, Prostokat& prostokat);
    Prostokat& operator++(int);
    bool operator!() {return czyPoprawny(bok1, bok2);}

    bool czyPoprawny();
    const string& jakaNazwa();
    double podajPole();
    double podajObwod();
    bool zmienBoki(double a, double b);

    virtual std::string doTekstu();
};

#endif // PROSTOKAT_H
