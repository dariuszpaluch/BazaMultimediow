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

class Film : public Multimedia {
public:
    Film(string tytul, string gatunek, int ocena, string wersja, int rokPremiery, bool widzialem);
    virtual ~Film();

    static int getIloscFilmow() {
        return iloscFilmow;
    }


    friend class BazaMultimediow;
    virtual string opisDoZapisu();
    virtual void wyswietl();

    string getWersja() const {
        return wersja;
    }

    void setWersja(string wersja) {
        this->wersja = wersja;
    }

    int getRokPremiery() const {
        return rokPremiery;
    }

    void setRokPremiery(int rokPremiery) {
        this->rokPremiery = rokPremiery;
    }

    bool isWidzialem() const {
        return widzialem;
    }

    void setWidzialem() {
        this->widzialem = true;
    }


private:
    static int iloscFilmow;
    string wersja;
    int rokPremiery;
    bool widzialem;


};

#endif	/* FILM_H */

