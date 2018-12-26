#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <libc.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    char *line;
    int fd1, fd2, fd3, fd4, fd5, fd6, fd7, fd8, fd9, fd10;
    int error_code;
    int i = 0;
    int fd_count = 0;

    if ((fd1 = open("txt1", O_RDONLY)) < 0)
        return (-1);
    if ((fd2 = open("txt2", O_RDONLY)) < 0)
        return (-1);
    if ((fd3 = open("txt3", O_RDONLY)) < 0)
        return (-1);
    if ((fd4 = open("txt4", O_RDONLY)) < 0)
        return (-1);
    if ((fd5 = open("txt5", O_RDONLY)) < 0)
        return (-1);
    if ((fd6 = open("txt6", O_RDONLY)) < 0)
        return (-1);
    if ((fd7 = open("txt7", O_RDONLY)) < 0)
        return (-1);
    if ((fd8 = open("txt8", O_RDONLY)) < 0)
        return (-1);
    if ((fd9 = open("txt9", O_RDONLY)) < 0)
        return (-1);
    if ((fd10 = open("0.txt", O_RDONLY)) < 0)
        return (-1);
    int fd[] = {fd1, fd2, fd3, fd4, fd5, fd6, fd7, fd8, fd9, fd10};
    printf("fd_source: ");
    while (i < 10)
        printf("%i ", fd[i++]);
    printf("\n\n");
    srand(time(NULL));

    time_t start = time(NULL);

    printf("BUFF_SIZE: %i\n", BUFF_SIZE);
    fd_count = 0;
    while ((error_code = get_next_line(fd[9], &line)) > 0)
    {
        i++;
        //fd_count = (fd_count + 1) % 10;
        fd_count = rand() % 10;
        printf("our line: %s\n", line);
        //printf("%s\n", line);
        //printf("with code: %i\n", error_code);
        printf("fd: %i\n", fd[fd_count]);
        free(line);
    }
    time_t end = time(NULL);
    double tt = (double)(end - start);

    printf("our line: %s\n", line);
    printf("with code: %i\n", error_code);
    printf("\n\n%-10s%.4lf", "time:", tt);
    free(line);
    return (0);
}