#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include <ctype.h>


 int main (){
    printf(
            "***BENVENUTO IN MASTERMIND***\n\n"
            "ISTRUZIONI DI GIOCO:\n"
            "Lo scopo del gioco e' quello di indovinare la sequenza segreta"
            "generata dal sistema, ne dovra' indovinare il carattere(colore) e"
            " l'ordine corretto di ogni lettera.\n"
            "Si potra' scegliere la difficolta' del gioco scegliendo la"
            " lunghezza del codice segreto partendo da 3 fino ad un massimo di"
            " 5 caratteri da indovinare.\nIl giocatore avra' 9 tentativi per "
            "scoprire la sequenza segreta prima di perdere la partita.\n"
            "Ad ogni tentativo ci sara' un log che permettera' di capire se c'e'"
            "qualche corrispondenza con la sequenza segreta,\nspecificando se"
            " il colore e l'ordine sono corretti o solo il colore.\n"
            "Con precisione il numero dei pioli neri indicheranno che nella"
            " sequenza digitata ci sono n corrispondenze tra la\nsequenza"
            " segreta e quella digitata in carattere ed in ordine;mentre i"
            " pioli bianchi indicheranno semplicemente che\nun carattere e'"
            "presente senza tener conto della posizione corretta.\n"
            "\nI colori a disposizione sono i seguenti!\n"
            "RED--> R, YELLOW--> Y, WHITE--> W, PINK--> P, BLUE--> B,GREEN--> G\n\n"
            "Detto cio', buon divertimento!\n"
    );
    
	char Colori [6] = {'R','Y','W','P','B','G'};  //Creo la struttura contenente i colori
	int i,j;
	int DimCodice;
	int PioloNero=0;
	int PioloBianco=0;
	int N=1; //Variabile contatore dei tentativi
	char P_Nero[5]={0}; //Array parametrizzati in base alla lunghezza del codice(Max 5)
	char P_Bianco[5]={0}; // E' usata per indicare se e' stato indoVinata la lettera ma non la posizione
	char CodiceSegreto[5]; 
	srand(time(NULL)); //Funzione che resetta la funzione ad ogni nuova esecuzione

	printf("Scegli di giocare con un codice da 3 a 5 cifre\n");
	scanf("%d",&DimCodice);
	
	//Controllo input corretto
	if (DimCodice < 3 || DimCodice > 5) {
        printf("Valore inserito non valido!");
        exit(1);
    }
    
	for(i=0; i<DimCodice; i++){  
    CodiceSegreto[i]=Colori[rand()%(sizeof Colori)];
    }
	printf("\n____________INSERISCI LA TUA IPOTESI___________\n\n");
    
	//Creo struttura loop con do per permettere al giocatore di avere N tentativi per indovinare il codice segreto prima di terminare il gioco
   do {     
	
	//Ciclo For per azzeramento array  
	for(i=0; i<DimCodice; i++){
       
	   P_Nero[i]=0;
	   P_Bianco[i]=0;	
	}
	
	printf("Tentativo N %d\n",N);
	char CodiceIpotesi[sizeof DimCodice]; 
    scanf("%s", CodiceIpotesi);
    //Ciclo for per controllo maiuscole---In nostanza anche se digito le minuscole l'algoritmo le trasfroma automaticamente in maiuscole cosi' da evitare bugs
	for(i=0; CodiceIpotesi[i]!='\0'; i++){
	   if((CodiceIpotesi[i]>='a' && CodiceIpotesi[i]<='z')){ //Fa il controllo con l'alfabeto completo delle minuscole
		  CodiceIpotesi[i]=CodiceIpotesi[i]-32; //Sottraendo 32 ad ogni carattere lo rendiamo in forma maiuscola(Rifacendosi al codice ASCII)
		  continue; 
	    }
	} 
     
    PioloNero=0; //Azzero le variabili per non sovrascrivere
	PioloBianco=0; //ad ogni tentativo rendendo inefficiente l'algoritmo
	
	N++; //Incremento numero tentativi ad ogni giro
	
    //Controllo input corretto
    if (strlen(CodiceIpotesi) != DimCodice) {
        printf("Lunghezza sequenza non valida!");
        exit(1);
        }
	
	//Ciclo for per riempire variabile PioloNero e contabilizzare array : P_Nero e P_Bianco	
    for(i=0; i<DimCodice; i++) {
        if(CodiceIpotesi[i] == CodiceSegreto[i]) //FACCIO IL CONFRONTO TRA I DUE CARATTERI DELLA STESSA POSIZIONE
            {
				 PioloNero ++;
				 P_Nero[i]=1;
	             P_Bianco[i]=1;	 //Assegnazione "1" agli array
	        }
		}
		
	//Ciclo for per riempire variabile PioloNero e contabilizzare array : P_Nero e P_Bianco	
	for(i=0; i<DimCodice; i++){   //P_Bianco[i] se e' 0 indica che non si sono verificate le condizioni nel ciclo precedente cioe' caratteri uguali nella stessa posizione ( CodiceSegreto [i] e CodiceDigitato[i]) La i indica un parametro di posizione.
			if(P_Bianco[i]==0){ //Se L'array risulta a 0 allora nel ciclo precedente non abbiamo trovato match in ordine ma solo in carattere.
				
				for(j=0; j<DimCodice; j++){
                  if(CodiceIpotesi[i] == CodiceSegreto[j] && P_Bianco[j]==0){ //FACCIO IL CONTROLLO DEI CARATTERI CON POSIZIONE NON UGUALE
					 PioloBianco++;
				     P_Bianco[j]==1; 
				}
			}	
		}	
   }
    
       
    printf("PioloBianco = %d, PioloNero = %d\n\n",PioloBianco,PioloNero);
    if(PioloNero == DimCodice){
	                             printf("\nHai indovinato il codice segreto :)\n");
								 return 0; //Con questa struttura terminerò il ciclo se indovinerò la sequenza segreta
	                          }
    
            
	} 
    while(N<=9);
	      
      
	  if (N=9 && PioloNero != DimCodice){ //Controllo finale giocata persa
	    printf("\nHai esaurito tutti i tentavi ed il codice digitato non corrisponde, GAME OVER.  :( "); 
	    printf("\nLa sequenza segreta era: %s",&CodiceSegreto);  
	  }        

return 0;
}
