#include "treeview1.h"


static GtkTreeModel * create_and_fill_model_camera (GtkWidget *treeview_cam,came T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="cameras.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (COLUMNS_CAMERA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_Id , T[i].id, COL_EMP, T[i].info, COL_INFO, T[i].emplacement,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_camera (GtkWidget *treeview_cam, came T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_cam),-1,"Identifiant",renderer,"text", COL_Id,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_cam),-1,"Info",renderer,"text", COL_INFO,NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_cam),-1,"Emplacement",renderer,"text", COL_EMP,NULL);



  model = create_and_fill_model_camera (treeview_cam,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_cam), model);

  g_object_unref (model); /* destroy model automatically with view */



  return (treeview_cam);
}

void affichagecamera (GtkWidget *treeview_cam, came T[])
{
  treeview_cam = create_view_and_model_camera (treeview_cam,T);
}



/**************Bracelet*********************/


static GtkTreeModel * create_and_fill_model_bracelet (GtkWidget *treeview_bra, brac T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[sz]="bracelets.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (COLUMNS_CAMERA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_Id , T[i].id, COL_EMP, T[i].info, COL_INFO, T[i].emplacement,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_bracelet (GtkWidget *treeview_bra, brac T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_bra),-1,"Identifiant",renderer,"text", COL_Id,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_bra),-1,"Info",renderer,"text", COL_INFO,NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview_bra),-1,"Emplacement",renderer,"text", COL_EMP,NULL);



  model = create_and_fill_model_bracelet (treeview_bra,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview_bra), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview_bra);
}

void affichagebracelet (GtkWidget *treeview_bra, brac T[])
{
  treeview_bra = create_view_and_model_bracelet (treeview_bra,T);
}
