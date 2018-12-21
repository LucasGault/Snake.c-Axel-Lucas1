#include "Gestion_obstacle.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int Pomme_obstacle(Pommes_liste *Pommes_liste_1,int X , int Y){
	int i;
	for (i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
		if (Pommes_liste_1->tab[i].Coord.X == X && Pommes_liste_1->tab[i].Coord.Y == Y){
			return 1;
		}
	}
	return 0;
}
int Pomme_Pomme(Pommes_liste* Pommes_liste_1,int X , int Y , int i){
	int j;
	for (j = 0 ; j < i ; j++){
		if (Pommes_liste_1->tab[j].Coord.X == X && Pommes_liste_1->tab[j].Coord.Y == Y) {
			return 1;
		}
	}
	return 0;
}
int Obstacle_Obstacle(Obstacle_liste* Obstacle_liste_1,int X , int Y , int i){
	int j;
	for (j = 0 ; j < i ; j++){
		if (Obstacle_liste_1->tab[j].Coord.X == X && Obstacle_liste_1->tab[j].Coord.Y == Y) {
			return 1;
		}
	}
	return 0;
}

Pommes_liste init_Pommes_liste(int G_X , int G_Y , int nbr_pommes , int echelle){
	Pommes_liste Pommes_liste_new;
	Pommes_liste_new.tab = (Pomme*) malloc(sizeof(Pomme) * nbr_pommes);
	Pommes_liste_new.nbr_pommes = nbr_pommes;
	int i,X,Y;
	for (i = 0 ; i < nbr_pommes ; i++){
		X = (rand() % (G_X - 1)) + 1;
		Y = (rand() % (G_Y - 1)) + 1;
		if (Pomme_Pomme(&Pommes_liste_new,X * echelle,Y * echelle,i) == 1 || X * echelle == (G_X * echelle)/2){
			while (Pomme_Pomme(&Pommes_liste_new,X * echelle,Y * echelle,i ) == 1 || X * echelle == (G_X * echelle)/2){
				X = (rand() % (G_X - 1)) + 1;
				Y = (rand() % (G_Y - 1)) + 1;
			}
		}
		Pommes_liste_new.tab[i].Coord.X = X * echelle;
		Pommes_liste_new.tab[i].Coord.Y = Y * echelle;
		Pommes_liste_new.tab[i].manger = 0;
	}
	return Pommes_liste_new;
}

Obstacle_liste init_Obstacle_liste(int G_X, int G_Y, int nbr_obstacle,Pommes_liste* Pommes_liste_1,int echelle){
	Obstacle_liste Obstacle_liste_new;
	Obstacle_liste_new.tab = (Obstacle*) malloc(sizeof(Obstacle) * nbr_obstacle);
	Obstacle_liste_new.nbr_obstacle = nbr_obstacle;
	int X,Y;
	for (int i = 0; i < nbr_obstacle; ++i){
		X = (rand() % (G_X - 1)) + 1;
		Y = (rand() % (G_Y - 1)) + 1;
		if (Obstacle_Obstacle(&Obstacle_liste_new,X *echelle,Y*echelle,i) == 1 || X * echelle == (G_X * echelle)/2){
			while (Obstacle_Obstacle(&Obstacle_liste_new,X*echelle,Y*echelle,i) == 1 || X * echelle == (G_X * echelle)/2){
				X = (rand() % (G_X - 1)) + 1;
				Y = (rand() % (G_Y - 1)) + 1;
			}
		}
		if (Pomme_obstacle(Pommes_liste_1,X*echelle,Y*echelle) == 1){
			while (Pomme_obstacle(Pommes_liste_1,X*echelle,Y*echelle) == 1){
				X = (rand() % (G_X - 1)) + 1;
				Y = (rand() % (G_Y - 1)) + 1;
			}
		}
		Obstacle_liste_new.tab[i].Coord.X = X * echelle;
		Obstacle_liste_new.tab[i].Coord.Y = Y * echelle;
	}
	return Obstacle_liste_new;
}
