#include "../Partie_Physique/Gestion_serpent.h"
#include "../Partie_Physique/Gestion_obstacle.h"
#include <graph.h>
#include <stdio.h>

//affiche un ecran de pause
void dessine_pause(int C_X, int C_Y,int echelle,int *couleur_pause, int * couleur_pause_m){
  ChoisirEcran(1);
  int bordure = 2*echelle;
  if(*couleur_pause_m == 0){
    *couleur_pause = *couleur_pause - 1;
  }
  if(*couleur_pause_m == 1){
    *couleur_pause = *couleur_pause + 1;
  }
  if(*couleur_pause < 190){
    *couleur_pause_m = 1;
  }
  if (*couleur_pause >253){
    *couleur_pause_m = 0;
  }
  ChoisirCouleurDessin(CouleurParComposante(*couleur_pause,*couleur_pause,*couleur_pause));
  int taille = TailleChaineEcran("Pause",2);
  EcrireTexte((C_X/2)*echelle - (taille/2),(C_Y/2)*echelle,"Pause",2);
  taille = TailleChaineEcran("Appuyer sur la touche espace pour reprendre",1.5);
  EcrireTexte((C_X/2)*echelle - (taille/2),(C_Y/2)*echelle + TailleInfPolice(2)+TailleSupPolice(2),"Appuyez sur la touche espace pour reprendre",1.5);
  CopierZone(1,0,0,0,C_X*echelle,C_Y*echelle + 6*echelle,bordure,bordure);
}
//affiche le message de début
void dessine_debut(int C_X, int C_Y,int echelle,int niveau){
  ChoisirEcran(1);
  int bordure = 2*echelle;
  ChoisirCouleurDessin(CouleurParComposante(0,0,0));
  char afficher[20];
  sprintf(afficher,"Niveau : %d",niveau);
  int taille = TailleChaineEcran(afficher,2);
  EcrireTexte((C_X/2)*echelle - (taille/2),(C_Y/2)*echelle,afficher,2);
  taille = TailleChaineEcran("Appuyez sur une touche pour commencer",1.5);
  EcrireTexte((C_X/2)*echelle - (taille/2),(C_Y/2)*echelle + TailleInfPolice(2)+TailleSupPolice(2),"Appuyez sur une touche pour commencer",1.5);
  CopierZone(1,0,0,0,C_X*echelle,C_Y*echelle + 6*echelle,bordure,bordure);
}
//affiche l'aarriere plan
void dessine_arrierep(int C_X, int C_Y , int echelle){
  ChoisirEcran(0);
  ChoisirCouleurDessin(CouleurParComposante(87,138,52));
  RemplirRectangle(0,0,C_X * echelle + 4 * echelle,C_Y * echelle + 4*echelle);
  ChoisirCouleurDessin(CouleurParComposante(74,117,44));
  RemplirRectangle(0,C_Y * echelle + 4*echelle,C_X * echelle + 4 *echelle ,TailleInfPolice(2)+TailleSupPolice(2));
}
//dessine le serpent
void dessine_serpent(Serpent *Serpent_1, int echelle){
  int nbr = Serpent_1->nbr_coord;
  int i;
  int ra,ga,ba;
  int r = 69;
  int g = 155;
  int b = 255;
  int intensite = 2;
  //sert a faire un dégrader
  if ( Serpent_1->last_coord + 1 - nbr >= 0){
    r = r - intensite * nbr;
    g = g - intensite * nbr;
    b = b - intensite * nbr;
    for (i = 0 ; i < nbr ; i++){
      if(r < 0){
        ra = 0;
      }else{
        ra = r;
      }
      if(g < 0){
        ga = 0;
      }else{
        ga = g;
      }
      if(b < 0){
        ba = 0;
      }else{
        ba = b;
      }
      ChoisirCouleurDessin(CouleurParComposante(ra,ga,ba));
      r = r + intensite;
      b = b + intensite;
      g = g + intensite;
      //printf("On dessine le carré à X = %d - %d = %d \n",(Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) , echelle , (Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) - echelle );
      //printf("On dessine le carré à Y = %d - %d = %d \n",(Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y), echelle , (Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y) - echelle);
      RemplirRectangle((Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X) - echelle ,(Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y) - echelle,1 * echelle,1 * echelle);
    }
  }else{
    i = 0;
    while(Serpent_1->last_coord - i >= 0){
      if(r < 0){
        ra = 0;
      }else{
        ra = r;
      }
      if(g < 0){
        ga = 0;
      }else{
        ga = g;
      }
      if(b < 0){
        ba = 0;
      }else{
        ba = b;
      }
      ChoisirCouleurDessin(CouleurParComposante(ra,ga,ba));
      r = r - intensite;
      g = g - intensite;
      b = b - intensite;
      RemplirRectangle((Serpent_1->tab[ Serpent_1->last_coord - i].X) - echelle ,(Serpent_1->tab[ Serpent_1->last_coord - i].Y) - echelle,1*echelle,1*echelle);
      i++;
    }
    int j = 0;
    while(Serpent_1->taille_tab - 1 -  j >= Serpent_1->taille_tab - (nbr - i )){
      if(r < 0){
        ra = 0;
      }else{
        ra = r;
      }
      if(g < 0){
        ga = 0;
      }else{
        ga = g;
      }
      if(b < 0){
        ba = 0;
      }else{
        ba = b;
      }
      ChoisirCouleurDessin(CouleurParComposante(ra,ga,ba));
      r = r - intensite;
      g = g - intensite;
      b = b - intensite;
      RemplirRectangle((Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X) - echelle ,(Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y) - echelle,1*echelle,1*echelle);
      j++;
    }
  }
}
//affiche les pommes
void dessine_pommes(Pommes_liste* Pommes_liste_1, int echelle){

  for (int i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
    if(Pommes_liste_1->tab[i].manger == 0){
      RemplirRectangle(Pommes_liste_1->tab[i].Coord.X - echelle,Pommes_liste_1->tab[i].Coord.Y -echelle,echelle,echelle);
    }
  }
}
//affiche les obstacles
void dessine_obstacle(Obstacle_liste * Obstacle_liste_1, int echelle){
  int sprite= ChargerSprite("pomme.png");
  for (int i = 0 ; i < Obstacle_liste_1->nbr_obstacle ; i++){
    RemplirRectangle(Obstacle_liste_1->tab[i].Coord.X - echelle,Obstacle_liste_1->tab[i].Coord.Y -echelle,echelle,echelle);
  }
}

void dessine_frame(Serpent* Serpent_1,Pommes_liste* Pommes_liste_1,Obstacle_liste* Obstacle_liste_1,int echelle,int C_X, int C_Y){
  int bordure = 2*echelle;
  ChoisirEcran(1);

	ChoisirCouleurDessin(CouleurParComposante(162,209,73));
	RemplirRectangle(0,0,C_X * echelle,C_Y * echelle);

	dessine_serpent(Serpent_1, echelle);
  ChoisirCouleurDessin(CouleurParNom("red"));
  dessine_pommes(Pommes_liste_1,echelle);
  ChoisirCouleurDessin(CouleurParNom("black"));
  dessine_obstacle(Obstacle_liste_1,echelle);
  ChoisirEcran(0);
  CopierZone(1,0,0,0,C_X*echelle,C_Y*echelle + 4*echelle + TailleInfPolice(2) + TailleSupPolice(2),bordure,bordure);
}