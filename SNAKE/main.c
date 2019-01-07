#include "Partie_Physique/Gestion_serpent.h"
#include "Partie_Physique/Affichage_console.h"
#include "Partie_Physique/Gestion_obstacle.h"
#include "Partie_Physique/Gestion_collision.h"
#include "Partie_Graphique/Dessine_frame.h"
#include "Partie_Graphique/Controle_Graphique.h"
#include "Partie_Graphique/Timer.h"
#include "Menu/Menu_graphique.h"
#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>

//Cette fonction sert à initialiser la partie 
int jeu(int C_X,int C_Y,int echelle,int taille_ini,int nbr_pommes,int intervale,int *score_p , int * niveau){
	srand(time(NULL));
	*niveau = 1;
	int pommes_manger = nbr_pommes;
	int nbr_obstacle =0;
	Serpent * Serpent_1 = init_Serpent(taille_ini, C_X/2 ,C_Y/2,nbr_pommes*2 + taille_ini  ,echelle);
	Pommes_liste * Pommes_liste_1 = init_Pommes_liste(C_X,C_Y,nbr_pommes, echelle);
	Obstacle_liste * Obstacle_liste_1 = init_Obstacle_liste(C_X ,C_Y ,nbr_obstacle,Pommes_liste_1,echelle);
	InitialiserGraphique();
	CreerFenetre(0,0,C_X * echelle + 4*echelle ,C_Y * echelle + 4 * echelle + TailleInfPolice(2)+TailleSupPolice(2));
	int Touche_s;
	int grandir = 0;
	int Derniere_touche = XK_Up;
	unsigned long chrono = Microsecondes();
	unsigned long chrono_2 = chrono;
	int milisecondes;
	int intervale_last = intervale;
	int last_interval = 1;
	int clean = 0;
	int pause = 0;
	int debut = 0;
	int couleur_pause = 254;
	int couleur_pause_m = 0;
	unsigned long timer_1 = Microsecondes();
	int timer_add = timer(timer_1,echelle,C_X,C_Y);;
	dessine_arrierep(C_X, C_Y ,echelle);
	score(score_p,echelle,C_X,C_Y,*niveau);
	dessine_frame(Serpent_1,Pommes_liste_1,Obstacle_liste_1,echelle,C_X,C_Y);

	while (1){
		
		while(ToucheEnAttente() != 1 && debut == 0){
			dessine_debut(C_X,C_Y,echelle,*niveau);
			timer_1 = Microsecondes() - timer_add;
		}
		debut = 1;
		chrono = Microsecondes();
		milisecondes = (chrono - chrono_2)/1000;
		if (pause == 3){
			break;
		}
		if ((milisecondes/intervale) > last_interval && pause == 1){
			last_interval = milisecondes/intervale;
			intervale = 50;
			dessine_pause(C_X,C_Y,echelle,&couleur_pause,&couleur_pause_m);
			if (ToucheEnAttente() && pause == 1){
				Touche_s = Touche();
				timer_1 = Microsecondes() - timer_add;
				if (Touche_s == XK_space){
					pause = 0;
					intervale = intervale_last;
					last_interval = milisecondes/intervale;
				}
				if (Touche_s == XK_Escape){
					timer_add = timer(timer_1,echelle,C_X,C_Y);
					score(score_p,echelle,C_X,C_Y,*niveau);
					dessine_frame(Serpent_1,Pommes_liste_1,Obstacle_liste_1,echelle,C_X,C_Y);
					pause = 3;
				}
			}
		}

		if ((milisecondes/intervale) > last_interval && pause == 0){
			last_interval = milisecondes/intervale;
			timer_add = timer(timer_1,echelle,C_X,C_Y);
			score(score_p,echelle,C_X,C_Y,*niveau);
			controle(Serpent_1,echelle,&grandir,&Derniere_touche,&pause);
			dessine_frame(Serpent_1,Pommes_liste_1,Obstacle_liste_1,echelle,C_X,C_Y);
			int Colli = Collision(Serpent_1,Pommes_liste_1,Obstacle_liste_1,echelle,C_X,C_Y);
			if ( Colli == C_Pomme){
				*score_p = *score_p +  5;
				pommes_manger--;
				Grandir_Serpent(Serpent_1,&grandir);
				dessine_frame(Serpent_1,Pommes_liste_1,Obstacle_liste_1,echelle,C_X,C_Y);
				if (pommes_manger == 0){
					free_serpent(Serpent_1);
					free_pomme(Pommes_liste_1);
					free_obstacle(Obstacle_liste_1);
					timer_add = timer(timer_1,echelle,C_X,C_Y);
					*niveau = *niveau + 1;
					score(score_p,echelle,C_X,C_Y,*niveau);
					nbr_pommes++;
					pommes_manger = nbr_pommes;
					nbr_obstacle++;
					if(intervale > 30){
						intervale= intervale - 5;
					}
					intervale_last = intervale;
					grandir = 0;
					Serpent_1 = init_Serpent(taille_ini,C_X/2 ,C_Y/2,nbr_pommes*2 + taille_ini,echelle);
					Pommes_liste_1 = init_Pommes_liste(C_X,C_Y,nbr_pommes, echelle);
					Obstacle_liste_1 = init_Obstacle_liste(C_X ,C_Y ,nbr_obstacle,Pommes_liste_1,echelle);
					Derniere_touche = XK_Up;
					debut = 0;
					dessine_frame(Serpent_1,Pommes_liste_1,Obstacle_liste_1,echelle,C_X,C_Y);
				}
			}
			if (Colli == C_Obstacle || Colli == C_Serpent ){
				free_serpent(Serpent_1);
				free_pomme(Pommes_liste_1);
				free_obstacle(Obstacle_liste_1);
				break;
			}
		}
	}
	FermerGraphique();
}

int main(){
	int continuer = 1;
	int score_p = 0;
	int niveau = 0;
	int lancer_jeu = 0;
	int echelle = 15;
	int intervale = 184;
	int intervale_choix = intervale;
	int C_X = 60;
	int C_Y = 40;
	int taille_ini = 10;
	int nbr_pommes = 5;
	while(continuer == 1){
		intervale = intervale_choix;
		Menu_graphique(&lancer_jeu,&nbr_pommes,&taille_ini,&C_X,&C_Y,&echelle,&intervale,&score_p,&niveau,&continuer);
		intervale_choix = intervale;
		if (lancer_jeu == 1){
			continuer = 1;
			lancer_jeu = 0;
			score_p = 0;
			jeu(C_X,C_Y,echelle,taille_ini,nbr_pommes,intervale,&score_p,&niveau);
		}
	}
}