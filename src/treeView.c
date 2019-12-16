#include "treeView.h"


static GtkTreeModel * create_and_fill_model_medecin (GtkWidget *treeview_med,medec T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="medecin.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}


  store = gtk_list_store_new (COLUMNS_MEDECIN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_ID , T[i].id, COL_NOM, T[i].nom, COL_PRENOM, T[i].prenom, COL_USERNAME, T[i].username, COL_PASSWORD, T[i].password,-1);

}

  return GTK_TREE_MODEL (store);
}


static GtkWidget * create_view_and_model_medecin (GtkWidget *treeview_med, medec T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                               -1,
                                               "Identifiant",
                                               renderer,
                                               "text", COL_ID,
                                               NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                               -1,
                                               "Nom",
                                               renderer,
                                               "text", COL_NOM,
                                               NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                               -1,
                                               "Prenom",
                                               renderer,
                                               "text", COL_PRENOM,
                                               NULL);

/* --- Colonne 4 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                               -1,
                                               "Username",
                                               renderer,
                                               "text", COL_USERNAME,
                                               NULL);

/* --- Colonne 5 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                               -1,
                                               "Password",
                                               renderer,
                                               "text", COL_PASSWORD,
                                               NULL);

/* --- Colonne  6--- */

/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Date de naissance",
                                            renderer,
                                              "text", COL_DATE,
                                            NULL);

/* --- Colonne  7--- */

/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Email",
                                            renderer,
                                              "text", COL_MAIL,
                                            NULL);

/* --- Colonne  8--- */
/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Numéro",
                                            renderer,
                                              "text", COL_NUMERO,
                                            NULL);

/* --- Colonne  9--- */
/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Rue",
                                            renderer,
                                              "text", COL_RUE,
                                            NULL);

/* --- Colonne  10--- */
/*col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_med),
                                            -1,
                                            "Ville",
                                            renderer,
                                              "text", COL_VILLE,
                                            NULL);
*/

  model = create_and_fill_model_medecin (treeview_med,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_med), model);

  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_med);
}

void affichageMedecin (GtkWidget *treeview_med, medec T[])
{
  treeview_med = create_view_and_model_medecin (treeview_med,T);
}



/**************INFIRMIER*********************/


static GtkTreeModel * create_and_fill_model_infirmier (GtkWidget *treeview_inf,medec T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="infirmier.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}


  store = gtk_list_store_new (COLUMNS_MEDECIN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_ID , T[i].id, COL_NOM, T[i].nom, COL_PRENOM, T[i].prenom, COL_USERNAME, T[i].username, COL_PASSWORD, T[i].password,-1);


  }

  return GTK_TREE_MODEL (store);
}


static GtkWidget * create_view_and_model_infirmier (GtkWidget *treeview_inf, medec T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_inf),
                                               -1,
                                               "Identifiant",
                                               renderer,
                                               "text", COL_ID,
                                               NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_inf),
                                               -1,
                                               "Nom",
                                               renderer,
                                               "text", COL_NOM,
                                               NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_inf),
                                               -1,
                                               "Prenom",
                                               renderer,
                                               "text", COL_PRENOM,
                                               NULL);

/* --- Colonne 4 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_inf),
                                               -1,
                                               "Username",
                                               renderer,
                                               "text", COL_USERNAME,
                                               NULL);

/* --- Colonne 5 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_inf),
                                               -1,
                                               "Password",
                                               renderer,
                                               "text", COL_PASSWORD,
                                               NULL);




  model = create_and_fill_model_infirmier (treeview_inf,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_inf), model);

  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_inf);
}

void affichageInfirmier (GtkWidget *treeview_inf, medec T[])
{
  treeview_inf = create_view_and_model_infirmier (treeview_inf,T);
}



/***************Aide_soignant********************/
//treeview_aide_soignant
static GtkTreeModel * create_and_fill_model_aide_soignant (GtkWidget *treeview_aide_soignant,medec T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="aide_soignant.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}


  store = gtk_list_store_new (COLUMNS_MEDECIN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_ID , T[i].id, COL_NOM, T[i].nom, COL_PRENOM, T[i].prenom, COL_USERNAME, T[i].username, COL_PASSWORD, T[i].password,-1);


  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_aide_soignant (GtkWidget *treeview_aide_soignant, medec T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_aide_soignant),
                                               -1,
                                               "Identifiant",
                                               renderer,
                                               "text", COL_ID,
                                               NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_aide_soignant),
                                               -1,
                                               "Nom",
                                               renderer,
                                               "text", COL_NOM,
                                               NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_aide_soignant),
                                               -1,
                                               "Prenom",
                                               renderer,
                                               "text", COL_PRENOM,
                                               NULL);

/* --- Colonne 4 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_aide_soignant),
                                               -1,
                                               "Username",
                                               renderer,
                                               "text", COL_USERNAME,
                                               NULL);

/* --- Colonne 5 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_aide_soignant),
                                               -1,
                                               "Password",
                                               renderer,
                                               "text", COL_PASSWORD,
                                               NULL);




  model = create_and_fill_model_aide_soignant (treeview_aide_soignant,T);
  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_aide_soignant), model);
  g_object_unref (model); /* destroy model automatically with view */

  return (treeview_aide_soignant);
}

void affichageAideSoignant (GtkWidget *treeview_aide_soignant, medec T[])
{
  treeview_aide_soignant = create_view_and_model_aide_soignant (treeview_aide_soignant,T);
}


/****************Technicien*********************/
//treeview_technicien

static GtkTreeModel * create_and_fill_model_technicien (GtkWidget *treeview_technicien,medec T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="technicien.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}


  store = gtk_list_store_new (COLUMNS_MEDECIN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_ID , T[i].id, COL_NOM, T[i].nom, COL_PRENOM, T[i].prenom, COL_USERNAME, T[i].username, COL_PASSWORD, T[i].password,-1);


  }

  return GTK_TREE_MODEL (store);

}

static GtkWidget * create_view_and_model_technicien (GtkWidget *treeview_technicien, medec T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_technicien),
                                               -1,
                                               "Identifiant",
                                               renderer,
                                               "text", COL_ID,
                                               NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_technicien),
                                               -1,
                                               "Nom",
                                               renderer,
                                               "text", COL_NOM,
                                               NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_technicien),
                                               -1,
                                               "Prenom",
                                               renderer,
                                               "text", COL_PRENOM,
                                               NULL);

/* --- Colonne 4 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_technicien),
                                               -1,
                                               "Username",
                                               renderer,
                                               "text", COL_USERNAME,
                                               NULL);

/* --- Colonne 5 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_technicien),
                                               -1,
                                               "Password",
                                               renderer,
                                               "text", COL_PASSWORD,
                                               NULL);




  model = create_and_fill_model_technicien (treeview_technicien,T);
  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_technicien), model);
  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_technicien);

}

void affichageTechnicien (GtkWidget *treeview_technicien, medec T[])
{
  treeview_technicien = create_view_and_model_technicien (treeview_technicien,T);
}





static GtkTreeModel * create_and_fill_model_pa (GtkWidget *treeview_pa,persag T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="personne_agee.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}


  store = gtk_list_store_new (COLUMNS_MEDECIN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_ID , T[i].nomp, COL_NOM, T[i].prenomp, COL_PRENOM, T[i].Daate.jour, COL_USERNAME, T[i].Daate.mois, COL_PASSWORD, T[i].Daate.anne,-1);


  }

  return GTK_TREE_MODEL (store);

}
static GtkWidget * create_view_and_model_pa (GtkWidget *treeview_pa, persag T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_pa),
                                               -1,
                                               "Nom",
                                               renderer,
                                               "text", COL_ID,
                                               NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_pa),
                                               -1,
                                               "Prénom",
                                               renderer,
                                               "text", COL_NOM,
                                               NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_pa),
                                               -1,
                                               "Jour",
                                               renderer,
                                               "text", COL_PRENOM,
                                               NULL);

/* --- Colonne 4 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_pa),
                                               -1,
                                               "Mois",
                                               renderer,
                                               "text", COL_USERNAME,
                                               NULL);

 /* --- Colonne 5 --- */

col = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_pa),
                                            -1,
                                            "Année",
                                            renderer,
                                            "text", COL_PASSWORD,
                                            NULL);



  model = create_and_fill_model_pa (treeview_pa,T);
  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_pa), model);
  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_pa);
}

void affichagepa (GtkWidget *treeview_pa, persag T[])
{
  treeview_pa = create_view_and_model_pa (treeview_pa,T);
}
