
CC = gcc

OFILES = Gestion_serpent.o \
				 Affichage_console.o\
				 Gestion_obstacle.o \
				 Gestion_collision.o

Partie_Physique : $(OFILES)


Gestion_serpent.o : Gestion_serpent.h Gestion_serpent.c
	$(CC) -c Gestion_serpent.c -o Gestion_serpent.o -lgraph

Affichage_console.o : Gestion_serpent.h Affichage_console.h Affichage_console.c
	$(CC) -c Affichage_console.c -o Affichage_console.o -lgraph

Gestion_obstacle.o : Gestion_obstacle.c Gestion_obstacle.h Gestion_serpent.h
	$(CC) -c Gestion_obstacle.c -o Gestion_obstacle.o -lgraph

Gestion_collision.o : Gestion_collision.h Gestion_collision.c Gestion_obstacle.h Gestion_serpent.h
	$(CC) -c Gestion_collision.c -o Gestion_collision.o -lgraph

clean :
	-rm -f $(OFILES) exo.out
