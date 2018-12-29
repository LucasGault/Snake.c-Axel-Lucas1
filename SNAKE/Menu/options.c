#include "options.h"
#include<stdlib.h>
#include<graph.h>
#include<stdio.h>

void Options(int X,int Y){
    //Initialisation fenetre
	InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);
    //options
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,0,600,85);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(45,45,"Options",2);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(500,45,"Jouer",2);
    //Vitesse
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,100,600,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(245,120,"Vitesse",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(52,150,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(65,170,"Normal",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(250,170,"Moyen",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(415,170,"Rapide",2);
    //Pommes
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,200,600,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(248,220,"Pommes",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(77,250,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(90,270,"-",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(240,250,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(260,270,"nbr",1);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(452,250,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(465,270,"+",2);
    //Taille
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,300,600,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(248,320,"Taille",2);
    //Taille Serpent
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(87,335,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(97,351,"Serpent",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(25,450,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(37,470,"-",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(93,450,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(112,470,"nbr",1);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(185,450,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(196,470,"+",2);
    //traits milieu
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(265,330,2,280);
    //Taille Grille
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(387,335,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(397,351,"Grille",2);
    //Taille Grille: Lignes
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(300,380,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(312,400,"Lignes",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(315,430,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(327,449,"-",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(300,475,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(320,493,"nbr",1);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(315,525,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(327,544,"+",2);
    //traits milieu
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(415,365,1,245);
    //Taille Grille; Colonnes
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(478,380,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(485,400,"Colonnes",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(500,430,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(512,449,"-",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(485,475,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(505,493,"nbr",1);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(500,525,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(512,544,"+",2);

    //fin
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(500,600,"Retour",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(10,600,"Quitter (Esc)",2);
    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		printf("X %d Y %d\n",_X,_Y );
    		if(_X>=52 && _Y>=150 && _X<=112 && _Y<=180){
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                RemplirRectangle(52,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
                EcrireTexte(65,170,"Normal",2);

                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(234,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(250,170,"Moyen",2);
                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(404,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(415,170,"Rapide",2);
            }
            if(_X>=234 && _Y>=150 && _X<=294 && _Y<=180){
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                RemplirRectangle(234,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
                EcrireTexte(250,170,"Moyen",2);

                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(52,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(65,170,"Normal",2);
                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(404,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(415,170,"Rapide",2);
            }
            if(_X>=404 && _Y>=150 && _X<=464 && _Y<=180){
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                RemplirRectangle(404,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
                EcrireTexte(415,170,"Rapide",2);

                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(52,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(65,170,"Normal",2);
                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(234,150,60,30);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(250,170,"Moyen",2);
            }
            if(_X>=77 && _Y>=250 && _X<=107 && _Y<=280){
                //faire nbr--
                printf("--\n");
            }
            if(_X>=452 && _Y>=250 && _X<=482 && _Y<=280){
                //faire nbr++
                printf("++\n");
            }
            if(_X>=25 && _Y>=450 && _X<=55 && _Y<=480){
                //nbr --
                printf("-\n");
            }
            if(_X>=185 && _Y>=450 && _X<=215 && _Y<=480){
                //nbr++
                printf("+\n");
            }
            if(_X>=315 && _Y>=430 && _X<=345 && _Y<=460){
                //nbr--
                printf("-\n");
            }
            if(_X>=315 && _Y>=525 && _X<=345 && _Y<=555){
                //nbr++
                printf("+\n");
            }
            if(_X>=500 && _Y>=430 && _X<=530 && _Y<=460){
                //nbr--
                printf("-\n");
            }
            if(_X>=500 && _Y>=525 && _X<=530 && _Y<=555){
                //nbr++
                printf("+\n");
            }
            if(_X>=497 && _Y>=30 && _X<=600 && _Y<=50){
                FermerGraphique();
                Jeu(X,Y);
                break;
            }
    		if(_X>=497 && _Y>=589 && _X<=600 && _Y<=610){
    			break;
    		}
            //chui pas sur
            if(_X>=0 && _Y>=589 && _X<=87 && _Y<=610){
                FermerGraphique();
            }
            //
    	}
   		if(ToucheEnAttente()){
            //chui pas sur pour ça
            if(Touche()==XK_Escape){
                FermerGraphique();
            }
            //
            if(Touche()==XK_Left){
                break;
            }
        }
   	}    
}