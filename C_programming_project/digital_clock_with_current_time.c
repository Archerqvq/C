#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    time_t s, val = 1;
    struct tm *current_time;

    while (1)
    {
        system("clear");
        // time in seconds
        s = time(NULL);
        // to get current time
        current_time = localtime(&s);
        // print time in minutes, hours and seconds
        printf("%02d : %02d : %02d", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}