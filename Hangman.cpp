#include <iostream>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<conio.h>
using namespace std;
typedef struct CONCURENT{char utilizator[100];
                         char parola[50];
                         int scor; };

char a[1000][50],indiciu[1000][50],cuvant[50],ind[50],introdus[50],sir[255];
int scor,numarUtilizatori,pozitieClasament;
char utilizator[100];
CONCURENT highscore[1000];

void citire()
{
    ifstream f("date.in");
    while(f.getline(highscore[numarUtilizatori].utilizator,100)&&f.getline(highscore[numarUtilizatori].parola,50)&&f>>highscore[numarUtilizatori].scor)
           {numarUtilizatori++;f.get();}
f.close();
}

void afisareScoruriConsola()
{
    int i;
    system("CLS");
     cout<<"##### SPANZURATOAREA #####"<<endl;
    cout<<"TOP SCOR"<<endl;
    for(i=0;i<numarUtilizatori;i++)
    {
        cout<<highscore[i].utilizator;
        for(int j=strlen(highscore[i].utilizator);j<30;j++)
            cout<<' ';
        cout<<highscore[i].scor<<endl;
    }
cout<<"1-Inapoi";
char x=' ';
x=_getch();
while(x!='1')
  x=_getch();
}

void afisareScoruri()
{

    ofstream g("date.in");
    int i;
    for(i=0;i<numarUtilizatori;i++)
    {
        g<<highscore[i].utilizator<<endl;
        g<<highscore[i].parola<<endl;
        g<<highscore[i].scor<<endl;
    }
g.close();
}


void sortareScoruri()
{
    int i=0;
    CONCURENT aux;
    while(i<numarUtilizatori)
    if(highscore[i].scor<highscore[i+1].scor)
       {
           aux=highscore[i];
           highscore[i]=highscore[i+1];
           highscore[i+1]=aux;
           i--;
           if(i==-1)
              i=0;
       }
     else i++;
}


char logare()
{
    char parola[50],x=' ';
logare:
system("CLS");
  cout<<"##### SPANZURATOAREA #####"<<endl<<"Logare"<<endl;
 cout<<"Doriti sa va logati?"<<endl<<"1-Da"<<endl<<"2-Inapoi"<<endl;
x=_getch();
while(x!='1'&&x!='2')
x=_getch();
if(x=='1')
 {pozitieClasament=-1;
 system("CLS");
  cout<<"##### SPANZURATOAREA #####"<<endl<<"Logare"<<endl;
 cout<<"Introduceti numele de utilizator"<<endl;
    cin>>utilizator;
    for(int i=0;i<numarUtilizatori;i++)
         if(strcmp(utilizator,highscore[i].utilizator)==0)
              pozitieClasament=i;
if(pozitieClasament==-1)
{
    cout<<"Utilizator neinregistrat";
    Sleep(1500);
    goto logare;
}
parola:
system("CLS");
cout<<"##### SPANZURATOAREA #####"<<endl<<"Logare"<<endl;
cout<<"Introduceti parola"<<endl;
cin>>parola;
if(strcmp(parola,highscore[pozitieClasament].parola)!=0)
     {
         cout<<"Parola incorecta"<<endl;
         Sleep(1500);
         goto parola;
     }}
return x;
}


char inregistrare()
{
    char parola1[50],parola2[50],x=' ';
    int ok;
inregistrare:
 ok=1;
 system("CLS");
  cout<<"##### SPANZURATOAREA #####"<<endl<<"Inregistrare"<<endl;
 cout<<"Doriti sa va inregistrati?"<<endl<<"1-Da"<<endl<<"2-Inapoi"<<endl;
x=_getch();
while(x!='1'&&x!='2')
x=_getch();
if(x=='1')
{system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl<<"INREGISTRARE"<<endl<<endl;
 cout<<"Introduceti numele de utilizator"<<endl;
    cin>>utilizator;
          for(int i=0;i<numarUtilizatori;i++)
           if(strcmp(utilizator,highscore[i].utilizator)==0)
              ok=-1;
           if(ok==-1)
             {cout<<"Concurent inregistrat"<<endl;
              Sleep(1500);
              goto inregistrare;
             }

 cout<<"Introduceti parola"<<endl;
 cin>>parola1;
 cout<<"Comfirmati parola"<<endl;
 cin>>parola2;
 if(strcmp(parola1,parola2)!=0)
    {
      cout<<"Confirmare esuata"<<endl;
      Sleep(1500);
      system("CLS");
      goto inregistrare;
    }
pozitieClasament=numarUtilizatori;
strcpy(highscore[numarUtilizatori].utilizator,utilizator);
strcpy(highscore[numarUtilizatori].parola,parola1);
highscore[numarUtilizatori++].scor=0;}
return x;
}


void afisare(int k,char cuvant[],char indiciu[],char solutie[],char introdus[])
{int i;
if(k==0)
{   system("CLS");
    cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |                |"<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" |                          "<<"Cuvantul: "<<cuvant<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     if(indiciu[0]!=NULL)
     cout<<" |                          "<<"Indiciu: "<<indiciu<<endl;
else cout<<" | "<<endl;
     cout<<"_|_                         "<<"Introdus: "<<introdus<<endl;
}
else
if(k==1)
 {   system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |            ____|____  "<<endl;
     cout<<" |           /  @   @  \\ "<<endl;
     cout<<" |           |    &    | "<<endl;
     cout<<" |           |   ___   | "<<endl;
     cout<<" |           \\_________/ "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
     cout<<" |                          "<<"Cuvantul: "<<cuvant<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
      if(indiciu[0]!=NULL)
     cout<<" |                          "<<"Indiciu: "<<indiciu<<endl;
else cout<<" | "<<endl;
      cout<<"_|_                         "<<"Introdus: "<<introdus<<endl;
 }
 else if(k==2)
         {system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |            ____|____  "<<endl;
     cout<<" |           /  @   @  \\ "<<endl;
     cout<<" |           |    &    | "<<endl;
     cout<<" |           |   ___   | "<<endl;
     cout<<" |           \\_________/ "<<endl;
     cout<<" |                |"<<endl;
     cout<<" |                |"<<endl;
     cout<<" |                |"<<endl;
     cout<<" |                |"<<endl;
     cout<<" |                | "<<endl;
     cout<<" |                          "<<"Cuvantul: "<<cuvant<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
      if(indiciu[0]!=NULL)
     cout<<" |                          "<<"Indiciu: "<<indiciu<<endl;
else cout<<" | "<<endl;
     cout<<"_|_                         "<<"Introdus: "<<introdus<<endl;
         }
else if(k==3)
      {system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |            ____|____  "<<endl;
     cout<<" |           /  @   @  \\ "<<endl;
     cout<<" |           |    &    | "<<endl;
     cout<<" |           |   ___   | "<<endl;
     cout<<" |           \\_________/ "<<endl;
     cout<<" |                |"<<endl;
     cout<<" |               /|"<<endl;
     cout<<" |              / |"<<endl;
     cout<<" |             /  |"<<endl;
     cout<<" |                | "<<endl;
     cout<<" |                          "<<"Cuvantul: "<<cuvant<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
      if(indiciu[0]!=NULL)
     cout<<" |                          "<<"Indiciu: "<<indiciu<<endl;
else cout<<" | "<<endl;
     cout<<"_|_                         "<<"Introdus: "<<introdus<<endl;

      }
else if(k==4)
{system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |            ____|____  "<<endl;
     cout<<" |           /  @   @  \\ "<<endl;
     cout<<" |           |    &    | "<<endl;
     cout<<" |           |   ___   | "<<endl;
     cout<<" |           \\_________/ "<<endl;
     cout<<" |                | "<<endl;
     cout<<" |               /|\\ "<<endl;
     cout<<" |              / | \\ "<<endl;
     cout<<" |             /  |  \\ "<<endl;
     cout<<" |                |    "<<endl;
     cout<<" |                          "<<"Cuvantul: "<<cuvant<<endl;
     cout<<" | "<<endl;
     cout<<" | "<<endl;
      if(indiciu[0]!=NULL)
     cout<<" |                          "<<"Indiciu: "<<indiciu<<endl;
else cout<<" | "<<endl;
     cout<<"_|_                         "<<"Introdus: "<<introdus<<endl;

}
else if(k==5)
{system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |            ____|____  "<<endl;
     cout<<" |           /  @   @  \\ "<<endl;
     cout<<" |           |    &    | "<<endl;
     cout<<" |           |   ___   | "<<endl;
     cout<<" |           \\_________/ "<<endl;
     cout<<" |                | "<<endl;
     cout<<" |               /|\\ "<<endl;
     cout<<" |              / | \\ "<<endl;
     cout<<" |             /  |  \\ "<<endl;
     cout<<" |                |    "<<endl;
     cout<<" |               /          "<<"Cuvantul: "<<cuvant<<endl;
     cout<<" |              /"<<endl;
     cout<<" |            _/"<<endl;
      if(indiciu[0]!=NULL)
     cout<<" |                          "<<"Indiciu: "<<indiciu<<endl;
else cout<<" | "<<endl;
     cout<<"_|_                         "<<"Introdus: "<<introdus<<endl;
      }
else if(k==6)
{system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
     cout<<"  ________________                "<<"Scor: "<<scor<<endl;
     cout<<" |            ____|____  "<<endl;
     cout<<" |           /  @   @  \\ "<<endl;
     cout<<" |           |    &    | "<<endl;
     cout<<" |           |   ___   | "<<endl;
     cout<<" |           \\_________/ "<<endl;
     cout<<" |                | "<<endl;
     cout<<" |               /|\\ "<<endl;
     cout<<" |              / | \\ "<<endl;
     cout<<" |             /  |  \\ "<<endl;
     cout<<" |                |    "<<endl;
     cout<<" |               / \\ "<<endl;
     cout<<" |              /   \\ "<<endl;
     cout<<" |            _/     \\_ "<<endl;
     cout<<" |                          "<<"Cuvantul este: "<<solutie<<endl;
     cout<<"_|_                         "<<"Introdus: "<<introdus<<endl<<endl;
     cout<<"##### GAME OVER #####"<<endl;

}
}


void resurse(char a[1000][50],char indiciu[1000][50])
{int i;
strcpy(a[0],"maimuta");
strcpy(a[1],"antilopa");
strcpy(a[2],"pisica");
strcpy(a[3],"tigru");
strcpy(a[4],"vulpe");
strcpy(a[5],"elefant");
strcpy(a[6],"hipopotam");
strcpy(a[7],"cerb");
strcpy(a[8],"ghepard");
strcpy(a[9],"hiena");
strcpy(a[10],"leopard");
strcpy(a[11],"camila");
strcpy(a[12],"sacal");
strcpy(a[13],"raton");
strcpy(a[14],"mistret");
strcpy(a[15],"bursuc");
strcpy(a[16],"nevastuica");
strcpy(a[17],"capra");
strcpy(a[18],"zebra");
strcpy(a[19],"lemur");
strcpy(a[20],"girafa");
strcpy(a[21],"cartita");
strcpy(a[22],"cangur");
strcpy(a[23],"rinocer");
strcpy(a[24],"dihor");
for(i=0;i<=24;i++)
    strcpy(indiciu[i],"animal");
strcpy(a[25],"cioara");
strcpy(a[26],"graur");
strcpy(a[27],"corb");
strcpy(a[28],"vrabie");
strcpy(a[29],"pitigoi");
strcpy(a[30],"privighetoare");
strcpy(a[31],"sturz");
strcpy(a[32],"mierla");
strcpy(a[33],"randunica");
strcpy(a[34],"ciocarlie");
strcpy(a[35],"ciocanitoare");
strcpy(a[36],"pescarus");
strcpy(a[37],"nagat");
strcpy(a[38],"dropie");
strcpy(a[39],"cocor");
strcpy(a[40],"fazan");
strcpy(a[41],"soim");
strcpy(a[42],"vultur");
strcpy(a[43],"acvila");
strcpy(a[44],"pelican");
strcpy(a[45],"lebada");
strcpy(a[46],"cormoran");
strcpy(a[47],"gaina");
for(i=25;i<=47;i++)
    strcpy(indiciu[i],"pasare");
strcpy(a[48],"albina");
strcpy(a[49],"buburuza");
strcpy(a[50],"calugarita");
strcpy(a[51],"carabus");
strcpy(a[52],"furnica");
strcpy(a[53],"lacusta");
strcpy(a[54],"libelula");
strcpy(a[55],"paianjen");
strcpy(a[56],"plosnita");
strcpy(a[57],"tantar");
strcpy(a[58],"termite");
strcpy(a[59],"molie");
strcpy(a[60],"cosas");
strcpy(a[61],"calugarita");
strcpy(a[62],"urechelnita");
strcpy(a[63],"fluture");
strcpy(a[64],"omida");
strcpy(a[65],"musca");
strcpy(a[66],"licurici");
strcpy(a[67],"scarabeu");
strcpy(a[68],"viespie");
strcpy(a[69],"bondar");
strcpy(a[70],"greiere");
for(i=48;i<=70;i++)
    strcpy(indiciu[i],"insecta");
strcpy(a[71],"testoasa");
strcpy(a[72],"sarpe");
strcpy(a[73],"iguana");
strcpy(a[74],"salamandra");
strcpy(a[75],"crocodil");
strcpy(a[76],"soparla");
strcpy(a[77],"cameleon");
strcpy(a[78],"guster");
strcpy(a[79],"aligator");
strcpy(a[80],"varan");
for(i=71;i<=80;i++)
   strcpy(indiciu[i],"reptila");
strcpy(a[81],"bibn");
strcpy(a[82],"lostrita");
strcpy(a[83],"caras");
strcpy(a[84],"crap");
strcpy(a[85],"ghibort");
strcpy(a[86],"oblete");
strcpy(a[87],"pastrav");
strcpy(a[88],"platica");
strcpy(a[89],"salau");
strcpy(a[90],"scrumbie");
strcpy(a[91],"somn");
strcpy(a[92],"stiuca");
strcpy(a[93],"fitofag");
strcpy(a[94],"rosioara");
strcpy(a[95],"tipar");
strcpy(a[96],"morun");
strcpy(a[97],"nisetru");
strcpy(a[98],"macrou");
strcpy(a[99],"cega");
for(i=81;i<=99;i++)
    strcpy(indiciu[i],"peste");
strcpy(a[100],"cartita");
strcpy(a[101],"popandau");
strcpy(a[102],"hamster");
strcpy(a[103],"sobolan");
strcpy(a[104],"soarece");
strcpy(a[105],"veverita");
for(i=100;i<=105;i++)
   strcpy(indiciu[i],"rozatoare");

}


int main()
{
int k=100;int ok=1;strcpy(introdus,"ana");
char x='0';
srand(time(0));
resurse(a,indiciu);
citire();
 inceput:
 system("CLS");
 cout<<"##### SPANZURATOAREA #####"<<endl;
cout<<"1-Inregistrare"<<endl<<"2-Logare"<<endl;
x=_getch();
while(x!='1'&&x!='2')
      x=_getch();
if(x=='1')
   {x=inregistrare();if(x=='2') goto inceput;}
if(x=='2')
{x=logare();if(x=='2') goto inceput;}

while(x!='4'&&ok==1)
{  meniu: ok=1;
    system("CLS");
    cout<<"##### SPANZURATOAREA #####"<<endl;
    cout<<"1-Joc nou"<<endl<<"2-Instructiuni"<<endl<<"3-Top scoruri"<<endl<<"4-Iesire";
    x=_getch();
    while(x!='1'&&x!='2'&&x!='3'&&x!='4')
      x=_getch();
    if(x=='1')
       {   system("CLS");
           cout<<"##### SPANZURATOAREA #####"<<endl;
           cout<<"1-Incepator\n"<<"2-Experimentat\n";
           x=_getch();
           while(x!='1'&&x!='2')
           x=_getch();
           scor=0;
   start:  int val=rand()%106;
           if(x=='1')
           strcpy(ind,indiciu[val]);
           else ind[0]=NULL;
           strcpy(cuvant,a[val]);
           int p=0;
           for(int i=0;i<strlen(introdus);i++)
               introdus[i]=' ';
           int n=strlen(cuvant);
           for(int i=1;i<n-1;i++)
               if(cuvant[i]!=cuvant[0]&&cuvant[i]!=cuvant[n-1])
                  cuvant[i]='-';
           introdus[p++]=cuvant[0];
           introdus[p++]=',';
           introdus[p++]=cuvant[n-1];
           int k=0;
           while(k<7&&strcmp(cuvant,a[val])!=0)
                 {
                   afisare(k,cuvant,ind,a[val],introdus);
                   x=_getch();
                  while(!isalpha(x)||strchr(introdus,x))
                         x=_getch();
                   introdus[p++]=',';
                   introdus[p++]=x;
                   if(strchr(a[val],x))
                     {for(int i=1;i<=n;i++)
                       if(cuvant[i]=='-'&&a[val][i]==x)
                          {cuvant[i]=x;scor+=100;}}
                    else k++;
                    if(strcmp(cuvant,a[val])==0)
                        {afisare(k,cuvant,ind,a[val],introdus);
                         cout<<endl<<"1-Continua ca incepator"<<endl<<"2-Continua ca avansat"<<endl<<"3-Iesire"<<endl;
                         x=_getch();
                         while(x!='1'&&x!='2'&&x!='3')
                          x=_getch();
                         if(x=='1'||x=='2')
                            goto start;
                         else {
                               cout<<endl<<"La revedere !";
                               ok=0;
                               Sleep(1500);
                               break;
                              }
                        }
                     if(k==6)
                        {afisare(k,cuvant,ind,a[val],introdus);
                            cout<<endl<<"1-Meniul principal"<<endl<<"2-Iesire"<<endl;
                         x=_getch();
                         while(x!='1'&&x!='2')
                            x=_getch();
                         if(x=='1')
                           goto meniu;
                        else {ok=0;
                              break;}}
                 }
       }
       else if(x=='2')
        {system("CLS");
           cout<<"##### SPANZURATOAREA #####"<<endl;
            cout<<"DETALII JOC"<<endl<<endl;
            cout<<"Jocul contine cuvinte din urmatoarele ramuri:"<<endl<<"-animale"<<endl<<"-pasari"<<endl<<"-insecte"<<endl<<"-reptile"<<endl<<"-pesti"<<endl<<"Modul incepator dispune de un indiciu ajutator"<<endl<<endl;
            cout<<"1-Inapoi"<<endl;
            x=_getch();
        while(x!='1')
         x=_getch();
        }
        else
            if(x=='3')
      {
          afisareScoruriConsola();
          goto meniu;
      }
             else if(x=='4')
                     {ok=0;
                     system("CLS");
                     cout<<"La revedere!";
                     Sleep(1500);
                     }

}
if(scor>highscore[pozitieClasament].scor)
   highscore[pozitieClasament].scor=scor;
sortareScoruri();
afisareScoruri();
    return 0;
}

