#ifndef TREEALERTETEC_H_INCLUDED
#define TREEALERTETEC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct technique{
  char nom_p[50];
  char text_r[200];
};

typedef struct technique al_tec;
enum
{
  C_NP=0,
  C_T,
  C_R
};

static GtkTreeModel * create_and_fill_model_t (GtkWidget *treeview, al_tec T[]);
static GtkWidget * create_view_and_model_t (GtkWidget *treeview, al_tec T[]);
void affichaget (GtkWidget *treeview, al_tec T[]);
void lecture_t(FILE *f,al_tec T[]);

#endif
