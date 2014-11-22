/* 
 * File:   Multimedia.h
 * Author: Dariusz Paluch
 *
 * Created on 9 listopada 2014, 16:49
 */

#ifndef MULTIMEDIA_H
#define	MULTIMEDIA_H
#include <string>
#include <iostream>

using namespace std;

class Multimedia
{
protected:
    string tytul;
    string gatunek;
    int ocena;

public:
 
    
    Multimedia(string tytul, string gatunek, int ocena);
    virtual ~Multimedia();
    virtual void wyswietl()=0;
    virtual string opisDoZapisu()=0;
    friend ostream & operator<<(ostream &wyjscie, const Multimedia &multimedia);
    string getGatunek() const
    {
        return gatunek;
    }

    void setGatunek(string gatunek)
    {
        this->gatunek = gatunek;
    }

    int getOcena() const
    {
        return ocena;
    }

    void setOcena(int ocena)
    {
        this->ocena = ocena;
    }

    string getTytul() const
    {
        return tytul;
    }

    void setTytul(string tytul)
    {
        this->tytul = tytul;
    }

   
    

};

#endif	/* MULTIMEDIA_H */

