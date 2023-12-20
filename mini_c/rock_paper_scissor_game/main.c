#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int usrScore = 0, compScore = 0;

void checkOptions(int usr, int comp);

int main(void)
{
    int userChoice, compChoice, roundNum = 0;
    printf("\t\t\t\t==========*Welcome to Rock, Paper & Scissor Game*==========\n");
    srand(time(0));

    while (userChoice != 4)
    {
        printf("\nRound %d", ++roundNum);
        printf("\nPlease select the option: ");
        printf("\n1.Scissor");
        printf("\n2.Paper");
        printf("\n3.Rock");
        printf("\n4.Quit\n");
        scanf("%d", &userChoice);
        compChoice = (rand() % 3) + 1;
        checkOptions(userChoice, compChoice);
    }

    return 0;
}

void checkOptions(int usr, int comp)
{
    // 1 = scissor, 2 = paper, 3 = rock
    if (usr == comp)
    {
        printf(" -------------------------\n");
        printf("|        Its a tie        |\n");
        printf(" -------------------------\n");
    }
    else if (usr == 1)
    {
        if (comp == 2)
        {
            printf(" --------------------------\n");
            printf("|        You Won :)        |\n");
            printf("|  You: Scissor            |\n");
            printf("|  Computer: Paper         |\n");
            printf(" --------------------------\n");
            usrScore++;
        }
        else
        {
            printf(" --------------------------\n");
            printf("|        You Lose :(       |\n");
            printf("|  You: Paper              |\n");
            printf("|  Computer: Scissor       |\n");
            printf(" --------------------------\n");
            compScore++;
        }
    }
    else if (usr == 2)
    {
        if (comp == 3)
        {
            printf(" --------------------------\n");
            printf("|        You Won :)        |\n");
            printf("|  You: Paper              |\n");
            printf("|  Computer: Rock          |\n");
            printf(" --------------------------\n");
            usrScore++;
        }
        else
        {
            printf(" --------------------------\n");
            printf("|        You Lose :(       |\n");
            printf("|  You: Rock               |\n");
            printf("|  Computer: Paper         |\n");
            printf(" --------------------------\n");
            compScore++;
        }
    }
    else if (usr == 3)
    {
        if (comp == 1)
        {
            printf(" --------------------------\n");
            printf("|        You Won :)        |\n");
            printf("|  You: Rock               |\n");
            printf("|  Computer: Scissor       |\n");
            printf(" --------------------------\n");
            usrScore++;
        }
        else
        {
            printf(" --------------------------\n");
            printf("|        You Lose :(       |\n");
            printf("|  You: Scissor            |\n");
            printf("|  Computer: Rock          |\n");
            printf(" --------------------------\n");
            compScore++;
        }
    }
    else if (usr == 4)
    {
        printf(" --------------------------\n");
        if (usrScore > compScore)
        {
            printf("|        You Won :)        |\n");
        }
        else if (usrScore < compScore)
        {
            printf("|        You Lose :(       |\n");
        }
        else if (usrScore == compScore)
        {
            printf("|        Its a tie         |\n");
        }
        printf("|      Final Score         |\n");
        printf("|      You: %2d             |\n", usrScore);
        printf("|     Computer:%2d          |\n", compScore);
        printf(" --------------------------\n");
    }
}