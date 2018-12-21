#include<stdlib.h>
#include<graph.h>
#include <stdio.h>

void Options(int X,int Y){
    CopierZone(4,0,0,0,X,Y,0,0);       
}
void Menu(int X,int Y){
    CopierZone(2,0,0,0,X,Y,0,0);
}
void Vitesse(int X, int Y){
    CopierZone(5,0,0,0,X,Y,0,0);  
}
void Jeu(){

}
int main() {
	int X = 600;
	int Y = 610;
	int i = 0; 
    int c;
    int X_= _X;
    int Y_= _Y;
    InitialiserGraphique();
    CreerFenetre(500,200,X,Y);
    //Ecran (2)Menu 
    ChoisirEcran(2);
    ChargerImageFond("serpent.png");
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(260,Y/2,"Jouer",2);
    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
    EcrireTexte(260,Y/1.5,"Options",2);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(60,540,"Niveau : ",1.5);
    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
    EcrireTexte(375,540,"Score : ",1.5);
    //Ecran (4) options
    ChoisirEcran(4);
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
    //Ecran (5) Vitesse
    ChoisirEcran(5);
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
    ChoisirEcran(0);
    CopierZone(4,0,0,0,X,Y,0,0);

    while(1){
        if(SourisCliquee() == 1){
            SourisPosition();
            printf("X %d Y %d\n",_X,_Y );
        }
        if (SourisCliquee() == 1){
            if(_X>=262 && _Y>=284 && _X<341 && _Y<=306){
                FermerGraphique();
                InitialiserGraphique();
                CreerFenetre(500,200,X,Y);
                InitialiserGraphique();
                ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                RemplirRectangle(0,0,X,Y);
                ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                EcrireTexte(260,Y/2,"LE JEU",2);

                if(ToucheEnAttente()){
                    if(Touche()==XK_Escape){
                        break;
                    }
                }
            }
            if(_X>=257 && _Y>=394 && _X<371 && _Y<=408){
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
    }
    FermerGraphique();
}
/*if(_X>=500 && _Y>=575 && _X<594 && _Y<=601){
                    FermerGraphique();
                    InitialiserGraphique();
                    CreerFenetre(500,200,X,Y);
                    ChargerImageFond("serpent.png");
                    ChoisirCouleurDessin(CouleurParComposante(255,255,255));
                    EcrireTexte(260,Y/2,"Jouer",2);
                    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                    EcrireTexte(260,Y/1.5,"Options",2);
                }*/