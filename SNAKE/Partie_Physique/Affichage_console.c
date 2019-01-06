/*Cette page sert à affiche les informations (positions du serpent, nbr de pommes/obstacles, 
taille du serpent ...) dans la console*/
#include "Affichage_console.h"
#include "Gestion_serpent.h"
#include "Gestion_obstacle.h"
#include <stdio.h>

void position_serpent(Serpent* Serpent_1){
/*
Cette fonction sert a afficher la position du serpent dans la console.
*/
  int nbr = Serpent_1->nbr_coord;
  printf("Nombre de segment : %d\n", nbr);
  printf("Position de la tête : %d\n", Serpent_1->last_coord);
  printf("Taille du tableau = %d\n",Serpent_1->taille_tab );
  int i = 0;
  if ( Serpent_1->last_coord + 1 - nbr >= 0){
    for (i = 0 ; i < nbr ; i++){
      printf("Segment n°%d est en positions (X,Y) = (%d,%d)\n",i, Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X ,Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y );
    }
  }
  else{
   int i = 0;
   while(Serpent_1->last_coord - i >= 0){
    printf("Segment n°%d est en positions (X,Y) = (%d,%d)\n",nbr-i - 1, Serpent_1->tab[ Serpent_1->last_coord - i].X
                                                                      ,Serpent_1->tab[ Serpent_1->last_coord - i].Y );
    i++;
   }
   int j = 0;
   while(Serpent_1->taille_tab - 1 -  j >= Serpent_1->taille_tab - (nbr - i )){
    printf("Segment n°%d est en positions (X,Y) = (%d,%d)\n",nbr -i - j - 1,Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X,
                                                            Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y);
    j++;
   }
 }
}

void position_pommes(Pommes_liste * Pommes_liste_1){
  /*
  Cette fonction sert a afficher la positions des pommes.
  */
  int i;
  printf("Il y'a %d pommes\n",Pommes_liste_1->nbr_pommes);
  for (i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
    printf("La pomme numéro %d se situe en (X,Y) = (%d,%d)\n",i,Pommes_liste_1->tab[i].Coord.X,Pommes_liste_1->tab[i].Coord.Y);
  }
}

void position_obstacle(Obstacle_liste * Obstacle_liste_1){
  /*
  Cette fonction sert a afficher la positions des obstacles
  */
  int i;
  printf("Il y'a %d Obstacle\n",Obstacle_liste_1->nbr_obstacle);
  for (i = 0 ; i < Obstacle_liste_1->nbr_obstacle; i++){
    printf("L'obstacle numéro %d se situe en (X,Y) = (%d,%d)\n",i,Obstacle_liste_1->tab[i].Coord.X,Obstacle_liste_1->tab[i].Coord.Y);
  }
}
