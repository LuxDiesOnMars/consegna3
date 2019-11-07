#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 20

int main(void)
{

    char str2[MAXDIM];
    char str1[MAXDIM];
    memset(str1,'\0',sizeof(str1));
    memset(str2,'\0',sizeof(str2));
    puts("inserisci stringa1:\n");
    scanf("%19s",str1);
    fflush(stdin);
    puts("inserisci stringa per confronto:\n");
    scanf("%9s",str2);
    fflush(stdin);
    char *ptr;

    while(strstr(str1,str2)!= NULL)
    {
        ptr=strstr(str1,str2);
        char *ptrA=(char *)malloc(MAXDIM*sizeof(char));
        memset(ptrA,'\0',sizeof(ptrA));
        int num=ptr-str1;
        strncpy(ptrA,str1,num);
        *(ptrA+num)='*';
        *(ptrA+num+1)='\0';
        strcat(ptrA,ptr+(strlen(str2)));
        strcpy(str1,ptrA);
        free(ptrA);

    }

    puts(str1);



    return 0;
}
