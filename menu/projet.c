#include<stdlib.h>
#include<graph.h>
#include <stdio.h>



int main() {
	int X = 600;
	int Y = 610;
	int i = 0; 
    int c;
    int X_= _X;
    int Y_= _Y;
    InitialiserGraphique();
    CreerFenetre(0,0,X,Y);
        ChoisirEcran(2);
        ChargerImageFond("serpent.png");
        //ChoisirCouleurDessin(CouleurParComposante(162,209,73));
        //RemplirRectangle(0,0,X,Y);
        ChoisirCouleurDessin(CouleurParComposante(255,255,255));
        EcrireTexte(260,Y/2,"Jouer",2);
        ChoisirCouleurDessin(CouleurParComposante(0,0,0));
        EcrireTexte(260,Y/1.5,"Options",2);
        ChoisirEcran(0);
        CopierZone(2,0,0,0,X,Y,0,0);

    while(1){
        if(SourisCliquee() == 1){
            SourisPosition();
            printf("%d %d\n",_X,_Y );
        }
        while(1){

            if (SourisCliquee()){
                SourisPosition();
                if(_X>=259 && _Y>=293 && _X<292 && _Y<=308){
                    FermerGraphique();
                    InitialiserGraphique();
                    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                    RemplirRectangle(0,0,X,Y);
                    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                    EcrireTexte(260,Y/2,"LE JEU",2);
                    /*if(Touche()==XK_Escape){
                        break;
                    }*/
                }
                if(_X>=257 && _Y>=394 && _X<304 && _Y<=408){
                    FermerGraphique();
                    InitialiserGraphique();
                    CreerFenetre(0,0,X,Y);
                    ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                    RemplirRectangle(0,0,X,Y);
                    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                    EcrireTexte(260,Y/2,"Niveau",2);
                    ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                    EcrireTexte(260,Y/1.5,"Retour",2);
                    /*if(Touche()==XK_Escape){
                            break;
                    }*/
                    while(1){
                        if (SourisCliquee()){
                        if(_X>=259 && _Y>=293 && _X<292 && _Y<=308){

                        FermerGraphique();
                        InitialiserGraphique();
                        CreerFenetre(0,0,X,Y);
                        ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                        RemplirRectangle(0,0,X,Y);
                    }
                }
            }
                    while(1){
                        if (SourisCliquee()){
                    if(_X>=257 && _Y>=394 && _X<304 && _Y<=408){
                        FermerGraphique();
                        InitialiserGraphique();
                        CreerFenetre(0,0,X,Y);
                        ChargerImageFond("serpent.png");
                        //ChoisirCouleurDessin(CouleurParComposante(162,209,73));
                        //RemplirRectangle(0,0,X,Y);
                        ChoisirCouleurDessin(CouleurParComposante(255,255,255));
                        EcrireTexte(260,Y/2,"Jouer",2);
                        ChoisirCouleurDessin(CouleurParComposante(0,0,0));
                        EcrireTexte(260,Y/1.5,"Options",2);
                    }
                }
            }
                }
            }
               
        } 
        /*if(Touche()==XK_Escape){
            break;
        }*/ 	
    }
    FermerGraphique();
    return EXIT_SUCCESS;
}