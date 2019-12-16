#include "personnel.h"
#include "Login.h"


/*************************Medecin************************/
/*********************************************************/
/*********************************AJOUTER**************************************/

void ajouter_m(medecin med)
{
  FILE *f;

  f=fopen("medecin.txt","a+");

  if (f != NULL)
  {
    fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                        med.Date.mois,med.Date.anne,med.email,med.num,med.adresse.ville,med.adresse.rue);
    fclose(f);
  }
  ajouterlogin(med.username,med.password,2);
}


/*********************************SUPPRIMER************************************/

void supprimer(char cin[sz])
{
  medecin med;
  FILE *f;
  FILE *f_tmp;

  f=fopen("medecin.txt","a+");
	f_tmp=fopen("medecin.tmp","w");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                      (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue)!=EOF)
        {
          if (strcmp(cin,med.id)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                                (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue);
          }
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("medecin.txt");
      	rename("medecin.tmp","medecin.txt");
}

/*********************************MODIFIER*************************************/

void modifier(medecin m)
{
  FILE* f;
  FILE* f_tmp;
  medecin med;

  f=fopen("medecin.txt","r");
  f_tmp=fopen("medecin.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                        (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue)!=EOF)
          {
                if (strcmp(m.id,med.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                                        (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(m.id),m.username,m.password,m.nom,med.prenom, (m.Date.jour),
                                                        (m.Date.mois),(m.Date.anne),m.email,m.num,m.adresse.ville,m.adresse.rue);
                  }

          }
          fclose(f);
          fclose(f_tmp);

          remove("medecin.txt");
          rename("medecin.tmp","medecin.txt");
  }
}

/*********************************CHERCHER*************************************/

medecin chercher(char x[])
{
  medecin med;
  FILE* f;
  f=fopen("medecin.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                        (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue)!=EOF)
          {
            if (strcmp(x,med.id)==0)
              {
                return med;
              }
          }
          fclose(f);
  }

  strcpy(med.id, "-1");
  return med;
}

/*************************ID_INCREMENT_AUTOMATIQUE*****************************/

int auto_incre_id()
{
  medecin med;
  FILE *f;
  int new_id=0;
  char new[10];
  f=fopen("medecin.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                      (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue)!=EOF)
        {
          strcpy(new,med.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}


/*******************************************Infirmier**********************************/
/**************************************************************************************/

/*********************************ajouter_infirmier**************************/


void ajouter_i(infirmier infir)
{
FILE *f ;
f=fopen("infirmier.txt","a+");
if (f!= NULL){

fprintf (f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",infir.id , infir.username , infir.password ,
                                                    infir.nom ,infir.prenom,infir.Date.jour,infir.Date.mois,
                                                    infir.Date.anne,infir.email,infir.num,infir.adresse.ville,
                                                    infir.adresse.rue);
fclose(f);
}
  ajouterlogin(infir.username,infir.password,3);
}

/**************************supprimer******************************/



void supprimer_i(char cin[sz])
{
  infirmier inf;
  FILE *f;
  FILE *f_tmp;

  f=fopen("infirmier.txt","a+");
	f_tmp=fopen("infirmier.tmp","w");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(inf.id),inf.username,inf.password,inf.nom,inf.prenom, (inf.Date.jour),
                                      (inf.Date.mois),(inf.Date.anne),inf.email,inf.num,inf.adresse.ville,inf.adresse.rue)!=EOF)
        {
          if (strcmp(cin,inf.id)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(inf.id),inf.username,inf.password,inf.nom,inf.prenom, (inf.Date.jour),
                                                (inf.Date.mois),(inf.Date.anne),inf.email,inf.num,inf.adresse.ville,inf.adresse.rue);
          }
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("infirmier.txt");
      	rename("infirmier.tmp","infirmier.txt");
}

/******************Chercher infirmier**************/

infirmier chercher_i(char x[])
{
  infirmier inf;
  FILE* f;
  f=fopen("infirmier.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(inf.id),inf.username,inf.password,inf.nom,inf.prenom, (inf.Date.jour),
                                        (inf.Date.mois),(inf.Date.anne),inf.email,inf.num,inf.adresse.ville,inf.adresse.rue)!=EOF)
          {
            if (strcmp(x,inf.id)==0)
              {
                return inf;
              }
          }
          fclose(f);
  }

  strcpy(inf.id, "-1");
  return inf;
}


/**************************************modifier**********************************/

void modifier_i(infirmier infir1)
{
  FILE* f;
  FILE* f_tmp;
  infirmier infir;

  f=fopen("infirmier.txt","r");
  f_tmp=fopen("infirmier.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",infir.id , infir.username , infir.password ,
                                                        infir.nom ,infir.prenom,infir.Date.jour,infir.Date.mois,
                                                        infir.Date.anne,infir.email,infir.num,infir.adresse.ville,
                                                        infir.adresse.rue)!=EOF)
          {
                if (strcmp(infir1.id,infir.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",infir.id , infir.username , infir.password ,
                                                                        infir.nom ,infir.prenom,infir.Date.jour,infir.Date.mois,
                                                                        infir.Date.anne,infir.email,infir.num,infir.adresse.ville,
                                                                        infir.adresse.rue);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",infir1.id , infir1.username , infir1.password,
                                                                        infir1.nom ,infir1.prenom,infir1.Date.jour,infir1.Date.mois,
                                                                        infir1.Date.anne,infir1.email,infir1.num,infir1.adresse.ville,
                                                                        infir1.adresse.rue);
                  }
          }
          fclose(f);
          fclose(f_tmp);

          remove("infirmier.txt");
          rename("infirmier.tmp","infirmier.txt");
  }
}

int auto_incre_id_inf()
{
  infirmier inf;
  FILE *f;
  int new_id=0;
  char new[10];
  f=fopen("infirmier.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(inf.id),inf.username,inf.password,inf.nom,inf.prenom, (inf.Date.jour),
                                      (inf.Date.mois),(inf.Date.anne),inf.email,inf.num,inf.adresse.ville,inf.adresse.rue)!=EOF)
        {
          strcpy(new,inf.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}



/*******************************************Technicien**********************************/
/**************************************************************************************/

/*********************************ajouter**************************/


void ajouter_tec(technicien tec)
{
FILE *f ;
f=fopen("technicien.txt","a+");
if (f!= NULL){

fprintf (f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",tec.id , tec.username , tec.password ,
                                                    tec.nom ,tec.prenom,tec.Date.jour,tec.Date.mois,
                                                    tec.Date.anne,tec.email,tec.num,tec.adresse.ville,
                                                    tec.adresse.rue);
fclose(f);
}
ajouterlogin(tec.username,tec.password,4);

}

/**************************supprimer******************************/



void supprimer_tec(char CIN[]){
FILE *f ;
FILE *f_tmp;
technicien tec;
f=fopen("technicien.txt","a+");
f_tmp=fopen("technicien.tmp","w");

while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",tec.id , tec.username , tec.password ,
                                                    tec.nom ,tec.prenom,tec.Date.jour,tec.Date.mois,
                                                    tec.Date.anne,tec.email,tec.num,tec.adresse.ville,
                                                    tec.adresse.rue)!=EOF){

 if(strcmp(CIN,tec.id)!=0){
fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s \n",tec.id , tec.username , tec.password ,
                                                    tec.nom ,tec.prenom,tec.Date.jour,tec.Date.mois,
                                                    tec.Date.anne,tec.email,tec.num,tec.adresse.ville,
                                                    tec.adresse.rue);
}



}

fclose(f);
remove("technicien.txt");
rename("technicien.tmp","technicien.txt");

}


/**************************************modifier**********************************/

void modifier_tec(technicien tec1)
{
  FILE* f;
  FILE* f_tmp;
  technicien tec;

  f=fopen("technicien.txt","r");
  f_tmp=fopen("technicien.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",tec.id , tec.username , tec.password ,
                                                        tec.nom ,tec.prenom,tec.Date.jour,tec.Date.mois,
                                                        tec.Date.anne,tec.email,tec.num,tec.adresse.ville,
                                                        tec.adresse.rue)!=EOF)
          {
                if (strcmp(tec1.id,tec.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",tec.id , tec.username , tec.password ,
                                                                        tec.nom ,tec.prenom,tec.Date.jour,tec.Date.mois,
                                                                        tec.Date.anne,tec.email,tec.num,tec.adresse.ville,
                                                                        tec.adresse.rue);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",tec1.id , tec1.username , tec1.password,
                                                                        tec1.nom ,tec1.prenom,tec1.Date.jour,tec1.Date.mois,
                                                                        tec1.Date.anne,tec1.email,tec1.num,tec1.adresse.ville,
                                                                        tec1.adresse.rue);
                  }
          }
          fclose(f);
          fclose(f_tmp);

          remove("technicien.txt");
          rename("technicien.tmp","technicien.txt");
  }
}
/*************Chercher tec*************/
technicien chercher_tec(char x[])
{
  technicien tech;
  FILE* f;
  f=fopen("technicien.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(tech.id),tech.username,tech.password,tech.nom,tech.prenom, (tech.Date.jour),
                                        (tech.Date.mois),(tech.Date.anne),tech.email,tech.num,tech.adresse.ville,tech.adresse.rue)!=EOF)
          {
            if (strcmp(x,tech.id)==0)
              {
                return tech;
              }
          }
          fclose(f);
  }

  strcpy(tech.id, "-1");
  return tech;
}

/**********Auto_increment tec id******/
int auto_incre_id_tec()
{
  technicien tec;
  FILE *f;
  int new_id=0;
  char new[10];
  f=fopen("technicien.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(tec.id),tec.username,tec.password,tec.nom,tec.prenom, (tec.Date.jour),
                                      (tec.Date.mois),(tec.Date.anne),tec.email,tec.num,tec.adresse.ville,tec.adresse.rue)!=EOF)
        {
          strcpy(new,tec.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}


/*******************************************Aide_soignat**********************************/
/**************************************************************************************/

/*********************************ajouter**************************/


void ajouter_as(aide_soignant as)
{
FILE *f ;
f=fopen("aide_soignant.txt","a+");
if (f!= NULL){

fprintf (f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",as.id , as.username , as.password ,
                                                    as.nom ,as.prenom,as.Date.jour,as.Date.mois,
                                                    as.Date.anne,as.email,as.num,as.adresse.ville,
                                                    as.adresse.rue);
fclose(f);
}
ajouterlogin(as.username,as.password,5);

}

/**************************supprimer******************************/



void supprimer_as(char cin[sz])
{
  aide_soignant as;
  FILE *f;
  FILE *f_tmp;

  f=fopen("aide_soignant.txt","a+");
	f_tmp=fopen("aide_soignant.tmp","w");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(as.id),as.username,as.password,as.nom,as.prenom, (as.Date.jour),
                                      (as.Date.mois),(as.Date.anne),as.email,as.num,as.adresse.ville,as.adresse.rue)!=EOF)
        {
          if (strcmp(cin,as.id)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(as.id),as.username,as.password,as.nom,as.prenom, (as.Date.jour),
                                                (as.Date.mois),(as.Date.anne),as.email,as.num,as.adresse.ville,as.adresse.rue);
          }
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("aide_soignant.txt");
      	rename("aide_soignant.tmp","aide_soignant.txt");
}

/**************************************modifier**********************************/

void modifier_as(aide_soignant as1)
{
  FILE* f;
  FILE* f_tmp;
  aide_soignant as;

  f=fopen("aide_soignant.txt","r");
  f_tmp=fopen("aide_soignant.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",as.id , as.username , as.password ,
                                                        as.nom ,as.prenom,as.Date.jour,as.Date.mois,
                                                        as.Date.anne,as.email,as.num,as.adresse.ville,
                                                        as.adresse.rue)!=EOF)
          {
                if (strcmp(as1.id,as.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",as.id , as.username , as.password ,
                                                                        as.nom ,as.prenom,as.Date.jour,as.Date.mois,
                                                                        as.Date.anne,as.email,as.num,as.adresse.ville,
                                                                        as.adresse.rue);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s\n",as1.id , as1.username , as1.password,
                                                                        as1.nom ,as1.prenom,as1.Date.jour,as1.Date.mois,
                                                                        as1.Date.anne,as1.email,as1.num,as1.adresse.ville,
                                                                        as1.adresse.rue);
                  }
          }
          fclose(f);
          fclose(f_tmp);

          remove("aide_soignant.txt");
          rename("aide_soignant.tmp","aide_soignant.txt");
  }
}
/************chercher aide_soignant*************/

aide_soignant chercher_as(char x[])
{
  aide_soignant as;
  FILE* f;
  f=fopen("aide_soignant.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(as.id),as.username,as.password,as.nom,as.prenom, (as.Date.jour),
                                        (as.Date.mois),(as.Date.anne),as.email,as.num,as.adresse.ville,as.adresse.rue)!=EOF)
          {
            if (strcmp(x,as.id)==0)
              {
                return as;
              }
          }
          fclose(f);
  }

  strcpy(as.id, "-1");
  return as;
}
/****************Auto_inc aide_soignant*********/
int auto_incre_id_as()
{
  aide_soignant as;
  FILE *f;
  int new_id=0;
  char new[10];
  f=fopen("aide_soignant.txt","r+");

  while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(as.id),as.username,as.password,as.nom,as.prenom, (as.Date.jour),
                                      (as.Date.mois),(as.Date.anne),as.email,as.num,as.adresse.ville,as.adresse.rue)!=EOF)
        {
          strcpy(new,as.id);
        }
    fclose(f);
    new_id = atoi(new);
    new_id = new_id +1;
return new_id;
}

/*************PErsonne agée*****/
void ajouter_pa(p_agee p)
{
  FILE *f ;
  f=fopen("personne_agee.txt","a+");
  if (f!= NULL){

  fprintf (f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.id,p.nompa,p.prenompa,p.Date.jour,p.Date.mois,
                                                      p.Date.anne,p.poids,p.taille,p.gs,p.t,p.a,p.d
                                                      ,p.c);
  fclose(f);
  }
}

/****Supp***/
void supprimer_pa(char cin[]);

p_agee chercher_pa(char x[])
{
  p_agee p;
  FILE* f;
  f=fopen("personne_agee.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",p.id,p.nompa,p.prenompa,p.Date.jour,p.Date.mois,
                                                        p.Date.anne,p.poids,p.taille,p.gs,p.t,p.a,p.d
                                                        ,p.c)!=EOF)
          {
            if (strcmp(x, p.id)==0)
              {
                return p;
              }
          }
          fclose(f);
  }

  strcpy( p.id, "-1");
  return  p;
}
void modifier_pa(p_agee p1)
{
  FILE* f;
  FILE* f_tmp;
  p_agee p;

  f=fopen("personne_agee.txt","r");
  f_tmp=fopen("personne_agee.tmp","w");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",p.id,p.nompa,p.prenompa,p.Date.jour,p.Date.mois,
                                                        p.Date.anne,p.poids,p.taille,p.gs,p.t,p.a,p.d
                                                        ,p.c)!=EOF)
          {
                if (strcmp(p1.id,p.id)!=0)
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",p.id,p.nompa,p.prenompa,p.Date.jour,p.Date.mois,
                                                                        p.Date.anne,p.poids,p.taille,p.gs,p.t,p.a,p.d
                                                                        ,p.c);
                  }
                else
                  {
                    fprintf(f_tmp,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",p1.id,p1.nompa,p1.prenompa,p1.Date.jour,p1.Date.mois,
                                                                        p1.Date.anne,p1.poids,p1.taille,p1.gs,p1.t,p1.a,p1.d
                                                                        ,p1.c);
                  }
          }
          fclose(f);
          fclose(f_tmp);

          remove("personne_agee.txt");
          rename("personne_agee.tmp","personne_agee.txt");
  }

}

int auto_incre_id_pa();

void ajout_espace(Espace e) {
  FILE *f;
  f= fopen("espaces.txt","a+");
  if (f != NULL)
  {
    fprintf(f,"%s %s %s %s \n",e.nom,e.etat,e.temp,e.tele);
    fclose(f);
  }
}

Espace chercher_espace(char x[])
{	Espace e;
  FILE*f;

  f=fopen("espaces.txt","r");

  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s\n",e.nom,e.etat,e.temp,e.tele)!=EOF)
    {
      if (strcmp(x,e.nom)==0)
        {
        return e;
        }
    }
  }
  strcpy(e.nom, "-1");
  return e;
}


void modifier_espace(Espace e1)
{
  FILE*f;
  FILE*ftemp;
  Espace e;

  f=fopen("espaces.txt","r");
  ftemp=fopen("espaces.tmp","w");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s\n",e.nom,e.etat,e.temp,e.tele)!=EOF)
    {
      if(strcmp(e.nom,e1.nom)!=0)
      {
        fprintf(ftemp,"%s %s %s %s\n",e.nom,e.etat,e.temp,e.tele);
      }
      else
      {
        fprintf(ftemp,"%s %s %s %s\n",e.nom,e1.etat,e1.temp,e1.tele);
      }
    }
  fclose(f);
  fclose(ftemp);

  remove("espaces.txt");
  rename("espaces.tmp","espaces.txt");
}
}


char *get_text_of_textview(GtkWidget *text_view) {
    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer((GtkTextView *)text_view);
    gchar *text;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    return text;
}
