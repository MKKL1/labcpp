#include "srodowisko.h"
#include "nisza.h"
#include "generatorlosowy.h"
#include "ustawieniasymulacji.h"
#include "indeks2d.h"
#include "sasiedztwo.h"

Srodowisko::Srodowisko(unsigned int _wiersze, unsigned int _kolumny)
    :wiersze(_wiersze),kolumny(_kolumny),liczbaNisz(_wiersze * _kolumny) {
    nisza = new Nisza*[wiersze];
    for(unsigned int i =0; i < wiersze;i++)
        nisza[i] = new Nisza[kolumny];
}

Srodowisko::~Srodowisko(){
    for(unsigned int i=0; i<wiersze; i++)
        delete [] nisza[i];
    delete []nisza;
}

void Srodowisko::lokuj(Mieszkaniec *mieszkaniec,
                       unsigned int wiersz, unsigned int kolumna)
{
    if(wiersz < wiersze && kolumna < kolumny)
        nisza[wiersz][kolumna].przyjmijLokatora(mieszkaniec);
}

Sasiedztwo Srodowisko::ustalSasiedztwo(unsigned int wiersz, unsigned int kolumna) const{
    Sasiedztwo sasiedztwo(SCIANA);

    long wiersz1, kolumna1;

    for(Polozenie p : {P, PG, G, LG, L, LD, D, PD}) {
        wiersz1 = wiersz;
        kolumna1 = kolumna;

        Sasiedztwo::zmienIndeksyWgPolozenia(p, wiersz1, kolumna1);

        if(wiersz>=0 && wiersz1<wiersze && kolumna1>=0 && kolumna1 < kolumny) {
            sasiedztwo.okreslSasiada(p, nisza[wiersz1][kolumna1].ktoTuMieszka());
        }
    }
    return sasiedztwo;
}

unsigned long Srodowisko::liczba(RodzajMieszkanca rodzaj) const {
    unsigned long licznik = 0;

    for(unsigned int w = 0; w < wiersze; w++)
        for(unsigned int k = 0; k < kolumny; k++)
            if(nisza[w][k].ktoTuMieszka() == rodzaj)
                licznik++;
    return licznik;
}

bool Srodowisko::martwy(){
    return liczba(GLON)+liczba(GRZYB)+liczba(BAKTERIA)==0;
}

void Srodowisko::wykonajSkok(unsigned int wiersz, unsigned int kolumna){
    if(!nisza[wiersz][kolumna].lokatorZywy() ||
            nisza[wiersz][kolumna].ktoTuMieszka()==GLON) return;
    Sasiedztwo sasiedztwo = ustalSasiedztwo(wiersz, kolumna);
    if(sasiedztwo.ile(PUSTKA) > 0) {
        Polozenie polozenie = sasiedztwo.losujSasiada(PUSTKA);
        unsigned int wiersz1 = wiersz, kolumna1 = kolumna;

        Sasiedztwo::zmienIndeksyWgPolozenia(polozenie, wiersz1, kolumna1);

        nisza[wiersz1][kolumna1] = nisza[wiersz][kolumna];
    }
}

void Srodowisko::wykonajAkcje(unsigned int wiersz, unsigned int kolumna)
{
    if(!nisza[wiersz][kolumna].lokatorZywy()) return;

    Sasiedztwo sasiedztwo = ustalSasiedztwo(wiersz,kolumna);

    ZamiarMieszkanca zamiar = nisza[wiersz][kolumna].aktywujLokatora(sasiedztwo);

    unsigned int wiersz1 = wiersz, kolumna1 = kolumna;

    Sasiedztwo::zmienIndeksyWgPolozenia(zamiar.gdzie, wiersz1, kolumna1);

    Mieszkaniec *m =nullptr;

    switch (zamiar.akcja) {
        case NIC:
            wykonajSkok(wiersz,kolumna); break;
        case POTOMEK:
            m = nisza[wiersz][kolumna].wypuscPotomka();
            nisza[wiersz1][kolumna1].przyjmijLokatora(m);
            break;

        case POLOWANIE:
        case ROZKLAD:
            m = nisza[wiersz1][kolumna1].oddajLokatora();
            nisza[wiersz][kolumna].przyjmijZdobycz(m);
            break;
    }
}

void Srodowisko::wykonajKrokSymulacji(){
    WektorIndeksow2D indeksyLosowe = GeneratorLosowy::indeksyLosowe(wiersze, kolumny);

    for(Indeks2D indeks : indeksyLosowe)
        wykonajAkcje(indeks.wiersz, indeks.kolumna);
}

std::string Srodowisko::doTekstu() const
{
    std::string tekst ="";
    char sep = UstawieniaSymulacji::pobierzUstawienia().znakSeparator;

    for(unsigned int w=0; w<wiersze; w++){
        for(unsigned int k=0; k<kolumny; k++){
            if(k>0) tekst += sep;

            tekst += nisza[w][k].jakiSymbol();
        }
        tekst += '\n';
    }

    tekst += "\n Glony * : " + std::to_string(liczba(GLON))
    + "\n Grzyby # : " + std::to_string(liczba(GRZYB))
    + "\nBakterie @ : " + std::to_string(liczba(BAKTERIA))
    + "\n Martwe + : " + std::to_string(liczba(TRUP))
    +'\n';

    return tekst;
}
