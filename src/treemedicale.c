#include "treemedicale.h"

void lecturei(FILE *f, cel T[])
{
  char iden[20]; char exp[20]; char msg[1000];
  int i=0;
  f=fopen("alertemed.txt","r");

    while (fscanf(f,"%s %[^\n]",iden,msg) != EOF )
       {
        //if (strcmp(iden,"medecin")==0)
         //{
           strcpy(T[i].mss, msg);
         //}
         i++;
       }
    fclose(f);
}

static GtkTreeModel * create_and_fill_model_i (GtkWidget *treeview, cel T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[20]="alertemed.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (C_A, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, C_MS , T[i].mss,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_i (GtkWidget *treeview, cel T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Message",renderer,"text", C_MS,NULL);

  model = create_and_fill_model_i (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);

}
void affichagei (GtkWidget *treeview, cel T[])
{
  treeview = create_view_and_model_i (treeview,T);
}


void lecturea(FILE *f, cel T[])
{
  char iden[20]; char exp[20]; char msg[1000];
  int i=0;
  f=fopen("alertemed.txt","r");

    while (fscanf(f,"%s %[^\n]",iden,msg) != EOF )
       {
      //  if (strcmp(iden,"aidesoignant")==0)
        // {
           strcpy(T[i].mss, msg);
         //}
         i++;
       }
    fclose(f);
}
static GtkTreeModel * create_and_fill_model_a (GtkWidget *treeview, cel T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[20]="alertemed.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (C_A, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, C_MS , T[i].mss,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_a (GtkWidget *treeview, cel T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Message",renderer,"text", C_MS,NULL);

  model = create_and_fill_model_a (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}
void affichagea (GtkWidget *treeview, cel T[])
{
  treeview = create_view_and_model_a (treeview,T);
}
