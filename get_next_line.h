#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// t_list	*find_last_node(t_list *list);
// void    dealloc(t_list **list, t_list *clean_node, char *buf);
// int     len_to_newline(t_list *list);
// void    cp_strto(t_list *list, char *str);
// int	    found_newline(t_list *list);
// void    handle_rest(t_list **list);
// char    *get_line(t_list *list);
// void    create_list(t_list **list, int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);


size_t ft_strlen(const char *str);
char    *get_next_line(int fd);

#endif