/* 
 * File:   Gra.cpp
 * Author: Dariusz Paluch
 * 
 * Created on 16 listopad 2014, 11:26
 */

#include "Gra.h"

Gra::Gra(string tytul, string gatunek, int ocena) : Multimedia(tytul, gatunek, ocena)
{
    iloscGier++;
}

Gra::~Gra()
{
    cout << "DESTRUKTOR: Gre usunięto" << endl;
    iloscGier--;
}

int Gra::iloscGier = 0;

void Gra::wyswietl()
{
    cout << "Gra: " << tytul << ", ";
    cout << "gatunek: " << gatunek << ", ";
    cout << "ocena: " << ocena << endl;

}

string Gra::opisDoZapisu()
{

    int ocena = getOcena();
    ostringstream ss;
    ss << ocena;
    string ocenaString = ss.str();


    string text = "gra\t" + tytul + "\t" + gatunek + "\t" + ocenaString + "\n";
    return text;
}


