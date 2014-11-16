/* 
 * File:   Film.h
 * Author: darek
 *
 * Created on 9 listopada 2014, 16:54
 */

#ifndef FILM_H
#define	FILM_H
#include <string>
#include <iostream>
#include "Multimedia.h"
#include <ostream>
#include <sstream>

using namespace std;

class Film : public Multimedia
{
public:
    Film(string tytul, string gatunek, int ocena);
    virtual ~Film();
    static int getIloscFilmow() 
    {
        return iloscFilmow;
    }
    friend ostream & operator<<(ostream &wyjscie, const Film &film);
    
    friend class BazaMultimediow;
    virtual string opisDoZapisu();
    virtual void wyswietl();

private:
    static int iloscFilmow;
    
};

#endif	/* FILM_H */

