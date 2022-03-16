#include <iostream>
#include <zlab02.h>
#include <prostokat.h>

using namespace std;

int main()
{
    //Lab 03
    Prostokat prostokat1(20, 5,"nazwa");
    Prostokat prostokat2(25.4, 2.2,"prostokat 2");
    cout.precision(2);
    cout << prostokat1.doTekstu() << endl;
    cout << prostokat2.doTekstu() << endl;

    prostokat1 = prostokat2;

    cout << prostokat1.doTekstu() << endl;
    cout << prostokat2.doTekstu() << endl;


    /*Lab 02
    cout << "Laboratoria test2" << endl;
    ZLab02 lab02;
    lab02.menu();
    */
    return 0;
}
