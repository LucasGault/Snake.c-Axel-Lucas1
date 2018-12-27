#include<stdlib.h>
#include<graph.h>
#include <stdio.h>


void Options(int X,int Y){
	InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);

    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,0,600,85);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(245,45,"Options",2);

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

    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(0,300,600,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(248,320,"Taille",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(87,335,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(97,351,"Serpent",2);

    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(265,330,2,280);

    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    RemplirRectangle(387,335,60,30);
    ChoisirCouleurDessin(CouleurParComposante(62, 86, 15));
    EcrireTexte(397,351,"Grille",2);

    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(500,600,"Retour",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(10,600,"Quitter (Esc)",2);
    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		printf("X %d Y %d\n",_X,_Y );
    		
    		if(_X>=497 && _Y>=589 && _X<=536 && _Y<=602){
    			break;
    		}
    	}
   		if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                break;
            }
        }
   	}    
}
void Jeu(int X,int Y){
	InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
	InitialiserGraphique();
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
   	EcrireTexte(260,Y/2,"LE JEU",2);
   	while(1){
   		if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                break;
            }
        }
   	}
}
void Menu(int X,int Y ,int * continuer){
    InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChargerImageFond("serpent.png");
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(260,Y/2,"Jouer",2);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(260,Y/1.5,"Options",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(60,540,"Niveau : ",1.5);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(375,540,"Score : ",1.5);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(10,600,"Quitter (Esc)",2);
    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		//printf("X %d Y %d\n",_X,_Y );
            if(_X>=262 && _Y>=284 && _X<=341 && _Y<=306){
                FermerGraphique();
                Jeu(X,Y);
                break;
            }
            if(_X>=257 && _Y>=394 && _X<=371 && _Y<=408){
            	FermerGraphique();
                Options(X,Y);
                break;
            }
            if(_X>=7 && _Y>=587 && _X<=86 && _Y<=604){
            	*continuer = 0;
            	break;
            }
        }
        if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                *continuer = 0;
                break;
            }
        }
    }
}


int main() {
	int X = 600;
	int Y = 610;
    int continuer = 1;
	while(continuer == 1){
		Menu(X,Y,&continuer);
		FermerGraphique();
	}
}
/*void Vitesse(int X, int Y){
	InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(110, 158, 19));
    RemplirRectangle(20,228,50,30);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(500,600,"Retour",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(10,600,"Menu",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(28,245,"Normal",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(250,245,"Moyen",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(465,245,"Rapide",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(245,50,"Vitesse",2);
    while(1){
    	SourisPosition();
    	if (SourisCliquee() == 1){
    		printf("X %d Y %d\n",_X,_Y );
    		if(_X>=25 && _Y>=233 && _X<=63 && _Y<=247){
    			ChoisirCouleurDessin(CouleurParComposante(162,209,73));
   				RemplirRectangle(0,0,X,Y);
   				ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(500,600,"Retour",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(10,600,"Menu",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(250,245,"Moyen",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(465,245,"Rapide",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(245,50,"Vitesse",2);
    			ChoisirCouleurDessin(CouleurParComposante(110, 158, 19));
    			RemplirRectangle(20,228,50,30);
    			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
   				EcrireTexte(28,245,"Normal",2);
   				//mettre le serpent a la bonne vittesse
    		}
    		if(_X>=246 && _Y>=233 && _X<=281 && _Y<=247){
    			ChoisirCouleurDessin(CouleurParComposante(162,209,73));
   				RemplirRectangle(0,0,X,Y);
   				ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(500,600,"Retour",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(10,600,"Menu",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    			EcrireTexte(28,245,"Normal",2);
    			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    			EcrireTexte(465,245,"Rapide",2);
			    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			    EcrireTexte(245,50,"Vitesse",2);
    			ChoisirCouleurDessin(CouleurParComposante(110, 158, 19));
    			RemplirRectangle(242,228,50,30);
    			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    			EcrireTexte(250,245,"Moyen",2);
    			//mettre le serpent a la bonne vittesse
    		}
    		if(_X>=461 && _Y>=234 && _X<=502 && _Y<=247){
    			//mettre le serpent a la bonne vittesse
    		}
    		if(_X>=7 && _Y>=590 && _X<=34 && _Y<=601){

    		}
    	}
   		if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                break;
            }
        } 
    } 
}
void Pommes(int X, int Y){
	InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(60,100,"Pommes",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(28,245,"-",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(250,245,"nbr",1);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(465,245,"+",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(500,600,"Retour",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(10,600,"Menu",2);
}
void Taille (int X, int Y){
	InitialiserGraphique();
    CreerFenetre(300,50,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
    RemplirRectangle(0,0,X,Y);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(500,600,"Retour",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(10,600,"Menu",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(28,230,"Serpent",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(28,260,"Grille",2);
    //ajouter + - le nb 
}*/