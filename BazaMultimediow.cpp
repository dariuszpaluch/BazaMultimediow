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

bool BazaMultimediow::wyswietlWszystkieElementy()
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


        return true;
    } else
        return false;

}

bool BazaMultimediow::wyswietlWszystkieFilmy()
{
    int size = listaFilmow.size();


    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            listaFilmow[i]->wyswietl();
        }
        cout << endl;
        return true;
    } else
    {
        return false;
    }
}

bool BazaMultimediow::wyswietlWszystkieGry()
{
    int size = listaGier.size();


    if (size > 0)
    {
        cout << "Twoja baza gier:" << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            //Film film = **listaFilmow[i];
            // (Film)listaFilmow[i]->wyswietl();
            listaGier[i]->wyswietl();
        }
        cout << endl;
        return true;
    } else
    {
        return false;
    }
}

bool BazaMultimediow::wyswietlWszystkieTytulyElementow()
{
    if (listaElementow.size() > 0)
    {


        for (int i = 0; i < listaElementow.size(); i++)
            cout << i + 1 << "." << (*listaElementow[i]) << endl;
        // cout << i+1 << ". " << listaElementow[i]->getTytul() << endl;



        cout << endl;
        return true;
    } else
        return false;
}

bool BazaMultimediow::wyswietlFilmyKtorychNieWidziales()
{
    bool brakFilmowDoWyswietlenia = false;
    for (int i = 0; i < listaFilmow.size(); i++)
    {
        if (!listaFilmow[i]->isWidzialem())
        {
            listaFilmow[i]->wyswietl();
            brakFilmowDoWyswietlenia = true;

        }

    }
    cout << endl;

    if (brakFilmowDoWyswietlenia)
        return true;
    else
        return false;
}

bool BazaMultimediow::setSelectWatchedMovie(string tittleMovie)
{
    for (int i = 0; i < listaFilmow.size(); i++)
    {
        if (listaFilmow[i]->getTytul() == tittleMovie)
        {
            listaFilmow[i]->setWidzialem();
            return true;
        }


    }


    return false;
}

bool BazaMultimediow::wyswietlWszystkieTytuluFilmowNieWidzialem()
{
    int size = listaFilmow.size();
    //dynamic_cast < Kwadrat *>( p );
    int j = 1;
    for (int i = 0; i < size; i++)
    {
        if (!listaFilmow[i]->isWidzialem())
        {
            cout << j << "." << listaFilmow[i]->getTytul() << endl;
            j++;
        }
    }

    if (j > 0)
        return true;
    else
        return false;
}

bool BazaMultimediow::dodajFilm(string tytul, string gatunek, int ocena, string wersja, int rokPremiery, bool widzialem)
{
    if ((tytul.length() > 0) && (gatunek.length() > 0) && (ocena != 0))
    {
        //Film film(tytul, gatunek, ocena, wersja, rokPremiery);
        listaElementow.push_back(new Film(tytul, gatunek, ocena, wersja, rokPremiery, widzialem));
        listaFilmow.push_back((Film*) listaElementow[listaElementow.size() - 1]);
        //   cout<< "Ilosc filmow: "<<listaFilmow.size()<<endl;
        return true;
    } else
        return false;
}

bool BazaMultimediow::dodajGre(string tytul, string gatunek, int ocena)
{
    if ((tytul.length() > 0) && (gatunek.length() > 0) && (ocena != 0))
    {

        listaElementow.push_back(new Gra(tytul, gatunek, ocena));
        listaGier.push_back((Gra*) listaElementow[listaElementow.size() - 1]);




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
