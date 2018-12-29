#include "Menu_graphique.h"
#include <stdlib.h>
#include <graph.h>
#include <stdio.h>


int main() {
	int X = 600;
	int Y = 610;
    int continuer = 1;
	while(continuer == 1 ){
		Menu(X,Y,&continuer);
		FermerGraphique();
	}
}
