#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 30

int main(void)
{
    char str2[MAXDIM];
    char str1[MAXDIM];
    memset(str1,'\0',sizeof(str1));
    memset(str2,'\0',sizeof(str2));
    puts("inserisci stringa1:\n");
    scanf("%29s",str1);
    fflush(stdin);
    puts("inserisci stringa per confronto:\n");
    scanf("%29s",str2);
    fflush(stdin);
    char *ptr;

    while(strstr(str1,str2)!= NULL)  //se trova occorrenza di str2 inizia ciclo e continua finche continua a trovare occorrenza
    {
        ptr=strstr(str1,str2);          //assegno a ptr indirizzo di str1 in cui compare occorrenza di str2
        char *ptrA=(char *)malloc(MAXDIM*sizeof(char));   //creo array dinamico di uguale dimensione di str1
        memset(ptrA,'\0',sizeof(ptrA));     //inizializzo il vettore tutto a \0
        int num=ptr-str1;              //num ora equivale all num di elementi di str1 che precedono la prima occorrenza di str2
        strncpy(ptrA,str1,num);     //copio dunque num elementi di str1 in vettore dinamico
        *(ptrA+num)='*';            //il num+1 elemento di str1 sarà la prima lettera di str2 quindi pongo come *
        *(ptrA+num+1)='\0';         //aggiungo il terminatore per sicurezza
        strcat(ptrA,ptr+(strlen(str2)));    //concateno all array dinamico il vettore che parte da ptr+n elementi di str2 es.str1=ciaone str2=ciao :concatena "ne"
        strcpy(str1,ptrA);              //copio l array dinamico definitivo con la nuova stringa modificata con eventuali *
        free(ptrA);                 //libero la hyp

    }

    puts("stringa finale:");
    puts(str1);



    return 0;
}
