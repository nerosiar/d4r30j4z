#include "lecture_cam.h"


void lecture_camera(FILE *f,came T[])
{
		char filename[20]="cameras.txt";
		char iden[20]; char emp[20]; char inf[20];
		int i=0;
		f=fopen(filename,"r");

			while (fscanf(f,"%s %s %s\n",iden,inf,emp) != EOF )
				 {
				   strcpy(T[i].id, iden);
				   strcpy(T[i].info, inf);
					 strcpy(T[i].emplacement, emp);

				   i++;
				 }
			fclose(f);
	}

	void lecture_bracelet(FILE *f, brac T[])
	{
			char filename[20]="bracelets.txt";
			char iden[20]; char emp[20]; char inf[20];
			int i=0;
			f=fopen(filename,"r");

				while (fscanf(f,"%s %s %s\n",iden,inf,emp) != EOF )
					 {
					   strcpy(T[i].id, iden);
					   strcpy(T[i].info, inf);
						 strcpy(T[i].emplacement, emp);

					   i++;
					 }
				fclose(f);
		}
