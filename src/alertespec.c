#include "alertespec.h"
#include "Alerte.h"


void lectureatec(FILE *f,alsp T[])
{

  char nomm[20]; char types[20]; char time[20];
  char s[20]; char nn[20];
  infop p1,p2,p3,p4,p5,p6,p7,p8,p9,p0;
  int i1=0; int i=0;
  remplirtableau(&p0,&p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9,&i1);
  remove("alertebracelet.txt");

  erreurtech(&p1,(i1-2));
  erreurtech(&p2,(i1-2));
  erreurtech(&p3,(i1-2));
  erreurtech(&p4,(i1-2));
  erreurtech(&p5,(i1-2));
  erreurtech(&p6,(i1-2));
  erreurtech(&p7,(i1-2));
  erreurtech(&p8,(i1-2));
  erreurtech(&p9,(i1-2));

  f=fopen("alertebracelet.txt","r");

  while (fscanf(f,"%s %s %s %s %s\n",nomm,types,time,s,nn) != EOF )
  {
    strcpy(T[i].np, nomm);
    strcpy(T[i].type, types);
    strcpy(T[i].temps, time);
    strcpy(T[i].temph, nn);
    i++;
  }
fclose(f);
}


static GtkTreeModel * create_and_fill_model_atec (GtkWidget *treeview, alsp T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[20]="alertebracelet.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (C_AS, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, C_PA , T[i].np, C_TYPE, T[i].type,C_DD, T[i].dd, C_TIME, T[i].temps, C_TH, T[i].temph,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_atec (GtkWidget *treeview, alsp T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"PA",renderer,"text", C_PA,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Type d'alerte",renderer,"text", C_TYPE,NULL);


  /* --- Colonne 3 --- */

    col = gtk_tree_view_column_new();
    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Date",renderer,"text", C_TIME,NULL);


  model = create_and_fill_model_atec (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}

void affichagealtec (GtkWidget *treeview, alsp T[])
{
  treeview= create_view_and_model_atec(treeview,T);
}



//Alerte medicale

void lectureamed(FILE *f,alsp T[])
{
  char nomm[20]; char types[20]; char time[20]; char hour[20]; char d[10];
  infop p1,p2,p3,p4,p5,p6,p7,p8,p9,p0; char pp[20];
  int i1=0; int i=0;
  remplirtableau(&p0,&p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9,&i1);
  remove("alertemedicale.txt");

  erreurmed(&p1,(i1-2));
  erreurmed(&p2,(i1-2));
  erreurmed(&p3,(i1-2));
  erreurmed(&p4,(i1-2));
  erreurmed(&p5,(i1-2));
  erreurmed(&p6,(i1-2));
  erreurmed(&p7,(i1-2));
  erreurmed(&p8,(i1-2));
  erreurmed(&p9,(i1-2));

  f=fopen("alertemedicale.txt","r");

  while (fscanf(f,"%s %s %s %s %s %s\n",(nomm),types,pp,time,d,hour) != EOF )
  {
    strcpy(T[i].np, nomm);
    //T[i].idl = nomm;
    strcpy(T[i].type, types);
    strcpy(T[i].temps, time);
    strcpy(T[i].dd, pp);
    strcpy(T[i].temph, hour);
    //strcat(T[i].temph," h");
    i++;
  }
fclose(f);

}

static GtkTreeModel * create_and_fill_model_amed (GtkWidget *treeview, alsp T[])
{
  GtkListStore  *store;
  GtkTreeIter    iter;
  int i,nbline=0;
  char c;
  char filename[20]="alertemedicale.txt";
  FILE *f;
  f=fopen(filename,"r");

				while((c=fgetc(f))!=EOF)
        				{
          				  if (c=='\n')
           					 nbline++;
        				}
  store = gtk_list_store_new (C_AS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a row and fill in some data */
  for(i=0;i<nbline;i++)
 {
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, C_PA , T[i].np, C_TYPE, T[i].type,C_DD, T[i].dd, C_TIME, T[i].temps, C_TH, T[i].temph,-1);
  }

  return GTK_TREE_MODEL (store);
}

static GtkWidget * create_view_and_model_amed (GtkWidget *treeview, alsp T[])
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkTreeModel        *model;

  /* --- Colonne 1 --- */

  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"PA",renderer,"text", C_PA,NULL);

  /* --- Colonne 2 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Type d'alerte",renderer,"text", C_TYPE,NULL);


  /* --- Colonne 3 --- */

    col = gtk_tree_view_column_new();
    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Problème",renderer,"text", C_DD,NULL);


/* --- Colonne 3 --- */

  col = gtk_tree_view_column_new();
  renderer = gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"Date",renderer,"text", C_TIME,NULL);

  /* --- Colonne 4 --- */

  /*  col = gtk_tree_view_column_new();
    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),-1,"heur",renderer,"text", C_TH,NULL);
*/


  model = create_and_fill_model_amed (treeview,T);

  gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), model);

  g_object_unref (model); /* destroy model automatically with view */

  return (treeview);
}
void affichageamed (GtkWidget *treeview, alsp T[])
{
  treeview= create_view_and_model_amed(treeview,T);
}
