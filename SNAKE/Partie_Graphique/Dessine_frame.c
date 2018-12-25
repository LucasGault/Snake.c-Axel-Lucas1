#include "../Partie_Physique/Gestion_serpent.h"
#include "../Partie_Physique/Gestion_obstacle.h"
#include <graph.h>
#include <stdio.h>
void dessine_serpent(Serpent *Serpent_1, int multi){
  int nbr = Serpent_1->nbr_coord;
  int i;
  if ( Serpent_1->last_coord + 1 - nbr >= 0){
  for (i = 0 ; i < nbr ; i++){
    //printf("On dessine le carré à X = %d - %d = %d \n",(Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) , multi , (Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) - multi );
    //printf("On dessine le carré à Y = %d - %d = %d \n",(Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y), multi , (Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y) - multi);
    RemplirRectangle((Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) - multi ,(Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y) - multi,1 * multi,1 * multi);
   }
 }
 else{
   i = 0;
   while(Serpent_1->last_coord - i >= 0){
     RemplirRectangle((Serpent_1->tab[ Serpent_1->last_coord - i].X) - multi ,(Serpent_1->tab[ Serpent_1->last_coord - i].Y) - multi,1*multi,1*multi);
     i++;
   }
   int j = 0;
   while(Serpent_1->taille_tab - 1 -  j >= Serpent_1->taille_tab - (nbr - i )){
    RemplirRectangle((Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X) - multi ,(Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y) - multi,1*multi,1*multi);
     j++;
   }
 }
}
void dessine_pommes(Pommes_liste* Pommes_liste_1, int multi){

  for (int i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
    if(Pommes_liste_1->tab[i].manger == 0){
    RemplirRectangle(Pommes_liste_1->tab[i].Coord.X - multi,Pommes_liste_1->tab[i].Coord.Y -multi,multi,multi);
    }
  }
}
void dessine_obstacle(Obstacle_liste * Obstacle_liste_1, int multi){
  for (int i = 0 ; i < Obstacle_liste_1->nbr_obstacle ; i++){
    RemplirRectangle(Obstacle_liste_1->tab[i].Coord.X - multi,Obstacle_liste_1->tab[i].Coord.Y -multi,multi,multi);
  }

}
void dessine_frame(Serpent* Serpent_1,Pommes_liste* Pommes_liste_1,Obstacle_liste* Obstacle_liste_1,int multi){
  ChoisirEcran(1);
	ChoisirCouleurDessin(CouleurParComposante(162,209,73));
	RemplirRectangle(0,0,60 * multi,40 * multi);
  ChoisirCouleurDessin(CouleurParComposante(69,115,232));
	dessine_serpent(Serpent_1, multi);
  ChoisirCouleurDessin(CouleurParNom("red"));
  dessine_pommes(Pommes_liste_1,multi);
  ChoisirCouleurDessin(CouleurParNom("black"));
  dessine_obstacle(Obstacle_liste_1,multi);
  ChoisirEcran(0);
  CopierZone(1,0,0,0,60*multi,40*multi + 6*multi,0,0);



}
