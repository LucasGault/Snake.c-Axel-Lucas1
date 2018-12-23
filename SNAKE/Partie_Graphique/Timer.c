#include "Timer.h"
#include <stdio.h>
#include <graph.h>
unsigned long  timer(unsigned long timer_1){
	unsigned long timer = Microsecondes();
    char seconde_a[5];
    char minute_a[5];
    char afficher[30];
    timer = Microsecondes();
    unsigned long timer_add = timer - timer_1;
    int seconde = ((timer_add)/1000000);
    int minute = seconde/60;
    if ((seconde%60) < 10){
    	sprintf(seconde_a,"0%d",seconde%60);
    }
    else {sprintf(seconde_a,"%d",seconde%60);}
    if ((minute%60) < 10){
    sprintf(minute_a , "0%d",minute%60);}
    else {sprintf(minute_a , "%d",minute%60);}
    sprintf(afficher,"%s : %s ",minute_a,seconde_a);
    printf(afficher);
    return timer_add;
}
