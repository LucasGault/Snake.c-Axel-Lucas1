#include "Gestion_serpent.h"
#include <stdlib.h>
#include <stdio.h>
void init_Coord(int longueur , Serpent* Serpent_m, int C_X , int C_Y, int echelle){
  // initialise les coordonées d'un serpent
  int i = 0;
  for(i = 0; i < longueur  ; i++){
    Serpent_m->tab[i].X = C_X;
    Serpent_m->tab[i].Y = C_Y - (longueur*echelle -  i*echelle) + echelle; // Distribue les coordonés de façon à ce que la tête se trouve en derniére positions du serpents
  }
  Serpent_m->nbr_coord = longueur;
  Serpent_m->last_coord = longueur - 1;
}

Serpent * init_Serpent(int longueur, int C_X , int C_Y , int taillemax, int echelle) {
  //Initialise un Serpent avec une longueur de base définie , a des coord X,Y définis.
  Serpent * New_Serpent = (Serpent * )malloc(1 * sizeof(Serpent));
  New_Serpent->tab = (Coord *) malloc(sizeof(Coord) * taillemax);
  New_Serpent->taille_tab = taillemax;
  init_Coord(longueur,New_Serpent,C_X * echelle,C_Y * echelle,echelle);
  New_Serpent->nbr_coord = longueur;

  return New_Serpent;
}
void free_serpent(Serpent* Serpent_1){
  free(Serpent_1->tab);
  free(Serpent_1);
}
void changer_taille(int newtaillemax, Serpent * Serpent_m){ //Change la taille du serpent
  Serpent_m->tab = (Coord *) realloc(Serpent_m->tab, sizeof(Coord) * newtaillemax);
}
void Grandir_Serpent(Serpent * Serpent_1, int* nbr_plus){
  //Serpent_1->nbr_coord = Serpent_1->nbr_coord + 1;
  *nbr_plus = *nbr_plus + 2;

}
void Ajuster_Serpent(Serpent * Serpent_1, int* nbr_plus){
  if(*nbr_plus > 0){
    Serpent_1->nbr_coord = Serpent_1->nbr_coord + 1;
    *nbr_plus = *nbr_plus - 1;
  }
}
void deplacement_droite(Serpent * Serpent_m , int echelle){
  if (Serpent_m->last_coord + 1 <= Serpent_m->taille_tab - 1){
    Serpent_m->tab[Serpent_m->last_coord + 1].X = Serpent_m->tab[Serpent_m->last_coord].X + echelle;
    Serpent_m->tab[Serpent_m->last_coord + 1].Y = Serpent_m->tab[Serpent_m->last_coord].Y;
    Serpent_m->last_coord = Serpent_m->last_coord + 1;
  }else{
    Serpent_m->tab[0].X = Serpent_m->tab[Serpent_m->last_coord].X + echelle;
    Serpent_m->tab[0].Y = Serpent_m->tab[Serpent_m->last_coord].Y;
    Serpent_m->last_coord = 0;
  }
}

void deplacement_gauche(Serpent * Serpent_m, int echelle){
  if (Serpent_m->last_coord + 1 <= Serpent_m->taille_tab - 1){
  Serpent_m->tab[Serpent_m->last_coord + 1].X = Serpent_m->tab[Serpent_m->last_coord].X - echelle;
  Serpent_m->tab[Serpent_m->last_coord + 1].Y = Serpent_m->tab[Serpent_m->last_coord].Y;
  Serpent_m->last_coord = Serpent_m->last_coord + 1;
  }else{
    Serpent_m->tab[0].X = Serpent_m->tab[Serpent_m->last_coord].X - echelle;
    Serpent_m->tab[0].Y = Serpent_m->tab[Serpent_m->last_coord].Y;
    Serpent_m->last_coord = 0;
  }
}
void deplacement_bas(Serpent * Serpent_m, int echelle){
  if (Serpent_m->last_coord + 1 <= Serpent_m->taille_tab - 1){
  Serpent_m->tab[Serpent_m->last_coord + 1].X = Serpent_m->tab[Serpent_m->last_coord].X;
  Serpent_m->tab[Serpent_m->last_coord + 1].Y = Serpent_m->tab[Serpent_m->last_coord].Y - echelle;
  Serpent_m->last_coord = Serpent_m->last_coord + 1;
  }else{
    Serpent_m->tab[0].X = Serpent_m->tab[Serpent_m->last_coord].X;
    Serpent_m->tab[0].Y = Serpent_m->tab[Serpent_m->last_coord].Y - echelle;
    Serpent_m->last_coord = 0;
  }
}
void deplacement_haut(Serpent * Serpent_m, int echelle){
  if (Serpent_m->last_coord + 1 <= Serpent_m->taille_tab - 1){
  Serpent_m->tab[Serpent_m->last_coord + 1].X = Serpent_m->tab[Serpent_m->last_coord].X;
  Serpent_m->tab[Serpent_m->last_coord + 1].Y = Serpent_m->tab[Serpent_m->last_coord].Y + echelle;
  Serpent_m->last_coord = Serpent_m->last_coord + 1;
  }else{
    Serpent_m->tab[0].X = Serpent_m->tab[Serpent_m->last_coord].X;
    Serpent_m->tab[0].Y = Serpent_m->tab[Serpent_m->last_coord].Y + echelle;
    Serpent_m->last_coord = 0;
  }
}
