#include "lecture_med.h"


void lecture_medecin(FILE *f,medec T[])
{
		char filename[sz]="medecin.txt";
		char ide[sz]; char name[sz]; char famname[sz]; char use[sz]; char pwd[sz];
		char jj[3]; char mm[10]; char aaaa[5]; char mail[50]; char cite[30]; char cont[30];
		char nume[sz];
		int i=0;
		f=fopen(filename,"r");

			while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n",ide,name,famname,use,pwd,jj,mm,aaaa,mail,nume,cite,cont) != EOF )
				 {
					 /*char jourm[sz];
					 strcat(jj,"/");
					 strcpy(jourm,strcat(jj,mm));
					 strcat(jourm,"/");
					 char date_naiss[sz];
					 strcpy(date_naiss,strcat(jourm,aaaa));*/

				   strcpy(T[i].id, ide);
				   strcpy(T[i].nom, name);
					 strcpy(T[i].prenom, famname);
				   strcpy(T[i].username, use);
					 strcpy(T[i].password, pwd);
					 /*strcpy(T[i].date_n, date_naiss);
					 /*strcpy(T[i].jour, jj);
				   strcpy(T[i].mois, mm);
					 strcpy(T[i].anne, aaaa);
				   strcpy(T[i].email,mail);
					 strcpy(T[i].num, nume);
					 strcpy(T[i].ville, cite);
					 strcpy(T[i].rue, cont);*/

				   i++;
				 }
			fclose(f);
	}


void lecture_infirmier(FILE *f,medec T[])
{
	char filename[sz]="infirmier.txt";
	char ide[sz]; char name[sz]; char famname[sz]; char use[sz]; char pwd[sz]; char nume[sz];
	char jj[3]; char mm[10]; char aaaa[5]; char mail[50]; char cite[30]; char cont[30];
	int i=0;
	f=fopen(filename,"r");

		while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n",ide,name,famname,use,pwd,jj,mm,aaaa,mail,nume,cite,cont) != EOF )
			 {
				 strcpy(T[i].id, ide);
				 strcpy(T[i].nom, name);
				 strcpy(T[i].prenom, famname);
				 strcpy(T[i].username, use);
				 strcpy(T[i].password, pwd);

				 i++;
			 }
		fclose(f);
}

void lecture_aide_soignant(FILE *f,medec T[])
{
	char filename[sz]="aide_soignant.txt";
	char ide[sz]; char name[sz]; char famname[sz]; char use[sz]; char pwd[sz]; char nume[sz];
	char jj[3]; char mm[10]; char aaaa[5]; char mail[50]; char cite[30]; char cont[30];
	int i=0;
	f=fopen(filename,"r");

		while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n",ide,name,famname,use,pwd,jj,mm,aaaa,mail,nume,cite,cont) != EOF )
			 {
				 strcpy(T[i].id, ide);
				 strcpy(T[i].nom, name);
				 strcpy(T[i].prenom, famname);
				 strcpy(T[i].username, use);
				 strcpy(T[i].password, pwd);

				 i++;
			 }
		fclose(f);

}

void lecture_technicien(FILE *f,medec T[])
{
	char filename[sz]="technicien.txt";
	char ide[sz]; char name[sz]; char famname[sz]; char use[sz]; char pwd[sz]; char nume[sz];
	char jj[3]; char mm[10]; char aaaa[5]; char mail[50]; char cite[30]; char cont[30];
	int i=0;
	f=fopen(filename,"r");

		while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n",ide,name,famname,use,pwd,jj,mm,aaaa,mail,nume,cite,cont) != EOF )
			 {
				 strcpy(T[i].id, ide);
				 strcpy(T[i].nom, name);
				 strcpy(T[i].prenom, famname);
				 strcpy(T[i].username, use);
				 strcpy(T[i].password, pwd);

				 i++;
			 }
		fclose(f);

}

void lecture_pa(FILE *f,persag T[])
{
	char name[sz]; char famname[sz]; char jj[sz]; char mm[sz]; char aaaa[sz]; char pp[sz]; char tt[sz]; char gg[sz];
	char t_t[sz]; char a_a[sz]; char c_c[sz]; char d_d[sz]; char id[sz];
	f=fopen("personne_agee.txt","r");
	int i=0;
	while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n",id,name,famname,jj,mm,aaaa,pp,tt,gg,t_t,a_a,d_d,c_c) != EOF )
		 {
			 //strcpy(T[i].id, id);
			 strcpy(T[i].nomp, name);
			 strcpy(T[i].prenomp, famname);
			 strcpy(T[i].Daate.jour, jj);
			 strcpy(T[i].Daate.mois, mm);
			 strcpy(T[i].Daate.anne, aaaa);

			 i++;
		 }
	fclose(f);
}
