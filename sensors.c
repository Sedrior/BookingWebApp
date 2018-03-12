#include<stdio.h>
#include<random>
#include<time.h>

#define SIZE 10 //dimensiunea vectorului
#define validationRange 13 //dimensiunea zonei de validare

//vector de frecventa folosit pentru distantele valide
int Frecv[251]={0};

void initialization(int *v)//functie care initializeaza distantele valide
{
	int r,i;
	for(i=0;i< SIZE;i++)
	{
		r=rand()%251;//random intre 0-250
		if(r==1 || r==2 )//eliminam varianta pt r=1 si r=2
			i--;
		else
			v[i]=r;
	}
	printf("Vectorul de distante:\n");
	for(i=0;i<SIZE;i++)
		printf("%d ",v[i]);
	printf("\n\n");
}

void initialization_frecv(int *v)//initializam vectorul de frecventa
{
	int i;
	for(i=0;i<SIZE;i++)
		Frecv[v[i]]++; //incrementam vectorul cu 1 pentru fiecare valoare gasita in vector
}

void validation(int *v,int *valid_vector)
{
	int contor, valid=0, i=3,j,k,verificare,contor_valid;
	printf("Zone de validare:\n");
	while(i+validationRange<=250)//pargurgem vectorul de frecventa pe zone de validare cu 13 elemente
	{
		j=i;//j inceputul zonei de validare, i sfarsitul zonei de validare
		contor=0;//pargurgem zona de validare
		verificare=0;//numaram nr de elemente din zona de validare
		while(contor!=validationRange)
		{
			if(Frecv[i]!=0)
				verificare++;
			contor++;
			i++;
		}
		printf("Nr elemente din zona %d-%d = %d\n",j,i,verificare);
		if(valid<=verificare)//verificam daca exista mai multe elemente in zona de validare
		{
			valid=verificare;
			contor_valid=0;
			for(k=j;k<=i;k++)//pargurgem zona de validare
			{
				if(Frecv[k]!=0)
				{
					valid_vector[contor_valid]=k;//punem valoarea in vectorul de validare
					contor_valid++;
				}
			}
			
		}
				
	}
	printf("\nVectorul valid:\n");
	for(i=0;i<contor_valid;i++)
		printf("%d ",valid_vector[i]);
	printf("\n");
}

int main()
{
	int vector[SIZE]={};
	int *v=&vector[0];//vectorul de distante
	int valid[SIZE]={};
	int *val=&valid[0];//vectorul de validare
	int i;
	srand(time(NULL));//pentru nr de random
	initialization(v);
	initialization_frecv(v);
	validation(v,val);
}
