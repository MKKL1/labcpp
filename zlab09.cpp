#include "zlab09.h"
#include <iostream>
#include "glon.h"

using namespace std;

void ZLab09::rozmiary() {
    std::cout << "Rozmiary \nint " << sizeof(int) << "\nint* " << sizeof(int*) <<"\nint** " << sizeof(int**);
    std::cout << "\nGlon " << sizeof(Glon) << "\nGlon* " << sizeof(Glon*) << "\nGlon** " << sizeof(Glon**);
    std::cout << endl;
}

void ZLab09::skalar()
{
    cout << "--->Skalar" << endl;
    wskInt1D = new int;
    *wskInt1D = 5;
    cout << "*wskInt1D = " << *wskInt1D << endl
    << "*wskInt1D + 3 = " << *wskInt1D + 3 << endl
    << "adres zapisany w wskInt1D ->" << wskInt1D
           << endl << endl;

    delete wskInt1D;
}

void ZLab09::tablica1D()
{
    cout << "--->Tablica 1D" << endl;
    wskInt1D = new int [3];

    wskInt1D[0] = 2;
    *(wskInt1D+1) = 5;
    wskInt1D[2] = 7;

    cout << *wskInt1D << " " << wskInt1D[1] << " " << *(wskInt1D+2) << endl;

    int * iter = wskInt1D;
    cout << *iter << " ";
    iter++;
    cout << *iter << " ";
    iter++;
    cout << *iter << endl;

    delete [] wskInt1D;
}

void ZLab09::tablica2D(int w, int k)
{
    cout << "--->Tablica 2D" << endl;

    wskInt2D = new int*[w];

    for(int i=0; i<w; i++)
        wskInt2D[i] = new int(k);
    //Wpisanie
    for(int i=0; i<w; i++)
        for(int j=0; j<k; j++)
            wskInt2D[i][j] = i + j;
    //Wyswietlenie
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<k; j++)
            cout << wskInt2D[i][j] << " ";
        cout << endl;
    }

    for(int i=0; i<k; i++)
        delete [] wskInt2D[i];

    delete [] wskInt2D;

}

void ZLab09::referencja()
{
    cout << "---> Referencje" << endl;

    int a = 1, b = 5;
    cout << "a=" << a << " b=" << b << endl;

    int & refInt = a; //Łączenie z a
    cout << "a=" << a << " b=" << b << endl;

    refInt = b; //?Łączenie z b?
    cout << "a=" << a << " b=" << b << endl;

    cout << "To samo ale na wskaźnikach" << endl;
    int A = 1, B = 5;
    cout << "A=" << A << " B=" << B << endl;

    int * wskInt = &A;
    cout << "A=" << A << " B=" << B << endl;

    wskInt = &B;
    cout << "A=" << A << " B=" << B << endl;

    Glon glon;
    Glon &refGlon = glon;

    cout << "Rozmiary" << endl
    << "sizeof (int &)=" << sizeof (int &) << endl
    << "sizeof(refInt)=" << sizeof(refInt) << endl
    << "sizeof(Glon &)=" << sizeof(Glon &) << endl
    << "sizeof(refGlon)=" << sizeof(refGlon) << endl;
}
