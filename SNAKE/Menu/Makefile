CC = gcc

OFILES = jeu.o \
		 options.o \
		 menu.o \
		 Menu_graphique.o

Menu: $(OFILES)

jeu.o : jeu.h
	$(CC) -c jeu.c -o jeu.o -lgraph

options.o :options.h jeu.h
	$(CC) -c options.c -o options.o -lgraph

menu.o : menu.h jeu.h options.h
	$(CC) -c menu.c -o menu.o -lgraph

Menu_graphique.o : Menu_graphique.h jeu.h options.h menu.h
	$(CC) -c Menu_graphique.c -o Menu_graphique.o -lgraph

clean :
	-rm -f $(OFILES) Menu.out
