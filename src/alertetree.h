#ifndef ALERTETREE_H_INCLUDED
#define ALERTETREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct flaps
{
  char id[5];
  char mes[20];
  char exped[20];
};
typedef struct flaps ale;

enum
{
  COL_IDE=0,
  COL_EXP,
  COL_MSG,
  COL_AL
} ;

static GtkTreeModel * create_and_fill_model_alerte (GtkWidget *treeview, ale T[]);
static GtkWidget * create_view_and_model_alerte (GtkWidget *treeview, ale T[]);
void affichageAlerte (GtkWidget *treeview, ale T[]);
void lecture_a(FILE *f,ale T[]);

#endif
