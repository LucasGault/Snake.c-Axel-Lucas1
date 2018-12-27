#include "Partie_Physique/Gestion_serpent.h"
#include "Partie_Physique/Affichage_console.h"
#include "Partie_Physique/Gestion_obstacle.h"
#include "Partie_Physique/Gestion_collision.h"
#include "Partie_Graphique/Dessine_frame.h"
#include "Partie_Graphique/Controle_Graphique.h"
#include "Partie_Graphique/Timer.h"
#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc , int argv[]){
	srand(time(NULL));
	int echelle = 15;
	int C_X = 60;
	int C_Y = 30;
	int taille_ini = 10;
	int nbr_pommes = 5;
	int pommes_manger = nbr_pommes;
	int nbr_obstacle =0;
	Serpent Serpent_1 = init_Serpent(taille_ini, C_X/2 ,C_Y/2,nbr_pommes*2 + taille_ini  ,echelle);
	//position_serpent(&Serpent_1);
	Pommes_liste Pommes_liste_1 = init_Pommes_liste(C_X,C_Y,nbr_pommes, echelle);
	Obstacle_liste Obstacle_liste_1 = init_Obstacle_liste(C_X ,C_Y ,nbr_obstacle,&Pommes_liste_1,echelle);
	InitialiserGraphique();
	CreerFenetre(10,10,C_X * echelle ,C_Y * echelle + 5*echelle);
	int Touche_s;
	int grandir = 0;
	int Derniere_touche = XK_Up;
	unsigned long chrono = Microsecondes();
	unsigned long chrono_2 = chrono;
	int milisecondes;
	int intervale = 150;
	int last_interval = 1;
	int clean = 0;
	int pause = 0;
	int debut = 0;
	unsigned long timer_1 = Microsecondes();
	int timer_add = timer(timer_1,echelle,C_X,C_Y);;
	dessine_frame(&Serpent_1,&Pommes_liste_1,&Obstacle_liste_1,echelle,C_X,C_Y);
	int score_p = 0;
	score(&score_p,echelle,C_X,C_Y);
	while (1){
		while(ToucheEnAttente() != 1 && debut == 0){
			dessine_frame(&Serpent_1,&Pommes_liste_1,&Obstacle_liste_1,echelle,C_X,C_Y);
			timer_1 = Microsecondes() - timer_add;
		}
		debut = 1;
		chrono = Microsecondes();
		milisecondes = (chrono - chrono_2)/1000;
		if (pause == 3){
			break;
		}
		if (ToucheEnAttente() && pause == 1){
			Touche_s = Touche();
			timer_1 = Microsecondes() - timer_add;
			if (Touche_s == XK_space){
				pause = 0;
			}
			if (Touche_s == XK_Escape){
				pause = 3;
			}
		}

		if ((milisecondes/intervale) > last_interval && pause == 0){
			timer_add = timer(timer_1,echelle,C_X,C_Y);
			score(&score_p,echelle,C_X,C_Y);
			last_interval = milisecondes/intervale;
			controle(&Serpent_1,echelle,&grandir,&Derniere_touche,&pause);
			dessine_frame(&Serpent_1,&Pommes_liste_1,&Obstacle_liste_1,echelle,C_X,C_Y);
			int Colli = Collision(&Serpent_1,&Pommes_liste_1,&Obstacle_liste_1,echelle,C_X,C_Y);
			if ( Colli == C_Pomme){
				score_p = score_p +  5;
				pommes_manger--;
				Grandir_Serpent(&Serpent_1,&grandir);
				dessine_frame(&Serpent_1,&Pommes_liste_1,&Obstacle_liste_1,echelle,C_X,C_Y);

				if (pommes_manger == 0){
					nbr_pommes++;
					pommes_manger = nbr_pommes;
					nbr_obstacle++;
					intervale = intervale - 5;
					Serpent_1 = init_Serpent(taille_ini,C_X/2 ,C_Y/2,nbr_pommes*2 + taille_ini,echelle);
					Pommes_liste_1 = init_Pommes_liste(C_X,C_Y,nbr_pommes, echelle);
					Obstacle_liste_1 = init_Obstacle_liste(C_X ,C_Y ,nbr_obstacle,&Pommes_liste_1,echelle);
					Derniere_touche = XK_Up;
					debut = 0;
				}
			}

			if (Colli == C_Obstacle || Colli == C_Serpent ){
				break;
			}
		}

	}
	FermerGraphique();
}
