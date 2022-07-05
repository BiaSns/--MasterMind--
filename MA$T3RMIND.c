#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
 int main (){

    printf("I COLORI A DISPOSIZIONE SONO QUESTI:\n\n");	

    printf("RED--> R\n");	
    printf("------ \n");
    printf("YELLOW--> Y\n");
    printf("------ \n");
	printf("WHITE--> W\n");
	printf("------ \n");     //Legenda colori
	printf("PINK--> P\n");
	printf("------ \n");     
	printf("BLUE--> B\n");
	printf("------ \n");
	printf("GREEN--> G\n\n"); 


	char SecretStringColours [6] = {'R','Y','W','P','B','G'};  //Creo la struttura contenente i colori
	int i;
	//int j;
    int CodeLenght;
	char SecretString[5]; //QUESTO ARRAY INVECE SALVERA' LA STRINGA RANDOM GENERATA
	srand(time(NULL)); //Funzione che permette il funzionamento della funzione random 

	printf("Scegli di giocare con un codice da 1 a 5 cifre\n");
	scanf("%d",&CodeLenght);
    
	printf("\nLa sequenza segreta e'\n\n");

		for(i=0; i<CodeLenght; i++){  
        SecretString[i]=SecretStringColours[rand()%(sizeof SecretStringColours)];
        }
    printf("\n%s",&SecretString);  //stampo la sequenza random
    
	printf("\nINSERISCI LA TUA IPOTESI-RICORDA DI INSERIRE IN MAIUSCOLO\n\n");
    
	int ComparingVariable=0;
    int FlagBianco=0;
	int FlagNero=0;
	int N=1;
   
   do
	{ 
	printf("Tentativo N %d\n",N);
	char DigitatedSequence[sizeof CodeLenght]; 
    scanf("%s", DigitatedSequence);
    N++;//VAriabile contatore per numero tentativi
        for(i = 0; i < CodeLenght; i++)
        {
        printf("\nconfronto tra %c e %c \n", SecretString[i], DigitatedSequence[i]);
        //{  
        //for(j=0; j<CodeLenght; j++)
        // {
         if(SecretString[i] == DigitatedSequence[i]) //FACCIO IL CONFRONTO
            {
            	printf("Esito positivo tra %c e %c \n", SecretString[i], DigitatedSequence[i]);
				ComparingVariable +=1;
				FlagBianco +=1; // HO MESSO FLAGNERO E BIANCO SOLO PER INIZIARE A VISUALIZZARLI MA DEVO ANCORA CAPIRE COME E DOVE INCREMENTARLI E VICEVERSA.
		        FlagNero +=1;
				printf("\nIl valore di ComparingVariable = %d\n",ComparingVariable);//METTO LA STAMPA PER AVERE SOTT'OCCHIO DOVE LA VARIABILE ASSUME IL VALORE E PERCHE'
				printf("\nFlagBianco = %d, FlagNero = %d\n",FlagBianco,FlagNero);
				
				if(ComparingVariable == CodeLenght) //E con questo if mi assicuro che se dovessi infovinare la sequenza si stopperanno i tentativi e il gioco finirà.
				   {  
				    printf("\nHai indovinato il codice segreto :)\n");
					break; //Devo vedere come stoppare il loop ( DA sistemare)
				   }
			}
        else    
		        {
                printf("Esito negativo tra %c e %c\n ", SecretString[i], DigitatedSequence[i]);	
                printf("\nIl valore di ComparingVariable = %d\n",ComparingVariable);//METTO LA STAMPA PER AVERE SOTT'OCCHIO DOVE LA VARIABILE ASSUME IL VALORE E PERCHE'
			    printf("\nFlagBianco = %d, FlagNero = %d\n",FlagBianco,FlagNero);
				}
		
		printf("\n Il codice digitato non corrisponde, riprova!\n");
     	}
    }
    
	while(N<=9);
	      {
			 printf("\n Hai esaurito tutti i tentavi ed il codice digitato non corrisponde, sei scarso. )");  
          }
return 0;
}
  

	


/*AGGIORNAMNETI: 
HO DECISO DI SEPARARE LE LOGICHE(CONTROLLO STRINGA E ASSEGNAZIONI AI FLAG + CONTROLLO FINALE) PERCHE' SEMBRAVA CONFUSIONALE, HO FREEZATO IL SECONDO CILCO NELLA RIGA 57 FACENDO SCORRERE LE STRINGHE CON LO STESSO CONTATORE ORA CONFRONTO
LETTERA PER LETTERA (CON LA RISPETTIVA SOTTO)-COSI' HO RISOLTO I BUG RELATIVI AL NORMALE FUNZIONAMENTO- ORA RESTA LA PARTE INTERESSANTE OVVERO LA PARTE FUNZIONALE DEI FLAG PER TENERE CONTO DEL RISULTATO
AD OGNI TENTATIVO FATTO
PRIMA DI PASSARE ALLA FUNZIONE DEI FLAG HO MESSO UN CICLO PER DARE UN MASSIMO DI NOVE TENTAIVI COSI' DA INIZIARE A SIMULARE IL VERO E PROPRIO GIOCO
Devo vedere come stoppare il loop quando la sequenza è ordinata vedi riga 71 ( DA sistemare)*/
