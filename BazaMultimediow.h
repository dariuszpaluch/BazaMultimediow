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
    bool wyswietlWszystkieElementy();
    bool wyswietlWszystkieFilmy();
    bool wyswietlFilmyKtorychNieWidziales();
    bool wyswietlWszystkieGry();
    bool wyswietlWszystkieTytulyElementow();
    bool wyswietlWszystkieTytuluFilmowNieWidzialem();
    bool ustawFilmJakoObejrzany(string tittleMovie);
    
    bool dodajFilm(string tytul, string gatunek, int ocena, string wersja , int rokPremiery, bool widzialem);
    bool dodajGre(string tytul, string gatunek, int ocena);
    bool usunElement(int x);
    bool usunElement(string tytul);
    void usunBazeDanych();
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
    deque<Film*> listaFilmow;
    deque<Gra*> listaGier;
     

     
     
     

};
#endif	/* BAZAMULTIMEDIOW_H */

