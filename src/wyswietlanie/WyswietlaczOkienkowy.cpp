#include "WyswietlaczOkienkowy.h"
#include "OknoEkosystemu.h"

WyswietlaczOkienkowy::WyswietlaczOkienkowy(Srodowisko *srodowisko, QWidget* parent) : WyjscieGraficzne(srodowisko),
                                                                                      QMainWindow(parent){
    oknoEkosystemu = new OknoEkosystemu(this);
    this->resize(600, 600);
    oknoEkosystemu->resize(600,600);
    setCentralWidget(oknoEkosystemu);
}

void WyswietlaczOkienkowy::krokSymulacji(unsigned long krok) {
    oknoEkosystemu->rysujEkosystem(srodowisko, styl);
}

WyswietlaczOkienkowy::~WyswietlaczOkienkowy() {
    delete oknoEkosystemu;
}

void WyswietlaczOkienkowy::dodajStyl(Identifikator &id, const QBrush& brush, bool wyswietl) {
    styl.insert(std::pair<Identifikator, std::pair<QBrush, bool>>(id, std::pair<QBrush, bool>(brush, wyswietl)));
}
