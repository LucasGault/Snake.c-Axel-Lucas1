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
    	Dessiner_Texte_Encadrer(5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);

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
    
        // 'nbr'
        Dessiner_Texte_Encadrer(X/5,450,"10",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
    
        //'+'
        Dessine_texte_carre(3*X/10,450,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
    
    //traits milieu
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(265,330,2,280);

    //Taille Grille
    Dessiner_Texte_Encadrer(3.5*X/5,350,"Grille",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);

    //Taille Grille: Lignes
    Dessiner_Texte_Encadrer(X/1.75,375,"Lignes",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
        // '-'
        Dessine_texte_carre(X/1.75,420,"-",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
        // 'nbr'
        Dessiner_Texte_Encadrer(X/1.76,455,"40",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);    
        //'+'
        Dessine_texte_carre(X/1.75,490,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
    
    //traits milieu
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(420,365,1,245);

    //Taille Grille; Colonnes
    Dessiner_Texte_Encadrer(5*X/6,375,"Colonnes",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
        // '-'
        Dessine_texte_carre(X/1.2,420,"-",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
        // 'nbr'
        Dessiner_Texte_Encadrer(X/1.2,455,"60",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
        //'+'
        Dessine_texte_carre(X/1.2,490,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
    
    //fin
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(500,600,"Retour",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(10,600,"Quitter (Esc)",2);

    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		printf("X %d Y %d\n",_X,_Y ); 
            //on prend les coordonnées des zones cliquable
            //facile
    		if(_X>=81 && _Y>=149 && _X<=122 && _Y<=167){
                Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

                Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
                Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
            }
            //Moyen
            if(_X>=284 && _Y>=149 && _X<=319 && _Y<=167){
                Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);
                
                Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
                Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
            }
            //Rapide
            if(_X>=481 && _Y>=149 && _X<=522 && _Y<=167){
                Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

                Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
                Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
            }

            //change le nbr de pommes
            if(_X>=94 && _Y>=250 && _X<=108 && _Y<=264){
                //faire nbr--
                printf("-\n");
            }
            if(_X>=494 && _Y>=250 && _X<=507 && _Y<=264){
                //faire nbr++
                printf("+\n");
            }

            //change la taille du serpent
            if(_X>=54 && _Y>=449 && _X<=64 && _Y<=464){
                //nbr --
                printf("--\n");
            }
            if(_X>=173 && _Y>=449 && _X<=187 && _Y<=464){
                //nbr++
                printf("++\n");
            }

            //change le nbr de lignes
            if(_X>=336 && _Y>=420 && _X<=349 && _Y<=433){
                //nbr--
                printf("---\n");
            }
            if(_X>=336 && _Y>=490 && _X<=349 && _Y<=503){
                //nbr++
                printf("+++\n");
            }

            //change le nbr de colonnes
            if(_X>=494 && _Y>=419 && _X<=507 && _Y<=434){
                //nbr--
                printf("----\n");
            }
            if(_X>=494 && _Y>=490 && _X<=507 && _Y<=503){
                //nbr++
                printf("++++\n");
            }
            //on lance le jeu
            if(_X>=497 && _Y>=30 && _X<=600 && _Y<=50){
                FermerGraphique();
                Jeu(X,Y);
                break;
            }
            //Retour au menu 
    		if(_X>=497 && _Y>=589 && _X<=600 && _Y<=610){
				FermerGraphique();
    			break;
    		}
            //ferme le menu
            if(_X>=0 && _Y>=589 && _X<=87 && _Y<=610){
                FermerGraphique();
                *continuer = 0;
				break;
            }
            //
    	}
        
   		if(ToucheEnAttente()){
            //Ferme le jeu
            if(Touche()==XK_Escape){
                FermerGraphique();
				*continuer = 0;
				break;
            }
            //retour au menu
            if(Touche()==XK_Left){
                FermerGraphique();
                break;
            }
        }
   	}
}
