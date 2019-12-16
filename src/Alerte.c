#include "Alerte.h"

void remplirtableau(infop *p1, infop *p2, infop *p3, infop *p4, infop *p5, infop *p6, infop *p7, infop *p8, infop *p9, infop *p10,int *i1)
  {
    FILE* f;
    f=fopen("log.txt","r");
    p1->id = 1;
    p2->id = 2;
    p3->id = 3;
    p4->id = 4;
    p5->id = 5;
    p6->id = 6;
    p7->id = 7;
    p8->id = 8;
    p9->id = 9;
    p10->id = 10;
    *i1=0; int i2=0; int i3=0; int i4=0; int i5=0; int i6=0; int i7=0; int i8=0; int i9=0; int i10=0;
    int a0=0; int a1=0; int a2=0; int a3=0; int a4=0; int a5=0; int a6=0; int a7=0;

   if (f!=NULL)
    {
      while((fscanf(f,"%d %d %d %d %d %d %d %d\n",&(a0),&(a1),&(a2),&(a3),&(a4),&(a5),&(a6),&(a7)))!=EOF)
            {
              if (a0 == p1->id)
              {
                p1->presence[*i1]=a1;
                p1->mvt[*i1]=a2;
                p1->temp[*i1]=a3;
                p1->jour[*i1]=a4;
                p1->mois[*i1]=a5;
                p1->anee[*i1]=a6;
                p1->heure[*i1]=a7;
                (*i1)++;
              }

              else if (a0 == p2->id)
              {
                p2->presence[i2]=a1;
                p2->mvt[i2]=a2;
                p2->temp[i2]=a3;
                p2->jour[i2]=a4;
                p2->mois[i2]=a5;
                p2->anee[i2]=a6;
                p2->heure[i2]=a7;
                (i2)++;
              }

              else if (a0 == p3->id)
              {
                p3->presence[i3]=a1;
                p3->mvt[i3]=a2;
                p3->temp[i3]=a3;
                p3->jour[i3]=a4;
                p3->mois[i3]=a5;
                p3->anee[i3]=a6;
                p3->heure[i3]=a7;
                (i3)++;
              }

              else if (a0 == p4->id)
              {
                p4->presence[i4]=a1;
                p4->mvt[i4]=a2;
                p4->temp[i4]=a3;
                p4->jour[i4]=a4;
                p4->mois[i4]=a5;
                p4->anee[i4]=a6;
                p4->heure[i4]=a7;
                (i4)++;
              }

              else if (a0 == p5->id)
              {
                p5->presence[i5]=a1;
                p5->mvt[i5]=a2;
                p5->temp[i5]=a3;
                p5->jour[i5]=a4;
                p5->mois[i5]=a5;
                p5->anee[i5]=a6;
                p5->heure[i5]=a7;
                i5++;
              }

              else if (a0 == p6->id)
              {
                p6->presence[i6]=a1;
                p6->mvt[i6]=a2;
                p6->temp[i6]=a3;
                p6->jour[i6]=a4;
                p6->mois[i6]=a5;
                p6->anee[i6]=a6;
                p6->heure[i6]=a7;
                i6++;
              }

              else if (a0 == p7->id)
              {
                p7->presence[i7]=a1;
                p7->mvt[i7]=a2;
                p7->temp[i7]=a3;
                p7->jour[i7]=a4;
                p7->mois[i7]=a5;
                p7->anee[i7]=a6;
                p7->heure[i7]=a7;
                i7++;
              }

              else if (a0 == p8->id)
              {
                p8->presence[i8]=a1;
                p8->mvt[i8]=a2;
                p8->temp[i8]=a3;
                p8->jour[i8]=a4;
                p8->mois[i8]=a5;
                p8->anee[i8]=a6;
                p8->heure[i8]=a7;
                i8++;
              }

              else if (a0 == p9->id)
              {
                p9->presence[i9]=a1;
                p9->mvt[i9]=a2;
                p9->temp[i9]=a3;
                p9->jour[i9]=a4;
                p9->mois[i9]=a5;
                p9->anee[i9]=a6;
                p9->heure[i9]=a7;
                i9++;
              }

              else if (a0 == p10->id)
              {
                p10->presence[i10]=a1;
                p10->mvt[i10]=a2;
                p10->temp[i10]=a3;
                p10->jour[i10]=a4;
                p10->mois[i10]=a5;
                p10->anee[i10]=a6;
                p10->heure[i10]=a7;
                i10++;
              }

            }
            fclose(f);
        }
  }
void erreurtech(infop *p,int i1)
  {
    int i=0;
    FILE *f;
    f= fopen("alertebracelet.txt","a+");
    if(f!=NULL)
    {
        for (i=0; i<(i1-1);i++)
        {
            if((p->presence[i]<0)||(p->presence[i]>1))
              {
                fprintf(f,"%d %s %d/%d/%d à %d\n",p->id,"Presence",p->jour[i],p->mois[i],p->anee[i],p->heure[i]);
              }

            if((p->mvt[i]<0)||(p->mvt[i]>1))
              {
                fprintf(f,"%d %s %d/%d/%d à %d\n",p->id,"Mouvement",p->jour[i],p->mois[i],p->anee[i],p->heure[i]);
              }

              if((p->temp[i]<33)||(p->temp[i]>40))
                {
                  fprintf(f,"%d %s %d/%d/%d à %d\n",p->id,"Température",p->jour[i],p->mois[i],p->anee[i],p->heure[i]);
                }
        }
      fclose(f);
    }
  }

  void erreurmed(infop *p,int i1)
    {
      int i=0;
      FILE *f;
    f= fopen("alertemedicale.txt","a+");
    int occ=0;
    if (f!=NULL)
    {
    for(i=0;i<(i1);i++)
    {
      if ((p->temp[i]<36)||(p->temp[i]>39))
      {
        fprintf(f,"%d %s %d %d/%d/%d à %d\n",p->id,"Temperature",p->temp[i],p->jour[i],p->mois[i],p->anee[i],p->heure[i]);
      }

      if(p->mvt[i]==0)
        {occ++;
          if(occ>=5)
          {
            fprintf(f,"%d %s %s %d/%d/%d à %d\n",p->id,"Mouvement","Absent",p->jour[i],p->mois[i],p->anee[i],p->heure[i]);
            //occ=0;
          }
        }
      if(p->mvt[i] == 1)
      {occ=0;}
    }
    fclose(f);
  }
    }

int erreurequ()
{
  /*int i3=0;int i1=0;int i2=0;int res=0;
  FILE* f1;
  f1=fopen("infirmier.txt","r");
  FILE* f2;
  f2=fopen("aide_soignant.txt","r");
  FILE* f3;
  f3=fopen("personne_agee.txt","r");
      while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(inf.id),inf.username,inf.password,inf.nom,inf.prenom, (inf.Date.jour),(inf.Date.mois),(inf.Date.anne),inf.email,inf.num,inf.adresse.ville,inf.adresse.rue)!=EOF)
          {i1++;}
          fclose(f1);
      while(fscanf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",(as.id),as.username,as.password,as.nom,as.prenom, (as.Date.jour),(as.Date.mois),(as.Date.anne),as.email,as.num,as.adresse.ville,as.adresse.rue)!=EOF)
          {i2++;}
          fclose(f2);
      while(fscanf(f3,"%s %s %s %s %s %s %s %s %s %s %s %s \n",p.nompa,p.prenompa,p.Date.jour,p.Date.mois,p.Date.anne,p.poids,p.taille,p.gs,p.t,p.a,p.d,p.c)!=EOF)
          {i3++;}
          fclose(f3);
if (i1<(i3/4))
   {res=res+1;}
if (i2<(i3/4))
   {res=res+2;}
return res;*/
}
