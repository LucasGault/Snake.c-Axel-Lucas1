#include "options.h"
#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
void Dessiner_Bordure(int X_max , int Y , char * texte , couleur couleur_arriere , couleur couleur_texte){
	ChoisirCouleurDessin(couleur_arriere); //On choisis la couleur de la bordure
	int taille_h = TailleInfPolice(2) + TailleSupPolice(2); //On récupére la taille de la police pour pouvoir l'encadrer correctement
	RemplirRectangle(0,Y,X_max,taille_h + 4);
	ChoisirCouleurDessin(couleur_texte);
	EcrireTexte(X_max/2 - TailleChaineEcran(texte,2)/2, Y + TailleSupPolice(2),texte,2);
}
void Dessiner_Texte_Encadrer(int X, int Y , char* texte, couleur couleur_arriere , couleur couleur_texte, int taille){
	ChoisirCouleurDessin(couleur_arriere); //On choisis la couleur de la bordure
	int taille_h = TailleInfPolice(taille) + TailleSupPolice(taille); //On récupére la taille de la police pour pouvoir l'encadrer correctement
	int longueur_t = TailleChaineEcran(texte,taille);
	RemplirRectangle(X - longueur_t/2, Y,longueur_t + 4, taille_h + 4);
	ChoisirCouleurDessin(couleur_texte);
	EcrireTexte(X - longueur_t/2,Y + 2 + TailleSupPolice(taille),texte,taille);

}
void Dessiner_texte(int X , int Y , char* texte,couleur couleur_texte, int taille){
	ChoisirCouleurDessin(couleur_texte);
	int longueur_t = TailleChaineEcran(texte,taille);
	EcrireTexte(X - longueur_t/2,Y + TailleSupPolice(taille),texte,taille);

}
void Dessine_texte_carre(int X , int Y , char*texte , couleur couleur_carre , couleur couleur_texte , int taille){
	ChoisirCouleurDessin(couleur_carre); //On choisis la couleur de la bordure
	int taille_h = TailleInfPolice(taille) + TailleSupPolice(taille); //On récupére la taille de la police pour pouvoir l'encadrer correctement
	int longueur_t = TailleChaineEcran(texte,taille);
	DessinerRectangle(X - taille_h/2,Y,taille_h,taille_h);
	EcrireTexte(X - longueur_t/2, Y + TailleSupPolice(taille), texte,taille);

}

void Options(int X,int Y,int* continuer){
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
	int taille_h = TailleInfPolice(2) + TailleSupPolice(2);
	int longueur_t = TailleChaineEcran("Facile",2);
	Dessiner_Bordure(X,100,"Vitesse",CouleurParComposante(0,0,0),CouleurParComposante(62,86,15));
	//Facile
	Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);
	//Moyen
    Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
    //Rapide
	Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);

    //Pommes
    Dessiner_Bordure(X,200,"Pommes",CouleurParComposante(0,0,0),CouleurParComposante(62,86,15));
		// '-'
		Dessine_texte_carre(X/6,250,"-",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
		//'nbr'
		Dessiner_Texte_Encadrer(X/2,250,"5",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
        // '+'
    Dessine_texte_carre(5*X/6,250,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);

    //Taille
        Dessiner_Bordure(X,300,"Taille",CouleurParComposante(0,0,0),CouleurParComposante(62,86,15));
    //Taille Serpent
        Dessiner_Texte_Encadrer(X/5,350,"Serpent",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
    // '-'
        Dessine_texte_carre(X/10,450,"-",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
    /*ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(25,450,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(37,470,"-",2);*/
    // 'nbr'
        Dessiner_Texte_Encadrer(X/5,450,"10",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
    /*ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(93,450,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(112,470,"nbr",1);*/
    //'+'
        Dessine_texte_carre(3*X/10,450,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
    /*ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    DessinerRectangle(185,450,30,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(196,470,"+",2);*/
    ////traits milieu
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(265,330,2,280);
    //Taille Grille
    Dessiner_Texte_Encadrer(3.5*X/5,350,"Grille",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
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
    ////traits milieu (mettre bien au milieu)
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
					FermerGraphique();
    			break;
    		}
            //chui pas sur
            if(_X>=0 && _Y>=589 && _X<=87 && _Y<=610){
                FermerGraphique();
				break;
            }
            //
    	}
   		if(ToucheEnAttente()){
            //chui pas sur pour ça
            if(Touche()==XK_Escape){
                FermerGraphique();
				*continuer = 0;
				break;
            }
            //
            if(Touche()==XK_Left){
                FermerGraphique();
                break;
            }
        }
   	}
}
