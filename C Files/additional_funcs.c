#include <stdio.h>
#include <stdlib.h>


void setConsoleColor(int textColor);


void print2Dstr (char str[9][9][2], char const ElementsConst[9][9][2],int rows)
{
    int i,j;
    setConsoleColor(11);
    printf("\n                          #***********#***********#***********#\n");
    setConsoleColor(15);

    for(i=0; i<rows; i++)
    {
        setConsoleColor(11);
        printf("                          #");
        setConsoleColor(15);

        for(j=0; j<rows; j++)
        {

            if((j==2)||(j==5))
            {

                if(str[i][j][0] == '-')
                {
                    setConsoleColor(14);
                    printf(" %s ",str[i][j]);
                    setConsoleColor(15);
                }
                else if(( ElementsConst[i][j][0] == ' ')&&(str[i][j][0] != '-'))
                {

                    setConsoleColor(10);
                    printf(" %s ",str[i][j]);
                    setConsoleColor(15);

                }
                else
                {
                    setConsoleColor(12);
                    printf(" %s ",str[i][j]);
                    setConsoleColor(15);
                }

                setConsoleColor(11);
                printf("#");
                setConsoleColor(15);

            }
            else
            {

                if(j==8)
                {


                    if(str[i][j][0] == '-')
                    {
                        setConsoleColor(14);
                        printf(" %s ",str[i][j]);
                        setConsoleColor(15);
                    }
                    else if(( ElementsConst[i][j][0] == ' ')&&(str[i][j][0] != '-'))
                    {

                        setConsoleColor(10);
                        printf(" %s ",str[i][j]);
                        setConsoleColor(15);

                    }
                    else
                    {
                        setConsoleColor(12);
                        printf(" %s ",str[i][j]);
                        setConsoleColor(15);
                    }

                    setConsoleColor(11);
                    printf("#");
                    setConsoleColor(15);
                }
                else
                {


                    if(str[i][j][0] == '-')
                    {
                        setConsoleColor(14);
                        printf(" %s ",str[i][j]);
                        setConsoleColor(15);
                    }
                    else if(( ElementsConst[i][j][0] == ' ')&&(str[i][j][0] != '-'))
                    {

                        setConsoleColor(10);
                        printf(" %s ",str[i][j]);
                        setConsoleColor(15);

                    }
                    else
                    {
                        setConsoleColor(12);
                        printf(" %s ",str[i][j]);
                        setConsoleColor(15);
                    }


                    printf("|");

                }


            }

        }

        if((i==2)||(i==5)||(i==8))
        {

            printf("\n");
            setConsoleColor(11);
            printf("                          #***********#***********#***********#");
            setConsoleColor(15);
            printf("\n");

        }

        else
        {
            printf("\n");
            setConsoleColor(11);
            printf("                          #");
            setConsoleColor(15);
            printf("-----------");
            setConsoleColor(11);
            printf("#");
            setConsoleColor(15);
            printf("-----------");
            setConsoleColor(11);
            printf("#");
            setConsoleColor(15);
            printf("-----------");
            setConsoleColor(11);
            printf("#");
            setConsoleColor(15);

            printf("\n");
        }
    }


}


/************************************************************************************************************************************************************************************************/

void show_trials(int trials)
{

    setConsoleColor(12);
    printf("   |------------|\n");
    printf("   |");
    setConsoleColor(10);
    printf("TRIALS = '%d'",trials);
    setConsoleColor(12);
    printf("|\n");
    printf("   |------------|");
    setConsoleColor(15);


}
