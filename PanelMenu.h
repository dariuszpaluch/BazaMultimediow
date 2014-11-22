/* 
 * File:   PanelMenu.h
 * Author: Dariusz Paluch
 *
 * Created on 9 listopada 2014, 20:49
 */

#ifndef PANELMENU_H
#define	PANELMENU_H

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include "BazaMultimediow.h"
#include "Film.h"
#include "BazaMultimediow.h"

using namespace std;

class PanelMenu {
public:
    PanelMenu(BazaMultimediow * bazaElementow);

    virtual ~PanelMenu();
    int pokazGlowneMenu();
    int pobierzNumerOdpowiedz();
    void wyswietlWszystkieElementy();
    void wyswietlWszystkieFilmy();
    void wyswietlWszystkieGry();
    void wyswietlFilmyKtorychNieWidziales();
    void dodajFilmPrzezUzytkownika();
    void dodajGrePrzezUzytkownika();
    void usunWybranyElement();
    void usunCalaBazeDanych();
    void ustawFilmOgladany();
    int stringToInt(string text);
    
private:
    BazaMultimediow *bazaElementow;
};

#endif	/* PANELMENU_H */

