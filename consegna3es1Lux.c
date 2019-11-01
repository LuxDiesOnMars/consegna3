#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char array[10][10];
    memset(array,'o',sizeof(array));
    int rig;
    int col;
    int alf=65;
    int posizione;
    srand(time(NULL));

    rig=(rand()+time(NULL))%10;
    col=(rand()+time(NULL))%10;

    array[rig][col]=alf;
    alf++;

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            putchar(array[i][j]);
            if(j==9)putchar('\n');
            if(i==9&&j==9)printf("\n\n");
        }


    while(alf<=90)
    {
        int cont=1;
        int controllo=0;

        do{
            if(cont==1)posizione=(rand()+time(NULL))%4 +1;
            if(cont>4){printf("chiusura programma");return 0;}
            switch((posizione))
            {
                case 1:
                    if(rig-1>=0&&array[rig-1][col]=='o'){--rig;controllo=1;break;}
                    else {
                            cont++;
                            if((posizione%4)==0)posizione=1;
                            else posizione++;
                            break;
                            }
                case 2:
                    if(col+1<=9&&array[rig][col+1]=='o'){++col;controllo=1;break;}
                    else {
                            cont++;
                            if((posizione%4)==0)posizione=1;
                            else posizione++;
                            break;
                            }
                case 3:
                    if(rig+1<=9&&array[rig+1][col]=='o'){++rig;controllo=1;break;}
                    else {
                            cont++;
                            if((posizione%4)==0)posizione=1;
                            else posizione++;
                            break;
                            }
                case 4:
                    if(col-1>=0&&array[rig][col-1]=='o'){--col;controllo=1;break;}
                    else {
                            cont++;
                            if((posizione%4)==0)posizione=1;
                            else posizione++;
                            break;
                            }

                default: printf("ERROR 1");return 1;
            }

        }while(controllo!=1);


        array[rig][col]=alf;
        alf++;



        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
            {
                putchar(array[i][j]);
                if(j==9)putchar('\n');
                if(i==9&&j==9)printf("\n\n");
            }
    }
    return 0;
}
