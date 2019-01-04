#include "menu.h"
#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
void Dessiner_texte2(int X , int Y , char* texte,couleur couleur_texte, int taille){
	ChoisirCouleurDessin(couleur_texte);
	int longueur_t = TailleChaineEcran(texte,taille);
	EcrireTexte(X - longueur_t/2,Y + TailleSupPolice(taille),texte,taille);

}
void Menu(int X,int Y ,int * continuer,int *lancer_jeu,int * nbr_pommes , int * taille_ini,int * C_X, int * C_Y,int * echelle,int * intervale,int*score_p,int*niveau){
    //Initialisation Menu
    InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChargerImageFond("Menu/serpent.png");
    Dessiner_texte2(X/2,5*Y/12,"Jouer",CouleurParComposante(255,255,255),2);
    Dessiner_texte2(X/2,7*Y/12,"Options",CouleurParComposante(255,255,255),2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    //Niveau/score
    char Afficher[20];
    sprintf(Afficher,"Niveau : %d",*niveau);
    EcrireTexte(60,540,Afficher,1.5);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    sprintf(Afficher,"Score : %d",*score_p);
    EcrireTexte(375,540,Afficher,1.5);

    Dessiner_texte2(100,580,"Quitter (Esc)",CouleurParComposante(255,255,255),2);
    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		//printf("X %d Y %d\n",_X,_Y );
            if(_X>=X/2 - TailleChaineEcran("Jouer",2)/2 && _Y>=5*Y/12  && _X<=X/2 + TailleChaineEcran("Jouer",2)/2  && _Y<=5*Y/12 + TailleSupPolice(2)){
                FermerGraphique();
                *continuer = 0;
                *lancer_jeu = 1;
                break;
            }
            if(_X>=X/2 - TailleChaineEcran("Options",2)/2 && _Y>=7*Y/12  && _X<=X/2 + TailleChaineEcran("Options",2)/2  && _Y<=7*Y/12 + TailleSupPolice(2)){
            	FermerGraphique();
              Options(X,Y,continuer,nbr_pommes,taille_ini,C_X,C_Y,lancer_jeu,echelle,intervale);
              break;
            }
            if(_X>=100 - TailleChaineEcran("Quitter (Esc)",2)/2 && _Y>=580  && _X<=550 + TailleChaineEcran("Quitter (Esc)",2)/2  && _Y<=580 + TailleSupPolice(2)){
                FermerGraphique();
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