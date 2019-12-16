#ifndef ADD_MATERIEL_DATA_H_INCLUDED
#define ADD_MATERIEL_DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct camera{
char identifiant_camera[10];
char info[20];
char emplacement[20];
};
typedef struct camera Camera;




struct bracelet{
char identifiant_bracelet[10];
char info[20];
char etat[20];
};
typedef struct bracelet Bracelet;

int auto_incre_id_bracelet();

void ajout_bracelet(Bracelet bracelet);
void supprimer_bracelet(char identifiant_bracelet[10]);
Bracelet chercher_bracelet(char x[]);
void modifier_bracelet(Bracelet bracelet);

int auto_incre_id_camera();
void ajout_camera(Camera camera);
void supprimer_camera(char identifiant_camera[10]);
Camera chercher_camera(char x[]);
void modifier_camera(Camera camera);


#endif
