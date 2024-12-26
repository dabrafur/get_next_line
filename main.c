#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);

    while((line = get_next_line(fd)))
        printf("%s\n", line);

    return (0);
}