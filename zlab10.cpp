#include "zlab10.h"
#include <iostream>

using namespace std;

void ZLab10::wektor() {
    vector<double> wektor;

    wektor.push_back(2.3);
    wektor.push_back(4.5);
    wektor.push_back(-2.3);
    wektor.push_back(0.1);

    wyswietlWektor(wektor);

    //Proba zapisania poza granica
//    for(unsigned long i=5; i < 10; i++)
//        wektor[i] = 3.2;

//    wyswietlWektor(wektor);

    //Zwiekszenie rozmiaru
    wektor.resize(12);
    for(unsigned long i=5; i < 10; i++)
        wektor[i] = 3.2;
    wyswietlWektor(wektor);

    //Zapisz przy uzyciu petli
    for(unsigned long i=0; i < wektor.size(); i++)
        wektor[i] = i;

    wyswietlWektor(wektor);

    //Zapis przy uzyciu petli zakresowej
    for(double & d: wektor) d = 3.14;

    wyswietlWektor(wektor);

    //Czyszczenie
    wektor.clear();
    wyswietlWektor(wektor);
}

template <class T>
void ZLab10::wyswietlWektor(vector<T> wektor) {
    cout << "Rozmiar wektora: " << wektor.size() << endl;
    for(T d: wektor)
        cout << d << " ";
    cout << endl << endl;
}

#include "generatorlosowy.h"
#include <algorithm>
void ZLab10::wektor_sortowanie() {
    vector<int> wektor;
    wektor.resize(13);
    for(int & j: wektor)
        j = GEN::losujOdZeraDo(20);

    wyswietlWektor(wektor);

    cout << "Wektor wygenerowany" << endl;

    sort(wektor.begin(), wektor.end());
    wyswietlWektor(wektor);

    cout << "Wektor pomieszany" << endl;
    random_shuffle(wektor.begin(), wektor.end(), GEN::losujOdZeraDo);

    wyswietlWektor(wektor);
}

template <class T>
void ZLab10::wyswietlZbior(set<T> zbior, bool full) {

    //TODO
    if (full) {
        set<string>::iterator iter = zbior.begin();
        while(iter != zbior.end()){
            cout << *iter << " ";
            iter++;
        }
        cout << endl << endl;
        return;
    }

    for(T d: zbior)
        cout << d << " ";
    cout << endl << endl;
}

void ZLab10::zbior() {
    set<string> imiona;
    imiona.insert("Adam");
    imiona.insert("Ewa");
    imiona.insert("Maciek");

    wyswietlZbior(imiona);

    imiona.insert("Adam");
    imiona.insert("Iwona");
    imiona.insert("Ewa");
    imiona.insert("Beata");
    imiona.insert("Maciek");

    wyswietlZbior(imiona);

    wyswietlZbior(imiona, true);
}

//TODO
void ZLab10::mapa() {
    map<char, double> pomiary;

    pomiary.insert(pair<char, double>('A', 20));
    pomiary.insert(pair<char, double>('B', 30));
    pomiary.insert(pair<char, double>('C', 50));
    pomiary.insert(pair<char, double>('D', 25));
    pomiary.insert(pair<char, double>('A', 20));
    pomiary.insert(pair<char, double>('A', 40));

    cout << "Wyswietlanie mapy" << endl;
    for(char c:{'A', 'B', 'C'})
        cout << c << "->" << pomiary[c] << endl;

    cout << "Policz A -> " << pomiary.count('A') << endl;

    pomiary.erase('A');
    cout << "Wyswietlanie mapy" << endl;
    for(char c:{'A', 'B', 'C'})
        cout << c << "->" << pomiary[c] << endl;
    cout << "Policz A -> " << pomiary.count('A') << endl;

}
