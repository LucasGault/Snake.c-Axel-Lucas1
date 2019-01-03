#include "Menu_graphique.h"
#include "jeu.h"
#include "options.h"
#include "menu.h"
#include <stdlib.h>
#include <graph.h>
#include <stdio.h>


int Menu_graphique(int * lancer_jeu) {
	int X = 600;
	int Y = 610;
	int continuer = 1;
	//on lance le menu
	while(continuer == 1){
		Menu(X,Y,&continuer,lancer_jeu);
	}
}
