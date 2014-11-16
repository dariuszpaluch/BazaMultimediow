/* 
 * File:   Gra.cpp
 * Author: darek
 * 
 * Created on 16 listopad 2014, 11:26
 */

#include "Gra.h"

Gra::Gra(string tytul, string gatunek, int ocena) :Multimedia(tytul,gatunek,ocena) {
    iloscGier++;
}


Gra::~Gra() {
    cout<<"DESTRUKTOR: Gre usunięto"<<endl;
    iloscGier--;
}

void Gra::wyswietl()
{
     cout << "tytuł: " << tytul << endl;
    cout << "gatunek: " << gatunek << endl;
    cout << "ocena: " << ocena << endl;
    
}

string Gra::opisDoZapisu()
{
    
    int ocena = getOcena();
    ostringstream ss;
    ss << ocena;
    string ocenaString = ss.str();
    

    string text = tytul+"\t"+gatunek+"\t"+ocenaString+"\n";
    return text;
}

ostream & operator<<(ostream &wyjscie, const Gra &gra)
{   
    return wyjscie << " tytuł:"<<gra.getTytul()<<", gatunek:"<<gra.getGatunek()<<", ocena:"<<gra.getOcena()<<".\n";
}

int Gra::iloscGier=0;