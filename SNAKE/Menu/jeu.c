#include "jeu.h"
#include <stdlib.h>
#include <graph.h>
#include <stdio.h>

void Jeu(int X,int Y){
    InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    InitialiserGraphique();
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(260,Y/2,"LE JEU",2);
    while(1){
        if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                break;
            }
        }
    }
}