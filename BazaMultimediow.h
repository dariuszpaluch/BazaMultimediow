/* 
 * File:   BazaMultimediow.h
 * Author: darek
 *
 * Created on 9 listopada 2014, 17:27
 */

#ifndef BAZAMULTIMEDIOW_H
#define	BAZAMULTIMEDIOW_H
#include <deque>
#include "Film.h"
#include <string>
#include <iostream> 
#include "Gra.h"

using namespace std;

class BazaMultimediow
{
public:
   
    BazaMultimediow();
    virtual ~BazaMultimediow();
    void wyswietlWszystkieElementy();
    void wyswietlWszystkieFilmy();
    void wyswietlWszystkieGry();
    void wyswietlWszystkieTytulyElementow();
    bool dodajFilm(string tytul, string gatunek, int ocena, string wersja , int rokPremiery, bool widzialem);
    bool dodajGre(string tytul, string gatunek, int ocena);
    bool usunElement(int x);
    bool usunElement(string tytul);
    void UsunBazeDanych();
    int iloscFilmow()
    {
        return Film::getIloscFilmow();
    }
    
    int iloscGier()
    {
        return Gra::getIloscGier();
    }
    
    int iloscWszystkichElementow()
    {
        return listaElementow.size();
    }
    
    
         deque<Multimedia*> listaElementow;
         
private:
    deque<int> listaFilmow;
    deque<int> listaGier;
     

     
     
     

};
#endif	/* BAZAMULTIMEDIOW_H */

