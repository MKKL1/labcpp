#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include <string>
using namespace std;
class Prostokat
{
private:
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
    Prostokat& operator=(Prostokat & prostokat2);
    bool czyPoprawny();
    const string& jakaNazwa();
    double podajPole();
    double podajObwod();
    bool zmienBoki(double a, double b);

    std::string doTekstu();
};

#endif // PROSTOKAT_H
