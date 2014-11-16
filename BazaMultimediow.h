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
    void wyswietlWszystkieTytulyElementow();
    bool dodajFilm(string tytul, string gatunek, int ocena);
    bool dodajGre(string tytul, string gatunek, int ocena);
    bool usunFilm(int x);
    bool usunFilm(string tytul);
    int iloscFilmow()
    {
        return Film::iloscFilmow;
    }
         deque<Multimedia*> listaFilmow;
private:

     
     

     
     
     

};
#endif	/* BAZAMULTIMEDIOW_H */

