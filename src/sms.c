#include "sms.h"


void mailpointage(char abc[])
{
  	char mail[1000]="";

  sprintf(mail,"sendemail -f Maison_de_retraite@gmail.com -t amine.massaabi@esprit.tn -u pointage -m \"%s connecte\" -s smtp.gmail.com:587 -o tls=yes -xu esprit.maisonderetraite@gmail.com -xp kaka1899",abc);
  system(mail);
}


void mailtonew(char email1[])
{
  	char mail[1000]="";
  sprintf(mail,"sendemail -f Maison_de_retraite@gmail.com -t %s -u Bienvenu -m \"Welcome to GeekGods\" -s smtp.gmail.com:587 -o tls=yes -xu esprit.maisonderetraite@gmail.com -xp kaka1899",email1);
  system(mail);
}

void sms(){
char mail[1000]="";
sprintf(mail,"sendemail -f Maison_de_retraite@gmail.com -t 0021697358843@txtlocal.co.uk -u pointage -m \" Medecin present \" -s smtp.gmail.com:587 -o tls=yes -xu esprit.maisonderetraite@gmail.com -xp kaka1899");
  
system(mail);
}
