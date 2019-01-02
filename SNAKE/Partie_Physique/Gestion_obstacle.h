#ifndef GESTION_OBSTACLE_H
#define GESTION_OBSTACLE_H
#include "Gestion_serpent.h"
struct Pomme_def {
	Coord Coord;
	int manger;
};
typedef struct Pomme_def Pomme;

struct Pommes_liste_def{
	Pomme* tab;
	int nbr_pommes;
};
typedef struct Pommes_liste_def Pommes_liste;

struct Obstacle_def{
	Coord Coord;
};
typedef struct Obstacle_def Obstacle;
struct Obstacle_liste_def{
	Obstacle* tab;
	int nbr_obstacle;
};
typedef struct Obstacle_liste_def Obstacle_liste;

Pommes_liste * init_Pommes_liste(int G_X , int G_Y , int nbr_pommes,int echelle);
void free_pomme(Pommes_liste *Pommes_liste_1);
Obstacle_liste * init_Obstacle_liste(int G_X, int G_Y, int nbr_obstacle,Pommes_liste* Pommes_liste_1,int echelle);
void free_obstacle(Obstacle_liste* Obstacle_liste_1);
#endif
