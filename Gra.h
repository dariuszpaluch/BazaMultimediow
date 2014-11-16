/* 
 * File:   Gra.h
 * Author: darek
 *
 * Created on 16 listopad 2014, 11:26
 */

#ifndef GRA_H
#define	GRA_H
#include <ostream>
#include <sstream>
#include <iostream>
#include <string>
#include "Multimedia.h"


using namespace std;

class Gra : public Multimedia{
public:
    Gra(string tytul, string gatunek, int ocena);
    virtual ~Gra();
    static int getIloscGier()
    {
        return iloscGier;
    }
    friend ostream & operator<<(ostream &wyjscie, const Gra &gra);
    friend class BazaMultimediow;
    virtual string opisDoZapisu();
    virtual void wyswietl();
private:
    static int iloscGier;
};

#endif	/* GRA_H */

