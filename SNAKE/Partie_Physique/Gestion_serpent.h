#ifndef GESTION_SERPENT_H
#define GESTION_SERPENT_H
//Coordonés X_Y dans l'espace
struct Coordones_def {
  int X;
  int Y;
};
//On appelle la structure plus facilement
typedef struct Coordones_def Coord;
//On créer une structure serpent
struct Serpent_def {
  Coord* tab;
  int taille_tab;
  int nbr_coord;
  int last_coord;
};
//On appelle la structure plus facilement
typedef struct Serpent_def Serpent;
// Les fonctions :
Serpent init_Serpent(int longueur, int C_X , int C_Y,int taillemax,int echelle);
void Grandir_Serpent(Serpent * Serpent_1, int* nbr_plus);
void Ajuster_Serpent(Serpent * Serpent_1, int* nbr_plus);
void deplacement_droite(Serpent * Serpent_m, int echelle);
void deplacement_gauche(Serpent * Serpent_m, int echelle);
void deplacement_haut(Serpent * Serpent_m, int echelle);
void deplacement_bas(Serpent * Serpent_m, int echelle);
#endif
