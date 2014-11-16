/* 
 * File:   PanelMenu.cpp
 * Author: darek
 * 
 * Created on 8 listopada 2014, 20:49
 */

#include "PanelMenu.h"
#include "BazaMultimediow.h"
#include <stdio.h>
#include "Film.h"

PanelMenu::PanelMenu(BazaMultimediow * bazafilmow) {
    this->bazaFilmow = bazafilmow;

}

PanelMenu::PanelMenu(const PanelMenu& orig) {
}

PanelMenu::~PanelMenu() {
}

int PanelMenu::stringToInt(string text) {
    int x;
    istringstream iss(text);
    iss >> x;
    return x;
}

int PanelMenu::showMainMenu() {
    int wybor = -1;
    while (wybor != 0) {


        cout << "\n"
                "-------------MENU-------------\n"
                "1.Wyswietl spis filmów. \n"
                "2.Dodaj film. \n"
                "3.Dodaj gre. \n"
                "3.Usuń film. \n"
                "0.WYJSCIE."
                "\n"
                "Wprowadz nr wyboru:";

        wybor = getAnswer();
        cout << "------------------------------" << endl;
        system("clear");
        switch (wybor) {
            case 0:
                return 0;
            case 1:

                if (bazaFilmow->iloscFilmow() > 0) {
                    if (bazaFilmow->iloscFilmow() == 1)
                        cout << "Posiadasz: " << bazaFilmow->iloscFilmow() << " film." << endl;
                    else {
                        if (bazaFilmow->iloscFilmow() <= 3)
                            cout << "Posiadasz: " << bazaFilmow->iloscFilmow() << " filmy." << endl;
                        else
                            cout << "Posiadasz: " << bazaFilmow->iloscFilmow() << " filmów." << endl;
                    }

                    bazaFilmow->wyswietlWszystkieElementy();

                } else
                    cout << "Twoja baza filmow jest pusta !" << endl;
                break;
            case 2:
                addMovieFromUser();
                break;
            case 3:
                addGameFromUser();
                break;
            case 4:
                if (bazaFilmow->iloscFilmow() == 0)
                    cout << "Twoja baza filmow jest pusta !" << endl;
                else
                    removeSelectMovie();
                break;

                break;
            default:
                cout << "***Nie ma takiego wyboru.**** \n";
        }
        cout << endl << "Naciśnij aby kontynuować.";
        getchar();
        system("clear");

    }
}

int PanelMenu::getAnswer() {
    string odpowiedz;
    cin >>odpowiedz;
    cin.clear();
    cin.ignore(); // to wywołanie usunie z bufora znak '\n' pozostawiony przez obiekt "cin"

//    if (isdigit(odpowiedz[0]) && odpowiedz.length() == 1) {

        return stringToInt(odpowiedz);
//    } else
//        return -1;

}

void PanelMenu::addMovieFromUser() {
    string tytul, gatunek;
    int ocena = -1;
    cout << "Tytuł filmu:";
    getline(cin, tytul);

    cout << "Gatunek filmu:";
    getline(cin, gatunek);

    string ocenaString;
    cout << "Ocene filmu (0-10):";
    getline(cin, ocenaString);

    if (ocenaString == "10" || (ocenaString.length() == 1 && isdigit(ocenaString[0]))) {
        ocena = stringToInt(ocenaString);
    }

    if (tytul.length() > 0 && gatunek.length() > 0 && ocena != -1) {
        bazaFilmow->dodajFilm(tytul, gatunek, ocena);
        cout << "Dodano film do bazy danych" << endl;

    } else
        cout << "Złe wprowadzone dane. Spróboj jeszcze raz." << endl;
}

void PanelMenu::addGameFromUser()
{
     string tytul, gatunek;
    int ocena = -1;
    
    
    cout << "Tytuł gry:";
    getline(cin, tytul);

    cout << "Gatunek gry:";
    getline(cin, gatunek);

    string ocenaString;
    cout << "Ocene gry (0-10):";
    getline(cin, ocenaString);

    if (ocenaString == "10" || (ocenaString.length() == 1 && isdigit(ocenaString[0]))) {
        ocena = stringToInt(ocenaString);
    }

    if (tytul.length() > 0 && gatunek.length() > 0 && ocena != -1) {
        bazaFilmow->dodajGre(tytul, gatunek, ocena);
        cout << "Dodano gre do bazy danych" << endl;

    } else
        cout << "Złe wprowadzone dane. Spróboj jeszcze raz." << endl;
    
}
void PanelMenu::removeSelectMovie() {
    bazaFilmow->wyswietlWszystkieTytulyElementow();

    cout << endl << "Wprowadz nazwe lub numer filmu do usunięcia: ";
    string answer;
    getline(cin, answer);
    bool czyNumer = true;

    for (int i = 0; i < answer.length(); i++) {
        if (!isdigit(answer[i]))
            czyNumer = false;
    }

    if (czyNumer && answer.length() > 0) {
        if (answer[0] == '0')
            czyNumer = false;
    }

    bool usuniecie;
    if (czyNumer) {
        int index = stringToInt(answer);
        usuniecie = bazaFilmow->usunFilm(index);
    } else {
        usuniecie = bazaFilmow->usunFilm(answer);
    }


    if (!usuniecie)
        cout << "Takiego filmu nie ma w bazie" << endl;

}