#include "treeMateriel.h"


void lecture_mat(FILE *f, materiel T[])
{
  char iden[20]; char exp[20]; char msg[200];
  int i=0;
  f=fopen("materiel_technicien.txt","r");

    while (fscanf(f,"%s %s %s\n",iden,exp,msg) != EOF )
       {
         strcpy(T[i].nom_m, iden);
         strcpy(T[i].ref_m, exp);
         strcpy(T[i].quant_m, msg);

         i++;
       }
    fclose(f);
}

static GtkTreeModel * create_and_fill_model_mat (GtkWidget *treeview, materiel T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[30]="materiel_technicien.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (COL_TL, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_NM , T[i].nom_m, COL_REF, T[i].ref_m, COL_QUA, T[i].quant_m,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_mat (GtkWidget *treeview, materiel T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"NOM",renderer,"text", COL_NM,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Référence",renderer,"text", COL_REF,NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Quantité",renderer,"text", COL_QUA,NULL);



  model = create_and_fill_model_mat (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}

void affichagemat(GtkWidget *treeview, materiel T[])
{
    treeview = create_view_and_model_mat (treeview, T);
}


/*






*/


void lecture_matm(FILE *f, materiel T[])
{
  char iden[20]; char exp[20]; char msg[200];
  int i=0;
  f=fopen("materiel_médicale.txt","r");

    while (fscanf(f,"%s %s %s\n",iden,exp,msg) != EOF )
       {
         strcpy(T[i].nom_m, iden);
         strcpy(T[i].ref_m, exp);
         strcpy(T[i].quant_m, msg);

         i++;
       }
    fclose(f);
}

static GtkTreeModel * create_and_fill_model_matm (GtkWidget *treeview, materiel T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[30]="materiel_médicale.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (COL_TL, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_NM , T[i].nom_m, COL_REF, T[i].ref_m, COL_QUA, T[i].quant_m,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_matm (GtkWidget *treeview, materiel T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"NOM",renderer,"text", COL_NM,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Référence",renderer,"text", COL_REF,NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Quantité",renderer,"text", COL_QUA,NULL);



  model = create_and_fill_model_matm (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}

void affichagematm(GtkWidget *treeview, materiel T[])
{
    treeview = create_view_and_model_matm (treeview, T);
}
