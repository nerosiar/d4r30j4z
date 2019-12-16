#include"alertetree.h"



void lecture_a(FILE *f,ale T[])
{
  char iden[20]; char exp[20]; char msg[200];
  int i=0;
  f=fopen("alerte.txt","r");

    while (fscanf(f,"%s %s %s\n]",iden,exp,msg) != EOF )
       {
         strcpy(T[i].id, iden);
         strcpy(T[i].exped, exp);
         strcpy(T[i].mes, msg);

         i++;
       }
    fclose(f);
}

static GtkTreeModel * create_and_fill_model_alerte (GtkWidget *treeview, ale T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[20]="alerte.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (COL_AL, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, COL_IDE , T[i].id, COL_EXP, T[i].exped, COL_MSG, T[i].mes,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_alerte (GtkWidget *treeview, ale T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"ID",renderer,"text", COL_IDE,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Expéditeur",renderer,"text", COL_EXP,NULL);

/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Message d'alerte",renderer,"text", COL_MSG,NULL);



  model = create_and_fill_model_alerte (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}

void affichageAlerte(GtkWidget *treeview, ale T[])
{
    treeview = create_view_and_model_alerte (treeview,T);
}
