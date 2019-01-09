#include "Menu_graphique.h"
#include "options.h"
#include "menu.h"
#include <stdlib.h>
#include <graph.h>
#include <stdio.h>


int Menu_graphique(int * lancer_jeu, int * nbr_pommes, int * taille_ini,int * C_X, int * C_Y,int * echelle,int * intervale,int*score_p,int*niveau,int * continuer) {
	int X = 600;
	int Y = 610;
	//on lance le menu
	while(*continuer == 1){
		Menu(X,Y,continuer,lancer_jeu,nbr_pommes,taille_ini,C_X,C_Y,echelle,intervale,score_p,niveau);
	}
}
