#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[20];
    char str2[10];
    char str3[20];
    memset(str3,'\0',sizeof(str3));
    memset(str2,'\0',sizeof(str2));
    memset(str,'\0',sizeof(str));
    puts("inserisci stringa1:\n");
    scanf("%19s",str);
    fflush(stdin);
    puts("inserisci stringa per confronto:\n");
    scanf("%9s",str2);
    fflush(stdin);
    char *ptr;


   if((ptr=strstr(str,str2))!= NULL)
   {
       int i=0;
       for(;str+i<ptr;i++)
       {
           str3[i]=*(str+i);
       }
       int n=ptr-str;
       str3[n]='*';
       i++;
       for(int j=0;ptr+(int)strlen(str2)+j<=str+strlen(str)-1;j++,i++)
       {
           str3[i]=*(ptr+(int)strlen(str2)+j);
       }
       str3[i]='\0';

       while(strstr(str3,str2)!= NULL)
       {
            ptr=strstr(str3,str2);
            int i=0;
            for(;str3+i<ptr;i++)
            {
                str3[i]=*(str3+i);
            }
            int n=ptr-str3;
            str3[n]='*';
            i++;
            for(int j=0;ptr+(int)strlen(str2)+j<=str3+strlen(str3)-1;j++,i++)
            {
                str3[i]=*(ptr+(int)strlen(str2)+j);
            }
            str3[i]='\0';
       }

       puts(str3);
   }
   else puts("nessuna occorrenza");





    return 0;
}
