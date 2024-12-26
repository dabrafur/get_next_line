#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    int     lines;

    lines = 1;
    fd = open("test.txt", O_RDONLY);

    while((line = get_next_line(fd)))
        printf("%d->%s\n", lines++, line);

    return (0);
}