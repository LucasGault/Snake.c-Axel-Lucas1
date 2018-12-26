#include "Timer.h"
#include <stdio.h>
#include <graph.h>
void dessine_score(char afficher[],int echelle){
	ChoisirEcran(1);
	ChoisirCouleurDessin(CouleurParNom("white"));
	int taille = TailleChaineEcran(afficher,2);
	EcrireTexte(60*echelle - taille - 2 * echelle,43*echelle,afficher,2);
}
void score(int* score_p , int echelle){
	char afficher[10];
	if (*score_p < 10){
		sprintf(afficher,"0000%d",*score_p);
	}
	else if(*score_p < 100){
		sprintf(afficher,"000%d",*score_p);
	}
	else if(*score_p < 1000){
		sprintf(afficher,"00%d",*score_p);
	}
	else if(*score_p < 10000){
		sprintf(afficher,"0%d",*score_p);
	}
	else{
		sprintf(afficher,"%d");
	}
	dessine_score(afficher,echelle);
}
void Dessine_Timer(char afficher[],int echelle){
	ChoisirEcran(1);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(0,40*echelle,60*echelle,6*echelle);
	ChoisirCouleurDessin(CouleurParNom("white"));
	EcrireTexte(2*echelle,43*echelle,afficher,2);
}


unsigned long  timer(unsigned long timer_1,int echelle){
	unsigned long timer = Microsecondes();
	char seconde_a[5];
	char minute_a[5];
	char afficher[30];
	timer = Microsecondes();
	unsigned long timer_add = timer - timer_1;
	int seconde = ((timer_add)/1000000);
	int minute = seconde/60;
	if ((seconde%60) < 10){
		sprintf(seconde_a,"0%d",seconde%60);
	}
	else {sprintf(seconde_a,"%d",seconde%60);}
	if ((minute%60) < 10){
		sprintf(minute_a , "0%d",minute);}
	else {sprintf(minute_a , "%d",minute);}
		sprintf(afficher,"%s : %s",minute_a,seconde_a);
		Dessine_Timer(afficher,echelle);
		return timer_add;
	}
