#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct info{
int id;
int presence[2000];
int mvt[2000];
int temp[2000];
int heure[2000];
int jour[2000];
int mois[2000];
int anee[2000];
};
typedef struct info infop;

void remplirtableau(infop *p1, infop *p2, infop *p3, infop *p4, infop *p5, infop *p6, infop *p7, infop *p8, infop *p9, infop *p10,int *i1);
void erreurtech(infop *p,int i1);
void erreurmed(infop *p,int i1);
