//
// Created by krystian on 14.06.2022.
//

#ifndef EKOSYSTEM_OKNOEKOSYSTEMU_H
#define EKOSYSTEM_OKNOEKOSYSTEMU_H


#include <QGraphicsView>
#include "srodowisko.h"

class OknoEkosystemu : public QWidget{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
public:
    OknoEkosystemu(QWidget *parent = nullptr);
    void rysujEkosystem(Srodowisko* srodowisko, std::map<Identifikator, std::pair<QBrush, bool>>& styl);
    ~OknoEkosystemu() override;
};


#endif //EKOSYSTEM_OKNOEKOSYSTEMU_H
