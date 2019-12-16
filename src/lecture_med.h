#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sz 20
#define jm 3
#define aa 5

struct datee{
  char jour[5];
  char mois[10];
  char anne[10];
};

struct medecin1
 {
    char id[sz];
    char nom[sz];
    char prenom[sz];
    char username[sz];
    char password[sz];
    /*char jour[jm];
    char mois[jm];
    char anne[a];*/
  /*  char date_n[sz];
    char email[sz];
    char num[sz];
    char ville[sz];
    char rue[sz];*/
 };
typedef struct medecin1 medec;


struct personne1
 {
   char nomp[sz];
   char prenomp[sz];
   struct datee Daate;
   char poi[sz];
   char tail[sz];
   char gsp[3];
   char tp[sz];
   char ap[sz];
   char dp[sz];
   char cp[sz];

 };
typedef struct personne1 persag;


void lecture_medecin(FILE *f,medec T[]);
void lecture_infirmier(FILE *f,medec T[]);
void lecture_aide_soignant(FILE *f,medec T[]);
void lecture_technicien(FILE *f,medec T[]);
void lecture_pa(FILE *f,persag T[]);
