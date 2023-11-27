#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define N 20
#define V 8
#define T 5

struct data 
{
    int gg;
    int mm;
    int aa;
} typedef data;

struct alunno {
    char cognome[N];
    data nascita;
    int voti[V];
} typedef alunno;

//funzione per scrivere un file di N record
void crea(char[]);

void modifica( char[], char[], char[]);//Si sostituisca su file il cognome1 (per tutte le occorrenze presenti nel file) con cognome2.
//Si restituisca quante volte � stato incontrato cognome1


int main()
{
	crea("modifica.dat");
	
	modifica("modifica2.dat","sollo","menicucci");

}
void crea(char file[])
{
    alunno buffer;
    FILE * puntfile = fopen(file, "ab");// ab perche sono file binari

    if(puntfile!=NULL)// controllo se c'� un errore nell'apertura
	{
        for(int i=0;i<T;i++)
        {
        
            printf("inserisci il cognome che vuoi cercare: ");
            scanf("%s",buffer.cognome);

            buffer.nascita.gg=rand()%30+1;//genero il giorno
            buffer.nascita.mm=rand()%12+1;//genero il mese
            buffer.nascita.aa=rand()%32+1990;//genero l'anno

            for(int j=0;j<V;j++) 
			{
                buffer.voti[j] = rand()%10+1;//genero i voti
            }

            fwrite(&buffer,sizeof(alunno),1,puntfile);//faccio fwrite nel file puntfile
        }
    }
    fclose(puntfile);//chiudo il file
}

void modifica(char file[],char cog1[],char cog2[])
{
	FILE * puntfile = fopen(file,"rb");//apro il file in lettura 
	
	alunno buffer;
	
	if(puntfile!=NULL)//se il file si � aperto
	

	while(!feof(puntfile))//finch� il file non � finito
	{
		fread(&buffer,sizeof(alunno),1,puntfile);//leggo un record alla volta che ci � scritto sul file
		
		if(strcmp(buffer.cognome,cog1)==0)//se il cognome � uguale a quello che cerco
		{
			strcpy(buffer.cognome,cog2);//sostituisco il cognome
			fseek(puntfile,-sizeof(alunno),SEEK_CUR);//mi riposiziono sulla posizione corretta tornando indietro di una posizione
			fwrite(&buffer,sizeof(alunno),1,puntfile);//scrivo la modifica sul file
		}
	}
	
	fclose(puntfile);
	//chiudo il file
}
