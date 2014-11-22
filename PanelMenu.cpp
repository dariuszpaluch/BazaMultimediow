/* 
 * File:   PanelMenu.cpp
 * Author: Dariusz Paluch
 * 
 * Created on 9 listopada 2014, 20:49
 */

#include "PanelMenu.h"

PanelMenu::PanelMenu(BazaMultimediow * bazaElementow)
{
    this->bazaElementow = bazaElementow;

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

int PanelMenu::pokazGlowneMenu()
{
    system("clear");
    int wybor = -1;
    while (wybor != 0)
    {

        cout << "\n"
                "-------------MENU-------------\n"
                "1.Wyświetl spis wszystkich elementów. \n"
                "2.Wyświetl wszystkie filmy.\n"
                "3.Wyświetl wszytkie gry.\n"
                "4.Wyświetl filmy które nie widziałeś.\n"
                "5.Dodaj film. \n"
                "6.Dodaj gre. \n"
                "7.Zaznacz że obejrzałeś jakiś film.\n"
                "8.Usuń element. \n"
                "9.Usuń całą baze danych.\n"
                "0.WYJSCIE."
                "\n"
                "Wprowadz nr wyboru:";

        wybor = pobierzNumerOdpowiedz();
        cout << "------------------------------" << endl;
        system("clear");
        switch (wybor)
        {
            case 0:
                return 0;
            case 1:
                wyswietlWszystkieElementy();
                break;
            case 2:
                wyswietlWszystkieFilmy();
                break;
            case 3:
                wyswietlWszystkieGry();
                break;
            case 4:
                wyswietlFilmyKtorychNieWidziales();
                break;
            case 5:
                dodajFilmPrzezUzytkownika();
                break;
            case 6:
                dodajGrePrzezUzytkownika();
                break;
            case 7:
                ustawFilmOgladany();
                break;
            case 8:
                usunWybranyElement();
                break;
            case 9:
                usunCalaBazeDanych();
                break;
            default:
                cout << "***Nie ma takiego wyboru.**** \n";
        }
        cout << endl << "Naciśnij enter aby kontynuować.";
        cin.get();
        system("clear");

    }
}

void PanelMenu::wyswietlWszystkieElementy()
{
    cout << "Twoja baza danych:" << endl;
    if (!bazaElementow->wyswietlWszystkieElementy())
    {
        system("clear");
        cout << "Twoja baza danych jest pusta." << endl;
    }


}

void PanelMenu::wyswietlWszystkieFilmy()
{
    cout << "Twoja baza filmów:" << endl;
    if (!bazaElementow->wyswietlWszystkieFilmy())
    {
        system("clear");
        cout << "Twoja baza filmów jest pusta." << endl;
    }
}

void PanelMenu::wyswietlWszystkieGry()
{
    cout << "Twoja baza gier:" << endl;
    if (!bazaElementow->wyswietlWszystkieGry())
    {
        system("clear");
        cout << "Twoja baza gier jest pusta." << endl;
    }

}

void PanelMenu::wyswietlFilmyKtorychNieWidziales()
{
    cout << "Filmy których jeszcze nie widziałeś:" << endl;
    if (!bazaElementow->wyswietlFilmyKtorychNieWidziales())
    {
        system("clear");
        cout << "Widziałeś wszystkie filmy z twojej bazy danych." << endl;
    }

}

int PanelMenu::pobierzNumerOdpowiedz()
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

void PanelMenu::dodajFilmPrzezUzytkownika()
{
    string tytul;
    cout << "Tytuł filmu:";
    getline(cin, tytul);

    string gatunek;
    cout << "Gatunek filmu:";
    getline(cin, gatunek);

    string ocenaString;
    int ocena = -1;
    cout << "Ocene filmu (0-10):";
    getline(cin, ocenaString);

    ocena = stringToInt(ocenaString);
    if (!(ocena <= 10 && ocena >= 0))
        ocena = -1;

    bool wprowadzonaWersja = false;
    string wersja;
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

    string widzialem = "";
    cout << "Czy widziałeś ten film (TAK,NIE):";
    getline(cin, widzialem);
    bool widzialemBool;
    if (widzialem == "TAK" || widzialem == "Tak" || widzialem == "tak")
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

void PanelMenu::dodajGrePrzezUzytkownika()
{


    string tytul;
    cout << "Tytuł gry:";
    getline(cin, tytul);

    string gatunek;
    cout << "Gatunek gry:";
    getline(cin, gatunek);

    string ocenaString;
    int ocena = -1;
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

void PanelMenu::ustawFilmOgladany()
{
    if (bazaElementow->wyswietlWszystkieTytuluFilmowNieWidzialem())
    {
        cout << endl << "Wprowadz nazwę filmu który widziałeś: ";
        string answer;
        getline(cin, answer);
        bool widzialem = false;
        widzialem = bazaElementow->ustawFilmJakoObejrzany(answer);


        if (widzialem)
            cout << "Zmieniono dane filmu";
        else
            cout << "Nie ma takiego filmu.";

    } else
        cout << "Widziałeś wszystkie filmy z bazy danych";
}

void PanelMenu::usunWybranyElement()
{

    if (bazaElementow->wyswietlWszystkieTytulyElementow())
    {
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
    } else
        cout << "Twoja baza danych jest pusta.";
}

void PanelMenu::usunCalaBazeDanych()
{
    string odpowiedz;
    cout<<"Czy napewno chcesz usunac cala baze danych? (TAK/NIE)";
    cin>>odpowiedz;
    
    if (odpowiedz=="TAK" || odpowiedz=="tak" || odpowiedz=="Tak")
        bazaElementow->usunBazeDanych();
    
    cin.clear();
    cin.ignore();
}