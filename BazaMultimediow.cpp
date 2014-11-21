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

void BazaMultimediow::wyswietlWszystkieFilmy ()
{
    int size = listaFilmow.size();
    
    
    if (size > 0)
    {
        cout << "Twoja baza filmow:" <<size<< endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            //Film film = **listaFilmow[i];
           // (Film)listaFilmow[i]->wyswietl();
            listaElementow[listaFilmow[i]]->wyswietl();
        }
        cout << endl;
    } else
    {
        cout << "Twoja baza filmów jest pusta." << endl;
    }
}

void BazaMultimediow::wyswietlWszystkieGry ()
{
    int size = listaGier.size();
    
    
    if (size > 0)
    {
        cout << "Twoja baza gier:" <<size<< endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            //Film film = **listaFilmow[i];
           // (Film)listaFilmow[i]->wyswietl();
            listaElementow[listaGier[i]]->wyswietl();
        }
        cout << endl;
    } else
    {
        cout << "Twoja baza gier jest pusta." << endl;
    }
}

void BazaMultimediow::wyswietlWszystkieTytulyElementow()
{
    for (int i = 0; i < listaElementow.size(); i++)
        cout<<i+1<<"."<<(*listaElementow[i])<<endl;
       // cout << i+1 << ". " << listaElementow[i]->getTytul() << endl;
        
       

    cout << endl;

}

void BazaMultimediow::wyswietlFilmyKtorychNieWidziales()
{
   bool brakFilmowDoWyswietlenia=false;
    for (int i=0; i< listaFilmow.size(); i++)
    {
        if (!((Film*)listaElementow[listaFilmow[i]])->isWidzialem())
        {
           ((Film*)listaElementow[listaFilmow[i]])->wyswietl();
           brakFilmowDoWyswietlenia=true;
           
        }
            
    }
    
    if (!brakFilmowDoWyswietlenia)
        cout<< "Widziałeś wszystkie filmy z bazy danych.";
    
    cout<<endl;
}

bool BazaMultimediow::setSelectWatchedMovie(string tittleMovie)
{   
    for (int i=0; i<listaFilmow.size(); i++)
    {
        if (listaElementow[listaFilmow[i]]->getTytul()==tittleMovie)
        {
            ((Film*)listaElementow[listaFilmow[i]])->setWidzialem();
            return true;
        }
            
                
    }
       
        
    return false;
}

void BazaMultimediow::wyswietlWszystkieTytuluFilmowNieWidzialem()
{
    int size = listaFilmow.size();
    Film *film;
    //dynamic_cast < Kwadrat *>( p );
    int j=1;
    for (int i=0; i< size; i++)
    {
        film = dynamic_cast <Film*> (listaElementow[listaFilmow[i]]);
        if (!film->isWidzialem())
        {
            cout<<j<<"."<< film->getTytul();
            j++;
        }
            
            
         cout << endl;   
        
    }
}

bool BazaMultimediow::dodajFilm(string tytul, string gatunek, int ocena, string wersja, int rokPremiery, bool widzialem)
{
    if ((tytul.length() > 0) && (gatunek.length() > 0) && (ocena != 0))
    {
        //Film film(tytul, gatunek, ocena, wersja, rokPremiery);
        listaElementow.push_back(new Film(tytul, gatunek, ocena, wersja, rokPremiery, widzialem));
        listaFilmow.push_back(listaElementow.size()-1);
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
        listaGier.push_back(listaElementow.size()-1);




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
