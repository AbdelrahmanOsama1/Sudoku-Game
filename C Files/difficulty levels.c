
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void print2Dstr (char str[9][9][2], char const ElementsConst[9][9][2],int rows);
void setConsoleColor(int textColor);
void show_trials(int trials);
void playWinSound(void);
void playErrorSound(void);
void playButtonPressSound(void);
void playWelcomeSound(void);

/*******************************************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************************************/


static char ANSWER[9][9][2] =  {  {"9","7","6","5","1","3","2","4","8"},
    {"1","5","8","6","4","2","7","9","3"},
    {"2","3","4","7","9","8","5","1","6"},
    {"7","6","1","8","3","5","9","2","4"},
    {"8","2","3","4","7","9","1","6","5"},
    {"5","4","9","1","2","6","8","3","7"},
    {"6","9","7","3","5","1","4","8","2"},
    {"3","1","5","2","8","4","6","7","9"},
    {"4","8","2","9","6","7","3","5","1"}
};



// EASY

void easy_level(void)
{
    int i,j,flag_repeat_in_row=0,flag_repeat_in_column=0,num,row_num,column_num,block=0,flag_block=0,winner_flag=0;

    static char sudoku[9][9][2]= { {" ","7","6","5","1","3","2","4","8"},
        {"1"," ","8","6","4","2","7","9","3"},
        {"2","3"," ","7","9","8","5","1","6"},
        {"7","6","1"," ","3","5","9","2","4"},
        {"8","2","3","4"," ","9","1","6","5"},
        {"5","4","9","1","2"," ","8","3","7"},
        {"6","9","7","3","5","1"," ","8","2"},
        {"3","1","5","2","8","4","6"," ","9"},
        {"4","8","2","9","6","7","3","5"," "}
    };

    static const char const_elements_easy[9][9][2] = { {" ","7","6","5","1","3","2","4","8"},
        {"1"," ","8","6","4","2","7","9","3"},
        {"2","3"," ","7","9","8","5","1","6"},
        {"7","6","1"," ","3","5","9","2","4"},
        {"8","2","3","4"," ","9","1","6","5"},
        {"5","4","9","1","2"," ","8","3","7"},
        {"6","9","7","3","5","1"," ","8","2"},
        {"3","1","5","2","8","4","6"," ","9"},
        {"4","8","2","9","6","7","3","5"," "}
    };


    for(i=0; i<9; i++)
    {

        for(j=0; j<9; j++)
        {

            if(sudoku[i][j][0] == ' ')
            {
                sudoku[i][j][0]='-';
            }
        }

    }

    setConsoleColor(10);
    printf("\n>> WELCOME TO <EASY LEVEL>\n");
    printf("\n>> ARE YOU READY TO START ? \n\n");

    setConsoleColor(12);
    printf(">> To empty place Enter number -1\n");
    printf(">> To leave the game and show the answer , Enter number 0 , and any adjustable [row , column]\n");

    setConsoleColor(14);
    printf(">> press any button to start ^__^\n");
    setConsoleColor(15);
    playWelcomeSound();
    getch();
    system("cls");
    print2Dstr(sudoku, const_elements_easy,9);

    while(1)
    {

        flag_repeat_in_column=0, flag_repeat_in_row=0;

        setConsoleColor(14);
        printf("\n\n>> Enter number        >>  ");
        setConsoleColor(10);
        scanf("%d",&num);
        playButtonPressSound();
        //printf("\n");

        setConsoleColor(14);
        printf(">> Enter row number    >>  ");
        setConsoleColor(10);
        scanf("%d",&row_num);
        playButtonPressSound();
        //printf("\n");

        setConsoleColor(14);
        printf(">> Enter column number >>  ");
        setConsoleColor(10);
        scanf("%d",&column_num);
        setConsoleColor(15);
        playButtonPressSound();
        //printf("\n\n");


        if(((num>=-1)&&(num<=9))&&((row_num>=1)&&(row_num<=9))&&((column_num>=1)&&(column_num<=9)))    // check if values in the right range
        {





            if(const_elements_easy[row_num-1][column_num-1][0] != ' ')    // this place is for the main program (can't be modified)
            {

                system("cls");
                print2Dstr(sudoku,const_elements_easy,9);
                setConsoleColor(12);
                printf("\n>> SORRY , You can't write in this place\n");
                setConsoleColor(14);
                printf("\n>> press any button to try again ^__^\n");
                setConsoleColor(15);
                playErrorSound();
                getch();
                system("cls");
                print2Dstr(sudoku,const_elements_easy,9);

            }





            else       // a place which can be modified
            {

                block=0;
                flag_block=0;
                if((row_num>=1)&&(row_num<=3)&&(column_num>=1)&&(column_num<=3))        // block 1
                {
                    block=1;
                    for(i=0; i<3; i++)
                    {
                        for(j=0; j<3; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=1)&&(row_num<=3)&&(column_num>=4)&&(column_num<=6))   // block 2
                {
                    block=2;
                    for(i=0; i<3; i++)
                    {
                        for(j=3; j<6; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=1)&&(row_num<=3)&&(column_num>=7)&&(column_num<=9))   // block 3
                {
                    block=3;
                    for(i=0; i<3; i++)
                    {
                        for(j=6; j<9; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=4)&&(row_num<=6)&&(column_num>=1)&&(column_num<=3))   // block 4
                {
                    block=4;
                    for(i=3; i<6; i++)
                    {
                        for(j=0; j<3; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=4)&&(row_num<=6)&&(column_num>=4)&&(column_num<=6))   // block 5
                {
                    block=5;
                    for(i=3; i<6; i++)
                    {
                        for(j=3; j<6; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=4)&&(row_num<=6)&&(column_num>=7)&&(column_num<=9))   // block 6
                {
                    block=6;
                    for(i=3; i<6; i++)
                    {
                        for(j=6; j<9; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=7)&&(row_num<=9)&&(column_num>=1)&&(column_num<=3))   // block 7
                {
                    block=7;
                    for(i=6; i<9; i++)
                    {
                        for(j=0; j<3; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else if((row_num>=7)&&(row_num<=9)&&(column_num>=4)&&(column_num<=6))   // block 8
                {
                    block=8;
                    for(i=6; i<9; i++)
                    {
                        for(j=3; j<6; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }
                else                                                                    // block 9
                {
                    block=9;
                    for(i=6; i<9; i++)
                    {
                        for(j=6; j<9; j++)
                        {
                            if(num==(sudoku[i][j][0]-'0'))
                            {
                                flag_block=1;
                                break;
                            }
                        }
                        if(flag_block==1)
                        {
                            break;
                        }
                    }
                }


                for(i=0; i<9; i++)
                {

                    if(sudoku[row_num-1][i][0] == (num+'0'))
                    {
                        flag_repeat_in_row=1;
                        break;
                    }

                }


                for(j=0; j<9; j++)
                {

                    if(sudoku[j][column_num-1][0] == (num+'0'))
                    {
                        flag_repeat_in_column=1;
                        break;
                    }

                }

                if(num==-1)    // empty place
                {
                    sudoku[row_num-1][column_num-1][0] = '-';
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }
                else if(num==0)
                {
                    system("cls");
                    print2Dstr(ANSWER,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n\n>> THIS IS THE ANSWER\n\n>> GAME OVER -__-\n");
                    setConsoleColor(14);
                    printf("\n>> press any button to exit -__-\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    exit(0);
                    setConsoleColor(15);
                }

                else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==1)&&(flag_block==0))       // number is repeated in this row and column
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) AND THIS COLUMN (%d)\n",num,row_num,column_num);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }


                else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==1)&&(flag_block==1))       // number is repeated in this row and column and 3*3 block
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) AND THIS COLUMN (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,row_num,column_num,block);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }


                else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==0)&&(flag_block==0))       // number is repeated in this row only
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d)\n",num,row_num);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }


                else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==0)&&(flag_block==1))       // number is repeated in this row only and 3*3 block
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,row_num,block);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }

                else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==1)&&(flag_block==0))       // number is repeated in this column only
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS COLUMN (%d)\n",num,column_num);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }


                else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==1)&&(flag_block==1))       // number is repeated in this column only and 3*3 block
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS COLUMN (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,column_num,block);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }

                else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==0)&&(flag_block==1))       // number isn't repeated
                {

                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY !!!  '%d' IS IN THIS 3*3 BLOCK '%d'\n",num,block);
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                }


                else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==0)&&(flag_block==0))       // number isn't repeated
                {

                    sudoku[row_num-1][column_num-1][0] = num+'0';
                    system("cls");
                    print2Dstr(sudoku,const_elements_easy,9);
                    playButtonPressSound();
                }






            }





        }
        else       // error in range for inputs
        {

            system("cls");
            print2Dstr(sudoku,const_elements_easy,9);
            setConsoleColor(12);
            printf("\n\n>> ERROR IN INPUT VALUES , MAKE SURE THAT :-\n>> NUMBER , ROW NUMBER , COLUMN NUMBER SHOULD BE FROM '1' TO '9'\n");
            setConsoleColor(14);
            printf("\n>> press any button to try again ^__^\n");
            setConsoleColor(15);
            playErrorSound();
            getch();
            system("cls");
            print2Dstr(sudoku,const_elements_easy,9);
        }

        winner_flag=0;

        for(i=0; i<9; i++)      // check if user wins or not
        {

            for(j=0; j<9; j++)
            {
                if(sudoku[i][j][0] == '-')
                {
                    winner_flag=1;
                    break;
                }
            }
            if(winner_flag==1)
            {
                break;
            }
        }


        if(winner_flag==0)
        {
            system("cls");
            print2Dstr(sudoku,const_elements_easy,9);
            setConsoleColor(10);
            printf("\n\n>> CONGRATULATION !!!  YOU WIN ^__^\n\n");
            setConsoleColor(14);
            printf("\n>> press any button to exit ^__^\n");
            setConsoleColor(15);
            playWinSound();
            getch();
            exit(0);
            setConsoleColor(15);

        }





    }




}


/*******************************************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************************************/

// MEDIUM

void medium_level(void)
{
    int i,j,flag_repeat_in_row=0,flag_repeat_in_column=0,num,row_num,column_num,block=0,flag_block=0,winner_flag=0,trials=5;

    static char sudoku[9][9][2]= { {" ","7","6","5"," ","3","2","4","8"},
        {"1"," ","8","6"," ","2","7","9"," "},
        {" ","3"," ","7","9","8","5"," ","6"},
        {"7","6","1"," ","3","5"," ","2","4"},
        {"8"," ","3","4"," "," ","1","6","5"},
        {" ","4","9","1","2"," ","8"," ","7"},
        {"6","9"," ","3","5","1"," ","8","2"},
        {"3","1","5"," ","8","4","6"," ","9"},
        {"4"," ","2","9","6","7","3","5"," "}
    };

    static const char const_elements_medium[9][9][2] = { {" ","7","6","5"," ","3","2","4","8"},
        {"1"," ","8","6"," ","2","7","9"," "},
        {" ","3"," ","7","9","8","5"," ","6"},
        {"7","6","1"," ","3","5"," ","2","4"},
        {"8"," ","3","4"," "," ","1","6","5"},
        {" ","4","9","1","2"," ","8"," ","7"},
        {"6","9"," ","3","5","1"," ","8","2"},
        {"3","1","5"," ","8","4","6"," ","9"},
        {"4"," ","2","9","6","7","3","5"," "}
    };


    for(i=0; i<9; i++)
    {

        for(j=0; j<9; j++)
        {

            if(sudoku[i][j][0] == ' ')
            {
                sudoku[i][j][0]='-';
            }
        }

    }

    setConsoleColor(10);
    printf("\n>> WELCOME TO <MEDIUM LEVEL>\n");
    printf("\n>> ARE YOU READY TO START ? \n\n");
    setConsoleColor(12);
    printf(">> To empty place Enter number -1\n");
    printf(">> To leave the game and show the answer , Enter number 0 , and any adjustable [row , column]\n");
    setConsoleColor(14);
    printf(">> press any button to start ^__^\n");
    setConsoleColor(15);
    playWelcomeSound();
    getch();
    system("cls");
    show_trials(trials);
    print2Dstr(sudoku, const_elements_medium,9);

    while(1)
    {

        flag_repeat_in_column=0, flag_repeat_in_row=0;

        if(trials==0)
        {

            system("cls");
            show_trials(trials);
            print2Dstr(sudoku,const_elements_medium,9);
            setConsoleColor(12);
            printf("\n\n>> THERE ARE NO TRIALS\n\n>> GAME OVER -__-\n");
            setConsoleColor(14);
            printf("\n>> press any button to exit -__-\n");
            setConsoleColor(15);
            playErrorSound();
            getch();
            exit(0);
            setConsoleColor(15);
        }

        else
        {

            setConsoleColor(14);
            printf("\n\n>> Enter number        >>  ");
            setConsoleColor(10);
            scanf("%d",&num);
            playButtonPressSound();
            //printf("\n");

            setConsoleColor(14);
            printf(">> Enter row number    >>  ");
            setConsoleColor(10);
            scanf("%d",&row_num);
            playButtonPressSound();
            //printf("\n");

            setConsoleColor(14);
            printf(">> Enter column number >>  ");
            setConsoleColor(10);
            scanf("%d",&column_num);
            setConsoleColor(15);
            playButtonPressSound();
            //printf("\n\n");

            if(((num>=-1)&&(num<=9))&&((row_num>=1)&&(row_num<=9))&&((column_num>=1)&&(column_num<=9)))    // check if values in the right range
            {


                if(const_elements_medium[row_num-1][column_num-1][0] != ' ')    // this place is for the main program (can't be modified)
                {
                    trials--;
                    system("cls");
                    show_trials(trials);
                    print2Dstr(sudoku,const_elements_medium,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY , You can't write in this place\n");
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    show_trials(trials);
                    print2Dstr(sudoku,const_elements_medium,9);

                }





                else       // a place which can be modified
                {

                    block=0;
                    flag_block=0;
                    if((row_num>=1)&&(row_num<=3)&&(column_num>=1)&&(column_num<=3))        // block 1
                    {
                        block=1;
                        for(i=0; i<3; i++)
                        {
                            for(j=0; j<3; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=1)&&(row_num<=3)&&(column_num>=4)&&(column_num<=6))   // block 2
                    {
                        block=2;
                        for(i=0; i<3; i++)
                        {
                            for(j=3; j<6; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=1)&&(row_num<=3)&&(column_num>=7)&&(column_num<=9))   // block 3
                    {
                        block=3;
                        for(i=0; i<3; i++)
                        {
                            for(j=6; j<9; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=4)&&(row_num<=6)&&(column_num>=1)&&(column_num<=3))   // block 4
                    {
                        block=4;
                        for(i=3; i<6; i++)
                        {
                            for(j=0; j<3; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=4)&&(row_num<=6)&&(column_num>=4)&&(column_num<=6))   // block 5
                    {
                        block=5;
                        for(i=3; i<6; i++)
                        {
                            for(j=3; j<6; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=4)&&(row_num<=6)&&(column_num>=7)&&(column_num<=9))   // block 6
                    {
                        block=6;
                        for(i=3; i<6; i++)
                        {
                            for(j=6; j<9; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=7)&&(row_num<=9)&&(column_num>=1)&&(column_num<=3))   // block 7
                    {
                        block=7;
                        for(i=6; i<9; i++)
                        {
                            for(j=0; j<3; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=7)&&(row_num<=9)&&(column_num>=4)&&(column_num<=6))   // block 8
                    {
                        block=8;
                        for(i=6; i<9; i++)
                        {
                            for(j=3; j<6; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else                                                                    // block 9
                    {
                        block=9;
                        for(i=6; i<9; i++)
                        {
                            for(j=6; j<9; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }


                    for(i=0; i<9; i++)
                    {

                        if(sudoku[row_num-1][i][0] == (num+'0'))
                        {
                            flag_repeat_in_row=1;
                            break;
                        }

                    }


                    for(j=0; j<9; j++)
                    {

                        if(sudoku[j][column_num-1][0] == (num+'0'))
                        {
                            flag_repeat_in_column=1;
                            break;
                        }

                    }



                    if(num==-1)    // empty place
                    {
                        trials--;
                        sudoku[row_num-1][column_num-1][0] = '-';
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }
                    else if(num==0)
                    {
                        system("cls");
                        show_trials(trials);
                        print2Dstr(ANSWER,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n\n>> THIS IS THE ANSWER\n\n>> GAME OVER -__-\n");
                        setConsoleColor(14);
                        printf("\n>> press any button to exit -__-\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        exit(0);
                        setConsoleColor(15);
                    }

                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==1)&&(flag_block==0))       // number is repeated in this row and column
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) AND THIS COLUMN (%d)\n",num,row_num,column_num);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }


                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==1)&&(flag_block==1))       // number is repeated in this row and column and 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) AND THIS COLUMN (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,row_num,column_num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }


                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==0)&&(flag_block==0))       // number is repeated in this row only
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d)\n",num,row_num);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }


                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==0)&&(flag_block==1))       // number is repeated in this row only and 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,row_num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }

                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==1)&&(flag_block==0))       // number is repeated in this column only
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS COLUMN (%d)\n",num,column_num);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }


                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==1)&&(flag_block==1))       // number is repeated in this column only and 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS COLUMN (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,column_num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }

                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==0)&&(flag_block==1))       // number is repeated in this 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS 3*3 BLOCK '%d'\n",num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                    }


                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==0)&&(flag_block==0))       // number isn't repeated
                    {

                        if(sudoku[row_num-1][column_num-1][0] != '-')        // we wrote in this place before
                        {
                            trials--;
                        }
                        sudoku[row_num-1][column_num-1][0] = num+'0';
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_medium,9);
                        playButtonPressSound();
                    }






                }





            }
            else       // error in range for inputs
            {
                trials--;
                system("cls");
                show_trials(trials);
                print2Dstr(sudoku,const_elements_medium,9);
                setConsoleColor(12);
                printf("\n\n>> ERROR IN INPUT VALUES , MAKE SURE THAT :-\n>> NUMBER , ROW NUMBER , COLUMN NUMBER SHOULD BE FROM '1' TO '9'\n");
                setConsoleColor(14);
                printf("\n>> press any button to try again ^__^\n");
                setConsoleColor(15);
                playErrorSound();
                getch();
                system("cls");
                show_trials(trials);
                print2Dstr(sudoku,const_elements_medium,9);
            }

            winner_flag=0;

            for(i=0; i<9; i++)      // check if user wins or not
            {

                for(j=0; j<9; j++)
                {
                    if(sudoku[i][j][0] == '-')
                    {
                        winner_flag=1;
                        break;
                    }
                }
                if(winner_flag==1)
                {
                    break;
                }
            }


            if(winner_flag==0)
            {
                system("cls");
                show_trials(trials);
                print2Dstr(sudoku,const_elements_medium,9);
                setConsoleColor(10);
                printf("\n\n>> CONGRATULATION !!!  YOU WIN ^__^\n\n");
                setConsoleColor(14);
                printf("\n>> press any button to exit ^__^\n");
                setConsoleColor(15);
                playWinSound();
                getch();
                exit(0);
                setConsoleColor(15);

            }


        }


    }




}


/*******************************************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************************************************/

// HARD

void hard_level(void)
{
    int i,j,flag_repeat_in_row=0,flag_repeat_in_column=0,num,row_num,column_num,block=0,flag_block=0,winner_flag=0,trials=3;

    static char sudoku[9][9][2]= { {"9"," ","6"," ","1","3"," "," ","8"},
        {" ","5","8"," "," "," "," ","9"," "},
        {" ","3"," "," "," "," "," ","1"," "},
        {" ","6"," ","8"," "," ","9","2"," "},
        {" "," ","3","4"," ","9","1"," "," "},
        {" ","4","9"," "," ","6"," ","3"," "},
        {" ","9"," "," "," "," "," ","8"," "},
        {" ","1"," "," "," "," ","6","7"," "},
        {"4"," "," ","9","6"," ","3"," ","1"}
    };

    static const char const_elements_hard[9][9][2] = { {"9"," ","6"," ","1","3"," "," ","8"},
        {" ","5","8"," "," "," "," ","9"," "},
        {" ","3"," "," "," "," "," ","1"," "},
        {" ","6"," ","8"," "," ","9","2"," "},
        {" "," ","3","4"," ","9","1"," "," "},
        {" ","4","9"," "," ","6"," ","3"," "},
        {" ","9"," "," "," "," "," ","8"," "},
        {" ","1"," "," "," "," ","6","7"," "},
        {"4"," "," ","9","6"," ","3"," ","1"}
    };


    for(i=0; i<9; i++)
    {

        for(j=0; j<9; j++)
        {

            if(sudoku[i][j][0] == ' ')
            {
                sudoku[i][j][0]='-';
            }
        }

    }

    setConsoleColor(10);
    printf("\n>> WELCOME TO <HARD LEVEL>\n");
    printf("\n>> ARE YOU READY TO START ? \n\n");
    setConsoleColor(12);
    printf(">> To empty place Enter number -1\n");
    printf(">> To leave the game and show the answer , Enter number 0 , and any adjustable [row , column]\n");
    setConsoleColor(14);
    printf(">> press any button to start ^__^\n");
    setConsoleColor(15);
    playWelcomeSound();
    getch();
    system("cls");
    show_trials(trials);
    print2Dstr(sudoku, const_elements_hard,9);

    while(1)
    {

        flag_repeat_in_column=0, flag_repeat_in_row=0;

        if(trials==0)
        {

            system("cls");
            show_trials(trials);
            print2Dstr(sudoku,const_elements_hard,9);
            setConsoleColor(12);
            printf("\n\n>> THERE ARE NO TRIALS\n\n>> GAME OVER -__-\n");
            setConsoleColor(14);
            printf("\n>> press any button to exit -__-\n");
            setConsoleColor(15);
            playErrorSound();
            getch();
            exit(0);
            setConsoleColor(15);
        }

        else
        {

            setConsoleColor(14);
            printf("\n\n>> Enter number        >>  ");
            setConsoleColor(10);
            scanf("%d",&num);
            playButtonPressSound();
            //printf("\n");

            setConsoleColor(14);
            printf(">> Enter row number    >>  ");
            setConsoleColor(10);
            scanf("%d",&row_num);
            playButtonPressSound();
            //printf("\n");

            setConsoleColor(14);
            printf(">> Enter column number >>  ");
            setConsoleColor(10);
            scanf("%d",&column_num);
            setConsoleColor(15);
            playButtonPressSound();
            //printf("\n\n");


            if(((num>=-1)&&(num<=9))&&((row_num>=1)&&(row_num<=9))&&((column_num>=1)&&(column_num<=9)))    // check if values in the right range
            {


                if(const_elements_hard[row_num-1][column_num-1][0] != ' ')    // this place is for the main program (can't be modified)
                {
                    trials--;
                    system("cls");
                    show_trials(trials);
                    print2Dstr(sudoku,const_elements_hard,9);
                    setConsoleColor(12);
                    printf("\n>> SORRY , You can't write in this place\n");
                    setConsoleColor(14);
                    printf("\n>> press any button to try again ^__^\n");
                    setConsoleColor(15);
                    playErrorSound();
                    getch();
                    system("cls");
                    show_trials(trials);
                    print2Dstr(sudoku,const_elements_hard,9);

                }





                else       // a place which can be modified
                {

                    block=0;
                    flag_block=0;
                    if((row_num>=1)&&(row_num<=3)&&(column_num>=1)&&(column_num<=3))        // block 1
                    {
                        block=1;
                        for(i=0; i<3; i++)
                        {
                            for(j=0; j<3; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=1)&&(row_num<=3)&&(column_num>=4)&&(column_num<=6))   // block 2
                    {
                        block=2;
                        for(i=0; i<3; i++)
                        {
                            for(j=3; j<6; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=1)&&(row_num<=3)&&(column_num>=7)&&(column_num<=9))   // block 3
                    {
                        block=3;
                        for(i=0; i<3; i++)
                        {
                            for(j=6; j<9; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=4)&&(row_num<=6)&&(column_num>=1)&&(column_num<=3))   // block 4
                    {
                        block=4;
                        for(i=3; i<6; i++)
                        {
                            for(j=0; j<3; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=4)&&(row_num<=6)&&(column_num>=4)&&(column_num<=6))   // block 5
                    {
                        block=5;
                        for(i=3; i<6; i++)
                        {
                            for(j=3; j<6; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=4)&&(row_num<=6)&&(column_num>=7)&&(column_num<=9))   // block 6
                    {
                        block=6;
                        for(i=3; i<6; i++)
                        {
                            for(j=6; j<9; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=7)&&(row_num<=9)&&(column_num>=1)&&(column_num<=3))   // block 7
                    {
                        block=7;
                        for(i=6; i<9; i++)
                        {
                            for(j=0; j<3; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else if((row_num>=7)&&(row_num<=9)&&(column_num>=4)&&(column_num<=6))   // block 8
                    {
                        block=8;
                        for(i=6; i<9; i++)
                        {
                            for(j=3; j<6; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }
                    else                                                                    // block 9
                    {
                        block=9;
                        for(i=6; i<9; i++)
                        {
                            for(j=6; j<9; j++)
                            {
                                if(num==(sudoku[i][j][0]-'0'))
                                {
                                    flag_block=1;
                                    break;
                                }
                            }
                            if(flag_block==1)
                            {
                                break;
                            }
                        }
                    }


                    for(i=0; i<9; i++)
                    {

                        if(sudoku[row_num-1][i][0] == (num+'0'))
                        {
                            flag_repeat_in_row=1;
                            break;
                        }

                    }


                    for(j=0; j<9; j++)
                    {

                        if(sudoku[j][column_num-1][0] == (num+'0'))
                        {
                            flag_repeat_in_column=1;
                            break;
                        }

                    }


                    if(num==-1)    // empty place
                    {
                        trials--;
                        sudoku[row_num-1][column_num-1][0] = '-';
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }
                    else if(num==0)
                    {
                        system("cls");
                        show_trials(trials);
                        print2Dstr(ANSWER,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n\n>> THIS IS THE ANSWER\n\n>> GAME OVER -__-\n");
                        setConsoleColor(14);
                        printf("\n>> press any button to exit -__-\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        exit(0);
                        setConsoleColor(15);
                    }

                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==1)&&(flag_block==0))       // number is repeated in this row and column
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) AND THIS COLUMN (%d)\n",num,row_num,column_num);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }


                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==1)&&(flag_block==1))       // number is repeated in this row and column and 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) AND THIS COLUMN (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,row_num,column_num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }


                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==0)&&(flag_block==0))       // number is repeated in this row only
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d)\n",num,row_num);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }


                    else if((flag_repeat_in_row==1)&&(flag_repeat_in_column==0)&&(flag_block==1))       // number is repeated in this row only and 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS ROW (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,row_num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }

                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==1)&&(flag_block==0))       // number is repeated in this column only
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS COLUMN (%d)\n",num,column_num);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }


                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==1)&&(flag_block==1))       // number is repeated in this column only and 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS COLUMN (%d) , AND IN THIS 3*3 BLOCK '%d'\n",num,column_num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }

                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==0)&&(flag_block==1))       // number is repeated in this 3*3 block
                    {
                        trials--;
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        setConsoleColor(12);
                        printf("\n>> SORRY !!!  '%d' IS IN THIS 3*3 BLOCK '%d'\n",num,block);
                        setConsoleColor(14);
                        printf("\n>> press any button to try again ^__^\n");
                        setConsoleColor(15);
                        playErrorSound();
                        getch();
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                    }


                    else if((flag_repeat_in_row==0)&&(flag_repeat_in_column==0)&&(flag_block==0))       // number isn't repeated
                    {

                        if(sudoku[row_num-1][column_num-1][0] != '-')      // we wrote in this place before
                        {
                            trials--;
                        }

                        sudoku[row_num-1][column_num-1][0] = num+'0';
                        system("cls");
                        show_trials(trials);
                        print2Dstr(sudoku,const_elements_hard,9);
                        playButtonPressSound();
                    }






                }





            }
            else       // error in range for inputs
            {
                trials--;
                system("cls");
                show_trials(trials);
                print2Dstr(sudoku,const_elements_hard,9);
                setConsoleColor(12);
                printf("\n\n>> ERROR IN INPUT VALUES , MAKE SURE THAT :-\n>> NUMBER , ROW NUMBER , COLUMN NUMBER SHOULD BE FROM '1' TO '9'\n");
                setConsoleColor(14);
                printf("\n>> press any button to try again ^__^\n");
                setConsoleColor(15);
                playErrorSound();
                getch();
                system("cls");
                show_trials(trials);
                print2Dstr(sudoku,const_elements_hard,9);
            }

            winner_flag=0;

            for(i=0; i<9; i++)      // check if user wins or not
            {

                for(j=0; j<9; j++)
                {
                    if(sudoku[i][j][0] == '-')
                    {
                        winner_flag=1;
                        break;
                    }
                }
                if(winner_flag==1)
                {
                    break;
                }
            }


            if(winner_flag==0)
            {
                system("cls");
                show_trials(trials);
                print2Dstr(sudoku,const_elements_hard,9);
                setConsoleColor(10);
                printf("\n\n>> CONGRATULATION !!!  YOU WIN ^__^\n\n");
                setConsoleColor(14);
                printf("\n>> press any button to exit ^__^\n");
                setConsoleColor(15);
                playWinSound();
                getch();
                exit(0);
                setConsoleColor(15);

            }


        }


    }




}

