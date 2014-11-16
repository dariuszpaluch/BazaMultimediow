/* 
 * File:   Film.cpp
 * Author: darek
 * 
 * Created on 9 listopada 2014, 16:54
 */

#include "Film.h"

Film::Film(string tytul, string gatunek, int ocena):Multimedia(tytul,gatunek,ocena)
{
    iloscFilmow++;
}

Film::~Film()
{
    cout<<"DESTRUKTOR: Film usunięto"<<endl;
    iloscFilmow--;
    
}

void Film::wyswietl()
{
     cout << "Film: " << tytul <<", ";
    cout << "gatunek: " << gatunek <<", ";
    cout << "ocena: " << ocena << endl;
    
}


string Film::opisDoZapisu()
{
    
    int ocena = getOcena();
    ostringstream ss;
    ss << ocena;
    string ocenaString = ss.str();
    

    string text ="film\t" + tytul+"\t"+gatunek+"\t"+ocenaString+"\n";
    return text;
}

ostream & operator<<(ostream &wyjscie, const Film &film)
{   
    return wyjscie << " tytuł:"<<film.getTytul()<<", gatunek:"<<film.getGatunek()<<", ocena:"<<film.getOcena()<<".\n";
}
int Film::iloscFilmow=0;
