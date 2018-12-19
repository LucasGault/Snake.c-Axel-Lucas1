#ifndef GESTION_COLLISION_H
#define GESTION_COLLISION_H
#include "Gestion_obstacle.h"
#include "Gestion_serpent.h"
typedef enum {C_Serpent,C_Pomme,C_Obstacle,C_Rien} C_Collision;
C_Collision Collision(Serpent *Serpent_1,Pommes_liste *Pommes_liste_1, Obstacle_liste *Obstacle_liste_1,int echelle);
#endif
