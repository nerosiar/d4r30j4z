#ifndef TREEMEDICALE_H_INCLUDED
#define TREEMEDICALE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct mac {
  char d[50];
  char mss[1000];
};
  typedef struct mac cel;
enum
{
  C_MS=0,
  C_A
};

void lecturei(FILE *f, cel T[]);
static GtkTreeModel * create_and_fill_model_i (GtkWidget *treeview, cel T[]);
static GtkWidget * create_view_and_model_i (GtkWidget *treeview, cel T[]);
void affichagei (GtkWidget *treeview, cel T[]);


void lecturea(FILE *f, cel T[]);
static GtkTreeModel * create_and_fill_model_a (GtkWidget *treeview, cel T[]);
static GtkWidget * create_view_and_model_a (GtkWidget *treeview, cel T[]);
void affichagea (GtkWidget *treeview, cel T[]);

#endif
