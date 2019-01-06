#include "Gestion_collision.h"
#include "Gestion_obstacle.h"
#include "Gestion_serpent.h"

//gere les collision avec le serpent
C_Collision Serpent_test_C(Serpent *Serpent_1){
  /*
  Cette fonction sert a savoir si le serpent est en collision avec lui même
  Si il se touche lui même , la fonction renvois C_Serpent (du type C_Collision)
  ou il renvois C_Rien si il ne se touche pas lui même (du type C_Rien)
  Variable
  --------
    Serpent *Serpent_1 -> Le Serpent à tester du type serpent
  Retourne
  --------
    C_Serpent ou C_Rien -> Du type C_Collision
  */
  int nbr = Serpent_1->nbr_coord;
  int i;
  if (Serpent_1->last_coord + 1 - nbr >= 0){
    for (i = 0 ; i < nbr - 1 ; i++){
      if (Serpent_1->tab[Serpent_1->last_coord].X ==  Serpent_1->tab[ Serpent_1->last_coord + 1 - (nbr - i)].X
          && Serpent_1->tab[Serpent_1->last_coord].Y == Serpent_1->tab[ Serpent_1->last_coord + 1  - (nbr - i)].Y ){
        return C_Serpent;
      }
    }
  }else {
    i = 1;
    while(Serpent_1->last_coord - i  >= 0){
      if (Serpent_1->tab[Serpent_1->last_coord].X == Serpent_1->tab[ Serpent_1->last_coord - i].X
          && Serpent_1->tab[Serpent_1->last_coord].Y == Serpent_1->tab[ Serpent_1->last_coord - i].Y){
        return C_Serpent;
      }
      i++;
    }
    int j = 0;
    while(Serpent_1->taille_tab - 1 -  j >= Serpent_1->taille_tab - (nbr - i )){
      if (Serpent_1->tab[Serpent_1->last_coord].X == Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].X
          && Serpent_1->tab[Serpent_1->last_coord].Y == Serpent_1->tab[Serpent_1->taille_tab - 1 -  j ].Y){
        return C_Serpent;
      }
      j++;
    }
  }
  return C_Rien;
}

C_Collision Pommes_test_C(Serpent *Serpent_1,Pommes_liste *Pommes_liste_1){
  /*Cette fonction regarde quand une pomme est mangée par le serpent
    cette fonction renvoie C_pomme si une pomme est mangée et C_rien sinon
    Variable
    --------
    Serpent_1 -> Le serpent à tester du type Serpent
    Pommes_liste_1 -> La liste des pommes à verifier du type Pommes_liste
    
    Retourne
    --------
    C_Pomme ou C_Rien -> du type C_Collision
    */
  int i;
  for (i = 0 ; i < Pommes_liste_1->nbr_pommes ; i++){
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
  /*Cette fonction gere les collisions avec les obstacles
    Cette fonction renvoie C_Obstacle si le serpent touche un obstacle C_rien sinon
    Variable
    --------
      Serpent_1 -> Le serpent a tester du type Serpent
      Obstacle_liste_1 -> La liste des obstacle à tester du type Obstacle_liste
    
    Retourne
    --------
    C_Obstacle ou C_Rien -> Du type C_Collision
    */
  int i;
  for (i = 0 ; i < Obstacle_liste_1->nbr_obstacle; i++){
    if (Serpent_1->tab[Serpent_1->last_coord].X == Obstacle_liste_1->tab[i].Coord.X
        && Serpent_1->tab[Serpent_1->last_coord].Y == Obstacle_liste_1->tab[i].Coord.Y){
      return C_Obstacle;
    }
  }
  return C_Rien;
}
C_Collision Grille_C(Serpent *Serpent_1,int echelle,int C_X,int C_Y){
  /*Cette fonction gere les collisions avec les bords du jeu
    Cette fonction renvoie C_Obstacle si le serpent touche la bordure C_rien sinon
    Variable
    --------
    Serpent_1 -> Le serpent a tester du type C_Serpent
    echelle -> Le niveau de zoom du programme
    C_X -> les X max
    C_Y -> les Y max
    Retourne
    --------
    C_Rien ou C_Obstacle -> Du type C_Collision
    */
  if (Serpent_1->tab[Serpent_1->last_coord].X < echelle|| Serpent_1->tab[Serpent_1->last_coord].X > C_X*echelle ||
      Serpent_1->tab[Serpent_1->last_coord].Y < echelle || Serpent_1->tab[Serpent_1->last_coord].Y > C_Y*echelle){
    return C_Obstacle;
  }
  return C_Rien;
}

C_Collision Collision(Serpent *Serpent_1,Pommes_liste *Pommes_liste_1, Obstacle_liste *Obstacle_liste_1,int echelle,int C_X,int C_Y){
  /*
  Cette fonction utilise les fonction Grille_C , Obstacle_test_C , Pomme_test_C , Serpent_test_C et determine 
  avec quoi le serpent est en contact , il peut être en contact avec Rien (C_Rien) avec lui même (C_Serpent) avec une pommes (C_pommes)
  ou avec un obstacle (C_obstacle)
  Variable
  --------
  Pommes_liste_1 -> La liste des pommes à verifier du type Pommes_liste
  Obstacle_liste_1 -> La liste des obstacle à tester du type Obstacle_liste
  Serpent_1 -> Le serpent a tester du type C_Serpent
  echelle -> Le niveau de zoom du programme
  C_X -> les X max
  C_Y -> les Y max
  Retourne
  --------
  Collision_T -> Du type C_Collision qui symbolise avec quoi le serpent est en collision
  
  */
  C_Collision Collision_T = Pommes_test_C(Serpent_1,Pommes_liste_1);
  if (Collision_T == C_Rien){
    Collision_T = Obstacle_test_C(Serpent_1,Obstacle_liste_1);
    if (Collision_T == C_Rien){
      Collision_T = Serpent_test_C(Serpent_1);
      if (Collision_T == C_Rien){
        Collision_T = Grille_C(Serpent_1,echelle,C_X,C_Y);
      }
    }
  }
  return Collision_T;
}
