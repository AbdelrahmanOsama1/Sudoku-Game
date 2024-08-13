// sudoku game

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void easy_level(void);
void medium_level(void);
void hard_level(void);
void playErrorSound(void);
void playButtonPressSound(void);
void playWelcomeSound(void);
void setConsoleColor(int textColor);


/*ANSWER =               { {"9","7","6","5","1","3","2","4","8"},
                           {"1","5","8","6","4","2","7","9","3"},
                           {"2","3","4","7","9","8","5","1","6"},
                           {"7","6","1","8","3","5","9","2","4"},
                           {"8","2","3","4","7","9","1","6","5"},
                           {"5","4","9","1","2","6","8","3","7"},
                           {"6","9","7","3","5","1","4","8","2"},
                           {"3","1","5","2","8","4","6","7","9"},
                           {"4","8","2","9","6","7","3","5","1"} }*/





int main()
{
    int level;

    while(1)
    {
        setConsoleColor(10);
        printf("\n>> Hello , Welcome to SUDOKU Game\n");
        printf(">> Please choose the level of difficulty you want :-\n\n");
        setConsoleColor(14);
        printf(">> 1- EASY LEVEL\n>> 2- MEDIUM LEVEL\n>> 3- HARD LEVEL\n\n>> ");
        playWelcomeSound();
        setConsoleColor(10);
        scanf("%d",&level);
        playButtonPressSound();

        if(level==1)
        {
            system("cls");
            easy_level();
        }
        else if(level==2)
        {
            system("cls");
            medium_level();
        }
        else if(level==3)
        {
            system("cls");
            hard_level();
        }
        else
        {
            system("cls");
            setConsoleColor(12);
            printf("\n>> ERROR !!! CHOOSE NUMBER FROM '1' TO '3'\n");
            setConsoleColor(14);
            printf(">> press any button to try again ^__^\n");
            playErrorSound();
            getch();
            system("cls");
            setConsoleColor(15);

        }

    }

    return 0;
}

