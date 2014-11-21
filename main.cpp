/* 
 * File:   main.cpp
 * Author: darek
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
   
    char plik[] = "plik.txt";
    MenadzerPlikow menadzerPliku(plik);
    BazaMultimediow baza;
    
    baza=menadzerPliku.wczytajZPlik();
    
    PanelMenu panel(&baza);
    panel.showMainMenu();
    
    menadzerPliku.zapiszDoPliku(baza);
    
    baza.UsunBazeDanych();
    
    return 0;
}
