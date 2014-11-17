/* 
 * File:   Multimedia.cpp
 * Author: darek
 * 
 * Created on 9 listopada 2014, 16:49
 */

#include "Multimedia.h"

Multimedia::Multimedia(string tytul, string gatunek, int ocena)
{
    this->tytul = tytul;
    this->gatunek = gatunek;
    this->ocena = ocena;
}


Multimedia::~Multimedia()
{
}

ostream & operator<<(ostream &wyjscie, const Multimedia &multimedia)
{   
    return wyjscie << multimedia.tytul;
}