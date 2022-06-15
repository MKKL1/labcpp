//
// Created by krystian on 14.06.2022.
//

#include <QVBoxLayout>
#include <QPainterPath>
#include "OknoEkosystemu.h"
#include "nisza.h"
#include <QGraphicsSimpleTextItem>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>

OknoEkosystemu::OknoEkosystemu(QWidget *parent) : QWidget(parent) {
    this->setLayout(new QVBoxLayout);
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->setScene(scene);
    this->layout()->addWidget(view);
}

OknoEkosystemu::~OknoEkosystemu() {
    delete scene;
    delete view;
}

void OknoEkosystemu::rysujEkosystem(Srodowisko *srodowisko, std::map<Identifikator, std::pair<QBrush, bool>>& styl) {
    scene->clear();

    for(unsigned int w=0; w< srodowisko->wiersze; w++){
        for(unsigned int k=0; k< srodowisko->kolumny; k++){
            QRectF ksztalt = QRectF(w*40,k*40,36,36);
            QBrush brush = styl.at(srodowisko->dajNisze()[w][k].ktoTuMieszka()).first;
            scene->addRect(ksztalt, brush.color(), brush);
        }
    }
    int j = 0;
    //auto *legendalayout = new QGraphicsGridLayout;
    std::map<Identifikator, std::pair<QBrush, bool>>::iterator it;
    for(it = styl.begin(); it != styl.end(); it++) {
        if (it->second.second) {
            std::string stext;
            stext += it->first.jakaNazwa() + " ";
            stext += std::to_string(srodowisko->liczba(it->first));


            auto* io = new QGraphicsTextItem(QString::fromStdString(stext));
            io->setDefaultTextColor(it->second.first.color());
            //auto* rect = new QGraphicsRectItem();
            //rect->setRect(QRectF(0,0,10,10));
            //rect->setBrush(it->second.first);
            io->setPos(0, 550+(12*j));
            scene->addItem(io);
            //legendalayout->addItem(reinterpret_cast<QGraphicsLayoutItem *>(io), j, 0);
            //legendalayout->addItem(reinterpret_cast<QGraphicsLayoutItem *>(rect), j, 1);
            j++;
        }
    }
    //auto *form = new QGraphicsWidget;
    //form->setLayout(legendalayout);
    //scene->addItem(form);
    scene->update();
}