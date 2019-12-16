#include "add_materiel_data.h"
/*************************ID_Bracelet_INCREMENT_AUTOMATIQUE*****************************/
int auto_incre_id_bracelet()
{
  Bracelet bracelet;
  FILE *f;
  int new_id=0;
  f=fopen("bracelets.txt","r");

  while(fscanf(f,"%s %s %s\n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat)!=EOF)
        {
          //printf("last id is: %s\n",camera.identifiant_camera);
          new_id = atoi(bracelet.identifiant_bracelet);
        }
    fclose(f);

    new_id = new_id +1;
//sprintf(new_id,"5",)
return new_id;
}


/*************************ID_Camera_INCREMENT_AUTOMATIQUE*****************************/


int auto_incre_id_camera()
{
  Camera camera;
  FILE *f;
  int new_id=0;
  f=fopen("cameras.txt","r");

  while(fscanf(f,"%s %s %s\n",camera.identifiant_camera,camera.info,camera.emplacement)!=EOF)
        {
          //printf("last id is: %s\n",camera.identifiant_camera);
          new_id = atoi(camera.identifiant_camera);
        }
    fclose(f);

    new_id = new_id +1;
//sprintf(new_id,"5",)
return new_id;
}
/********ajouter bracelet********/
void ajout_bracelet(Bracelet bracelet) {
  FILE *f;
  f= fopen("bracelets.txt","a+");
  if (f != NULL)
  {
    fprintf(f,"%s %s %s \n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat);
    fclose(f);
  }
}

/********supprmier bracelet********/
void supprimer_bracelet(char identifiant_bracelet[14])
{
  Bracelet bracelet;
  FILE*f;
  FILE*ftemp;

  f=fopen("bracelets.txt","r");
  ftemp=fopen("bracelets.tmp","w");

  while(fscanf(f,"%s %s %s \n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat)!=EOF)
  {
    if(strcmp(identifiant_bracelet,bracelet.identifiant_bracelet)!=0)
    {
      fprintf(ftemp,"%s %s %s \n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat);
    }
  }
  fclose(f);
  fclose(ftemp);

  remove("bracelets.txt");
  rename("bracelets.tmp","bracelets.txt");
}

/********chercher bracelet********/
Bracelet chercher_bracelet(char x[])
{	Bracelet bracelet;
  FILE*f;

  f=fopen("bracelets.txt","r");

  if(f!=NULL) {



    while(fscanf(f,"%s %s %s \n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat)!=EOF)
    {	if (strcmp(x,bracelet.identifiant_bracelet)==0)
      {

        return bracelet;
      }
    }

    fclose(f);
  }
  strcpy(bracelet.identifiant_bracelet,"-1");
  return bracelet;
}

/********modifier bracelet********/
void modifier_bracelet(Bracelet bracelet1)
{
  FILE*f;
  FILE*ftemp;
  Bracelet bracelet;

  f=fopen("bracelets.txt","r");
  ftemp=fopen("bracelets.tmp","w");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s \n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat)!=EOF)
    {
      if(strcmp(bracelet.identifiant_bracelet,bracelet1.identifiant_bracelet)!=0)
      {	fprintf(ftemp,"%s %s %s \n",bracelet.identifiant_bracelet,bracelet.info,bracelet.etat);}
    else{fprintf(ftemp,"%s %s %s \n",bracelet1.identifiant_bracelet,bracelet1.info,bracelet1.etat);}
    }
  fclose(f);
  fclose(ftemp);

  remove("bracelets.txt");
  rename("bracelets.tmp","bracelets.txt");
}
}

/********ajouter camera********/
void ajout_camera(Camera camera)
{
  FILE *f;
  f= fopen("cameras.txt","a+");
  if (f != NULL)
  {
    fprintf(f,"%s %s %s\n",camera.identifiant_camera,camera.info,camera.emplacement);
    fclose(f);
  }
}
/********supprimer camera********/
void supprimer_camera(char identifiant_camera[20])
{
  Camera camera;
  FILE*f;
  FILE*ftemp;

  f=fopen("cameras.txt","a+");
  ftemp=fopen("cameras.tmp","w");

  while(fscanf(f,"%s %s %s\n",camera.identifiant_camera,camera.info,camera.emplacement)!=EOF)
  {
    if(strcmp(identifiant_camera,camera.identifiant_camera)!=0)
    {
      fprintf(ftemp,"%s %s %s\n",camera.identifiant_camera,camera.info,camera.emplacement);
    }
  }
  fclose(f);
  fclose(ftemp);

  remove("cameras.txt");
  rename("cameras.tmp","cameras.txt");
}


/********chercher camera********/
Camera chercher_camera(char x[])
{	Camera camera;
  FILE*f;

  f=fopen("cameras.txt","r");

  if(f!=NULL) {



    while(fscanf(f,"%s %s %s\n",camera.identifiant_camera,camera.info,camera.emplacement)!=EOF)
    {	if (strcmp(x,camera.identifiant_camera)==0)
      {

        return camera;
      }
    }

    fclose(f);
  }
  strcpy(camera.identifiant_camera,"-1");
  return camera;
}

/********modifier camera********/
void modifier_camera(Camera camera)
{
  FILE*f;
  FILE*ftemp;
  Camera camera1;

  f=fopen("cameras.txt","r");
  ftemp=fopen("cameras.tmp","w");
  if(f!=NULL)
  {    while(fscanf(f,"%s %s %s\n",camera1.identifiant_camera,camera1.info,camera1.emplacement)!=EOF)
    {
      if(strcmp(camera.identifiant_camera,camera1.identifiant_camera)!=0)
      {	fprintf(ftemp,"%s %s %s\n",camera1.identifiant_camera,camera1.info,camera1.emplacement);
    }
    else{
      fprintf(ftemp,"%s %s %s\n",camera.identifiant_camera,camera.info,camera.emplacement);
    }
  }
  fclose(f);
  fclose(ftemp);
  remove("cameras.txt");
  rename("cameras.tmp","cameras.txt");
}
}
