#include <iostream>
#include "KsiazkaAdresowa.h"
#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    AdresatMenedzer adresatMenedzer;
    PlikZAdresatami plikZAdresatami;
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika = 0;
    char wybor;

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                cout << "Koniec programu." << endl;
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            if (adresatMenedzer.pobierzAdresatow().empty() == true)
                {
                adresatMenedzer.ustawIdOstatniegoAdresata( plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika) );
                }

            wybor = adresatMenedzer.wybierzOpcjeZMenuUzytkownika();
/*
            switch (wybor)
            {
            case '1':
                idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '4':
                wyswietlWszystkichAdresatow(adresaci);
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
                adresaci.clear();
                break;
            } */
        }
    }
    return 0;
}
