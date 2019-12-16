#include "stat.h"

int nombreinfirmier()
{
  int i=0;
  infirmier inf;
  FILE* f;
  f=fopen("infirmier.txt","r");

  if (f!=NULL)
   {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(inf.id),inf.username,inf.password,inf.nom,inf.prenom, (inf.Date.jour),
                                        (inf.Date.mois),(inf.Date.anne),inf.email,inf.num,inf.adresse.ville,inf.adresse.rue)!=EOF)
          {
            i++;
          }
          fclose(f);
	}
        return i;
}

int nombremedecin()
{ int i=0;
  medecin med;
  FILE* f;
  f=fopen("medecin.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(med.id),med.username,med.password,med.nom,med.prenom, (med.Date.jour),
                                        (med.Date.mois),(med.Date.anne),med.email,med.num,med.adresse.ville,med.adresse.rue)!=EOF)
          {
          i++;
          }
          fclose(f);
  }
  return i;
}
int nombreas()
{ int i=0;
  aide_soignant as;
  FILE* f;
  f=fopen("aide_soignant.txt","r");

  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(as.id),as.username,as.password,as.nom,as.prenom, (as.Date.jour),
                                        (as.Date.mois),(as.Date.anne),as.email,as.num,as.adresse.ville,as.adresse.rue)!=EOF)
          {
            i++;
          }
          fclose(f);
  }

  return i;
}
int nombretec()
{
    int i=0;
    technicien tech;
    FILE* f;
    f=fopen("technicien.txt","r");

    if (f!=NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(tech.id),tech.username,tech.password,tech.nom,tech.prenom, (tech.Date.jour),
                                          (tech.Date.mois),(tech.Date.anne),tech.email,tech.num,tech.adresse.ville,tech.adresse.rue)!=EOF)
            {
              i++;
            }
            fclose(f);
    }

    return i;


}
int nombrepa()
{
    int i=0;
    p_agee p;
    FILE* f;
    f=fopen("personne_agee.txt","r");

    if (f!=NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",p.id,p.nompa,p.prenompa,p.Date.jour,p.Date.mois,
                                                          p.Date.anne,p.poids,p.taille,p.gs,p.t,p.a,p.d
                                                          ,p.c)!=EOF)
            {
              i++;
            }
            fclose(f);
    }

  return i;
}
float nbpaparinf()
{
  int a,b;
  float c;

  a=nombrepa();
  b=nombreinfirmier();
  c=(a/b);
  return c;
}
float nbpaparas()
{
  int a,b;
  float c;

  a=nombrepa();
  b=nombreas();
  c=(a/b);
  return c;
}

int nombretotale()
{
  int a,b,c,d,res;
  a=nombreinfirmier();
  b=nombreas();
  c=nombretec();
  d=nombremedecin();
  res=a+b+c+d;
  return res;
}

float pctmed()
{
  int a,b;
  float c;

  a=nombremedecin();
  b=nombretotale();
  c=(a/b);
  return c;
}
float pcttech()
{
  int a,b;
  float c;

  a=nombretec();
  b=nombretotale();
  c=(a/b);
  return c;
}
float pctas()
{
  int a,b;
  float c;

  a=nombreas();
  b=nombretotale();
  c=(a/b);
  return c;
}
float pctinf()
{
  int a,b;
  float c;

  a=nombreinfirmier();
  b=nombretotale();
  c=(a/b);
  return c;
}
