#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define sz 20
#define szm 50
#define jm 3
#define aa 5

struct date{
  char jour[jm];
  char mois[jm];
  char anne[aa];
};

struct adress{
  char ville[sz];
  char rue[sz];
};
typedef struct adress adress;

struct personel{
  char id[sz];
  char username[sz];
  char password[sz];
  char nom[sz];
  char prenom[sz];
  struct date Date;
  char email[szm];
  char num[sz];
  adress adresse;
};

typedef struct personel medecin;

struct pa
{
  char id[sz];
  char nompa[sz];
  char prenompa[sz];
  struct date Date;
  char poids[sz];
  char taille[sz];
  char gs[3];
  char t[sz];
  char a[sz];
  char d[sz];
  char c[sz];
};


struct espace{
char nom[20];
char etat[20];
char temp[20];
char tele[20];
};

char *get_text_of_textview(GtkWidget *text_view);

void ajouter_m(medecin);
void supprimer(char cin[]);
medecin chercher(char x[]);
void modifier(medecin);
int auto_incre_id();


typedef struct personel infirmier;

void ajouter_i(infirmier);
void supprimer_i(char cin[]);
infirmier chercher_i(char x[]);
void modifier_i(infirmier);
int auto_incre_id_inf();


typedef struct personel technicien;

void ajouter_tec(technicien);
void supprimer_tec(char cin[]);
technicien chercher_tec(char x[]);
void modifier_tec(technicien);
int auto_incre_id_tec();

typedef struct personel aide_soignant;

void ajouter_as(aide_soignant);
void supprimer_as(char cin[]);
aide_soignant chercher_as(char x[]);
void modifier_as(aide_soignant);
int auto_incre_id_as();


typedef struct pa p_agee;

void ajouter_pa(p_agee);
void supprimer_pa(char cin[]);
p_agee chercher_pa(char x[]);
void modifier_pa(p_agee);
int auto_incre_id_pa();

typedef struct espace Espace;

void ajout_espace(Espace e);
Espace chercher_espace(char x[]);
void modifier_espace(Espace e1);
