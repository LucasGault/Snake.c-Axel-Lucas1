but : P_physique P_graphique Snake.out

OFILES = Partie_Physique/Gestion_serpent.o \
				 Partie_Physique/Affichage_console.o\
				 Partie_Physique/Gestion_obstacle.o \
				 Partie_Physique/Gestion_collision.o \
				 Partie_Graphique/Dessine_frame.o \
				 Partie_Graphique/Controle_Graphique.o \
				 Partie_Graphique/Timer.o \
				 main.o

CC = gcc
P_graphique : P_physique
		cd Partie_Graphique && make && cd ../
P_physique :
		cd Partie_Physique/ && make && cd ../

main.o :  P_physique main.c

Snake.out : $(OFILES)
	$(CC)  -o Snake.out $(OFILES) -lgraph

clean :
	cd Partie_Physique/ && make clean && cd ../
	rm -f $(OFILES) Snake.out
