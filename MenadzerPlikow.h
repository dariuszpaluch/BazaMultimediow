/* 
 * File:   MenadzerPlikow.h
 * Author: darek
 *
 * Created on 15 listopad 2014, 20:29
 */

#ifndef MENADZERPLIKOW_H
#define	MENADZERPLIKOW_H
#include <iostream>
#include <string>
#include <fstream>
#include "BazaMultimediow.h"
#include "Film.h"
#include "Multimedia.h"

#include <cstdlib>
#include <iostream>

#include <stdio.h>

using namespace std;
class MenadzerPlikow {
public:
    MenadzerPlikow(char* nazwaPliku);
    void zapiszDoPliku(BazaMultimediow baza);
    BazaMultimediow wczytajZPlik();
private:
    char *nazwaPliku;
    string podkreslenieNaSpacje(string tekst);
    string spacjaNaPodkreslenie(string tekst);

};

#endif	/* MENADZERPLIKOW_H */

