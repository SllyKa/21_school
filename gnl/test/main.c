#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "get_next_line.h"

int main()
{
    char *line;
    int fd;
    int error_code;

    if ((fd = open("0.txt", O_RDONLY)) < 0)
        return (-1);
    time_t start = time(NULL);
    while ((error_code = get_next_line(fd, &line) > 0))
    {
        //printf("our line: %s\n", line);
        //printf("with code: %i\n", error_code);
    }
    time_t end = time(NULL);
    double tt = (double)(end - start);

    printf("our line: %s\n", line);
    printf("with code: %i\n", error_code);
    printf("\n\n%-10s%.4lf", "time:", tt);
    return (0);
}