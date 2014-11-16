/* 
 * File:   BazaMultimediow.cpp
 * Author: darek
 * 
 * Created on 9 listopada 2014, 17:27
 */

#include "BazaMultimediow.h"
#include <string>
#include <iostream>
using namespace std;

BazaMultimediow::BazaMultimediow()
{
}


BazaMultimediow::~BazaMultimediow()
{
}

 void BazaMultimediow::wyswietlWszystkieElementy()
 {
     
     for (int i=0;i<listaFilmow.size();i++)
     {
         cout<<i+1<<".";
        listaFilmow[i]->wyswietl();
     }
         
     
     cout<<endl;
     
 }
 void BazaMultimediow::wyswietlWszystkieTytulyElementow()
 {
     for (int i=0;i<listaFilmow.size();i++)
         cout<<i<<". "<<listaFilmow[i]->getTytul()<<endl;
     
     cout<<endl;
     
 }
 
   bool BazaMultimediow::dodajFilm(string tytul, string gatunek, int ocena)
   {
         if ((tytul.length()>0) && (gatunek.length() >0) && (ocena !=0))
        {
            
            listaFilmow.push_back(new Film(tytul,gatunek,ocena));
            
            
        
            
            return true;
        } else 
            return false;
   }

   bool BazaMultimediow::dodajGre(string tytul, string gatunek, int ocena)
   {
          if ((tytul.length()>0) && (gatunek.length() >0) && (ocena !=0))
        {
            
            listaFilmow.push_back(new Film(tytul,gatunek,ocena));
            
            
        
            
            return true;
        } else 
            return false;   if ((tytul.length()>0) && (gatunek.length() >0) && (ocena !=0))
        {
            
            listaFilmow.push_back(new Gra(tytul,gatunek,ocena));
            
            
        
            
            return true;
        } else 
            return false;
          
   }
    bool BazaMultimediow::usunFilm(int x) 
    {
        if (x<listaFilmow.size())
        {
            delete listaFilmow[x];
             listaFilmow.erase(listaFilmow.begin()+x);
             return true;
        }else
        {
            return false;
        }
       
        
    }
    bool BazaMultimediow::usunFilm(string tytul)
    {
   
        for (int i =0;i<listaFilmow.size(); i++)
        {
           if (listaFilmow[i]->getTytul() == tytul)
           {
                delete listaFilmow[i];
                listaFilmow.erase(listaFilmow.begin()+i);
                
                return true;
                
               
           }
        }
        
        return false;
    }
