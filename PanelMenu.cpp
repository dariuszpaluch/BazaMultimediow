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

PanelMenu::PanelMenu(BazaMultimediow * bazafilmow)
{
    this->bazaElementow = bazafilmow;

}

PanelMenu::~PanelMenu()
{
}

int PanelMenu::stringToInt(string text)
{
    bool liczba = true;

    if (text[0] == '0' && text.length() > 1)
        liczba = false;
    else
        for (int i = 0; i < text.length(); i++)
        {
            if (!isdigit(text[i]))
                liczba = false;
        }

    if (liczba)
    {


        int x;
        istringstream iss(text);
        iss >> x;
        return x;
    } else
        return -1;
}

int PanelMenu::showMainMenu()
{
    int wybor = -1;
    while (wybor != 0)
    {


        cout << "\n"
                "-------------MENU-------------\n"
                "1.Wyświetl spis wszystkich elementów. \n"
                "2.Wyświetl wszystkie filmy.\n"
                "3.Wyświetl wszytkie gry.\n"
                "4.Dodaj film. \n"
                "5.Dodaj gre. \n"
                "6.Usuń Element. \n"
                "0.WYJSCIE."
                "\n"
                "Wprowadz nr wyboru:";

        wybor = getAnswer();
        cout << "------------------------------" << endl;
        system("clear");
        switch (wybor)
        {
            case 0:
                return 0;
            case 1:
                bazaElementow->wyswietlWszystkieElementy();
                break;
            case 2:
                bazaElementow->wyswietlWszystkieFilmy();
                break;
            case 3:
                bazaElementow->wyswietlWszystkieGry();
                break;
            case 4:
                addMovieFromUser();
                break;
            case 5:
                addGameFromUser();
                break;
            case 6:
                if (bazaElementow->iloscWszystkichElementow() == 0)
                    cout << "Twoja baza filmow jest pusta !" << endl;
                else
                    removeSelectMovie();
                break;

                break;
            default:
                cout << "***Nie ma takiego wyboru.**** \n";
        }
        cout << endl << "Naciśnij aby kontynuować.";
        cin.get();
        // int x;
        // cin >> x;
        //       cin.clear();
        //       cin.ignore();
        system("clear");

    }
}

int PanelMenu::getAnswer()
{
    string odpowiedz;
    //getline(cin,odpowiedz);
    cin >>odpowiedz;
    cin.clear();
    cin.ignore(); // to wywołanie usunie z bufora znak '\n' pozostawiony przez obiekt "cin"

    if (isdigit(odpowiedz[0]) && odpowiedz.length() == 1)
    {
        return stringToInt(odpowiedz);
    } else
        return -1;

}

void PanelMenu::addMovieFromUser()
{
    string tytul, gatunek;
    int ocena = -1;
    string wersja;
    cout << "Tytuł filmu:";
    getline(cin, tytul);

    cout << "Gatunek filmu:";
    getline(cin, gatunek);

    string ocenaString;
    cout << "Ocene filmu (0-10):";
    getline(cin, ocenaString);

    ocena = stringToInt(ocenaString);
    if (!(ocena <= 10 && ocena >= 0))
        ocena = -1;

    bool wprowadzonaWersja = false;
    cout << "Wersja filmu(pl/napisy/lektor):";
    getline(cin, wersja);

    if (wersja == "pl" || wersja == "napisy" || wersja == "lektor")
        wprowadzonaWersja = true;

    string rokPremieryString;
    cout << "Rok premiery:";
    getline(cin, rokPremieryString);

    int rokPremiery = stringToInt(rokPremieryString);
    if (!(rokPremiery > 1000 && rokPremiery <= 2014))
        rokPremiery = -1;

    string widzialem="";
    cout << "Czy widziałeś ten film (TAK,NIE):";
    getline(cin, widzialem);
    bool widzialemBool;
    if (widzialem == "TAK")
        widzialemBool = true;
    else
        widzialemBool = false;
    


    if (tytul.length() > 0 && gatunek.length() > 0 && ocena != -1 && wprowadzonaWersja && rokPremiery != -1)
    {
        bazaElementow->dodajFilm(tytul, gatunek, ocena, wersja, rokPremiery, widzialemBool);
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

    if (ocenaString == "10" || (ocenaString.length() == 1 && isdigit(ocenaString[0])))
    {
        ocena = stringToInt(ocenaString);
    }

    if (tytul.length() > 0 && gatunek.length() > 0 && ocena != -1)
    {
        bazaElementow->dodajGre(tytul, gatunek, ocena);
        cout << "Dodano gre do bazy danych" << endl;

    } else
        cout << "Złe wprowadzone dane. Spróboj jeszcze raz." << endl;

}

void PanelMenu::removeSelectMovie()
{
    bazaElementow->wyswietlWszystkieTytulyElementow();

    cout << endl << "Wprowadz nazwe lub numer Elementu do usunięcia: ";
    string answer;
    getline(cin, answer);
    bool czyNumer = true;

    for (int i = 0; i < answer.length(); i++)
    {
        if (!isdigit(answer[i]))
            czyNumer = false;
    }

    if (czyNumer && answer.length() > 0)
    {
        if (answer[0] == '0')
            czyNumer = false;
    }

    bool usuniecie;
    if (czyNumer)
    {

        int index = stringToInt(answer);
        index--;
        usuniecie = bazaElementow->usunElement(index);
    } else
    {
        usuniecie = bazaElementow->usunElement(answer);
    }


    if (!usuniecie)
        cout << "Takiego elementu nie ma w bazie." << endl;

}