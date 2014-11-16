/* 
 * File:   MenadzerPlikow.cpp
 * Author: darek
 * 
 * Created on 15 listopad 2014, 20:29
 */

#include "MenadzerPlikow.h"

MenadzerPlikow::MenadzerPlikow(char *nazwaPliku) {
    this->nazwaPliku=nazwaPliku;
}

string MenadzerPlikow::podkreslenieNaSpacje(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
//        if (tekst[i] == '_')
//            tekst[i] = ' ';

    return tekst;
}

string MenadzerPlikow::spacjaNaPodkreslenie(string tekst)
{
    for (int i = 0; i < tekst.length(); i++)
//        if (tekst[i] == ' ')
//            tekst[i] = '_';

    return tekst;
}

void MenadzerPlikow::zapiszDoPliku(BazaMultimediow baza)
{
     //zapis pliku
    fstream plik;
    plik.open(nazwaPliku, std::ios::out );



    if (plik.good() == true)
    {
        cout << "Uzyskano dostep do zapisu bazy danych." << endl;

        for (int i = 0; i < baza.iloscFilmow(); i++)
        {
            string tekstDoZapisu = baza.listaFilmow[i]->opisDoZapisu();
            tekstDoZapisu = spacjaNaPodkreslenie(tekstDoZapisu);
            plik << tekstDoZapisu;
        }
        
        cout<<"Baza danych została zapisana."<<endl;
    } else cout << "Brak dostepu do pliku, nie zapisano danych." << endl;
    plik.close();
    
}

    BazaMultimediow MenadzerPlikow::wczytajZPlik()
    {
        BazaMultimediow baza;
        
        // odczyt z pliku
    fstream plik_odczyt;
    string tytul, gatunek;
    int ocena;
    plik_odczyt.open(nazwaPliku, std::ios::in);

    if (plik_odczyt.good() == true)
    {
        std::cout << "Uzyskano dostęp do pliku." << std::endl;
        while (true)
        {
            plik_odczyt >> tytul >> gatunek>>ocena;

            if (plik_odczyt.good())
            {
                tytul = podkreslenieNaSpacje(tytul);
                gatunek = podkreslenieNaSpacje(gatunek);
                baza.dodajFilm(tytul, gatunek, ocena);
            } else
                break;
        }
        
        std::cout << "Wczytano baze danych." << std::endl;
    } else std::cout <<"Brak bazy danych!" << std::endl;
    plik_odczyt.close();
    
        return baza;
    }
