#include "Timer.h"
#include <stdio.h>
#include <graph.h>

//initialisation du score
void dessine_score(char afficher[],int echelle,int C_X,int C_Y){
	ChoisirEcran(1);
	ChoisirCouleurDessin(CouleurParNom("white"));
	int taille = TailleChaineEcran(afficher,2);
	EcrireTexte(C_X*echelle - taille ,(C_Y + 2)*echelle + TailleSupPolice(2),afficher,2);
}
//affiche le niveau
void dessine_niveau(int C_X, int C_Y,int niveau,int echelle){
	char afficher[20];
	sprintf(afficher,"Niveau : %d",niveau);
	int taille = TailleChaineEcran(afficher,2);
	EcrireTexte((C_X*echelle)/2 - taille/2 ,(C_Y + 2)*echelle + TailleSupPolice(2),afficher,2);
}
//afiche le score
void score(int* score_p , int echelle,int C_X,int C_Y,int niveau){
	char afficher[15];
	if (*score_p < 10){
		sprintf(afficher,"Score : 0000%d",*score_p);
	}else if(*score_p < 100){
		sprintf(afficher,"Score : 000%d",*score_p);
	}else if(*score_p < 1000){
		sprintf(afficher,"Score : 00%d",*score_p);
	}else if(*score_p < 10000){
		sprintf(afficher,"Score : 0%d",*score_p);
	}else{
		sprintf(afficher,"Score : %d",*score_p);
	}
	dessine_score(afficher,echelle,C_X,C_Y);
	dessine_niveau(C_X,C_Y,niveau,echelle);
}
//initialisation du timer
void Dessine_Timer(char afficher[],int echelle,int C_X, int C_Y){
	ChoisirEcran(1);
	ChoisirCouleurDessin(CouleurParComposante(87,138,52));
	RemplirRectangle(0,C_Y*echelle,C_X*echelle,2*echelle);
	ChoisirCouleurDessin(CouleurParComposante(74,117,44));
	RemplirRectangle(0,C_Y*echelle + 2 * echelle,C_X*echelle,TailleInfPolice(2)+TailleSupPolice(2));
	ChoisirCouleurDessin(CouleurParNom("white"));
	EcrireTexte(0,(C_Y + 2)*echelle + TailleSupPolice(2) ,afficher,2);
}
//affichage du timer
unsigned long  timer(unsigned long timer_1,int echelle,int C_X , int C_Y){
	unsigned long timer = Microsecondes();
	char seconde_a[5];
	char minute_a[5];
	char afficher[50];
	timer = Microsecondes();
	unsigned long timer_add = timer - timer_1;
	int seconde = ((timer_add)/1000000);
	int minute = seconde/60;
	if ((seconde%60) < 10){
		sprintf(seconde_a,"0%d",seconde%60);
	}else {
		sprintf(seconde_a,"%d",seconde%60);
	}
	if ((minute%60) < 10){
		sprintf(minute_a , "0%d",minute);
	}else {
		sprintf(minute_a , "%d",minute);
	}
	sprintf(afficher,"Temps: %s : %s",minute_a,seconde_a);
	Dessine_Timer(afficher,echelle,C_X,C_Y);
	return timer_add;
}