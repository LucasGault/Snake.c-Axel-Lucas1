#include "menu.h"
#include <stdlib.h>
#include <graph.h>
#include <stdio.h>

void Menu(int X,int Y ,int * continuer){
    InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChargerImageFond("serpent.png");
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(260,Y/2,"Jouer",2);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(260,Y/1.5,"Options",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(60,540,"Niveau : ",1.5);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(375,540,"Score : ",1.5);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(10,600,"Quitter (Esc)",2);
    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		//printf("X %d Y %d\n",_X,_Y );
            if(_X>=262 && _Y>=284 && _X<=341 && _Y<=306){
                FermerGraphique();
                Jeu(X,Y);
                break;
            }
            if(_X>=257 && _Y>=394 && _X<=371 && _Y<=408){
            	FermerGraphique();
                Options(X,Y);
                break;
            }
            if(_X>=7 && _Y>=587 && _X<=86 && _Y<=604){
            	*continuer = 0;
            	break;
            }
        }
        if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                *continuer = 0;
                break;
            }
        }
    }
}