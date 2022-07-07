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
    printf("\n%s",&SecretString);  //stampo la sequenza random(MI SERVE IN FASE DI DEBUG)
    
	printf("\nINSERISCI LA TUA IPOTESI-RICORDA DI INSERIRE IN MAIUSCOLO\n\n");
    
	//int ComparingVariable=0;
    //int FlagBianco=0;
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
        //for(j=0; j<CodeLenght; j++) QUESTO FOR LO USERò NELLA FUNZIONE TROVA FLAG BIANCHI
        // {
         if(SecretString[i] == DigitatedSequence[i]) //FACCIO IL CONFRONTO
            {
            	printf("Esito positivo tra %c e %c \n", SecretString[i], DigitatedSequence[i]); 
		        FlagNero +=1;
				printf("\nIl valore di FlagNero = %d\n",FlagNero);//METTO LA STAMPA PER AVERE SOTT'OCCHIO DOVE LA VARIABILE ASSUME IL VALORE E PERCHE'
				printf("\nFlagNero = %d\n",FlagNero);
			}
        
		else    
		        {
                printf("Esito negativo tra %c e %c\n ", SecretString[i], DigitatedSequence[i]);	
                printf("\nIl valore di FlagNero e' = %d\n",FlagNero);//METTO LA STAMPA PER AVERE SOTT'OCCHIO DOVE LA VARIABILE ASSUME IL VALORE E PERCHE'
			    printf("FlagNero = %d\n",FlagNero);
				printf("\nIl codice digitato non corrisponde, riprova!\n");
				}
		
		
     	}
    if(FlagNero == CodeLenght){
	                             printf("\nHai indovinato il codice segreto :)\n");
								 break;  //QUESTA STRUTTURA SERVIRA' A TERMINARE IL LOOP NEL MOMENTO IN CUI INDOVINO IL CODICE SEGRETO
	                          }
      
			                     
        	                     

	
	FlagNero=0; //ASSEGNO ZERO ALLA VARIABILE ALLA FINE DI OGNI LOOP PER GARANTIRE IL CORRETTO FUNZIONAMENTO DELL'ALGORITMO
	}
    
	while(N<=9); 
	      
  if (N=9 && FlagNero != CodeLenght){ //STRUTTURA DI CONTROLLO FINALE PER VEERIFICARE LA SCONFITTA
	printf("\nHai esaurito tutti i tentavi ed il codice digitato non corrisponde, sei scarso.  :( "); 
	}        
return 0;
}
  

	


/*AGGIORNAMNETI: 
HO DECISO DI SEPARARE LE LOGICHE(CONTROLLO STRINGA E ASSEGNAZIONI AI FLAG + CONTROLLO FINALE) PERCHE' SEMBRAVA CONFUSIONALE, HO FREEZATO IL SECONDO CILCO NELLA RIGA 57 FACENDO SCORRERE LE STRINGHE CON LO STESSO CONTATORE ORA CONFRONTO
LETTERA PER LETTERA (CON LA RISPETTIVA SOTTO)-COSI' HO RISOLTO I BUG RELATIVI AL NORMALE FUNZIONAMENTO- ORA RESTA LA PARTE INTERESSANTE OVVERO LA PARTE FUNZIONALE DEI FLAG PER TENERE CONTO DEL RISULTATO
AD OGNI TENTATIVO FATTO
PRIMA DI PASSARE ALLA FUNZIONE DEI FLAG HO MESSO UN CICLO PER DARE UN MASSIMO DI NOVE TENTAIVI COSI' DA INIZIARE A SIMULARE IL VERO E PROPRIO GIOCO
RISOLTI TUTTI I BUG RELATIVI AL NORMALE FUNZIONAMENTO RESTA SOLO CREARE LA FUNZIONE CONTATORE DEI FLAGBIANCHI( QUELLI CHE SEGNANO LA PRESENZA DELLA LETTERA A PRESCINDERE DALL'ORDINE).
