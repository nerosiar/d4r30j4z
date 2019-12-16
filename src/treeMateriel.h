#ifndef TREEMATERIEL_H_INCLUDED
#define TREEMATERIEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct materiel{
  char nom_m[20];
  char ref_m[20];
  char quant_m[20];
};

typedef struct materiel materiel;

enum
{
  COL_NM=0,
  COL_REF,
  COL_QUA,
  COL_TL
} ;

static GtkTreeModel * create_and_fill_model_mat (GtkWidget *treeview, materiel T[]);
static GtkWidget * create_view_and_model_mat (GtkWidget *treeview, materiel T[]);
void affichagemat (GtkWidget *treeview, materiel T[]);
void lecture_mat(FILE *f,materiel T[]);


static GtkTreeModel * create_and_fill_model_matm (GtkWidget *treeview, materiel T[]);
static GtkWidget * create_view_and_model_matm (GtkWidget *treeview, materiel T[]);
void affichagematm (GtkWidget *treeview, materiel T[]);
void lecture_matm (FILE *f,materiel T[]);

#endif
