CC = gcc

OFILES = Dessine_frame.o \
		 Controle_Graphique.o \

Partie_Graphique : $(OFILES)

Dessine_frame.o : Dessine_frame.h
	$(CC) -c Dessine_frame.c -o Dessine_frame.o -lgraph
Controle_Graphique.o :Controle_Graphique.h
	$(CC) -c Controle_Graphique.c -o Controle_Graphique.o -lgraph
clean :
	-rm -f $(OFILES) exo.out