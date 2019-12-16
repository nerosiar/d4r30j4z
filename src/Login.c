#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Login.h"
#include "interface.h"
#define TAILLE 20
#define TAILLE_F 100

typedef struct nom{
  char nom[TAILLE];
  char motdepasse[TAILLE];
  int rol;
}users ;

int verifierlogin(char username[], char password[])
{
  users tableau[TAILLE_F];
  char util[TAILLE]; char passw[TAILLE]; int role;
  int nbline=0; int i=0;
  FILE *f;
  GtkWidget *Admin_window;
  GtkWidget *Medecin_window;
  GtkWidget *Infirmier_window;
  GtkWidget *Technicien_window;
  GtkWidget *Aide_soignat_window;

  int verif =0;

  f= fopen("users.txt","r");

  if (f != NULL)
  {
    while (fscanf(f,"%s %s %d\n",util,passw,&role) != EOF)
    {
      nbline++;
      strcpy(tableau[i].nom, util);
      strcpy(tableau[i].motdepasse, passw);
      tableau[i].rol = role;
      i++;
    }
    fclose(f);
  }

  for (i=0; i<nbline; i++)
  {
    if ((strcmp(tableau[i].nom, username)== 0) && (strcmp(tableau[i].motdepasse, password)== 0))
      {
        switch (tableau[i].rol)
        {
          case 1: //Admin_window

                  Admin_window = create_Admin_window ();
                  gtk_widget_show (Admin_window);

            break;
          case 2: //Medecin window
                  //gtk_label_set_text(GTK_LABEL(output), "Medecin");
                  Medecin_window = create_Espace_medecin();
                  gtk_widget_show (Medecin_window);
            break;
          case 3: //Infirmier_window
                  //gtk_label_set_text(GTK_LABEL(output), "Infirmier");
                  Infirmier_window = create_Espace_infirmier ();
                  gtk_widget_show (Infirmier_window);
            break;
          case 4: //Technicien_window
                  //gtk_label_set_text(GTK_LABEL(output), "Technicien");
                  Technicien_window = create_technicien_window ();
                  gtk_widget_show (Technicien_window);
            break;
          case 5: //Aide_soignat_window
                  //gtk_label_set_text(GTK_LABEL(output), "Aide-soignant");
                  Aide_soignat_window = create_espace_as ();
                  gtk_widget_show (Aide_soignat_window);
            break;
        }
        verif =tableau[i].rol;
        break;
      }

  }
  return verif;
}

int verifierexistant (char username[])
{
  int verif =-1;
  users tableau[TAILLE_F];
  FILE *f;
  char user[TAILLE];
  int nbline=0, i=0;

  f= fopen("users.txt","r");

  if (f != NULL)
    {
      while (fscanf(f,"%s",user) != EOF)
      {
        nbline ++;
        strcpy(tableau[i].nom ,user);
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(username, tableau[i].nom) == 0)
        {
          verif = 0; //Existant
          break;
        }
      else
      {
        verif =1; //inéxistant
      }
    }
  return verif;
}



void ajouterlogin (char username[], char password[], int role)
{
  FILE *f;
  int nouveau =0;
  //char utilisateur[20]; char pwd[20]; int role;

  f= fopen("users.txt","a+");

  if (f!= NULL)
  {
    nouveau = verifierexistant(username);
    if (nouveau == 1)
      {
        fprintf(f, "%s %s %d\n",username,password,role );
      }
    fclose(f);
  }
}
