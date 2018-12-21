#include<stdlib.h>
#include<graph.h>
#include <stdio.h>

void Options(int X,int Y){
	InitialiserGraphique();
   	CreerFenetre(500,200,X,Y);
	ChoisirCouleurDessin(CouleurParComposante(162,209,73));
	RemplirRectangle(0,0,X,Y);
    	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    	EcrireTexte(60,100,"Vitesse",2);
    	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
   	EcrireTexte(430,100,"Pomme",2);
    	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    	EcrireTexte(60,100,"Taille",2);
   	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(500,600,"Retour",2);      
}
void Vitesse(int X, int Y){
	InitialiserGraphique();
	CreerFenetre(500,200,X,Y);
	ChoisirCouleurDessin(CouleurParComposante(162,209,73));
	RemplirRectangle(0,0,X,Y);
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(500,600,"Retour",2);
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(10,600,"Menu",2);
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(28,245,"Lent",2);
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(250,245,"Moyen",2);
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(465,245,"Rapide",2);
	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
	EcrireTexte(245,50,"Vitesse",2);  
}
void Jeu(int X,int Y){
	InitialiserGraphique();
    	CreerFenetre(500,200,X,Y);
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
    	CreerFenetre(500,200,X,Y);
    	ChargerImageFond("serpent.png");
    	ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    	EcrireTexte(260,Y/2,"Jouer",2);
    	ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    	EcrireTexte(260,Y/1.5,"Options",2);
    	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    	EcrireTexte(60,540,"Niveau : ",1.5);
    	ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    	EcrireTexte(375,540,"Score : ",1.5);
    	while(1){
    		SourisPosition();
    		if (SourisCliquee() == 1){
            		if(_X>=262 && _Y>=284 && _X<341 && _Y<=306){
               			FermerGraphique();
               			Jeu(X,Y);
               			break;
           		}
             		if(_X>=257 && _Y>=394 && _X<371 && _Y<=408){
            			FermerGraphique();
               			Options(X,Y);
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
	int i = 0; 
    int c;
    int X_= _X;
    int Y_= _Y;
    int continuer = 1;
	while(continuer == 1){
	printf("continuer = %d\n",continuer);
	Menu(X,Y,&continuer);
	FermerGraphique();
	}

    /*while(1){
        /*if(SourisCliquee() == 1){
            SourisPosition();
            printf("X %d Y %d\n",_X,_Y );
        }
        if (SourisCliquee() == 1){
            if(_X>=262 && _Y>=284 && _X<341 && _Y<=306){
                FermerGraphique();
                Jeu(X,Y);

                if(ToucheEnAttente()){
                    if(Touche()==XK_Escape){
                        break;
                    }
                }
            }
            if(_X>=257 && _Y>=394 && _X<371 && _Y<=408){
            	FermerGraphique();
                Options(X,Y);
                if(SourisCliquee() == 1){
                    if(_X>=260 && _Y>=300 && _X<360 && _Y<=327){
                        Vitesse(X,Y);
                    }
                }
                
                if(ToucheEnAttente()){
                    if(Touche()==XK_Escape){
                        break;
                    }
                } 
            }
                
                   
        }        
        if(ToucheEnAttente()){
            if(Touche()==XK_Escape){
                break;
            }
        }	
    }*/

}
