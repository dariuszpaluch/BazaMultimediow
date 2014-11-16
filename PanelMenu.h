/* 
 * File:   PanelMenu.h
 * Author: darek
 *
 * Created on 8 listopada 2014, 20:49
 */

#ifndef PANELMENU_H
#define	PANELMENU_H

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "BazaMultimediow.h"
#include <cstdio>
#include <stdlib.h>
using namespace std;

class PanelMenu
{
public:
    PanelMenu(BazaMultimediow * bazaFilmow);
    PanelMenu(const PanelMenu& orig);
    virtual ~PanelMenu();
    int showMainMenu();
    int getAnswer();
    void addMovieFromUser();
    void addGameFromUser();
    void removeSelectMovie();
    int stringToInt(string text);
private:
    BazaMultimediow *bazaElementow;
};

#endif	/* PANELMENU_H */

