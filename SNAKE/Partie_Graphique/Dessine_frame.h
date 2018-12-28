#ifndef DESSINE_FRAME_H
#define DESSINE_FRAME_H
#include "../Partie_Physique/Gestion_serpent.h"
void dessine_frame(Serpent* Serpent,Pommes_liste* Pommes_liste_1,Obstacle_liste* Obstacle_liste_1, int echelle,int C_X, int C_Y);
void dessine_arrierep(int C_X, int C_Y , int echelle);
void dessine_pause(int C_X, int C_Y,int echelle,int * couleur_pause,int * couleur_pause_m);
#endif
