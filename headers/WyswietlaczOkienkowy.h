//
// Created by krystian on 14.06.2022.
//

#ifndef EKOSYSTEM_WYSWIETLACZOKIENKOWY_H
#define EKOSYSTEM_WYSWIETLACZOKIENKOWY_H


#include <QMainWindow>
#include <QApplication>
#include "WyjscieGraficzne.h"
#include "OknoEkosystemu.h"

class WyswietlaczOkienkowy: public QMainWindow, public WyjscieGraficzne{
    Q_OBJECT
private:
    OknoEkosystemu* oknoEkosystemu;
    std::map<Identifikator, std::pair<QBrush, bool>> styl;
public:
    WyswietlaczOkienkowy(Srodowisko *srodowisko, QWidget* parent = nullptr);
    ~WyswietlaczOkienkowy();
    void dodajStyl(Identifikator& id, const QBrush& brush, bool wyswietl = true);
    public slots:
    virtual void krokSymulacji(unsigned long krok);
};


#endif //EKOSYSTEM_WYSWIETLACZOKIENKOWY_H
