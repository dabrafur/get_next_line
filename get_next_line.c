#include "get_next_line.h"

static char *read_line(int fd, char *buf)
{

}


char *get_next_line(int fd)
{
    static char *buf;
    char *line; //onde vou guardar o que foi lido com read

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    buf = read_line(fd, buf);
    line = get_line(buf);

    





    return (line);
}
