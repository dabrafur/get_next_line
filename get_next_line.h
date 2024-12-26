#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    char            *str_buf;
    struct s_list   *next;
}   t_list;

t_list	*find_last_node(t_list *list);
void    dealloc(t_list **list, t_list *clean_node, char *buf);
int     len_to_newline(t_list *list);
void    cp_strto(t_list *list, char *str);
int	    found_newline(t_list *list);
void    handle_rest(t_list **list);
char    *get_line(t_list *list);
void    create_list(t_list **list, int fd);
char    *get_next_line(int fd);

#endif