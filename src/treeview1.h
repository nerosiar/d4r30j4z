#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "lecture_cam.h"

enum
{
  COL_Id=0,
  COL_EMP,
  COL_INFO,
  COLUMNS_CAMERA
} ;



static GtkTreeModel * create_and_fill_model_camera (GtkWidget *treeview_cam,came T[]);
static GtkWidget * create_view_and_model_camera (GtkWidget *treeview_cam, came T[]);
void affichagecamera (GtkWidget *treeview_cam, came T[]);

static GtkTreeModel * create_and_fill_model_bracelet (GtkWidget *treeview_bra,brac T[]);
static GtkWidget * create_view_and_model_bracelet (GtkWidget *treeview_bra, brac T[]);
void affichagebracelet (GtkWidget *treeview_bra, brac T[]);
