/* 
 * File:   BazaMultimediow.cpp
 * Author: darek
 * 
 * Created on 9 listopada 2014, 17:27
 */

#include "BazaMultimediow.h"
#include <string>
#include <iostream>
using namespace std;

BazaMultimediow::BazaMultimediow()
{
}

BazaMultimediow::~BazaMultimediow()
{
}

void BazaMultimediow::wyswietlWszystkieElementy()
{
    int size = listaElementow.size();
    if (size > 0)
    {


        cout << "Twoja baza danych:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            listaElementow[i]->wyswietl();
        }


        cout << endl;
    } else
    {
        cout << "Twoja baza danych jest pusta." << endl;
    }

}

void BazaMultimediow::wyswietlWszystkieTytulyElementow()
{
    for (int i = 0; i < listaElementow.size(); i++)
        cout<<i+1<<"."<<(*listaElementow[i])<<endl;
       // cout << i+1 << ". " << listaElementow[i]->getTytul() << endl;
        
       

    cout << endl;

}

bool BazaMultimediow::dodajFilm(string tytul, string gatunek, int ocena, string wersja, int rokPremiery)
{
    if ((tytul.length() > 0) && (gatunek.length() > 0) && (ocena != 0))
    {

        listaElementow.push_back(new Film(tytul, gatunek, ocena, wersja, rokPremiery));

        return true;
    } else
        return false;
}

bool BazaMultimediow::dodajGre(string tytul, string gatunek, int ocena)
{
    if ((tytul.length() > 0) && (gatunek.length() > 0) && (ocena != 0))
    {

        listaElementow.push_back(new Gra(tytul, gatunek, ocena));




        return true;
    } else
        return false;
    if ((tytul.length() > 0) && (gatunek.length() > 0) && (ocena != 0))
    {

        listaElementow.push_back(new Gra(tytul, gatunek, ocena));




        return true;
    } else
        return false;

}

bool BazaMultimediow::usunElement(int x)
{
    if (x < listaElementow.size())
    {
        delete listaElementow[x];
        listaElementow.erase(listaElementow.begin() + x);
        return true;
    } else
    {
        return false;
    }


}

bool BazaMultimediow::usunElement(string tytul)
{

    for (int i = 0; i < listaElementow.size(); i++)
    {
        if (listaElementow[i]->getTytul() == tytul)
        {
            delete listaElementow[i];
            listaElementow.erase(listaElementow.begin() + i);

            return true;


        }
    }

    return false;
}

void BazaMultimediow::UsunBazeDanych()
{
     for (int i = 0; i < listaElementow.size(); i++)
    {
            delete listaElementow[i];
    }
}
