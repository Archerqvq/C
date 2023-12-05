#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    system("color 3F");
    int pin = 1234, option, enteredPin, count = 0, amount = 1;
    float balance = 5000;
    int countinueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t             %s", ctime(&now));
    printf("\n\t\t\t=========================*Welcome to ATM*=========================\n");

    while (pin != enteredPin)
    {
        printf("\nPlease enter you pin : ");
        scanf("%d", &enteredPin);
        if (pin != enteredPin)
        {
            Beep(610, 500);
            printf("Invalid pin!!!");
        }
        count++;
        if (count == 3 && pin != enteredPin)
        {
            printf("\n\nSorry, you have entered wrong pin 3 times. :(\n\n");
            exit(0);
        }
    }

    while (countinueTransaction != 0)
    {
        printf("\n\t\t\t=========================*Availale Transactions*=========================");
        printf("\n\n\t\t1.Withdrawl");
        printf("\n\t\t2.Deposit");
        printf("\n\t\t3.Check Balance");
        printf("\n\n\tPlease select the option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            while (amount % 500 != 0)
            {
                printf("\n\t\tEnter the amount :");
                scanf("%d", &amount);
                if (amount % 500 != 0)
                {
                    printf("\n\t The amount should be multiple of 500");
                }
            }
            if (balance < amount)
            {
                printf("\n\t Sorry insufficient balance");
                amount = 1;
                break;
            }
            else
            {
                balance -= amount;
                printf("\n\t\tYou have withdrawn %d RMB. Your new balance is %.2f", amount, balance);
                amount = 1;
                break;
            }

        case 2:
            printf("\n\t\t Please enter the amount : ");
            scanf("%d", &amount);
            balance += amount;
            printf("\n\t\tYou have deposited %d RMB. Your new balance is %.2f", amount, balance);
            amount = 1;
            break;

        case 3:
            printf("\n\t\tYour balance is %.2f RMB", balance);
            break;

        default:
            Beep(610, 500);
            printf("\n\t\tInvalid option!!!");
        }

        printf("\n\n\t\t=======================================================================");
        printf("\n\t\tDo you wish to perform another transaction? Press 1[Yes], 0[No]\n\t\t");
        scanf("%d", &countinueTransaction);
    }

    printf("\n\t\tThank you for using ATM, so gald to see you again. Have a nice day;)\n\n");

    return 0;
}