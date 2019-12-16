#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "lecture_med.h"

enum
{
  COL_ID=0,
  COL_NOM,
  COL_PRENOM,
  COL_USERNAME,
  COL_PASSWORD,
//  COL_DATE,
  //COL_MAIL,
  //COL_NUMERO,
  //COL_RUE,
  //COL_VILLE,
  COLUMNS_MEDECIN
} ;



static GtkTreeModel * create_and_fill_model_medecin (GtkWidget *treeview_med,medec T[]);
static GtkWidget * create_view_and_model_medecin (GtkWidget *treeview_med, medec T[]);
void affichageMedecin (GtkWidget *treeview_med, medec T[]);

static GtkTreeModel * create_and_fill_model_infirmier (GtkWidget *treeview_inf,medec T[]);
static GtkWidget * create_view_and_model_infirmier (GtkWidget *treeview_inf, medec T[]);
void affichageInfirmier (GtkWidget *treeview_inf, medec T[]);

static GtkTreeModel * create_and_fill_model_aide_soignant (GtkWidget *treeview_aide_soignant,medec T[]);
static GtkWidget * create_view_and_model_aide_soignant (GtkWidget *treeview_aide_soignant, medec T[]);
void affichageAideSoignant (GtkWidget *treeview_aide_soignant, medec T[]);

static GtkTreeModel * create_and_fill_model_technicien (GtkWidget *treeview_technicien,medec T[]);
static GtkWidget * create_view_and_model_technicien (GtkWidget *treeview_technicien, medec T[]);
void affichageTechnicien (GtkWidget *treeview_technicien, medec T[]);

static GtkTreeModel * create_and_fill_model_pa (GtkWidget *treeview_pa,persag T[]);
static GtkWidget * create_view_and_model_pa (GtkWidget *treeview_pa, persag T[]);
void affichagepa (GtkWidget *treeview_pa, persag T[]);
