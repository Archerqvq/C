#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MONTHS_IN_A_YEAR 12

// Array to hold the number of days in each month
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Array of month names for display
const char *months[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

// Function to prompt user for a year and read their input
int inputyear(void)
{
    int year;
    printf("please enter a year (example: 1999) : ");
    scanf("%d", &year);
    getchar(); // Consume the newline character to avoid issues with subsequent input
    return year;
}

// Function to determine if a year is a leap year and adjust February days
void determineleapyear(int year)
{
    if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
    {
        days_in_month[1] = 29; // Set February to 29 days for a leap year
    }
}

// Function to determine the day code (day of the week for January 1st of the given year)
int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3, res;

    // Calculate leap year offset
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    res = d1 - d2 + d3;

    // Calculate the day code
    daycode = ((year - 1) * 365 + res + 1) % 7;

    return daycode;
}

// Function to print the calendar for a given year and starting day code
void calendar(int year, int daycode)
{
    for (int month = 0; month < MONTHS_IN_A_YEAR; month++)
    {
        int day = 0;                     // Start with the first day of the month
        printf("\n\n%s", months[month]); // Print month name
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Adjust the first position based on the day code
        for (int i = 0; i < 3 + daycode * 5; i++)
        {
            printf(" ");
        }

        // Print the first line of dates for the current month
        do
        {
            day++;
            printf("%2d   ", day);
        } while ((day + daycode) % 7 != 0);
        printf("\n");
        day += 1;

        // Print the remaining dates for the current month
        for (; day <= days_in_month[month]; day++)
        {
            printf("   %2d", day);
            if ((day % 7) == (7 - daycode))
            {
                printf("\n");
            }
        }
        // Calculate the day code for the next month
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main(void)
{
    int year, daycode, leapyear;
    year = inputyear();                 // Get the year from the user
    daycode = determinedaycode(year);   // Calculate the day code for the year
    leapyear = determineleapyear(year); // Determine if it's a leap year and adjust February
    calendar(year, daycode);            // Print the calendar for the year
    printf("\n");
    return 0;
}