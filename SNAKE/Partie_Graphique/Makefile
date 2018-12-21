CC = gcc

OFILES = Dessine_frame.o \
		 Controle_Graphique.o \
		 Timer.o \

Partie_Graphique : $(OFILES)

Dessine_frame.o : Dessine_frame.h
	$(CC) -c Dessine_frame.c -o Dessine_frame.o -lgraph
Controle_Graphique.o :Controle_Graphique.h
	$(CC) -c Controle_Graphique.c -o Controle_Graphique.o -lgraph

Timer.o : Timer.h
	$(CC) -c Timer.c -o Timer.o -lgraph
clean :
	-rm -f $(OFILES) 