#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Login.h"
#include "personnel.h"
#include "controle_saisie.h"
#include "treeView.h"
#include "treeview1.h"
#include "alertetree.h"
#include "add_materiel_data.h"
#include "alertespec.h"
#include "treeMateriel.h"
#include "treealertetec.h"
#include "sms.h"
#include "treemedicale.h"

/********************************Authetification*******************************/
void on_connecter_login_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *output;

  GtkWidget *Admin_window;
  GtkWidget *login_window;

  char user[20]; char pwd[20];
  int role =0; char nom[30];

  input1= lookup_widget(objet_graphique, "entry1");
  input2= lookup_widget(objet_graphique, "entry2");
  output= lookup_widget(objet_graphique, "label3");

  strcpy(user, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(pwd,  gtk_entry_get_text(GTK_ENTRY(input2)));

  role=  verifierlogin(user,pwd);

  switch (role)
    {
      case 0: //Erreur
              gtk_label_set_text(GTK_LABEL(output), "Erreur d'authetification");
        break;
      case 1: //Admin_window
              {
                gtk_label_set_text(GTK_LABEL(output), "vous venez de vous connecter en tant qu'administrateur");
                login_window=lookup_widget(objet_graphique,"login_window");
                gtk_widget_hide(login_window);
              }
        break;
      case 2: //Medecin window
            gtk_label_set_text(GTK_LABEL(output), "Medecin");
            login_window=lookup_widget(objet_graphique,"login_window");
            gtk_widget_hide(login_window);

            strcpy(nom,user);
            sms();


        break;
      case 3: //Infirmier_window
            gtk_label_set_text(GTK_LABEL(output), "Infirmier");
            login_window=lookup_widget(objet_graphique,"login_window");
            gtk_widget_hide(login_window);

            strcpy(nom,user);
            mailpointage(nom);

        break;
      case 4: //Technicien_window
            gtk_label_set_text(GTK_LABEL(output), "Technicien");
            login_window=lookup_widget(objet_graphique,"login_window");
            gtk_widget_hide(login_window);

            strcpy(nom,user);
            mailpointage(nom);
        break;
      case 5: //Aide_soignat_window
            gtk_label_set_text(GTK_LABEL(output), "Aide-soignant");
            login_window=lookup_widget(objet_graphique,"login_window");
            gtk_widget_hide(login_window);

            strcpy(nom,user);
            mailpointage(nom);
        break;
    }
}

/********************************Quitter*******************************/
void on_quitter_login_button_clicked(GtkWidget *objet_graphique,  gpointer user_data)
{
  gtk_main_quit();
}

void on_Admin_window_show (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *treeview_med,*treeview_technicien, *treeview_inf, *treeview_pa, *treeview_aide_soignant;
  GtkWidget *treeview_cam, *treeview_brac; GtkWidget *treeviewal; GtkWidget *treeview_materiel;
  GtkWidget *treeview_tec;
    FILE *f; FILE *h; FILE *b; FILE *te;
    medec T[200];
    persag M[200];
    came cam[200];
    brac bra[200];
    alsp A[200];
    materiel MA[200];
    al_tec TAB[200];


      treeview_med = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_med");
      treeview_technicien = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_technicien");
      treeview_inf = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_inf");
      treeview_aide_soignant = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_aide_soignant");
      treeview_pa = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_pa");
      treeview_cam = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_camera");
      treeview_brac = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_bracelet");
      treeviewal = lookup_widget (GTK_WIDGET(objet_graphique),"treeview11");
      treeview_materiel = lookup_widget (GTK_WIDGET(objet_graphique),"treeview13");
      treeview_tec = lookup_widget (GTK_WIDGET(objet_graphique),"treeview21");

      lecture_medecin(f,T);
      affichageMedecin (treeview_med ,T);

      lecture_infirmier(f,T);
      affichageInfirmier (treeview_inf, T);

      lecture_aide_soignant(f,T);
      affichageAideSoignant (treeview_aide_soignant ,T);

      lecture_technicien(f,T);
      affichageTechnicien (treeview_technicien ,T);

      lecture_pa(f,M);
      affichagepa (treeview_pa, M);

      lecture_camera(f,cam);
      affichagecamera(treeview_cam, cam);

      lecture_bracelet(f,bra);
      affichagebracelet(treeview_brac, bra);

      // Alerte technique
      lectureatec(h,A);
      affichagealtec (treeviewal,A);

      lecture_mat(b,MA);
      affichagemat(treeview_materiel, MA);

      lecture_t(te,TAB);
      affichaget (treeview_tec, TAB);

}

void on_ajouter_nouveau_med_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_med;
  GtkWidget *Admin_window;

  ajouter_nouveau_med = create_ajouter_medecin_window ();
  gtk_widget_show (ajouter_nouveau_med);
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);
}

void on_refresh_medecin_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *Admin_window;
    Admin_window=lookup_widget(objet_graphique,"Admin_window");
    gtk_widget_hide(Admin_window);

    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
}

void on_search_med_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_window;
  edit_window=create_edit_window();
  gtk_widget_show (edit_window);
}

void on_refresh_infirmier_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *Admin_window;
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
}

void on_search_infimier_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_window;
  edit_window=create_edit_infirmier_window();
  gtk_widget_show (edit_window);
}

void on_ajouter_nouveau_inf_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_inf;
  GtkWidget *Admin_window;

  ajouter_nouveau_inf = create_ajouter_infirmier_window ();
  gtk_widget_show (ajouter_nouveau_inf);
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);
}

void on_refresh_aide_soignant_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *Admin_window;
    Admin_window=lookup_widget(objet_graphique,"Admin_window");
    gtk_widget_hide(Admin_window);

    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
}

void on_search_aide_soignant_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_window;
  edit_window=create_edit_as_window();
  gtk_widget_show (edit_window);
}

void on_ajouter_nouveau_as_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_as;
  GtkWidget *Admin_window;

  ajouter_nouveau_as = create_ajouter_aide_soignant_window ();
  gtk_widget_show (ajouter_nouveau_as);
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);
}

void on_search_technicien_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_window;
  edit_window=create_edit_technicien_window();
  gtk_widget_show (edit_window);
}

void on_refresh_technicien_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *Admin_window;
    Admin_window=lookup_widget(objet_graphique,"Admin_window");
    gtk_widget_hide(Admin_window);

    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
}

void on_ajouter_nouveau_tech_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_tech;
  GtkWidget *Admin_window;

  ajouter_nouveau_tech = create_ajouter_technicien_window ();
  gtk_widget_show (ajouter_nouveau_tech);
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);
}

void on_treeview1_show (GtkWidget *objet_graphique,  gpointer user_data){



 }

void on_quit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *login_window;
  GtkWidget *Admin_window;

  login_window = create_login_window ();
  gtk_widget_show (login_window);
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);
}

void on_ajouter_infirmier_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input8;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *input11;
  GtkWidget *output;

  char name1[20]; char last1[20];
  char jour1[10]; char mois1[30]; char annee1[5];
  char email_nom_domaine[30]; char email_ent[30];
  char email1[30];
  char adress1[300];
  char numero1[10];
  char username1[20]; char password1[20];

  input1 = lookup_widget(objet_graphique, "nom_infirmier");
  input2 = lookup_widget(objet_graphique, "prenom_infirmier");
  input3 = lookup_widget(objet_graphique, "jour_infirmier"); //Combobox
  input4 = lookup_widget(objet_graphique, "mois_infirmier"); // combobox
  input5 = lookup_widget(objet_graphique, "annee_infirmier"); //entry
  input6 = lookup_widget(objet_graphique, "email_infirmier"); //entry2
  input7 = lookup_widget(objet_graphique, "mail_infirmier_combobox");//combobox
  input8 = lookup_widget(objet_graphique, "username_infirmier");
  input9 = lookup_widget(objet_graphique, "password_infirmier");
  input10 = lookup_widget(objet_graphique, "numero_infirmier");
  input11 = lookup_widget(objet_graphique, "adresse_infirmier");

  output= lookup_widget(objet_graphique, "label_verif_infirmier_info");

  strcpy(last1, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(name1, gtk_entry_get_text(GTK_ENTRY(input2)));
  int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(mois1, "%.2d", active_mois);
  strcpy(annee1, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(email_ent, gtk_entry_get_text(GTK_ENTRY(input6)));
  int nom_domaine =gtk_combo_box_get_active(GTK_COMBO_BOX(input7));
  //strcpy(email_nom_domaine, gtk_combo_box_get_active(GTK_COMBO_BOX(input7)));
  switch (nom_domaine)
  {
  case 0: strcpy(email_nom_domaine,"@gmail.com");
  break;
  case 1: strcpy(email_nom_domaine,"@yahoo.com");
  break;
  case 2: strcpy(email_nom_domaine,"@icloud.com");
  break;
  case 3: strcpy(email_nom_domaine,"@outlook.com");
  break;
  case 4: strcpy(email_nom_domaine,"@hotmail.com");
  break;
  case 5: strcpy(email_nom_domaine,"@esprit.tn");
  break;
  default : strcpy(email_nom_domaine,"@esprit.tn");
  }



  /*
  0-gmail.Com
  1-yahoo.Com
  2-icloud.Com
  3-outlook.Com
  4-hotmail.Com
  5-esprit.tn

  */
  /***Récupération de l'adresse mail***/
  strcpy(email1,email_ent);
  strcat(email1,email_nom_domaine);

  strcpy(username1, gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(password1, gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(numero1,  gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(adress1,  gtk_entry_get_text(GTK_ENTRY(input11)));


  if (verifierexistant(username1)== 0)
  {
      gtk_label_set_text(GTK_LABEL(output), "Nom d'utilsateur déjà utilisé !");
  }

  else
  {
    //char id[5] = "1151";
    infirmier inf;
if ((controle_saisie_numero(numero1)==0)||(controle_saisie_annee(annee1)==0))
{
  gtk_label_set_text(GTK_LABEL(output), "veuillez verifier vos données !");
}
else{
    int nouveau_id = auto_incre_id_inf();
    char n_id[sz];
    sprintf(n_id,"%d",nouveau_id);
    gtk_label_set_text(GTK_LABEL(output), n_id);
    //strcpy(n_id,inf.id);*/
    strcpy(inf.id,n_id);
    strcpy(inf.nom,name1);
    strcpy(inf.prenom,last1);
    strcpy(inf.username,username1);
    strcpy(inf.password,password1);
    strcpy(inf.email,email1);
    strcpy(inf.num,numero1);
    strcpy(inf.adresse.ville,adress1);
    strcpy(inf.adresse.rue,"Tunisia");
    strcpy(inf.Date.jour,jour1);
    strcpy(inf.Date.mois,mois1);
    strcpy(inf.Date.anne,annee1);
    ajouter_i(inf);
    gtk_label_set_text(GTK_LABEL(output),"infirmier ajouté avec succès");
    GtkWidget *ajouter_nouveau_inf;
    GtkWidget *Admin_window;

    GtkWidget *conf_window;
    mailtonew(email1);
    conf_window = create_ajout_succes_window ();
    gtk_widget_show (conf_window);
    ajouter_nouveau_inf=lookup_widget(objet_graphique,"ajouter_infirmier_window");
    gtk_widget_hide(ajouter_nouveau_inf);
    //gtk_label_set_text(GTK_LABEL(output), "infirmier ajouté avec succés");
  }
}
}

void on_annuler_infirmier_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_inf;
  GtkWidget *Admin_window;

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
  ajouter_nouveau_inf=lookup_widget(objet_graphique,"ajouter_infirmier_window");
  gtk_widget_hide(ajouter_nouveau_inf);
}

void on_ajouter_technicien_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input8;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *input11;
  GtkWidget *output;

  char name1[20]; char last1[20];
  char jour1[10]; char mois1[30]; char annee1[5];
  char email_nom_domaine[30]; char email_ent[30];
  char email1[30];
  char adress1[300];
  char numero1[10];
  char username1[20]; char password1[20];

  input1 = lookup_widget(objet_graphique, "nom_tech");
  input2 = lookup_widget(objet_graphique, "prenom_tech");
  input3 = lookup_widget(objet_graphique, "jour_tech"); //Combobox
  input4 = lookup_widget(objet_graphique, "mois_tech"); // combobox
  input5 = lookup_widget(objet_graphique, "annee_tech"); //entry
  input6 = lookup_widget(objet_graphique, "email_tech"); //entry2
  input7 = lookup_widget(objet_graphique, "mail_tech_combobox");//combobox
  input8 = lookup_widget(objet_graphique, "username_tech");
  input9 = lookup_widget(objet_graphique, "password_tech");
  input10 = lookup_widget(objet_graphique, "numero_tech");
  input11 = lookup_widget(objet_graphique, "adresse_tech");

  output= lookup_widget(objet_graphique, "label_verif_tec");

  strcpy(last1, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(name1, gtk_entry_get_text(GTK_ENTRY(input2)));
  int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(mois1, "%.2d", active_mois);
  strcpy(annee1, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(email_ent, gtk_entry_get_text(GTK_ENTRY(input6)));
  int nom_domaine =gtk_combo_box_get_active(GTK_COMBO_BOX(input7));
  //strcpy(email_nom_domaine, gtk_combo_box_get_active(GTK_COMBO_BOX(input7)));
  switch (nom_domaine)
  {
  case 0: strcpy(email_nom_domaine,"@gmail.com");
  break;
  case 1: strcpy(email_nom_domaine,"@yahoo.com");
  break;
  case 2: strcpy(email_nom_domaine,"@icloud.com");
  break;
  case 3: strcpy(email_nom_domaine,"@outlook.com");
  break;
  case 4: strcpy(email_nom_domaine,"@hotmail.com");
  break;
  case 5: strcpy(email_nom_domaine,"@esprit.tn");
  break;
  default : strcpy(email_nom_domaine,"@esprit.tn");
  }



  /*
  0-gmail.Com
  1-yahoo.Com
  2-icloud.Com
  3-outlook.Com
  4-hotmail.Com
  5-esprit.tn

  */
  /***Récupération de l'adresse mail***/
  strcpy(email1,email_ent);
  strcat(email1,email_nom_domaine);

  strcpy(username1, gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(password1, gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(numero1,  gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(adress1,  gtk_entry_get_text(GTK_ENTRY(input11)));


  if (verifierexistant(username1)== 0)
  {
      gtk_label_set_text(GTK_LABEL(output), "Nom d'utilsateur déjà utilisé !");
  }

  else
  {
    //char id[5] = "1151";
    technicien tec;
    if ((controle_saisie_numero(numero1)==0)||(controle_saisie_annee(annee1)==0))
    {
      gtk_label_set_text(GTK_LABEL(output), "veuillez verifier vos données !");
    }
    else {
    int nouveau_id = auto_incre_id_tec();
    char n_id[sz];
    sprintf(n_id,"%d",nouveau_id);
    gtk_label_set_text(GTK_LABEL(output), n_id);
    //strcpy(n_id,tec.id);*/
    strcpy(tec.id,n_id);
    strcpy(tec.nom,name1);
    strcpy(tec.prenom,last1);
    strcpy(tec.username,username1);
    strcpy(tec.password,password1);
    strcpy(tec.email,email1);
    strcpy(tec.num,numero1);
    strcpy(tec.adresse.ville,adress1);
    strcpy(tec.adresse.rue,"Tunisia");
    strcpy(tec.Date.jour,jour1);
    strcpy(tec.Date.mois,mois1);
    strcpy(tec.Date.anne,annee1);
    ajouter_tec(tec);
    gtk_label_set_text(GTK_LABEL(output),"technicien ajouté avec succès");
    GtkWidget *ajouter_nouveau_tec;
    GtkWidget *Admin_window;

    GtkWidget *conf_window;
    mailtonew(email1);
    conf_window = create_ajout_succes_window ();
    gtk_widget_show (conf_window);
    ajouter_nouveau_tec=lookup_widget(objet_graphique,"ajouter_technicien_window");
    gtk_widget_hide(ajouter_nouveau_tec);
    //gtk_label_set_text(GTK_LABEL(output), "technicien ajouté avec succés");
  }}
}

void on_annuler_technicien_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_tech;
  GtkWidget *Admin_window;

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
  ajouter_nouveau_tech=lookup_widget(objet_graphique,"ajouter_technicien_window");
  gtk_widget_hide(ajouter_nouveau_tech);
}

void on_ajouter_as_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input8;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *input11;
  GtkWidget *output;

  char name1[20]; char last1[20];
  char jour1[10]; char mois1[30]; char annee1[5];
  char email_nom_domaine[30]; char email_ent[30];
  char email1[30];
  char adress1[300];
  char numero1[10];
  char username1[20]; char password1[20];

  input1 = lookup_widget(objet_graphique, "nom_as");
  input2 = lookup_widget(objet_graphique, "prenom_as");
  input3 = lookup_widget(objet_graphique, "jour_as"); //Combobox
  input4 = lookup_widget(objet_graphique, "mois_as"); // combobox
  input5 = lookup_widget(objet_graphique, "annee_as"); //entry
  input6 = lookup_widget(objet_graphique, "email_as"); //entry2
  input7 = lookup_widget(objet_graphique, "mail_as_combobox");//combobox
  input8 = lookup_widget(objet_graphique, "username_as");
  input9 = lookup_widget(objet_graphique, "password_as");
  input10 = lookup_widget(objet_graphique, "numero_as");
  input11 = lookup_widget(objet_graphique, "adresse_as");

  output= lookup_widget(objet_graphique, "label_verif_as");

  strcpy(last1, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(name1, gtk_entry_get_text(GTK_ENTRY(input2)));
  int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(mois1, "%.2d", active_mois);
  strcpy(annee1, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(email_ent, gtk_entry_get_text(GTK_ENTRY(input6)));
  int nom_domaine =gtk_combo_box_get_active(GTK_COMBO_BOX(input7));
  //strcpy(email_nom_domaine, gtk_combo_box_get_active(GTK_COMBO_BOX(input7)));
  switch (nom_domaine)
  {
  case 0: strcpy(email_nom_domaine,"@gmail.com");
  break;
  case 1: strcpy(email_nom_domaine,"@yahoo.com");
  break;
  case 2: strcpy(email_nom_domaine,"@icloud.com");
  break;
  case 3: strcpy(email_nom_domaine,"@outlook.com");
  break;
  case 4: strcpy(email_nom_domaine,"@hotmail.com");
  break;
  case 5: strcpy(email_nom_domaine,"@esprit.tn");
  break;
  default : strcpy(email_nom_domaine,"@esprit.tn");
  }



  /*
  0-gmail.Com
  1-yahoo.Com
  2-icloud.Com
  3-outlook.Com
  4-hotmail.Com
  5-esprit.tn

  */
  /***Récupération de l'adresse mail***/
  strcpy(email1,email_ent);
  strcat(email1,email_nom_domaine);

  strcpy(username1, gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(password1, gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(numero1,  gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(adress1,  gtk_entry_get_text(GTK_ENTRY(input11)));


  if (verifierexistant(username1)== 0)
  {
      gtk_label_set_text(GTK_LABEL(output), "Nom d'utilsateur déjà utilisé !");
  }

  else
  {
    if ((controle_saisie_numero(numero1)==0)||(controle_saisie_annee(annee1)==0))
    {
      gtk_label_set_text(GTK_LABEL(output), "veuillez verifier vos données !");
    }
    //char id[5] = "1151";
    else{
    aide_soignant as;

    int nouveau_id = auto_incre_id();
    char n_id[sz];
    sprintf(n_id,"%d",nouveau_id);
    gtk_label_set_text(GTK_LABEL(output), n_id);
    //strcpy(n_id,as.id);*/
    strcpy(as.id,n_id);
    strcpy(as.nom,name1);
    strcpy(as.prenom,last1);
    strcpy(as.username,username1);
    strcpy(as.password,password1);
    strcpy(as.email,email1);
    strcpy(as.num,numero1);
    strcpy(as.adresse.ville,adress1);
    strcpy(as.adresse.rue,"Tunisia");
    strcpy(as.Date.jour,jour1);
    strcpy(as.Date.mois,mois1);
    strcpy(as.Date.anne,annee1);
    ajouter_as(as);
    gtk_label_set_text(GTK_LABEL(output),"aide_soignant ajouté avec succès");
    GtkWidget *ajouter_nouveau_as;
    GtkWidget *Admin_window;
    mailtonew(email1);
    GtkWidget *conf_window;

    conf_window = create_ajout_succes_window ();
    gtk_widget_show (conf_window);
    ajouter_nouveau_as=lookup_widget(objet_graphique,"ajouter_aide_soignant_window");
    gtk_widget_hide(ajouter_nouveau_as);

  }
}
}

void on_annuler_as_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_as;
  GtkWidget *Admin_window;

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
  ajouter_nouveau_as=lookup_widget(objet_graphique,"ajouter_aide_soignant_window");
  gtk_widget_hide(ajouter_nouveau_as);
}

void on_button_trouver_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
    GtkWidget *input;
    GtkWidget *output;
    GtkWidget *nom_entry;
    GtkWidget *prenom_entry;
    GtkWidget *username_entry;
    GtkWidget *password_entry;
    GtkWidget *ville_entry;
    GtkWidget *adresse_rue;
    GtkWidget *jour_combo;
    GtkWidget *mois_combo;
    GtkWidget *annee_entry;

    medecin med;
    input = lookup_widget(objet_graphique, "id_search");
    output= lookup_widget(objet_graphique, "label_not_found");

    nom_entry = lookup_widget(objet_graphique,"nom_input");
    prenom_entry = lookup_widget(objet_graphique,"prenom_input");
    username_entry = lookup_widget(objet_graphique,"username_input");
    password_entry = lookup_widget(objet_graphique,"password_input");
    annee_entry=lookup_widget(objet_graphique,"edit_annee_entry");
    ville_entry = lookup_widget(objet_graphique,"numero_input");
    adresse_rue = lookup_widget(objet_graphique,"adresse_rue");
    jour_combo = lookup_widget(objet_graphique, "edit_jour_combobox");
    mois_combo = lookup_widget(objet_graphique, "edit_mois_combobox");

    char id[10];

    strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
    med = chercher (id);
    if (strcmp(med.id , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "Aucun medecin n'est inscrit avec cet identifiant, veuillez réessayer");
    }
    else {
        gtk_label_set_text(GTK_LABEL(output), "Id existant");

        gtk_entry_set_text(GTK_ENTRY(nom_entry), med.username);
        gtk_entry_set_text(GTK_ENTRY(prenom_entry), med.password);
        gtk_entry_set_text(GTK_ENTRY(username_entry), med.nom);
        gtk_entry_set_text(GTK_ENTRY(password_entry), med.prenom);
        gtk_entry_set_text(GTK_ENTRY(annee_entry), med.Date.anne);
        gtk_entry_set_text(GTK_ENTRY(ville_entry), med.num);
        gtk_entry_set_text(GTK_ENTRY(adresse_rue), med.adresse.rue);
        gtk_combo_box_set_active(GTK_COMBO_BOX(jour_combo),(atoi(med.Date.jour)-1));
        gtk_combo_box_set_active(GTK_COMBO_BOX(mois_combo),(atoi(med.Date.mois)-1));
    }

}

void on_supprimer_id_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output2;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  medecin med;
  input = lookup_widget(objet_graphique, "id_search");
  output2= lookup_widget(objet_graphique, "label_not_found");

  nom_entry = lookup_widget(objet_graphique,"nom_input");
  prenom_entry = lookup_widget(objet_graphique,"prenom_input");
  username_entry = lookup_widget(objet_graphique,"username_input");
  password_entry = lookup_widget(objet_graphique,"password_input");
  annee_entry=lookup_widget(objet_graphique,"edit_annee_entry");
  ville_entry = lookup_widget(objet_graphique,"numero_input");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue");
  jour_combo = lookup_widget(objet_graphique, "edit_jour_combobox");
  mois_combo = lookup_widget(objet_graphique, "edit_mois_combobox");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  med = chercher (id);
  if (strcmp(med.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output2), "Nothing to be deleted");
  }
  else
  {
    strcpy(med.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(med.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(med.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(med.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(med.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(med.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(med.Date.jour,jour1);
    strcpy(med.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output2), "Champs supprimer avec succès");
    supprimer(med.id);

    gtk_entry_set_text(GTK_ENTRY(username_entry), "");
    gtk_entry_set_text(GTK_ENTRY(password_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(ville_entry), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");
    gtk_entry_set_text(GTK_ENTRY(annee_entry), "");

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }
}

void on_edit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output2;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  medecin med;
  input = lookup_widget(objet_graphique, "id_search");
  output2= lookup_widget(objet_graphique, "label164");

  nom_entry = lookup_widget(objet_graphique,"nom_input");
  prenom_entry = lookup_widget(objet_graphique,"prenom_input");
  username_entry = lookup_widget(objet_graphique,"username_input");
  password_entry = lookup_widget(objet_graphique,"password_input");
  annee_entry=lookup_widget(objet_graphique,"edit_annee_entry");
  ville_entry = lookup_widget(objet_graphique,"numero_input");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue");
  jour_combo = lookup_widget(objet_graphique, "edit_jour_combobox");
  mois_combo = lookup_widget(objet_graphique, "edit_mois_combobox");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  med = chercher (id);
  if (strcmp(med.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output2), "Nothing to be updated");
  }
  else
  {

    strcpy(med.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(med.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(med.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(med.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(med.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(med.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(med.Date.jour,jour1);
    strcpy(med.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output2), "Champs modifier avec succès");
    modifier(med);

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */

  }

}

void on_add_camera_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
 GtkWidget *input1;
 GtkWidget *input2;

 input1 = lookup_widget(objet_graphique, "ref_cam_box");
 input2 = lookup_widget(objet_graphique, "emp_camera_entry");

 char cam1[20];
 char cam2[20];
 Camera camera;


 int active_cam=gtk_combo_box_get_active(GTK_COMBO_BOX(input1)) + 1;
 switch (active_cam)
 {
   case 1: strcpy(cam1,"HIKVISION");
   break;
   case 2: strcpy(cam1,"D-Link");
   break;
   case 3: strcpy(cam1,"FUSDON");
   break;
   default : strcpy(cam1,"FUSDON");

 }
 strcpy(cam2,gtk_entry_get_text(GTK_ENTRY(input2)));
 int id = auto_incre_id_camera();
 char id_c[10];
 sprintf(id_c,"%d",id);

 strcpy(camera.identifiant_camera,id_c);
 strcpy(camera.info,cam1);
 strcpy(camera.emplacement,cam2);
 ajout_camera(camera);

 GtkWidget *ferme;
 ferme=lookup_widget(objet_graphique,"ajout_camera");
 gtk_widget_hide(ferme);
}



void on_search_cam_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *cam;
  cam=  create_edit_camera_window();
  gtk_widget_show(cam);
}
/***********supprime btra*****/
void on_button38_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *text;
  GtkWidget *combo;

  input1= lookup_widget(objet_graphique,"id_cam_search_entry");
  text = lookup_widget(objet_graphique,"edit_emp_cam_entry");
  combo =lookup_widget(objet_graphique,"edit_ref_cam_box");
  output= lookup_widget(objet_graphique,"label329");

  Camera camera;
  //camera = chercher_camera(gtk_entry_get_text(GTK_ENTRY(input1)));
  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  camera = chercher_camera(id);

  if (strcmp(camera.identifiant_camera , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "ID n'existe pas");

    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "ID existant");

    gtk_entry_set_text(GTK_ENTRY(text),camera.emplacement);
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),(atoi(camera.info)+1));
  }


  gtk_label_set_text(GTK_LABEL(output), "Champs supprimer avec succès");
  supprimer_camera(id);


}

/**********edit etat *********/
void on_button37_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *text;
  GtkWidget *combo;

  input1= lookup_widget(objet_graphique,"id_cam_search_entry");
  text = lookup_widget(objet_graphique,"edit_emp_cam_entry");
  combo =lookup_widget(objet_graphique,"edit_ref_cam_box");
  output= lookup_widget(objet_graphique,"label329");

  Camera camera;
  //camera = chercher_camera(gtk_entry_get_text(GTK_ENTRY(input1)));
/*  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  camera = chercher_camera(id);

  if (strcmp(camera.identifiant_camera , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "ID n'existe pas");

    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "ID existant");

    gtk_entry_set_text(GTK_ENTRY(text),camera.emplacement);
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),(atoi(camera.info)+1));
  }*/

  char ref1[10];
  char emp1[30];

  int active_ref=gtk_combo_box_get_active(GTK_COMBO_BOX(combo)) + 1;

  switch (active_ref)
    {
      case 1: strcpy(ref1,"HIKVISION");
      break;
      case 2: strcpy(ref1,"D-Link");
      break;
      case 3: strcpy(ref1,"FUSDON");
      break;
      default : strcpy(ref1,"FUSDON");
    }

  strcpy(emp1,gtk_entry_get_text(GTK_ENTRY(text)));
  strcpy(camera.info,ref1);
  strcpy(camera.emplacement,emp1);


  gtk_label_set_text(GTK_LABEL(output), "Champs modifier avec succès");
  modifier_camera(camera);

}

void on_find_bracelet_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *text;
  GtkWidget *combo;

  input1= lookup_widget(objet_graphique,"id_bra_search_entry");
  text = lookup_widget(objet_graphique,"edit_ref_bra_box");
  combo =lookup_widget(objet_graphique,"edit_etat_bra_box");
  output= lookup_widget(objet_graphique,"label330");

  Bracelet bracelet;
  //camera = chercher_camera(gtk_entry_get_text(GTK_ENTRY(input1)));
  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  bracelet = chercher_bracelet(id);

  if (strcmp(bracelet.identifiant_bracelet , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "Id n'existe pas");

    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "Id existant");

    gtk_combo_box_set_active(GTK_COMBO_BOX(text),(atoi(bracelet.info)+1));
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),(atoi(bracelet.etat)+1));
  }

}

void on_button42_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *text;
  GtkWidget *combo;

  input1= lookup_widget(objet_graphique,"id_bra_search_entry");
  text = lookup_widget(objet_graphique,"edit_ref_bra_box");
  combo =lookup_widget(objet_graphique,"edit_etat_bra_box");
  output= lookup_widget(objet_graphique,"label330");

  Bracelet bracelet;
  //camera = chercher_camera(gtk_entry_get_text(GTK_ENTRY(input1)));
  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  bracelet = chercher_bracelet(id);

  if (strcmp(bracelet.identifiant_bracelet , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "Id n'existe pas");

    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "Id existant");

    gtk_combo_box_set_active(GTK_COMBO_BOX(text),(atoi(bracelet.info)));
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),(atoi(bracelet.etat)));
  }


  char info1[10];
  char etat1[30];
  int active_inf=gtk_combo_box_get_active(GTK_COMBO_BOX(text)) + 1;
  //sprintf(info1,"%d",active_inf);
  int active_et=gtk_combo_box_get_active(GTK_COMBO_BOX(combo)) + 1;
  //sprintf(etat1, "%d", active_et);

  switch (active_inf)
  {
    case 1: strcpy(info1,"Excelvan");
    break;
    case 2: strcpy(info1,"Paradox");
    break;
    case 3: strcpy(info1,"Diagral");
    break;
    case 4: strcpy(info1,"Eden");
    break;
    default : strcpy(info1,"Eden");
  }

  switch (active_et)
  {
    case 1: strcpy(etat1,"non_fonctionnel");
    break;
    case 2: strcpy(etat1,"fonctionnel");
    break;
    default : strcpy(etat1,"fonctionnel");

  }

  strcpy(bracelet.info,info1);
  strcpy(bracelet.etat,etat1);


  gtk_label_set_text(GTK_LABEL(output), "Champs modifier avec succès");
  modifier_bracelet(bracelet);
}

void on_supprimer_bracelet_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *text;
  GtkWidget *combo;

  input1= lookup_widget(objet_graphique,"id_bra_search_entry");
  text = lookup_widget(objet_graphique,"edit_ref_bra_box");
  combo =lookup_widget(objet_graphique,"edit_etat_bra_box");
  output= lookup_widget(objet_graphique,"label330");

  Bracelet bracelet;
  //camera = chercher_camera(gtk_entry_get_text(GTK_ENTRY(input1)));
  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  bracelet = chercher_bracelet(id);

  if (strcmp(bracelet.identifiant_bracelet , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "Id n'existe pas");

    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "Id existant");

    gtk_combo_box_set_active(GTK_COMBO_BOX(text),(atoi(bracelet.info)+1));
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),(atoi(bracelet.etat)+1));
  }


  gtk_label_set_text(GTK_LABEL(output), "Champs supprimer avec succès");
  supprimer_bracelet(id);

}


/*****************Ajouter nouveau medecin ***********************************/
void on_ajouter_medecin_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *input8;
  GtkWidget *input9;
  GtkWidget *input10;
  GtkWidget *input11;
  GtkWidget *output;

  char name1[20]; char last1[20];
  char jour1[10]; char mois1[30]; char annee1[5];
  char email_nom_domaine[30]; char email_ent[30];
  char email1[30];
  char adress1[300];
  char numero1[10];
  char username1[20]; char password1[20];

  input1 = lookup_widget(objet_graphique, "nom_medecin");
  input2 = lookup_widget(objet_graphique, "prenom_medecin");
  input3 = lookup_widget(objet_graphique, "jour_medecin"); //Combobox
  input4 = lookup_widget(objet_graphique, "mois_medecin"); // combobox
  input5 = lookup_widget(objet_graphique, "annee_medecin"); //entry
  input6 = lookup_widget(objet_graphique, "email_medecin"); //entry2
  input7 = lookup_widget(objet_graphique, "mail_medecin_combobox");//combobox
  input8 = lookup_widget(objet_graphique, "username_medecin");
  input9 = lookup_widget(objet_graphique, "password_medecin");
  input10 = lookup_widget(objet_graphique, "numero_medecin");
  input11 = lookup_widget(objet_graphique, "adresse_medecin");

  output= lookup_widget(objet_graphique, "label221");

  strcpy(last1, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(name1, gtk_entry_get_text(GTK_ENTRY(input2)));
  int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(input3)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;
  sprintf(mois1, "%.2d", active_mois);
  strcpy(annee1, gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(email_ent, gtk_entry_get_text(GTK_ENTRY(input6)));
  int nom_domaine =gtk_combo_box_get_active(GTK_COMBO_BOX(input7));
  //strcpy(email_nom_domaine, gtk_combo_box_get_active(GTK_COMBO_BOX(input7)));
switch (nom_domaine)
{
  case 0: strcpy(email_nom_domaine,"@gmail.com");
  break;
  case 1: strcpy(email_nom_domaine,"@yahoo.com");
  break;
  case 2: strcpy(email_nom_domaine,"@icloud.com");
  break;
  case 3: strcpy(email_nom_domaine,"@outlook.com");
  break;
  case 4: strcpy(email_nom_domaine,"@hotmail.com");
  break;
  case 5: strcpy(email_nom_domaine,"@esprit.tn");
  break;
  default : strcpy(email_nom_domaine,"@esprit.tn");
}



/*
0-gmail.Com
1-yahoo.Com
2-icloud.Com
3-outlook.Com
4-hotmail.Com
5-esprit.tn

*/
  /***Récupération de l'adresse mail***/
  strcpy(email1,email_ent);
  strcat(email1,email_nom_domaine);

  strcpy(username1, gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(password1, gtk_entry_get_text(GTK_ENTRY(input9)));
  strcpy(numero1,  gtk_entry_get_text(GTK_ENTRY(input10)));
  strcpy(adress1,  gtk_entry_get_text(GTK_ENTRY(input11)));


  if (verifierexistant(username1)== 0)
  {
      gtk_label_set_text(GTK_LABEL(output), "Nom d'utilsateur déjà utilisé !");
  }

  else
  {
    //char id[5] = "1151";
    medecin med;
if ((controle_saisie_annee(annee1)==0)||(controle_saisie_numero(numero1)==0))
{
gtk_label_set_text(GTK_LABEL(output), "veuillez verifier votre saisie !");
}
else{
    int nouveau_id = auto_incre_id();
    char n_id[sz];
    sprintf(n_id,"%d",nouveau_id);
    gtk_label_set_text(GTK_LABEL(output), n_id);
    //strcpy(n_id,med.id);*/
    strcpy(med.id,n_id);
    strcpy(med.nom,name1);
    strcpy(med.prenom,last1);
    strcpy(med.username,username1);
    strcpy(med.password,password1);
    strcpy(med.email,email1);
    strcpy(med.num,numero1);
    strcpy(med.adresse.ville,adress1);
    strcpy(med.adresse.rue,"Tunisia");
    strcpy(med.Date.jour,jour1);
    strcpy(med.Date.mois,mois1);
    strcpy(med.Date.anne,annee1);
    ajouter_m(med);
    gtk_label_set_text(GTK_LABEL(output),"Medecin ajouté avec succès");
    GtkWidget *ajouter_nouveau_med;
    GtkWidget *Admin_window;
    mailtonew(email1);
    GtkWidget *conf_window;

    conf_window = create_ajout_succes_window ();
    gtk_widget_show (conf_window);
    ajouter_nouveau_med=lookup_widget(objet_graphique,"ajouter_medecin_window");
    gtk_widget_hide(ajouter_nouveau_med);
    //gtk_label_set_text(GTK_LABEL(output), "Medecin ajouté avec succés");
  }
}

}

void on_annuler_medecin_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_nouveau_med;
  GtkWidget *Admin_window;

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
  ajouter_nouveau_med=lookup_widget(objet_graphique,"ajouter_medecin_window");
  gtk_widget_hide(ajouter_nouveau_med);
}

void on_confirm_ajout_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *conf_window;
  GtkWidget *Admin_window;

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
  conf_window=lookup_widget(objet_graphique,"ajout_succes_window");
  gtk_widget_hide(conf_window);
}

void on_ajout_succes_window_show (GtkWidget       *widget,   gpointer         user_data)
{

}

void on_edit_inf_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{

  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  infirmier inf;
  input = lookup_widget(objet_graphique, "id_inf_search");
  output= lookup_widget(objet_graphique, "label276");

  nom_entry = lookup_widget(objet_graphique,"nom_inf");
  prenom_entry = lookup_widget(objet_graphique,"prenom_inf");
  username_entry = lookup_widget(objet_graphique,"username_inf");
  password_entry = lookup_widget(objet_graphique,"password_inf");
  annee_entry=lookup_widget(objet_graphique,"annee_inf");
  ville_entry = lookup_widget(objet_graphique,"numero_inf");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue_inf");
  jour_combo = lookup_widget(objet_graphique, "jour_inf");
  mois_combo = lookup_widget(objet_graphique, "mois_inf");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  inf = chercher_i(id);
  if (strcmp(inf.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be updated");
  }
  else
  {
    strcpy(inf.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(inf.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(inf.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(inf.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(inf.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(inf.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(inf.Date.jour,jour1);
    strcpy(inf.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output), "Champs modifier avec succès");
    modifier_i(inf);

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }


}


void on_supprimer_id_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  infirmier inf;
  input = lookup_widget(objet_graphique, "id_inf_search");
  output= lookup_widget(objet_graphique, "label276");

  nom_entry = lookup_widget(objet_graphique,"nom_inf");
  prenom_entry = lookup_widget(objet_graphique,"prenom_inf");
  username_entry = lookup_widget(objet_graphique,"username_inf");
  password_entry = lookup_widget(objet_graphique,"password_inf");
  annee_entry=lookup_widget(objet_graphique,"annee_inf");
  ville_entry = lookup_widget(objet_graphique,"numero_inf");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue_inf");
  jour_combo = lookup_widget(objet_graphique, "jour_inf");
  mois_combo = lookup_widget(objet_graphique, "mois_inf");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  inf = chercher_i(id);
  if (strcmp(inf.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be deleted");
  }
  else
  {
    strcpy(inf.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(inf.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(inf.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(inf.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(inf.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(inf.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(inf.Date.jour,jour1);
    strcpy(inf.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output), "Champs supprimer avec succès");
    supprimer_i(inf.id);

    gtk_entry_set_text(GTK_ENTRY(username_entry), "");
    gtk_entry_set_text(GTK_ENTRY(password_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(ville_entry), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }


}


void on_button_trouver_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  infirmier inf;
  input = lookup_widget(objet_graphique, "id_inf_search");
  output= lookup_widget(objet_graphique, "label276");

  nom_entry = lookup_widget(objet_graphique,"nom_inf");
  prenom_entry = lookup_widget(objet_graphique,"prenom_inf");
  username_entry = lookup_widget(objet_graphique,"username_inf");
  password_entry = lookup_widget(objet_graphique,"password_inf");
  annee_entry=lookup_widget(objet_graphique,"annee_inf");
  ville_entry = lookup_widget(objet_graphique,"numero_inf");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue_inf");
  jour_combo = lookup_widget(objet_graphique, "jour_inf");
  mois_combo = lookup_widget(objet_graphique, "mois_inf");


  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  inf = chercher_i(id);
  if (strcmp(inf.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Aucun infirmier n'est inscrit avec cet identifiant, veuillez réessayer");
  }
  else {
      gtk_label_set_text(GTK_LABEL(output), "Id existant");

      gtk_entry_set_text(GTK_ENTRY(nom_entry), inf.username);
      gtk_entry_set_text(GTK_ENTRY(prenom_entry), inf.password);
      gtk_entry_set_text(GTK_ENTRY(username_entry), inf.nom);
      gtk_entry_set_text(GTK_ENTRY(password_entry), inf.prenom);
      gtk_entry_set_text(GTK_ENTRY(annee_entry), inf.Date.anne);
      gtk_entry_set_text(GTK_ENTRY(ville_entry), inf.num);
      gtk_entry_set_text(GTK_ENTRY(adresse_rue), inf.adresse.rue);
      gtk_combo_box_set_active(GTK_COMBO_BOX(jour_combo),(atoi(inf.Date.jour)-1));
      gtk_combo_box_set_active(GTK_COMBO_BOX(mois_combo),(atoi(inf.Date.mois)-1));
  }


    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */

}


void on_supprimer_tec_button_clicked(GtkWidget *objet_graphique,   gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  technicien tec;
  input = lookup_widget(objet_graphique, "id_tech_search");
  output= lookup_widget(objet_graphique, "label_not_found_tec");

  nom_entry = lookup_widget(objet_graphique,"nom_tech");
  prenom_entry = lookup_widget(objet_graphique,"prenom_tech");
  username_entry = lookup_widget(objet_graphique,"username_tech");
  password_entry = lookup_widget(objet_graphique,"password_tech");
  annee_entry=lookup_widget(objet_graphique,"edit_annee_tech");
  ville_entry = lookup_widget(objet_graphique,"numero_tech");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue_tech");
  jour_combo = lookup_widget(objet_graphique, "edit_jour_tech");
  mois_combo = lookup_widget(objet_graphique, "edit_mois_tech");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  tec = chercher_tec(id);
  if (strcmp(tec.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be deleted");
  }
  else
  {
    strcpy(tec.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(tec.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(tec.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(tec.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(tec.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(tec.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(tec.Date.jour,jour1);
    strcpy(tec.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output), "Champs supprimer avec succès");
    supprimer_tec(tec.id);

    gtk_entry_set_text(GTK_ENTRY(username_entry), "");
    gtk_entry_set_text(GTK_ENTRY(password_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(ville_entry), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }
}


void on_edit_tech_button_clicked (GtkWidget *objet_graphique,   gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  technicien tec;
  input = lookup_widget(objet_graphique, "id_tech_search");
  output= lookup_widget(objet_graphique, "label_not_found_tec");

  nom_entry = lookup_widget(objet_graphique,"nom_tech");
  prenom_entry = lookup_widget(objet_graphique,"prenom_tech");
  username_entry = lookup_widget(objet_graphique,"username_tech");
  password_entry = lookup_widget(objet_graphique,"password_tech");
  annee_entry=lookup_widget(objet_graphique,"edit_annee_tech");
  ville_entry = lookup_widget(objet_graphique,"numero_tech");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue_tech");
  jour_combo = lookup_widget(objet_graphique, "edit_jour_tech");
  mois_combo = lookup_widget(objet_graphique, "edit_mois_tech");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  tec = chercher_tec(id);
  if (strcmp(tec.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be updated");
  }
  else
  {
    strcpy(tec.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(tec.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(tec.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(tec.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(tec.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(tec.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(tec.Date.jour,jour1);
    strcpy(tec.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output), "Champs modifier avec succès");
    modifier_tec(tec);

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }
}

void on_button_trouver_tech_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  technicien tec;
  input = lookup_widget(objet_graphique, "id_tech_search");
  output= lookup_widget(objet_graphique, "label_not_found_tec");

  nom_entry = lookup_widget(objet_graphique,"nom_tech");
  prenom_entry = lookup_widget(objet_graphique,"prenom_tech");
  username_entry = lookup_widget(objet_graphique,"username_tech");
  password_entry = lookup_widget(objet_graphique,"password_tech");
  annee_entry=lookup_widget(objet_graphique,"edit_annee_tech");
  ville_entry = lookup_widget(objet_graphique,"numero_tech");
  adresse_rue = lookup_widget(objet_graphique,"adresse_rue_tech");
  jour_combo = lookup_widget(objet_graphique, "edit_jour_tech");
  mois_combo = lookup_widget(objet_graphique, "edit_mois_tech");


  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  tec = chercher_tec(id);
  if (strcmp(tec.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Aucun technicien n'est inscrit avec cet identifiant, veuillez réessayer");
  }
  else {
      gtk_label_set_text(GTK_LABEL(output), "Id existant");

      gtk_entry_set_text(GTK_ENTRY(nom_entry), tec.username);
      gtk_entry_set_text(GTK_ENTRY(prenom_entry), tec.password);
      gtk_entry_set_text(GTK_ENTRY(username_entry), tec.nom);
      gtk_entry_set_text(GTK_ENTRY(password_entry), tec.prenom);
      gtk_entry_set_text(GTK_ENTRY(annee_entry), tec.Date.anne);
      gtk_entry_set_text(GTK_ENTRY(ville_entry), tec.num);
      gtk_entry_set_text(GTK_ENTRY(adresse_rue), tec.adresse.rue);
      gtk_combo_box_set_active(GTK_COMBO_BOX(jour_combo),(atoi(tec.Date.jour)-1));
      gtk_combo_box_set_active(GTK_COMBO_BOX(mois_combo),(atoi(tec.Date.mois)-1));
  }


    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
}


void on_button_trouver_as_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  aide_soignant as;
  input = lookup_widget(objet_graphique, "id_as");
  output= lookup_widget(objet_graphique, "label_not_found_as");

  nom_entry = lookup_widget(objet_graphique,"nom_as");
  prenom_entry = lookup_widget(objet_graphique,"prenom_as");
  username_entry = lookup_widget(objet_graphique,"username_as");
  password_entry = lookup_widget(objet_graphique,"password_as");
  annee_entry=lookup_widget(objet_graphique,"annee_as");
  ville_entry = lookup_widget(objet_graphique,"numero_as");
  adresse_rue = lookup_widget(objet_graphique,"adresse_as");
  jour_combo = lookup_widget(objet_graphique, "jour_as");
  mois_combo = lookup_widget(objet_graphique, "mois_as");


  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  as = chercher_as(id);
  if (strcmp(as.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Aucun aide soignant n'est inscrit avec cet identifiant, veuillez réessayer");
  }
  else {
      gtk_label_set_text(GTK_LABEL(output), "Id existant");

      gtk_entry_set_text(GTK_ENTRY(nom_entry), as.username);
      gtk_entry_set_text(GTK_ENTRY(prenom_entry), as.password);
      gtk_entry_set_text(GTK_ENTRY(username_entry), as.nom);
      gtk_entry_set_text(GTK_ENTRY(password_entry), as.prenom);
      gtk_entry_set_text(GTK_ENTRY(annee_entry), as.Date.anne);
      gtk_entry_set_text(GTK_ENTRY(ville_entry), as.num);
      gtk_entry_set_text(GTK_ENTRY(adresse_rue), as.adresse.rue);
      gtk_combo_box_set_active(GTK_COMBO_BOX(jour_combo),(atoi(as.Date.jour)-1));
      gtk_combo_box_set_active(GTK_COMBO_BOX(mois_combo),(atoi(as.Date.mois)-1));
  }


    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */

}


void on_supprimer_id_as_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  aide_soignant as;
  input = lookup_widget(objet_graphique, "id_as");
  output= lookup_widget(objet_graphique, "label_not_found_as");

  nom_entry = lookup_widget(objet_graphique,"nom_as");
  prenom_entry = lookup_widget(objet_graphique,"prenom_as");
  username_entry = lookup_widget(objet_graphique,"username_as");
  password_entry = lookup_widget(objet_graphique,"password_as");
  annee_entry=lookup_widget(objet_graphique,"annee_as");
  ville_entry = lookup_widget(objet_graphique,"numero_as");
  adresse_rue = lookup_widget(objet_graphique,"adresse_as");
  jour_combo = lookup_widget(objet_graphique, "jour_as");
  mois_combo = lookup_widget(objet_graphique, "mois_as");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  as = chercher_as(id);
  if (strcmp(as.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be deleted");
  }
  else
  {
    strcpy(as.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(as.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(as.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(as.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(as.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(as.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(as.Date.jour,jour1);
    strcpy(as.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output), "Champs supprimer avec succès");
    supprimer_as(as.id);

    gtk_entry_set_text(GTK_ENTRY(username_entry), "");
    gtk_entry_set_text(GTK_ENTRY(password_entry), "");
    gtk_entry_set_text(GTK_ENTRY(prenom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(nom_entry), "");
    gtk_entry_set_text(GTK_ENTRY(ville_entry), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");
    gtk_entry_set_text(GTK_ENTRY(adresse_rue), "");

    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }
}


void on_edit_as_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  GtkWidget *nom_entry;
  GtkWidget *prenom_entry;
  GtkWidget *username_entry;
  GtkWidget *password_entry;
  GtkWidget *ville_entry;
  GtkWidget *adresse_rue;
  GtkWidget *annee_entry;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;

  aide_soignant as;
  input = lookup_widget(objet_graphique, "id_as");
  output= lookup_widget(objet_graphique, "label_not_found_as");

  nom_entry = lookup_widget(objet_graphique,"nom_as");
  prenom_entry = lookup_widget(objet_graphique,"prenom_as");
  username_entry = lookup_widget(objet_graphique,"username_as");
  password_entry = lookup_widget(objet_graphique,"password_as");
  annee_entry=lookup_widget(objet_graphique,"annee_as");
  ville_entry = lookup_widget(objet_graphique,"numero_as");
  adresse_rue = lookup_widget(objet_graphique,"adresse_as");
  jour_combo = lookup_widget(objet_graphique, "jour_as");
  mois_combo = lookup_widget(objet_graphique, "mois_as");

  char id[10];

  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
  as = chercher_as(id);
  if (strcmp(as.id , "-1")==0)
  {
    gtk_label_set_text(GTK_LABEL(output), "Nothing to be updated");
  }
  else
  {
    strcpy(as.username, gtk_entry_get_text(GTK_ENTRY(username_entry)));
    strcpy(as.password, gtk_entry_get_text(GTK_ENTRY(password_entry)));
    strcpy(as.prenom, gtk_entry_get_text(GTK_ENTRY(prenom_entry)));
    strcpy(as.nom, gtk_entry_get_text(GTK_ENTRY(nom_entry)));
    strcpy(as.num, gtk_entry_get_text(GTK_ENTRY(ville_entry)));
    strcpy(as.adresse.rue, gtk_entry_get_text(GTK_ENTRY(adresse_rue)));

    char jour1[10];
    char mois1[30];
    int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
    sprintf(jour1,"%.2d",active_jour);
    int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
    sprintf(mois1, "%.2d", active_mois);

    strcpy(as.Date.jour,jour1);
    strcpy(as.Date.mois,mois1);

    gtk_label_set_text(GTK_LABEL(output), "Champs modifer avec succès");
    modifier_as(as);


    /*GtkWidget *edit_window;
    edit_window=lookup_widget(button,"edit_window");
    gtk_widget_hide(edit_window);
    GtkWidget *Admin_window;
    Admin_window = create_Admin_window ();
    gtk_widget_show (Admin_window);
    */
  }
}

void
on_ajout_photo_persoag_clicked         (GtkWidget *objet_graphique,  gpointer user_data)
{

}


void
on_supprimer_photo_persoag_clicked     (GtkWidget *objet_graphique,  gpointer user_data)
{

}


void on_enrg_fichier_persoag_clicked(GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *name;
  GtkWidget *lastname;
  GtkWidget *t_combo;
  GtkWidget *d_combo;
  GtkWidget *a_combo;
  GtkWidget *c_combo;
  GtkWidget *jour_combo;
  GtkWidget *mois_combo;
  GtkWidget *anne_entry;
  GtkWidget *poids_entry;
  GtkWidget *taille_entry;
  GtkWidget *gs_combo;

  name = lookup_widget(objet_graphique, "nom_persoag");
  lastname = lookup_widget(objet_graphique, "prenom_persoag");
  poids_entry = lookup_widget(objet_graphique, "poids_persoag");
  taille_entry = lookup_widget(objet_graphique, "taille_persoag");
  anne_entry = lookup_widget(objet_graphique, "annee_persoag");

  t_combo = lookup_widget(objet_graphique, "T_combobox");
  a_combo = lookup_widget(objet_graphique, "A_combobox");
  d_combo = lookup_widget(objet_graphique, "D_combobox");
  c_combo = lookup_widget(objet_graphique, "C_combobox");
  jour_combo = lookup_widget(objet_graphique, "jour_combobox_persoag");
  mois_combo = lookup_widget(objet_graphique, "mois_combobox_persoag");
  gs_combo = lookup_widget(objet_graphique, "gs_combobox_persoag");

  p_agee p;
  strcpy(p.nompa, gtk_entry_get_text(GTK_ENTRY(name)));
  strcpy(p.prenompa, gtk_entry_get_text(GTK_ENTRY(lastname)));
  strcpy(p.poids, gtk_entry_get_text(GTK_ENTRY(poids_entry)));
  strcpy(p.taille, gtk_entry_get_text(GTK_ENTRY(taille_entry)));
  strcpy(p.Date.anne, gtk_entry_get_text(GTK_ENTRY(anne_entry)));

  char jour1[10];
  char mois1[30];
  char a_c[10];
  char a_t[30];
  char a_a[10];
  char a_d[30];
  char a_gs[30];
  int active_jour=gtk_combo_box_get_active(GTK_COMBO_BOX(jour_combo)) + 1;
  sprintf(jour1,"%.2d",active_jour);
  int active_mois=gtk_combo_box_get_active(GTK_COMBO_BOX(mois_combo)) + 1;
  sprintf(mois1, "%.2d", active_mois);
  int active_t=gtk_combo_box_get_active(GTK_COMBO_BOX(t_combo)) + 1;
  sprintf(a_t,"%.2d",active_t);
  int active_a=gtk_combo_box_get_active(GTK_COMBO_BOX(a_combo)) + 1;
  sprintf(a_a, "%.2d", active_a);
  int active_c=gtk_combo_box_get_active(GTK_COMBO_BOX(c_combo)) + 1;
  sprintf(a_c,"%.2d",active_c);
  int active_d=gtk_combo_box_get_active(GTK_COMBO_BOX(d_combo)) + 1;
  sprintf(a_d, "%.2d", active_d);
  int active_gs=gtk_combo_box_get_active(GTK_COMBO_BOX(gs_combo)) + 1;
  sprintf(a_gs, "%.2d", active_gs);

  strcpy(p.Date.jour,jour1);
  strcpy(p.Date.mois,mois1);
  strcpy(p.c,a_c);
  strcpy(p.a,a_a);
  strcpy(p.t,a_t);
  strcpy(p.d,a_d);
  strcpy(p.gs,a_gs);

  ajouter_pa(p);

}


void
on_Quitter_persoag_clicked             (GtkWidget *objet_graphique,  gpointer user_data)
{

}

void on_ajouter_nouveaux_pa_clicked(GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajouter_persoag;
  ajouter_persoag = create_ajouter_persoag();
  gtk_widget_show(ajouter_persoag);
}

void on_refresh_cam_clicked(GtkWidget *objet_graphique,  gpointer user_data)
{
  /*GtkWidget *treeview_camera;
  FILE *f;
  came cam[200];
  treeview_camera = gtk_tree_view_new ();
  gtk_widget_show (treeview_camera);
  treeview_camera = lookup_widget (GTK_WIDGET(objet_graphique),"treeview_camera");

  lecture_camera(f,cam);
  affichagecamera(treeview_camera, cam);*/

  GtkWidget *Admin_window;
  Admin_window=lookup_widget(objet_graphique,"Admin_window");
  gtk_widget_hide(Admin_window);

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
}


void on_ajouter_nouveau_cam_clicked(GtkWidget *objet_graphique,  gpointer user_data)
{
GtkWidget *ajout_camera;
ajout_camera = create_ajout_camera ();
gtk_widget_show(ajout_camera);

}



void on_ajouter_nouveau_bra_clicked    (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *ajout_bra;
  ajout_bra = create_ajout_bracelet ();
  gtk_widget_show(ajout_bra);
}


void on_search_bra_clicked   (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *edit_bra;
  edit_bra= create_edit_bracelet_window();
  gtk_widget_show(edit_bra);
}


void
on_refresh_bra_clicked                 (GtkWidget *objet_graphique,  gpointer user_data)
{

}

void on_add_bracelet_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;

  input1 = lookup_widget(objet_graphique, "ref_bra_box");
  input2 = lookup_widget(objet_graphique, "etat_bra_box");

  char br1[20];
  char br2[20];
  Bracelet bracelet;


  int active_br1=gtk_combo_box_get_active(GTK_COMBO_BOX(input1)) + 1;
  switch (active_br1)
  {
    case 1: strcpy(br1,"Excelvan");
    break;
    case 2: strcpy(br1,"Paradox");
    break;
    case 3: strcpy(br1,"Diagral");
    break;
    case 4: strcpy(br1,"Eden");
    break;
    default : strcpy(br1,"Eden");
  }

  int active_br2=gtk_combo_box_get_active(GTK_COMBO_BOX(input1)) + 1;
  switch (active_br2)
  {
    case 1: strcpy(br2,"non_fonctionnel");
    break;
    case 2: strcpy(br2,"fonctionnel");
    break;
    default : strcpy(br2,"fonctionnel");

  }
  int id = auto_incre_id_bracelet();
  char id_c[10];
  sprintf(id_c,"%d",id);

  strcpy(bracelet.identifiant_bracelet,id_c);
  strcpy(bracelet.info,br1);
  strcpy(bracelet.etat,br2);
  ajout_bracelet(bracelet);

  GtkWidget *ferme;
  ferme=lookup_widget(objet_graphique,"ajout_bracelet");
  gtk_widget_hide(ferme);
}

void on_search_cam_edit_clicked   (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *text;
  GtkWidget *combo;

  input1= lookup_widget(objet_graphique,"id_cam_search_entry");
  text = lookup_widget(objet_graphique,"edit_emp_cam_entry");
  combo =lookup_widget(objet_graphique,"edit_ref_cam_box");
  output= lookup_widget(objet_graphique,"label329");

  Camera camera;
  //camera = chercher_camera(gtk_entry_get_text(GTK_ENTRY(input1)));
  char id[10];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  camera = chercher_camera(id);

  if (strcmp(camera.identifiant_camera , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "Id n'existe pas");
    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "Id existant");
    gtk_entry_set_text(GTK_ENTRY(text), camera.emplacement);
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),(atoi(camera.info)));
  }


}

void on_send_alertes_button_clicked         (GtkWidget *objet_graphique,  gpointer user_data)
{
 GtkWidget *input1;
 GtkWidget *input2;
 char envoie[20];
 char text[1000];

 input1 = lookup_widget(objet_graphique, "destinataire_combobox");
 input2 = lookup_widget(objet_graphique, "alerte_textview");

 int activre = gtk_combo_box_get_active(GTK_COMBO_BOX(input1));


  //textview1

  char *textg= get_text_of_textview(input2);
  printf("%s\n", textg);
  strcpy(text,textg);

  FILE*h;

  /*
  0 : Infirmier
  1 : Administrateur
  */

  if (activre == 0)
  {
    h=fopen("alertemed.txt","a+");
    if(h!=NULL)
    {
      fprintf(h,"medecin %s\n",text);
      } fclose(h);
  }
  else
  {
    h=fopen("alertetec.txt","a+");
    if(h!=NULL)
    {
      fprintf(h,"technicien %s\n",text);
      } fclose(h);
  }
  //strcpy


}


void on_enregister_saisie_rapport_button_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  input1 = lookup_widget(objet_graphique, "saisie_rapport_textview");

  char *textg  =get_text_of_textview(input1);
  char text[1000];
  strcpy(text,textg);


  FILE *p;

  p=fopen("rapports.txt","a+");

  if(p!=NULL)
    {
      fprintf(p,"%s\n",text);
      fclose(p);
    }

}


void on_fermer_saisie_rapport_clicked       (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  input1 = lookup_widget(objet_graphique, "saisie_rapport_textview");

  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input1));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);

  //gtk_tree_view_set_text(GTK_TEXTB)
}


void on_cancel_ordonnance_button_clicked    (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  input1 = lookup_widget(objet_graphique, "observation_textview");
  input2 = lookup_widget(objet_graphique, "titre_entry");
  input3 = lookup_widget(objet_graphique, "jour_ordonnance_combobox");
  input4 = lookup_widget(objet_graphique, "mois_ordonnance_combobox");
  input5 = lookup_widget(objet_graphique, "annee_ordonnance_entry");
  input6 = lookup_widget(objet_graphique, "h_ordonnance_entry");
  input7 = lookup_widget(objet_graphique, "min_ordonnance_entry");

  gtk_entry_set_text(GTK_ENTRY(input6),"");
  gtk_entry_set_text(GTK_ENTRY(input7),"");
  gtk_entry_set_text(GTK_ENTRY(input5),"");
  gtk_entry_set_text(GTK_ENTRY(input2),"");
  gtk_combo_box_set_active(GTK_COMBO_BOX(input3),-1);
  gtk_combo_box_set_active(GTK_COMBO_BOX(input4),-1);

  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input1));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
}


void on_save_ordonnance_button_clicked      (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *out;
  input1 = lookup_widget(objet_graphique, "observation_textview");
  input2 = lookup_widget(objet_graphique, "titre_entry");
  input3 = lookup_widget(objet_graphique, "jour_ordonnance_combobox");
  input4 = lookup_widget(objet_graphique, "mois_ordonnance_combobox");
  input5 = lookup_widget(objet_graphique, "annee_ordonnance_entry");
  input6 = lookup_widget(objet_graphique, "h_ordonnance_entry");
  input7 = lookup_widget(objet_graphique, "min_ordonnance_entry");
  out= lookup_widget(objet_graphique,"label_pa_re");

  char jj[3]; char mm[3]; char an[5]; char hh[3]; char mim[3];
  char id[5];

  strcpy(id,  gtk_entry_get_text(GTK_ENTRY(input2)));
  p_agee pag = chercher_pa(id);

  if(strcmp(pag.id,id) == 0)
  {
      gtk_label_set_text(GTK_LABEL(out),"Personne âgée trouvée");
      int active_j=gtk_combo_box_get_active(GTK_COMBO_BOX(input3))+1;
      int active_m=gtk_combo_box_get_active(GTK_COMBO_BOX(input4))+1;

      sprintf(jj,"%.2d",active_j);
      sprintf(mm,"%.2d",active_m);
      strcpy(an,gtk_entry_get_text(GTK_ENTRY(input5)));
      strcpy(hh,gtk_entry_get_text(GTK_ENTRY(input6)));
      strcpy(mim,gtk_entry_get_text(GTK_ENTRY(input7)));

      char *textg= get_text_of_textview(input1);
      char text[500];
      strcpy(text,textg);

      FILE *f;

      f=fopen("ordonnance.txt","a+");

      if(f!=NULL)
      {
        fprintf(f,"%s: après consultation le %s/%s/%s à %s:%s : %s\n",pag.id,jj,mm,an,hh,mim,text);
        gtk_label_set_text(GTK_LABEL(out),"Succès d'ajout");
        fclose(f);
      }

  }
  else {
    gtk_label_set_text(GTK_LABEL(out),"Aucune personne âgée n'est trouvée");
  }
}


void on_search_fiche_button_clicked         (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *output;

  input1 = lookup_widget(objet_graphique, "entry_num_fiche");
  input2 = lookup_widget(objet_graphique, "taille_entry");
  input3 = lookup_widget(objet_graphique, "poids_entry");
  input6 = lookup_widget(objet_graphique, "diagnostic_textview");
  output = lookup_widget(objet_graphique, "pa_label");


  char pa[5]; char id[5];
  char no[20]; char pren[20]; char jj[3]; char mm[3]; char ann[5]; char taille[5]; char poi[5]; char gs[2];
  char tbg[3]; char alch[3]; char diab[3]; char nn[3];
  //strcpy(,input1);
  strcpy(id,  gtk_entry_get_text(GTK_ENTRY(input1)));

 FILE *h;

  h= fopen("personne_agee.txt","r");

  if(h != NULL)
  {
    while(fscanf(h,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",pa,no,pren,jj,mm,ann,taille,poi,gs,tbg,alch,diab,nn)!= EOF)
      {
        if(strcmp(pa,id)== 0)
          {
            //gtk_entry_set_text(GTK_ENTRY())
            gtk_entry_set_text(GTK_ENTRY(input3), taille);
            gtk_entry_set_text(GTK_ENTRY(input2), poi);
            gtk_label_set_text(GTK_LABEL(output),"Personne âgée trouvée");
          }
          else
          {
            gtk_label_set_text(GTK_LABEL(output),"Personne âgée introuvable");
          }
      }
    fclose(h);
  }



}


void on_ajouter_info_button_clicked         (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input6;
  GtkWidget *output;

  input1 = lookup_widget(objet_graphique, "entry_num_fiche");
  input2 = lookup_widget(objet_graphique, "taille_entry");
  input3 = lookup_widget(objet_graphique, "poids_entry");
  input6 = lookup_widget(objet_graphique, "diagnostic_textview");
  output = lookup_widget(objet_graphique, "pa_label");

  char *textg  =get_text_of_textview(input6);
  p_agee pag;

  char id[5];
  char text[100];
  strcpy(id,  gtk_entry_get_text(GTK_ENTRY(input1)));
  pag = chercher_pa(id);
  strcpy(text,textg);
  if(strcmp(pag.id,id) == 0)
  {
    strcpy(pag.taille, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(pag.poids, gtk_entry_get_text(GTK_ENTRY(input3)));
    modifier_pa(pag);
    FILE *p;

    p =fopen("diagnostic.txt","a+");
    if((p!= NULL)&&(strcmp(text,"")!=0))
    {
      fprintf(p,"%s: %s\n",pag.id,text);
      fclose(p);
    }
    gtk_label_set_text(GTK_LABEL(output),"Ajout aboutie avec succès");
  }



}


void on_fermer_info_button_clicked          (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input6;
  input1 = lookup_widget(objet_graphique, "entry_num_fiche");
  input2 = lookup_widget(objet_graphique, "taille_entry");
  input3 = lookup_widget(objet_graphique, "poids_entry");
  input6 = lookup_widget(objet_graphique, "diagnostic_textview");

  gtk_entry_set_text(GTK_ENTRY(input1),"");
  gtk_entry_set_text(GTK_ENTRY(input2),"");
  gtk_entry_set_text(GTK_ENTRY(input3),"");

  GtkWidget *output;
  output = lookup_widget(objet_graphique, "pa_label");
  gtk_label_set_text(GTK_LABEL(output),"");

  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input6));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
}




void on_as_envoyer_alerte_button_clicked    (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *comb;
  /*
  Alerte Technique
  Alerte Medicale
*/


  input1= lookup_widget(objet_graphique,"as_alerte_text");
  comb = lookup_widget(objet_graphique,"as_type_alerte_combobox");

  char text[400];

  int activre = gtk_combo_box_get_active(GTK_COMBO_BOX(comb));

   char *textg= get_text_of_textview(input1);
  // 0 tec
   //1 med
   FILE *f;
   strcpy(text,textg);
   if (activre == 0)
   {
     if (strcmp(text,"")!=0)
     {
       f=fopen("alertetec.txt","a+");
       if(f!=NULL)
       {
         fprintf(f,"aidesoignant %s\n",text);
         fclose(f);
       }
     }
   }

   else if (activre == 1)
   {
     if (strcmp(text,"")!=0)
     {
       f=fopen("alertemed.txt","a+");
       if(f!=NULL)
       {
         fprintf(f,"aidesoignant %s\n",text);
         fclose(f);
       }
     }
   }
}


void on_as_ajouter_rapport_espace_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *output2;
  input1 = lookup_widget(objet_graphique,"as_chercher_espace_entry");
  input2 = lookup_widget(objet_graphique,"as_etat_espace_combobox");
  input3 = lookup_widget(objet_graphique,"as_temp_espace_entry");
  input4 = lookup_widget(objet_graphique,"as_tele_combobox");
  output1= lookup_widget(objet_graphique,"as_chercher_espace_label");
  output2= lookup_widget(objet_graphique,"as_modifier_espace_label");

  Espace e;

  strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input1)));

  int active_ref=gtk_combo_box_get_active(GTK_COMBO_BOX(input2)) + 1;

  switch (active_ref)
    {
      case 1:{ strcpy(e.etat,"propre");
      break;}
      case 2:{ strcpy(e.etat,"non_propre");
      break;}
      default : strcpy(e.etat,"propre");
    }

   strcpy(e.temp,gtk_entry_get_text(GTK_ENTRY(input3)));

   int active_ref1=gtk_combo_box_get_active(GTK_COMBO_BOX(input4)) + 1;

   switch (active_ref1)
    {
      case 1: strcpy(e.tele,"fonctionnel");
      break;
      case 2: strcpy(e.tele,"non_fonctionnel");
      break;
      default : strcpy(e.tele,"fonctionnel");
    }


if(digital(e.temp)==1)
{
  gtk_label_set_text(GTK_LABEL(output2), "Champs modifier avec succès");
  modifier_espace(e);
}
else{gtk_label_set_text(GTK_LABEL(output2), "veuiller verifier s'il vous plait");}
}


void on_as_ajouter_reclamation_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input2;
  char text[1000];
  input2 = lookup_widget(objet_graphique, "textview3");
  char *textg= get_text_of_textview(input2);
  strcpy(text,textg);

  FILE *f;

  f=fopen("reclamation_tec.txt","a+");

  if(f!=NULL)
  {
    fprintf(f,"technicien: %s\n",text);
    fclose(f);
  }
}

void on_Espace_medecin_show (GtkWidget  *widget, gpointer user_data)
{
  FILE *f;
  ale M[100];
  alsp T[100];
  GtkWidget *treeview;
  GtkWidget *treeview1;
  treeview= lookup_widget((widget),"treeview_alertes_urgence");
  treeview1= lookup_widget((widget),"treeview12");
  lecture_a(f,M);
  affichageAlerte (treeview1,M);

  lectureamed(f,T);
  affichageamed(treeview,T);

}

void  on_ordonnance_recherche_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *input5;
  GtkWidget *input6;
  GtkWidget *input7;
  GtkWidget *out;
  input1 = lookup_widget(objet_graphique, "observation_textview");
  input2 = lookup_widget(objet_graphique, "titre_entry");
  input3 = lookup_widget(objet_graphique, "jour_ordonnance_combobox");
  input4 = lookup_widget(objet_graphique, "mois_ordonnance_combobox");
  input5 = lookup_widget(objet_graphique, "annee_ordonnance_entry");
  input6 = lookup_widget(objet_graphique, "h_ordonnance_entry");
  input7 = lookup_widget(objet_graphique, "min_ordonnance_entry");
  out= lookup_widget(objet_graphique,"label_pa_re");

  char jj[3]; char mm[3]; char an[5]; char hh[3]; char mim[3];

  char id[5];
  strcpy(id,  gtk_entry_get_text(GTK_ENTRY(input2)));
  p_agee pag = chercher_pa(id);

  if(strcmp(pag.id,id) == 0)
  {
      gtk_label_set_text(GTK_LABEL(out),"Personne âgée trouvée");
  }
  else {
    gtk_label_set_text(GTK_LABEL(out),"Aucune personne âgée n'est trouvée");
  }





}
/***************************Technicien**************************/
void on_ajouter_materiel_clicked            (GtkWidget       *objet_graphique, gpointer         user_data)
{

}


void on_supprimer_materiel_clicked          (GtkWidget       *objet_graphique, gpointer         user_data)
{

}


void on_selectionner_tout_etat_clicked      (GtkWidget       *objet_graphique, gpointer         user_data)
{

}


void on_supprimer_etat_clicked              (GtkWidget       *objet_graphique, gpointer         user_data)
{

}


void on_enregister_remarque_etat_clicked    (GtkWidget       *objet_graphique, gpointer         user_data)
{

}


void on_actualiser_nouveau_alertes_clicked  (GtkWidget       *objet_graphique, gpointer         user_data)
{
  GtkWidget *tech_window;
  tech_window=lookup_widget(objet_graphique,"technicien_window");
  gtk_widget_hide(tech_window);

  tech_window = create_technicien_window ();
  gtk_widget_show (tech_window);
}


void on_envoyer_alerte_clicked              (GtkWidget       *objet_graphique, gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  input1 = lookup_widget(objet_graphique,"textview2");
  output = lookup_widget(objet_graphique,"label518");
  char *textg= get_text_of_textview(input1);

  char text[400];
  strcpy(text,textg);
  if (strcmp(text,"")!=0)
  {
    FILE *f;
    f=fopen("alertetec.txt","a+");
    if(f != NULL)
    {
      fprintf(f,"technicien %s\n",text);
      fclose(f);
    }
  }
  else {
      gtk_label_set_text(GTK_LABEL(output),"Champ vide veuillez verifier");
  }



}


void on_eregistrer_rapport_clicked          (GtkWidget       *objet_graphique, gpointer         user_data)
{

}

void on_se_deconnecter_clicked (GtkWidget       *objet_graphique, gpointer         user_data)
{
  GtkWidget *login_window;
  GtkWidget *infirmier_window;

  login_window = create_login_window ();
  gtk_widget_show (login_window);
  infirmier_window=lookup_widget(objet_graphique,"Espace_infirmier");
  gtk_widget_hide(infirmier_window);
}


void on_envoyer_alertes_clicked (GtkWidget       *objet_graphique, gpointer         user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  char text[500];
  input1= lookup_widget(objet_graphique, "combobox_envoies_alertes");
  input2 = lookup_widget(objet_graphique,"textview_envoie_alertes");

  /*
  0-Aide_soignante
  1-Administrateur
  */

  int activre = gtk_combo_box_get_active(GTK_COMBO_BOX(input1));

   char *textg= get_text_of_textview(input2);
   strcpy(text,textg);

   FILE*h;

   if (activre == 0)
   {
     h=fopen("alertemed.txt","a+");
     if(h!=NULL)
     {
       fprintf(h,"Infirmier %s\n",text);
       fclose(h);
       }
   }
   else if (activre == 1)
   {
     h=fopen("alertetec.txt","a+");
     if(h!=NULL)
     {

       fprintf(h,"Infirmier %s\n",text);
       fclose(h);
       }
   }


}


void on_ajouter_materiel_technique_clicked  (GtkWidget       *objet_graphique, gpointer         user_data)
{
  GtkWidget *ajout_mat;
  ajout_mat = create_ajout_mat_window ();
  gtk_widget_show(ajout_mat);
}


void on_actualiser_liste_materiel_technique_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *tech_window;
  tech_window=lookup_widget(objet_graphique,"technicien_window");
  gtk_widget_hide(tech_window);

  tech_window = create_technicien_window ();
  gtk_widget_show (tech_window);
}


void on_ajouter_materiel_medical_clicked   (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *ajout_mat;
  ajout_mat = create_window1 ();
  gtk_widget_show(ajout_mat);
}


void on_actualiser_liste_materiel_medical_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *tech_window;
  tech_window=lookup_widget(objet_graphique,"technicien_window");
  gtk_widget_hide(tech_window);

  tech_window = create_technicien_window ();
  gtk_widget_show (tech_window);
}



void on_deconnecter_clicked (GtkWidget       *objet_graphique, gpointer         user_data)
{
  GtkWidget *login_window;
  GtkWidget *tech_window;

  login_window = create_login_window ();
  gtk_widget_show (login_window);
  tech_window=lookup_widget(objet_graphique,"technicien_window");
  gtk_widget_hide(tech_window);
}


void on_espace_as_show(GtkWidget  *widget,gpointer   user_data)
{
  FILE *f;
  alsp T[100];
  GtkWidget *treeview;
  treeview = lookup_widget(widget, "treeview9");
  lectureamed(f,T);
  affichageamed(treeview,T);

  FILE *h;
  cel M[100];
  GtkWidget *treeview2;
  treeview2 = lookup_widget(widget, "treeview10");
  lecturea(f,M);
  affichagea(treeview2,M);


}

void on_Espace_infirmier_show (GtkWidget *widget,   gpointer user_data)
{
  FILE *f, *h;
  alsp T[100];
  cel M[100];
  GtkWidget *treeview;
  GtkWidget *tree;
  treeview = lookup_widget(widget, "treeview_alertes_urgences");
  tree = lookup_widget(widget, "treeview20");
  lectureamed(f,T);
  affichageamed(treeview,T);

  lecturei(h,M);
  affichagei (tree,M);
}

void on_technicien_window_show (GtkWidget       *widget, gpointer         user_data)
{
  GtkWidget *treeviewal;
  alsp A[200];
  FILE *h, *f;
  treeviewal = lookup_widget (GTK_WIDGET(widget),"treeview_nouveau_alertes");
  lectureatec(h,A);
  affichagealtec (treeviewal,A);
  //
  GtkWidget *treeview_materiel;
  FILE *b;
  materiel MA[200];
  treeview_materiel = lookup_widget (GTK_WIDGET(widget),"treeview_ajouter_materiel_technique");
  lecture_mat(b,MA);
  affichagemat(treeview_materiel, MA);

  GtkWidget *treevie;
  materiel M[200];
  treevie = lookup_widget (GTK_WIDGET(widget),"treeview_ajouter_materiel_medical");
  lecture_matm(f,M);
  affichagematm(treevie, M);





}

void on_as_chercher_espace_as_button_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *output;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;


  input1 = lookup_widget(objet_graphique,"as_chercher_espace_entry");
  input2 = lookup_widget(objet_graphique,"as_etat_espace_combobox");
  input3 = lookup_widget(objet_graphique,"as_temp_espace_entry");
  input4 = lookup_widget(objet_graphique,"as_tele_combobox");
  output = lookup_widget(objet_graphique,"as_chercher_espace_label");

  Espace espace;
  char id[20];
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
  espace = chercher_espace(id);

  if (strcmp(espace.nom , "-1")==0)
    {
      gtk_label_set_text(GTK_LABEL(output), "La chambre n'existe pas");
    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output), "chambre existante");
 if(strcmp(espace.etat,"propre")==0){
      gtk_combo_box_set_active(GTK_COMBO_BOX(input2),0);
}
else {gtk_combo_box_set_active(GTK_COMBO_BOX(input2),1);}
    gtk_entry_set_text(GTK_ENTRY(input3),espace.temp);

    if(strcmp(espace.tele,"fonctionnel")==0){
         gtk_combo_box_set_active(GTK_COMBO_BOX(input4),0);
    }
    else {gtk_combo_box_set_active(GTK_COMBO_BOX(input4),1);}
  }
}

void on_ajout_mat_butt_clicked(GtkWidget  *objet_graphique,   gpointer  user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *output;

  input1= lookup_widget(objet_graphique,"nom_mat");
  input2= lookup_widget(objet_graphique,"ref_mat");
  input3= lookup_widget(objet_graphique,"nbr_mat");
  output= lookup_widget(objet_graphique,"label517");

  char na[20]; char ref[20]; char nbc[10]; int nbr=0;

  strcpy(na, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(ref, gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(nbc, gtk_entry_get_text(GTK_ENTRY(input3)));

  if((digital(nbc)>0)||(digital(nbc)<99))
    {
      nbr= atoi(nbc);
    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output),"nombre de pièces incorrecte");
  }

  FILE *f;
  f=fopen("materiel_technicien.txt","a+");

  if(f!=NULL)
  {
    fprintf(f,"%s %s %s\n",na,ref,nbc);
    gtk_label_set_text(GTK_LABEL(output),"Ajoutée avec succès");
    fclose(f);
  }

}

void on_rest_as_button_clicked (GtkWidget  *objet_graphique,   gpointer  user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *output1;
  GtkWidget *output2;
  input1 = lookup_widget(objet_graphique,"as_chercher_espace_entry");
  input2 = lookup_widget(objet_graphique,"as_etat_espace_combobox");
  input3 = lookup_widget(objet_graphique,"as_temp_espace_entry");
  input4 = lookup_widget(objet_graphique,"as_tele_combobox");
  output1= lookup_widget(objet_graphique,"as_chercher_espace_label");
  output2= lookup_widget(objet_graphique,"as_modifier_espace_label");

  gtk_entry_set_text(GTK_ENTRY(input1),"");
  gtk_combo_box_set_active(GTK_COMBO_BOX(input2),-1);
  gtk_entry_set_text(GTK_ENTRY(input3),"");
  gtk_combo_box_set_active(GTK_COMBO_BOX(input4),-1);
  gtk_label_set_text(GTK_LABEL(output1), "");
  gtk_label_set_text(GTK_LABEL(output2), "");
}

void on_deconnecter_as_button_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *login_window;
  GtkWidget *as_window;

  login_window = create_login_window ();
  gtk_widget_show (login_window);
  as_window=lookup_widget(objet_graphique,"espace_as");
  gtk_widget_hide(as_window);
}

void on_deconnecter_medecin_button_clicked  (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *login_window;
  GtkWidget *med_window;

  login_window = create_login_window ();
  gtk_widget_show (login_window);
  med_window=lookup_widget(objet_graphique,"Espace_medecin");
  gtk_widget_hide(med_window);
}

void on_ajout_mat_med_butt_clicked (GtkWidget *objet_graphique,  gpointer user_data)
{
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *output;

  input1= lookup_widget(objet_graphique,"entry14");
  input2= lookup_widget(objet_graphique,"entry15");
  input3= lookup_widget(objet_graphique,"entry16");
  output= lookup_widget(objet_graphique,"label527");

  char na[20]; char ref[20]; char nbc[10]; int nbr=0;

  strcpy(na, gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(ref, gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(nbc, gtk_entry_get_text(GTK_ENTRY(input3)));

  if((digital(nbc)>0)||(digital(nbc)<99))
    {
      nbr= atoi(nbc);
    }
  else
  {
    gtk_label_set_text(GTK_LABEL(output),"nombre de pièces incorrecte");
  }

  FILE *f;
  f=fopen("materiel_médicale.txt","a+");

  if(f!=NULL)
  {
    gtk_label_set_text(GTK_LABEL(output),"Ajouté avec succès");
    fprintf(f,"%s %s %s\n",na,ref,nbc);
    fclose(f);
  }
}

void
on_map_button_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
  system ("./map/mapview");
}


void
on_cam_button_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window= create_cam_window();
gtk_widget_show(window);
}


void
on_waiting_room_cam_button_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
system ("vlc Videos/hall_camera.mp4");
}


void
on_hall_cam_button_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
system ("vlc Videos/hall_camera.mp4");
}


void
on_front_door_cam_button_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
system ("vlc Videos/Front_camera.mp4");
}


void
on_back_door_cam_button_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
system ("vlc Videos/Front_camera.mp4");
}

gboolean
on_label532_activate_link              (GtkLabel        *label,
                                        gchar           *arg1,
                                        gpointer         user_data)
{

  return FALSE;
}


void on_curve1_show  (GtkWidget  *widget,  gpointer   user_data)
{

}

void on_reset_al_tec_clicked                (GtkWidget       *button,   gpointer         user_data)
{
  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  GtkWidget *input1;
  input1=lookup_widget (button,"textview2");

  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input1));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
}

void on_reset_text_inf_clicked    (GtkWidget       *button,  gpointer         user_data)
{
  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  GtkWidget *input1;
  input1=lookup_widget (button,"textview_envoie_alertes");

  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input1));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
}

void
on_reset_as_txt_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  GtkWidget *input1;
  input1=lookup_widget (button,"as_alerte_text");

  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input1));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);

  GtkWidget *comb;
  comb = lookup_widget(button,"as_type_alerte_combobox");
  gtk_combo_box_set_active(GTK_COMBO_BOX(comb),-1);

}

void
on_reset_sr_as_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkTextBuffer *buffer=0;
  GtkTextIter start, end;
  GtkWidget *input1;
  input1=lookup_widget (button,"textview3");
  buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(input1));
  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
  gtk_text_buffer_delete (buffer,&start,&end);
  gtk_text_buffer_get_end_iter(buffer,&end);
}

gboolean
on_combobox_al_focus                   (GtkWidget       *widget,
                                        GtkDirectionType  direction,
                                        gpointer         user_data)
{

  return FALSE;
}

void
on_combobox_al_move_active             (GtkWidget     *widget,
                                        GtkScrollType    arg1,
                                        gpointer         user_data)
{

}

void
on_quit_cam_button_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *q;
  q=lookup_widget(button,"cam_window");
  gtk_widget_hide(q);
}

void
on_twitter_button_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
  system("firefox https://twitter.com/GeekGodsEsprit");
}


void
on_facebook_button_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
  system("firefox https://www.facebook.com/GeekGods-153464331960728/");

}


void on_youtube_button_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
  system("firefox https://www.youtube.com/watch?v=WpCuo5Q3mPU");
}


void on_publicite_button_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
system("firefox https://youtu.be/Zb8Yo9I-Z4k");
}


void on_authentification_button_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *login;
  login = create_login_window();
  gtk_widget_show (login);

  GtkWidget *acc=lookup_widget(button,"window2");
  gtk_widget_hide(acc);

}


void on_info_geek_button_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
system("eog logo.png");
}



void
on_stat_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
system ("rawya.gp");
}

void
on_afficher_stat_button_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
    GtkWidget *output1;
    GtkWidget *output2;
    GtkWidget *output3;
    GtkWidget *output4;
    GtkWidget *output5;
    GtkWidget *output6;
    GtkWidget *output7;
    GtkWidget *output8;

      output1= lookup_widget(objet_graphique, "nbmed");
      output2= lookup_widget(objet_graphique, "nbinf");
      output3= lookup_widget(objet_graphique, "nbas");
      output4= lookup_widget(objet_graphique, "nbpa");
      output5= lookup_widget(objet_graphique, "nbtec");
      output6= lookup_widget(objet_graphique, "moyas");
      output7= lookup_widget(objet_graphique, "moyinf");
      output8= lookup_widget(objet_graphique, "nbtot");
char outstat1[20]="";
char outstat2[20]="";
char outstat3[20]="";
char outstat4[20]="";
char outstat5[20]="";
char outstat6[20]="";
char outstat7[20]="";
char outstat8[20]="";
int stt1=nombremedecin();
int stt2=nombreinfirmier();
int stt3=nombreas();
int stt4=nombrepa();
int stt5=nombretec();
float stt6=nbpaparinf();
float stt7=nbpaparas();
int stt8=nombretotale();
sprintf(outstat1,"%d",stt1);
sprintf(outstat2,"%d",stt2);
sprintf(outstat3,"%d",stt3);
sprintf(outstat4,"%d",stt4);
sprintf(outstat5,"%d",stt5);
sprintf(outstat6,"%.2f",stt6);
sprintf(outstat7,"%.2f",stt7);
sprintf(outstat8,"%d",stt8);

gtk_label_set_text(GTK_LABEL(output1),outstat1);
gtk_label_set_text(GTK_LABEL(output2),outstat2);
gtk_label_set_text(GTK_LABEL(output3),outstat3);
gtk_label_set_text(GTK_LABEL(output4),outstat4);
gtk_label_set_text(GTK_LABEL(output5),outstat5);
gtk_label_set_text(GTK_LABEL(output6),outstat6);
gtk_label_set_text(GTK_LABEL(output7),outstat7);
gtk_label_set_text(GTK_LABEL(output8),outstat8);



}

void on_button44_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *Admin_window;
  Admin_window=lookup_widget(button,"Admin_window");
  gtk_widget_hide(Admin_window);

  Admin_window = create_Admin_window ();
  gtk_widget_show (Admin_window);
}
