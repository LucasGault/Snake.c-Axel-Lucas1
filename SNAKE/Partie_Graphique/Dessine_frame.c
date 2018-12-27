#include "../Partie_Physique/Gestion_serpent.h"
#include "../Partie_Physique/Gestion_obstacle.h"
#include <graph.h>
#include <stdio.h>
void dessine_arrierep(int C_X, int C_Y , int echelle){
  ChoisirEcran(0);
  ChoisirCouleurDessin(CouleurParComposante(87,138,52));
  RemplirRectangle(0,0,C_X * echelle + 4 * echelle,C_Y * echelle + 4*echelle);
  ChoisirCouleurDessin(CouleurParComposante(74,117,44));
  RemplirRectangle(0,C_Y * echelle + 4*echelle,C_X * echelle + 4 *echelle ,6*echelle);
}
void dessine_serpent(Serpent *Serpent_1, int echelle){
  int nbr = Serpent_1->nbr_coord;
  int i;
  if ( Serpent_1->last_coord + 1 - nbr >= 0){
  for (i = 0 ; i < nbr ; i++){
    //printf("On dessine le carré à X = %d - %d = %d \n",(Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) , echelle , (Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) - echelle );
    //printf("On dessine le carré à Y = %d - %d = %d \n",(Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y), echelle , (Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y) - echelle);
    RemplirRectangle((Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) - echelle ,(Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y) - echelle,1 * echelle,1 * echelle);
   }
 }
 else{
   i = 0;
   while(Serpent_1->last_coord - i >= 0){
     RemplirRectangle((Serpent_1->tab[ Serpent_1->last_coord - i].X) - echelle ,(Serpent_1->tab[ Serpent_1->last_coord - i].Y) - echelle,1*echelle,1*echelle);
     i++;
   }
   int j = 0;
   while(Serpent_1->taille_tab - 1 -  j >= Serpent_1->taille_tab - (nbr - i )){
    RemplirRectangle((Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X) - echelle ,(Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y) - echelle,1*echelle,1*echelle);
     j++;
   }
 }
}
void dessine_pommes(Pommes_liste* Pommes_liste_1, int echelle){

  for (int i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
    if(Pommes_liste_1->tab[i].manger == 0){
    RemplirRectangle(Pommes_liste_1->tab[i].Coord.X - echelle,Pommes_liste_1->tab[i].Coord.Y -echelle,echelle,echelle);
    }
  }
}
void dessine_obstacle(Obstacle_liste * Obstacle_liste_1, int echelle){
  for (int i = 0 ; i < Obstacle_liste_1->nbr_obstacle ; i++){
    RemplirRectangle(Obstacle_liste_1->tab[i].Coord.X - echelle,Obstacle_liste_1->tab[i].Coord.Y -echelle,echelle,echelle);
  }

}
void dessine_frame(Serpent* Serpent_1,Pommes_liste* Pommes_liste_1,Obstacle_liste* Obstacle_liste_1,int echelle,int C_X, int C_Y){
  int bordure = 2*echelle;
  ChoisirEcran(1);
	ChoisirCouleurDessin(CouleurParComposante(162,209,73));
	RemplirRectangle(0,0,C_X * echelle,C_Y * echelle);
  ChoisirCouleurDessin(CouleurParComposante(69,115,232));
	dessine_serpent(Serpent_1, echelle);
  ChoisirCouleurDessin(CouleurParNom("red"));
  dessine_pommes(Pommes_liste_1,echelle);
  ChoisirCouleurDessin(CouleurParNom("black"));
  dessine_obstacle(Obstacle_liste_1,echelle);
  ChoisirEcran(0);
  CopierZone(1,0,0,0,C_X*echelle,C_Y*echelle + 6*echelle,bordure,bordure);



}
