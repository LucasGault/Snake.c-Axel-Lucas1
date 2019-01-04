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

void Options(int X,int Y,int* continuer,int * nbr_pommes, int * taille_ini,int * C_X, int * C_Y, int * lancer_jeu,int * echelle,int * intervale){
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
    //EcrireTexte(500,45,"Jouer",2);
		Dessiner_texte(500,20,"Jouer",CouleurParComposante(62, 86, 15),2);
    //Vitesse
	int taille_h = TailleInfPolice(2) + TailleSupPolice(2);
	int longueur_t = TailleChaineEcran("Facile",2);
	Dessiner_Bordure(X,100,"Vitesse",CouleurParComposante(0,0,0),CouleurParComposante(62,86,15));
    	//Facile
			if(*intervale == 184){
    	Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);
    	//Moyen
      Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
        //Rapide
    	Dessiner_Texte_Encadrer(5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
			}
			if(*intervale == 110){
				Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

				Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
				Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
			}
			if(*intervale == 60){
			Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

			Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
			Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
		}

    //Pommes
    Dessiner_Bordure(X,200,"Pommes",CouleurParComposante(0,0,0),CouleurParComposante(62,86,15));
		// '-'
		Dessine_texte_carre(X/6,250,"-",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);
		//'nbr'
		char Afficher[10];
		sprintf(Afficher,"%d",*nbr_pommes);
		Dessiner_Texte_Encadrer(X/2,250,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
    // '+'
    Dessine_texte_carre(5*X/6,250,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);

    //Taille
    Dessiner_Bordure(X,300,"Taille",CouleurParComposante(0,0,0),CouleurParComposante(62,86,15));

    //Taille Serpent
    Dessiner_Texte_Encadrer(X/5,350,"Serpent",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
        // '-'
        Dessine_texte_carre(X/10,450,"-",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);

        // 'nbr'
				sprintf(Afficher,"%d",*taille_ini);
        Dessiner_Texte_Encadrer(X/5,450,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);

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
				sprintf(Afficher,"%d",*C_Y);
        Dessiner_Texte_Encadrer(X/1.76,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
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
				sprintf(Afficher,"%d",*C_X);
        Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
        //'+'
        Dessine_texte_carre(X/1.2,490,"+",CouleurParComposante(0,0,0),CouleurParComposante(0,0,0),2);

    //fin
		Dessiner_texte(550,580,"Retour",CouleurParComposante(0,0,0),2);
		Dessiner_texte(100,580,"Quitter (Esc)",CouleurParComposante(0,0,0),2);


    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
            //on prend les coordonnées des zones cliquable
            //facile
    		if(_X>=X/6 - TailleChaineEcran("Facile",2)/2 && _Y>=150 - TailleInfPolice(2) - TailleSupPolice(2) && _X<=X/6 + TailleChaineEcran("Facile",2)/2  && _Y<=150 + TailleInfPolice(2) + TailleSupPolice(2)){
                Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

                Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
                Dessiner_Texte_Encadrer(5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
								*intervale = 184;
            }
            //Moyen
            if(_X>=X/2 - TailleChaineEcran("Moyen",2)/2 && _Y>=150 - TailleInfPolice(2) - TailleSupPolice(2) && _X<=X/2 + TailleChaineEcran("Moyen",2)/2  && _Y<=150 + TailleInfPolice(2) + TailleSupPolice(2)){
                Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

                Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
                Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
								*intervale = 110;
            }
            //Rapide
            if(_X>=5*X/6 - TailleChaineEcran("Rapide",2)/2 && _Y>=150 - TailleInfPolice(2) - TailleSupPolice(2) && _X<=5*X/6 + TailleChaineEcran("Rapide",2)/2  && _Y<=150 + TailleInfPolice(2) + TailleSupPolice(2)){
                Dessiner_Texte_Encadrer( 5*X/6,150,"Rapide",CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),2);

                Dessiner_Texte_Encadrer(X/6,150,"Facile",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
                Dessiner_Texte_Encadrer(X/2,150,"Moyen",CouleurParComposante(162,209,73),CouleurParComposante(0,0,0),2);
								*intervale = 60;
            }
						int taille_h = TailleInfPolice(2) + TailleSupPolice(2);
            //change le nbr de pommes
            if(_X>=X/6 -taille_h/2 && _Y>=250&& _X<=X/6 -taille_h/2+ taille_h && _Y<=250 + taille_h){
							*nbr_pommes = *nbr_pommes - 1;
							if(*nbr_pommes >= 1){
								if(*nbr_pommes < 10){sprintf(Afficher,"0%d",*nbr_pommes);}else{sprintf(Afficher,"%d",*nbr_pommes);}
              		sprintf(Afficher,"%d",*nbr_pommes);
									Dessiner_Texte_Encadrer(X/2,250,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
									}
								else{
									*nbr_pommes = 1;
									Dessiner_Texte_Encadrer(X/2,250,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
									}

            }
						if(_X>=5*X/6 -taille_h/2 && _Y>=250&& _X<=5*X/6 -taille_h/2+ taille_h && _Y<=250 + taille_h){
							*nbr_pommes = *nbr_pommes + 1;
							if(*nbr_pommes <= 99){
								if(*nbr_pommes < 10){sprintf(Afficher,"0%d",*nbr_pommes);}else{sprintf(Afficher,"%d",*nbr_pommes);}
									sprintf(Afficher,"%d",*nbr_pommes);
									Dessiner_Texte_Encadrer(X/2,250,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
									}
								else{
									*nbr_pommes = 99;
									Dessiner_Texte_Encadrer(X/2,250,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
									}
            }

            //change la taille du serpent
						if(_X>=X/10 -taille_h/2 && _Y>=450&& _X<=X/10 -taille_h/2+ taille_h && _Y<=450 + taille_h){
							*taille_ini = *taille_ini - 1;
							if(*taille_ini >= 1){
								if(*taille_ini < 10){sprintf(Afficher,"0%d",*taille_ini);}else{sprintf(Afficher,"%d",*taille_ini);}
						  	Dessiner_Texte_Encadrer(X/5,450,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
						  	}
							else{
								*taille_ini = 1;
								Dessiner_Texte_Encadrer(X/5,450,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
								}
            }
						if(_X>=3*X/10 -taille_h/2 && _Y>=450&& _X<=3*X/10 -taille_h/2+ taille_h && _Y<=450 + taille_h){
							*taille_ini = *taille_ini + 1;
							if(*taille_ini <= 99){
							if(*taille_ini < 10){sprintf(Afficher,"0%d",*taille_ini);}else{sprintf(Afficher,"%d",*taille_ini);}
							Dessiner_Texte_Encadrer(X/5,450,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
							}
							else{
								*taille_ini = 99;
								Dessiner_Texte_Encadrer(X/5,450,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
							}
            }

            //change le nbr de lignes
						if(_X>=X/1.75 -taille_h/2 && _Y>=420&& _X<=X/1.75 -taille_h/2+ taille_h && _Y<=420 + taille_h){
							*C_Y = *C_Y - 1;
							if(*C_Y >= 10){

								if(*C_Y * *echelle > 800){
									while(*C_Y * *echelle > 800){
										*echelle = *echelle - 1;
									}
								if(*C_X * *echelle < 600){
									while(*C_X * *echelle < 600){
											*C_X = * C_X + 1;
										}
										sprintf(Afficher,"%d",*C_X);
										Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255,250,205),1);
									}
								}

							  if(*C_Y < 10){sprintf(Afficher,"0%d",*taille_ini);}else{sprintf(Afficher,"%d",*taille_ini);}
								sprintf(Afficher,"%d",*C_Y);
								Dessiner_Texte_Encadrer(X/1.76,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
            }
						else{
							*C_Y = 10;
							Dessiner_Texte_Encadrer(X/1.76,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
						}
					}

						if(_X>=X/1.75 -taille_h/2 && _Y>=490&& _X<=X/1.75 -taille_h/2+ taille_h && _Y<=490 + taille_h){
							*C_Y = *C_Y + 1;
							if(*C_Y <= 750){

								if(*C_Y * *echelle > 750){
									while(*C_Y * *echelle > 800){
										*echelle = *echelle - 1;
									}
								if(*C_X * *echelle < 600){
									while(*C_X * *echelle < 600){
											*C_X = * C_X + 1;
										}
										sprintf(Afficher,"%d",*C_X);
										Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255,250,205),1);
									}
								}

								if(*C_X < 10){sprintf(Afficher,"0%d",*taille_ini);}else{sprintf(Afficher,"%d",*taille_ini);}
								sprintf(Afficher,"%d",*C_Y);
								Dessiner_Texte_Encadrer(X/1.76,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
						}
						else{
							*C_Y = 750;
							Dessiner_Texte_Encadrer(X/1.76,450,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
						}
					}

            //change le nbr de colonnes
						if(_X>=X/1.2 -taille_h/2 && _Y>=420&& _X<=X/1.2 -taille_h/2+ taille_h && _Y<=420 + taille_h){
							*C_X = *C_X - 1;
							if(*C_X > 10){
								if(*C_X * *echelle > 1500){
									while(*C_X * *echelle > 1500){
										*echelle = *echelle - 1;
									}
								}
								if(*C_X * *echelle < 600){
									while(*C_X * *echelle < 600){
									*echelle = *echelle + 1;
									}
								}
								if(*C_Y * *echelle > 750){
									while(*C_Y* *echelle >800){
									*C_Y = *C_Y - 1;
									}
									sprintf(Afficher,"%d",*C_Y);
									Dessiner_Texte_Encadrer(X/1.76,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 255, 200),1);
								}
								if(*taille_ini < 10){sprintf(Afficher,"0%d",*taille_ini);}else{sprintf(Afficher,"%d",*taille_ini);}
								sprintf(Afficher,"%d",*C_X);
								Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
							}
						else{
							*C_X = 10;
							sprintf(Afficher,"%d",*C_X);
							Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
							}
					}
						if(_X>=X/1.2 -taille_h/2 && _Y>=490&& _X<=X/1.2 -taille_h/2+ taille_h && _Y<=490 + taille_h){
							*C_X = *C_X + 1;
							if(*C_X < 1500){
								if(*C_X * *echelle > 1500){
									while(*C_X * *echelle > 1500){
										*echelle = *echelle - 1;
									}
								}
								if(*C_X * *echelle < 600){
									while(*C_X * *echelle < 600){
									*echelle = *echelle + 1;
									}
								}
								if(*C_Y * *echelle > 800){
									while(*C_Y * *echelle > 800){
									*C_Y = *C_Y - 1;
									}
									sprintf(Afficher,"%d",*C_X);
									Dessiner_Texte_Encadrer(X/1.76,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 255, 200),1);
								}
								if(*taille_ini < 10){sprintf(Afficher,"0%d",*taille_ini);}else{sprintf(Afficher,"%d",*taille_ini);}
								sprintf(Afficher,"%d",*C_X);
								Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(62, 86, 15),1);
						}
						else{
							*C_X = 1500;
							Dessiner_Texte_Encadrer(X/1.2,455,Afficher,CouleurParComposante(0,0,0),CouleurParComposante(255, 0, 0),1);
							}

					}
            //on lance le jeu
						if(_X>=500 - TailleChaineEcran("Jouer",2)/2 && _Y>=20  && _X<=500 + TailleChaineEcran("Jouer",2)/2  && _Y<=20 + TailleSupPolice(2)){
                FermerGraphique();
								*lancer_jeu = 1;
								*continuer = 0;
                break;
            }
            //Retour au menu
				if(_X>=550 - TailleChaineEcran("Retour",2)/2 && _Y>=580  && _X<=550 + TailleChaineEcran("Retour",2)/2  && _Y<=580 + TailleSupPolice(2)){
					FermerGraphique();
    			break;
    		}
            //ferme le menu
						if(_X>=100 - TailleChaineEcran("Quitter (Esc)",2)/2 && _Y>=580  && _X<=550 + TailleChaineEcran("Quitter (Esc)",2)/2  && _Y<=580 + TailleSupPolice(2)){
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
