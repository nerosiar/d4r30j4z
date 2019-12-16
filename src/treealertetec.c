#include "treealertetec.h"


void lecture_t(FILE *f, al_tec T[])
{ char exp[20]; char msg[200];
  int c=0; int d=0; int i=0;
  f=fopen("alertetec.txt","r");

    while (fscanf(f,"%s %[^\n]",exp,msg) != EOF )
       {
         strcpy(T[i].nom_p, exp);
        strcpy(T[i].text_r, msg);
         i++;
       }
    fclose(f);
}

static GtkTreeModel * create_and_fill_model_t (GtkWidget *treeview, al_tec T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[30]="alertetec.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (C_R, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, C_NP , T[i].nom_p, C_T, T[i].text_r,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_t (GtkWidget *treeview, al_tec T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Expéditeur",renderer,"text", C_NP,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Text",renderer,"text", C_T,NULL);


  model = create_and_fill_model_t (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}

void affichaget(GtkWidget *treeview, al_tec T[])
{
    treeview = create_view_and_model_t (treeview, T);
}
