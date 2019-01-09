CC = gcc

OFILES = options.o \
		 menu.o \
		 Menu_graphique.o

Menu: $(OFILES)

options.o :options.h 
	$(CC) -c options.c -o options.o -lgraph

menu.o : menu.h options.h
	$(CC) -c menu.c -o menu.o -lgraph

Menu_graphique.o : Menu_graphique.h options.h menu.h
	$(CC) -c Menu_graphique.c -o Menu_graphique.o -lgraph

clean :
	-rm -f $(OFILES) Menu.out
