#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i=0;
    int h=0;
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
    int lun2=strlen(str2);

    do{
        while(str[i]!=str2[0]&&str[i]!='\0')
        {
            str3[h]=str[i];
            i++;
            h++;
        }

        if(str[i]==str2[0])
        {
            int memo=h;
            for(int a=0;a<lun2 && str[i]==str2[a];i++,a++)
            {

                if(a==lun2-1&&str[i]==str2[a])
                {
                    str3[memo]='*';
                    for(int l=memo+1;l<20;l++)str3[l]='\0';
                    h=memo+1;
                }
                else
                {
                    str3[h]=str[i];
                    h++;
                }
            }

        }

    }while(i<20&&str[i]!='\0');
    puts("stringa finale:");
    puts(str3);

    return 0;
}
