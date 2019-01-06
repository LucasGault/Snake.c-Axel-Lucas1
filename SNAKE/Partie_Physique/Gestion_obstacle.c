#include "Gestion_obstacle.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int Pomme_obstacle(Pommes_liste *Pommes_liste_1,int X , int Y){
	/* 
	Cette fonction vérifie si des coordonés X ou Y sont égaux aux coordonés d'une des pommes , 
	si oui elle renvoit 1 et si non , elle renvoit 0.
	Variable 
	--------
	Pommes_liste_1 -> La liste des pommes à tester du type Pommes_liste
	X -> Coordonés X à tester
	Y -> Coordonés Y à tester
	Retourne
	--------
	1 ou 0
	*/
	int i;
	for (i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
		if (Pommes_liste_1->tab[i].Coord.X == X && Pommes_liste_1->tab[i].Coord.Y == Y){
			return 1;
		}
	}
	return 0;
}
int Pomme_Pomme(Pommes_liste* Pommes_liste_1,int X , int Y , int i){
	/*
	Cette fonction vérifie si des coordonés X ou Y sont égaux aux coordonés d'une des pommes , 
	si oui elle renvoit 1 et si non , elle renvoit 0.
	Variable 
	--------
	Pommes_liste_1 -> La liste des pommes à tester du type Pommes_liste
	X -> Coordonés X à tester
	Y -> Coordonés Y à tester
	i -> derniére position de la pommes
	Retourne
	--------
	1 ou 0
	*/
	int j;
	for (j = 0 ; j < i ; j++){
		if (Pommes_liste_1->tab[j].Coord.X == X && Pommes_liste_1->tab[j].Coord.Y == Y) {
			return 1;
		}
	}
	return 0;
}
int Obstacle_Obstacle(Obstacle_liste* Obstacle_liste_1,int X , int Y , int i){
	/* 
	Cette fonction vérifie si des coordonés X ou Y sont égaux aux coordonés d'un des obstacles , 
	si oui elle renvoit 1 et si non , elle renvoit 0.
	Variable 
	--------
	Obstacle_liste_1 -> La liste des pommes à tester du type Pommes_liste
	X -> Coordonés X à tester
	Y -> Coordonés Y à tester
	Retourne
	--------
	1 ou 0
	*/
	int j;
	for (j = 0 ; j < i ; j++){
		if (Obstacle_liste_1->tab[j].Coord.X == X && Obstacle_liste_1->tab[j].Coord.Y == Y) {
			return 1;
		}
	}
	return 0;
}
//Cette fonction place aléatoirement les pommes sur la grille de jeu 
Pommes_liste* init_Pommes_liste(int G_X , int G_Y , int nbr_pommes , int echelle){
	Pommes_liste* Pommes_liste_new = malloc(sizeof(Pommes_liste));
	Pommes_liste_new->tab = (Pomme*) malloc(sizeof(Pomme) * nbr_pommes);
	Pommes_liste_new->nbr_pommes = nbr_pommes;
	int i,X,Y;
	for (i = 0 ; i < nbr_pommes ; i++){
		X = (rand() % (G_X - 1)) + 1;
		Y = (rand() % (G_Y - 1)) + 1;
		if (Pomme_Pomme(Pommes_liste_new,X * echelle,Y * echelle,i) == 1 || X * echelle == (G_X * echelle)/2){
			while (Pomme_Pomme(Pommes_liste_new,X * echelle,Y * echelle,i ) == 1 || X * echelle == (G_X * echelle)/2){
				X = (rand() % (G_X - 1)) + 1;
				Y = (rand() % (G_Y - 1)) + 1;
			}
		}
		Pommes_liste_new->tab[i].Coord.X = X * echelle;
		Pommes_liste_new->tab[i].Coord.Y = Y * echelle;
		Pommes_liste_new->tab[i].manger = 0;
	}
	return Pommes_liste_new;
}
void free_pomme(Pommes_liste *Pommes_liste_1){
	free(Pommes_liste_1->tab);
	free(Pommes_liste_1);
}
//Cette fonction place aléatoirement les Obstacles sur la grille de jeu 
Obstacle_liste * init_Obstacle_liste(int G_X, int G_Y, int nbr_obstacle,Pommes_liste* Pommes_liste_1,int echelle){
	Obstacle_liste * Obstacle_liste_new = (Obstacle_liste *)malloc(sizeof(Obstacle_liste));
	Obstacle_liste_new->tab = (Obstacle*) malloc(sizeof(Obstacle) * nbr_obstacle);
	Obstacle_liste_new->nbr_obstacle = nbr_obstacle;
	int X,Y;
	for (int i = 0; i < nbr_obstacle; ++i){
		X = (rand() % (G_X - 1)) + 1;
		Y = (rand() % (G_Y - 1)) + 1;
		if (Obstacle_Obstacle(Obstacle_liste_new,X *echelle,Y*echelle,i) == 1 || X * echelle == (G_X * echelle)/2){
			while (Obstacle_Obstacle(Obstacle_liste_new,X*echelle,Y*echelle,i) == 1 || X * echelle == (G_X * echelle)/2){
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
		Obstacle_liste_new->tab[i].Coord.X = X * echelle;
		Obstacle_liste_new->tab[i].Coord.Y = Y * echelle;
	}
	return Obstacle_liste_new;
}
void free_obstacle(Obstacle_liste* Obstacle_liste_1){
	free(Obstacle_liste_1->tab);
	free(Obstacle_liste_1);
}
