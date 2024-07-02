#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menu(void)
{
    printf("\n1------------->storing\n");
    printf("2------------->display\n");
    printf("3------------->number of words\n");
    printf("4------------->reverse\n");
    printf("0------------->exit\n");

    return (getchar());
}

char *storing()
{
    char array[80];
    char *type = NULL;

    printf("\ntype: ");
    // 80 is the maximum number of characters to read, including the newline character (\n) and the null terminator (\0).
    // If the user inputs more than 79 characters, fgets will read up to 79 characters and then add a newline character followed by a null terminator.
    fgets(array, 80, stdin);
    // malloc is used to allocate memory dynamically.
    // The size of the memory allocated is strlen(array) + 1 to accommodate the string and the null terminator.
    type = (char *)malloc(strlen(array) + 1);
    strcpy(type, array);

    return type;
}

void display(char array[])
{
    puts("\n");
    // puts(array); writes the string stored in array to the standard output, followed by a newline character.
    // This will print the content of array to the console and then move the cursor to the next line.
    puts(array);
}

void reverse(char *type)
{
    int icounter1, icounter2;
    char character;

    for (icounter1 = 0, icounter2 = strlen(type); icounter1 < icounter2 / 2; icounter1++)
    {
        character = type[icounter1];
        type[icounter1] = type[icounter2 - icounter1 - 1];
        type[icounter2 - icounter1 - 1] = character;
    }
}

int words(char *array)
{
    int icounter1, icounter2;
    int words = 0;

    for (icounter1 = 0, icounter2 = strlen(array); icounter1 < icounter2; icounter1++)
    {
        // if (array[icounter1 + 1] == ' ' || array[icounter1 + 1] == '\0' && array[icounter1] != ' ')
        // {
        //     words++;
        // }

        if (array[icounter1] != ' ' && array[icounter1] != '\0' && array[icounter1] != '\n')
        {
            words++;
        }
    }

    return words;
}

void main()
{
    char choice;
    char *type = "";

    while ((choice = menu()) != '0')
    {
        getchar();

        switch (choice)
        {
        case '1':
            type = storing();
            break;
        case '2':
            display(type);
            break;
        case '3':
            printf("\nnumber of words: %d\n", words(type));
            break;
        case '4':
            reverse(type);
            break;
        default:
            printf("try again");
        }

        printf("\n type to retrun to menu \n");
    }
}