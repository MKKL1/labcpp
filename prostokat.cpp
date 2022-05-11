#include "prostokat.h"
#include <iostream>

Prostokat::Prostokat(double a, double b, string n):nazwa(n)
{
    if (!zmienBoki(a,b)) {
        bok1 = bok2 = pole = obwod = 0;
        poprawny = false;
    }
}

bool Prostokat::zmienBoki(double a, double b) {
    if (czyPoprawny(a,b)) {
        poprawny = true;
        bok1 = a;
        bok2 = b;
        obliczPole();
        obliczObwod();
        return true;
    } else return false;
}

bool Prostokat::czyPoprawny(double bok1, double bok2) {
    return bok1 > 0 && bok2 > 0;
}

void Prostokat::obliczObwod() {
    obwod = 2*(bok1+bok2);
}

void Prostokat::obliczPole() {
    pole = bok1 * bok2;
}

double Prostokat::podajPole() {
    return pole;
}

double Prostokat::podajObwod() {
    return obwod;
}

bool Prostokat::czyPoprawny() {
    return poprawny;
}

const std::string &Prostokat::jakaNazwa() {
    return nazwa;
}

Prostokat::~Prostokat() {
    std::cout << "Prostokąt: " << nazwa << " zostal zniszczony." << std::endl;
}

std::string Prostokat::doTekstu() {
    std::string napis="";
    napis = "Prostokąt o nazwie: " + nazwa + " o bokach "
            + to_string(bok1) + " i " + to_string(bok2);
    if (poprawny)
        napis += " o obwodzie = " + to_string(obwod)
                + " i polu = " + to_string(pole);
    else napis += " jest figurą niepoprawną!";

    return napis;
}

//ostream& Prostokat::operator<<(ostream& strumien, Prostokat & prostokat) {
//    strumien << prostokat.doTekstu();
//    return strumien;
//}

//istream& Prostokat::operator>>(istream& strumien, Prostokat & prostokat) {
//    double a,b;
//    strumien >> a >> b;
//    prostokat.zmienBoki(a,b);
//    return strumien;
//}

Prostokat& Prostokat::operator++(int) {
    this->bok1 *= 2;
    this->bok2 *= 2;
    this->obliczPole();
    this->obliczObwod();
    return *this;
}
