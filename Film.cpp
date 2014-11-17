/* 
 * File:   Film.cpp
 * Author: darek
 * 
 * Created on 9 listopada 2014, 16:54
 */

#include "Film.h"

Film::Film(string tytul, string gatunek, int ocena, string wersja, int rokPremiery):Multimedia(tytul,gatunek,ocena)
{
    this->wersja=wersja;
    this->rokPremiery=rokPremiery;
    iloscFilmow++;
}

Film::~Film()
{
    cout<<"DESTRUKTOR: Film usunięto"<<endl;
    iloscFilmow--;
    
}
int Film::iloscFilmow=0;

void Film::wyswietl()
{
     cout << "Film: " << tytul <<", ";
    cout << "gatunek: " << gatunek <<", ";
    cout << "ocena: " << ocena <<", ";
    cout <<"wersja: "<<wersja<<", ";
    cout <<"premiera: "<<rokPremiery<<endl;
    
}


string Film::opisDoZapisu()
{
    
    int ocena = getOcena();
    ostringstream ss;
    ss << ocena;
    string ocenaString = ss.str();
    
    
    ostringstream ss2;
    ss2 << rokPremiery;
    string rokPremieryString = ss2.str();
    

    string text ="film\t" + tytul+"\t"+gatunek+"\t"+ocenaString+"\t"+wersja+"\t"+rokPremieryString+"\n";
    return text;
}



