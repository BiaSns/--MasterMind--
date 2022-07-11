#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>


 int main (){
    printf("***BENVENUTO IN MASTERMIND***\n\n");
    printf("ISTRUZIONI DI GIOCO : Lo scopo del gioco e' quello di indovinare la sequenza segreta generata dal sistema, ne dovrà indovinare il carattere(colore) e l'ordine corretto di ogni lettera.\n");
    printf("Si potrà scegliere la difficolta' del gioco scegliendo la nunghezza del codice segreto partendo da 1 fino ad un massimo di 5 caratteri da infovinare. Il giocatore avrà 9 tentativi per scoprire la sequenza segreta prima di perdere la partita.");
    printf("Ad ogni tentativo ci sarà un log che permetterà di capire se c'e' qualche corrispondenza con la sequenza segreta, specificando se il colore e l'ordine sono corretti o solo il colore.'");
    printf("Con precisione il numero dei pioli neri indicheranno che nella sequenza digitata ci sono n corrispondenze tra la sequenza segreta e quella digitata in carattere ed in ordine;Mentre i pioli bianchi indicheranno semplicemente che un carattere è presente senza tener conto della posizione corretta\n");
    
    
 	printf("I colori a disposizione sono i seguenti!\n");
    printf("RED--> R, YELLOW--> Y, WHITE--> W, PINK--> P, BLUE--> B, GREEN--> G\n\n");	//Legenda colori
    printf("Detto cio', buon divertimento!\n");
    
	char SecretStringColours [6] = {'R','Y','W','P','B','G'};  //Creo la struttura contenente i colori
	int i;
	int j;
    int CodeLenght; 
	int PioloNero=0;
	int PioloBianco=0;
	int N=1; //Variabile contatore dei tentativi
	char SecretString[5]; //QUESTO ARRAY INVECE SALVERA' LA STRINGA RANDOM GENERATA
	srand(time(NULL)); //Funzione che permette il funzionamento della funzione random 

	printf("Scegli di giocare con un codice da 1 a 5 cifre\n");
	scanf("%d",&CodeLenght);
    
	printf("\nLa sequenza segreta e'\n\n");

		for(i=0; i<CodeLenght; i++){  
        SecretString[i]=SecretStringColours[rand()%(sizeof SecretStringColours)];
        }
    printf("\n%s",&SecretString);  //stampo la sequenza random(MI SERVE IN FASE DI DEBUG)
    
	printf("\nINSERISCI LA TUA IPOTESI---*RICORDA DI INSERIRE IN MAIUSCOLO*\n\n");
    
	
   do      //Creo struttura loop con do per permettere al giocatore di avere N tentativi per indovinare il codice segreto prima di terminare il gioco.
	{ 
	printf("Tentativo N %d\n",N);
	char DigitatedSequence[sizeof CodeLenght]; 
    scanf("%s", DigitatedSequence);
    printf("%s",DigitatedSequence);

	N++;//VAriabile contatore per numero tentativi
    
		
     for(i = 0; i < CodeLenght; i++) {

        printf("\nGiro : %d\n",i);
                                             /*Il doppio ciclo for è per permettere il confronto completo tra le due stringhe SecretString e DigitatedSequence anallizzando elemento per elemento.
                                             In particolare il confronto avviene partendo dal carattere nella prima cella di SecretString che viene confrontato con i caratteri di tutte le celle
                                             di DigitatedSequence, poi passando all'elemento della seconda cella di Secret con tutti gli elementi di DIgitated e così via.*/
       for(j=0; j<CodeLenght; j++) {
         if(SecretString[i] == DigitatedSequence[j] && i==j) //FACCIO IL CONFRONTO
            {
                printf("%c e %c \n", SecretString[i], DigitatedSequence[j]);
		        PioloNero +=1;
				//printf("\PioloBianco = %d, PioloNero = %d\n",PioloBianco,PioloNero);
				//break; break termina il loop -> occhio! 	
			}
            else if(SecretString[i] == DigitatedSequence[j]) {
                printf("%c e %c\n ", SecretString[i], DigitatedSequence[j]);	
			    PioloBianco +=1;
				//printf("\PioloBianco = %d, PioloNero = %d",PioloBianco,PioloNero);
		    }
		        printf("\nconfronto tra %c e %c \n", SecretString[i], DigitatedSequence[j]);
                printf("\nPioloBianco = %d, PioloNero = %d\n\n",PioloBianco,PioloNero);

		}
	}  
    if(PioloNero == CodeLenght){
	                             printf("\nHai indovinato il codice segreto :)\n");
								 break;  //QUESTA STRUTTURA SERVIRA' A TERMINARE IL LOOP NEL MOMENTO IN CUI INDOVINO IL CODICE SEGRETO
	                          }
      
		PioloNero=0; //ASSEGNO ZERO ALLe VARIABILI ALLA FINE DI OGNI LOOP PER GARANTIRE IL CORRETTO FUNZIONAMENTO DELL'ALGORITMO
	    PioloBianco=0;
	}
    
	while(N<=9); 
	      
  if (N=9 && PioloNero != CodeLenght){ //STRUTTURA DI CONTROLLO FINALE PER VERIFICARE LA SCONFITTA
	printf("\nHai esaurito tutti i tentavi ed il codice digitato non corrisponde, GAME OVER.  :( "); 
	}        

return 0;
}
  

	

/*TUTTO FUNZIONA COME DEVE, UNICA COSA RIMANENTE E' RISOLVERE IL PROBLEMA DELLE DOPPIE(AVVIENE UNA SOVRACONTA DAI PIOLI BIANCHI) E QUESTO NON PERMETTE IL NORMALE FUNZIONAMENTO.
L'IDEA ERA CREARE UNA FUNZIONE CHE RIESCA A RICONOSCERE CHE SE IL PIOLO BIANCO E' GIA STATO INCREMENTATO E SI PRESENTA UNA DOPPIA QUESTO RIMANE COSI.*/
