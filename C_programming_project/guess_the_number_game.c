#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;

    printf("Guess My number Game!\n\n");

    do
    {
        printf("Enter a guess between 1 and 100 : ");
        scanf("%d", &guess);

        tries++;
        if (guess > num)
        {
            printf("Too High!! \n");
        }
        else if (guess < num)
        {
            printf("Too Low!! \n");
        }
        else
        {
            printf("\n Correct you got it in %d guesses \n", tries);
        }
    } while (guess != num);

    return 0;
}