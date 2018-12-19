#include "Gestion_collision.h"
#include "Gestion_obstacle.h"
#include "Gestion_serpent.h"
//#include "stdio.h"

C_Collision Serpent_test_C(Serpent *Serpent_1){
  int nbr = Serpent_1->nbr_coord;
  int i;
  //printf("On cherche pour (X = %d , Y = %d)\n",Serpent_1->tab[Serpent_1->last_coord].X,Serpent_1->tab[Serpent_1->last_coord].Y );
  if (Serpent_1->last_coord + 1 - nbr >= 0){
    for (i = 0 ; i < nbr - 1 ; i++){
      //printf("Et pour : (X = %d , Y = %d)\n",Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X,Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y );
      if (Serpent_1->tab[Serpent_1->last_coord].X ==  Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X
      && Serpent_1->tab[Serpent_1->last_coord].Y == Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y )
      {
        //printf("Collision !\n" );
        return C_Serpent;
      }
    }
  }
  else {
    i = 1;
    while(Serpent_1->last_coord - i  >= 0){
        //printf("zEt pour : (X = %d , Y = %d)\n",Serpent_1->tab[ Serpent_1->last_coord - i].X,Serpent_1->tab[ Serpent_1->last_coord - i].Y  );
      if (Serpent_1->tab[Serpent_1->last_coord].X == Serpent_1->tab[ Serpent_1->last_coord - i].X
        && Serpent_1->tab[Serpent_1->last_coord].Y == Serpent_1->tab[ Serpent_1->last_coord - i].Y){
        //printf("Collision\n");
        return C_Serpent;
        }
      i++;
    }
    //printf("i = %d\n", i);
    int j = 0;
      while(Serpent_1->taille_tab - 1 -  j >= Serpent_1->taille_tab - (nbr - i )){
          //printf("Et pour : (X = %d , Y = %d)\n",Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X,Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y );
        if (Serpent_1->tab[Serpent_1->last_coord].X == Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X
          && Serpent_1->tab[Serpent_1->last_coord].Y == Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y){
          //printf("Collision !\n" );
          return C_Serpent;

        }
        j++;
      }
  }
  return C_Rien;
  //printf("Pas de Collision !\n");
}
C_Collision Pommes_test_C(Serpent *Serpent_1,Pommes_liste *Pommes_liste_1){
  int i;
  for (i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
    //printf("%d %d , %d %d\n",Serpent_1->tab[Serpent_1->last_coord].X,Serpent_1->tab[Serpent_1->last_coord].Y, Pommes_liste_1->tab[i].Coord.X,Pommes_liste_1->tab[i].Coord.Y)
    if (Serpent_1->tab[Serpent_1->last_coord].X == Pommes_liste_1->tab[i].Coord.X
    &&  Serpent_1->tab[Serpent_1->last_coord].Y == Pommes_liste_1->tab[i].Coord.Y){
      if (Pommes_liste_1->tab[i].manger == 0){
        Pommes_liste_1->tab[i].manger = 1;
        return C_Pomme;
      }
    }
  }
  return C_Rien;
}

C_Collision Obstacle_test_C(Serpent *Serpent_1,Obstacle_liste *Obstacle_liste_1){
  int i;
  for (i = 0 ; i < Obstacle_liste_1->nbr_obstacle; i++){
    if (Serpent_1->tab[Serpent_1->last_coord].X == Obstacle_liste_1->tab[i].Coord.X
      && Serpent_1->tab[Serpent_1->last_coord].Y == Obstacle_liste_1->tab[i].Coord.Y){
      return C_Obstacle;
    }
  }
  return C_Rien;
}

C_Collision Grille_C(Serpent *Serpent_1,int echelle){
  if (Serpent_1->tab[Serpent_1->last_coord].X < echelle|| Serpent_1->tab[Serpent_1->last_coord].X > 60*echelle ||
    Serpent_1->tab[Serpent_1->last_coord].Y < echelle || Serpent_1->tab[Serpent_1->last_coord].Y > 40*echelle){
      return C_Obstacle;
  }
  return C_Rien;
}
C_Collision Collision(Serpent *Serpent_1,Pommes_liste *Pommes_liste_1, Obstacle_liste *Obstacle_liste_1,int echelle){

  C_Collision Collision_T = Pommes_test_C(Serpent_1,Pommes_liste_1);
  if (Collision_T == C_Rien){
     Collision_T = Obstacle_test_C(Serpent_1,Obstacle_liste_1);
      if (Collision_T == C_Rien){
        Collision_T = Serpent_test_C(Serpent_1);
        if (Collision_T == C_Rien){
          Collision_T = Grille_C(Serpent_1,echelle);
        }
      }
  }
  return Collision_T;


}
