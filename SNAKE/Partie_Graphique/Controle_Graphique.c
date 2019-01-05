#include "Controle_Graphique.h"
#include "Dessine_frame.h"
#include "../Partie_Physique/Gestion_serpent.h"
#include "../Partie_Physique/Gestion_obstacle.h"
#include <graph.h>

//Cette fonction sert à Dépalcer le serpent quand on appuye sur les flèches directionnelles
void controle(Serpent* Serpent_1 , int echelle, int*grandir,int*Derniere_touche,int * pause){
	if (ToucheEnAttente() == 0){
		//le serpent vas vers le haut
	  	if (*Derniere_touche == XK_Up){
			deplacement_haut(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
		}
		//le serpent vas vers le bas
		if (*Derniere_touche == XK_Down){
			deplacement_bas(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
		}
		//le serpent vas vers la gauche
		if (*Derniere_touche == XK_Right){
			deplacement_gauche(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
		}
		//le serpent vas vers la droite
		if (*Derniere_touche == XK_Left){
			deplacement_droite(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
		}
	}else{
		int Touche_s = Touche();
		if (Touche_s == *Derniere_touche){
			if (*Derniere_touche == XK_Up){
				deplacement_haut(Serpent_1,echelle);
				Ajuster_Serpent(Serpent_1,grandir);
			}
			if (*Derniere_touche == XK_Down){
				deplacement_bas(Serpent_1,echelle);
				Ajuster_Serpent(Serpent_1,grandir);
			}
			if (*Derniere_touche == XK_Right){
				deplacement_gauche(Serpent_1,echelle);
				Ajuster_Serpent(Serpent_1,grandir);
			}
			if (*Derniere_touche == XK_Left){
				deplacement_droite(Serpent_1,echelle);
				Ajuster_Serpent(Serpent_1,grandir);
			}
		}
		//mets en pause le jeu
		if (Touche_s == XK_space){
		    *pause = 1;
		}
		//retourne au menu
		if (Touche_s == XK_Escape){
		    *pause = 3;
		}

		if (Touche_s == XK_Right && Touche_s != *Derniere_touche){
			deplacement_droite(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
			*Derniere_touche = XK_Left;
		}
		if (Touche_s == XK_Left && Touche_s != *Derniere_touche){
			deplacement_gauche(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
			*Derniere_touche = XK_Right;
		}
		if (Touche_s == XK_Up && Touche_s != *Derniere_touche){
			deplacement_bas(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
			*Derniere_touche = XK_Down;
		}
		if (Touche_s == XK_Down && Touche_s != *Derniere_touche){
			deplacement_haut(Serpent_1,echelle);
			Ajuster_Serpent(Serpent_1,grandir);
			*Derniere_touche = XK_Up;
		}
		
		int clean = 0;
		while(ToucheEnAttente() > 0){
			Touche();
			clean++;
			if (clean > 20){
				break;
			}
		}
	}
}
