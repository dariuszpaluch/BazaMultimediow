/* 
 * File:   main.cpp
 * Author: Dariusz Paluch
 *
 * Created on 9 listopada 2014, 16:49
 */

#include <cstdlib>
#include "Film.h"
#include "BazaMultimediow.h"
#include "PanelMenu.h"
#include "MenadzerPlikow.h"
#include "Multimedia.h"
#include <string>
#include <deque>



using namespace std;

int main(int argc, char** argv)
{
    char nazwaPlik[] = "plik.txt";

    MenadzerPlikow menadzerPliku(nazwaPlik);
    BazaMultimediow bazaDanych;
    bazaDanych = menadzerPliku.wczytajZPlik();

    PanelMenu panel(&bazaDanych);
    panel.pokazGlowneMenu();

    menadzerPliku.zapiszDoPliku(bazaDanych);
    bazaDanych.usunBazeDanych();

    return 0;
}
