/* 
 * File:   MenadzerPlikow.cpp
 * Author: darek
 * 
 * Created on 15 listopad 2014, 20:29
 */

#include "MenadzerPlikow.h"

MenadzerPlikow::MenadzerPlikow(char *nazwaPliku)
{
    this->nazwaPliku = nazwaPliku;
}

string MenadzerPlikow::podkreslenieNaSpacje(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
        if (tekst[i] == '_')
            tekst[i] = ' ';

    return tekst;
}

string MenadzerPlikow::spacjaNaPodkreslenie(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
        if (tekst[i] == ' ')
            tekst[i] = '_';

    return tekst;
}

void MenadzerPlikow::zapiszDoPliku(BazaMultimediow baza)
{
    //zapis pliku
    fstream plik;
    plik.open(nazwaPliku, std::ios::out);



    if (plik.good() == true)
    {
        cout << "Uzyskano dostep do zapisu bazy danych." << endl;

        for (int i = 0; i < baza.iloscWszystkichElementow(); i++)
        {
            string tekstDoZapisu = baza.listaElementow[i]->opisDoZapisu();
            tekstDoZapisu = spacjaNaPodkreslenie(tekstDoZapisu);
            plik << tekstDoZapisu;
        }
        cout << endl;
        cout << "Baza danych została zapisana." << endl;
    } else cout << "Brak dostepu do pliku, nie zapisano danych." << endl;
    plik.close();

}

BazaMultimediow MenadzerPlikow::wczytajZPlik()
{
    BazaMultimediow baza;

    // odczyt z pliku
    fstream plik_odczyt;
    string tytul, gatunek;
    string rodzaj;
    int ocena;
    string wersja;
    string widzialemString;
    bool widzialem;
    int rokPremiery;
    plik_odczyt.open(nazwaPliku, std::ios::in);

    if (plik_odczyt.good() == true)
    {
        std::cout << "Uzyskano dostęp do pliku." << std::endl;
        while (true)
        {
            plik_odczyt >>rodzaj;

            if (rodzaj == "film")
            {
                plik_odczyt >> tytul >> gatunek >> ocena >> wersja >> rokPremiery>>widzialemString;
                if (widzialemString == "TAK")
                    widzialem = true;
                else
                    widzialem = false;
            }

            if (rodzaj == "gra")
                plik_odczyt >> tytul >> gatunek >> ocena;



            if (plik_odczyt.good())
            {
                tytul = podkreslenieNaSpacje(tytul);
                gatunek = podkreslenieNaSpacje(gatunek);

                if (rodzaj == "film")
                    baza.dodajFilm(tytul, gatunek, ocena, wersja, rokPremiery, widzialem);
                if (rodzaj == "gra")
                    baza.dodajGre(tytul, gatunek, ocena);
            } else
                break;
        }

        std::cout << "Wczytano baze danych." << std::endl;

    } else std::cout << "Brak bazy danych!" << std::endl;
    plik_odczyt.close();

    return baza;
}
