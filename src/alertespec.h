#ifndef ALERTESPEC_H_INCLUDED
#define ALERTESPEC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct qq{
  char np[20];
  char type[20];
  char dd[20];
  char temps[20];
  char temph[20];
};
typedef struct qq alsp ;
enum
{
  C_PA=0,
  C_TYPE,
  C_DD,
  C_TIME,
  C_TH,
  C_AS
};

//Alerte technique

void lectureatec(FILE *f,alsp T[]);
static GtkTreeModel * create_and_fill_model_atec (GtkWidget *treeview, alsp T[]);
static GtkWidget * create_view_and_model_atec (GtkWidget *treeview, alsp T[]);
void affichagealtec (GtkWidget *treeview, alsp T[]);


//Alerte medicale

void lectureamed(FILE *f,alsp T[]);
static GtkTreeModel * create_and_fill_model_amed (GtkWidget *treeview, alsp T[]);
static GtkWidget * create_view_and_model_amed (GtkWidget *treeview, alsp T[]);
void affichageamed (GtkWidget *treeview, alsp T[]);


#endif
