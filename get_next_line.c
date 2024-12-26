#include "get_next_line.h"

void    handle_rest(t_list **list)
{
    t_list  *last_node;
    t_list  *new_node;
    int     i;
    int     k;
    char    *buf;

    buf = malloc(BUFFER_SIZE + 1);
    new_node = malloc(sizeof(t_list));
    if (NULL == buf || NULL == new_node)
        return ;
    last_node = find_last_node(*list);

    i = 0;
    k = 0;
    while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
            i++; //skip everithg that is nos a \0 or \n
    while (last_node->str_buf[i] && last_node->str_buf[++i])
            buf[k++] = last_node->str_buf[i]; // for files that dont have the \n in the end
    buf[k] = '\0';
    new_node->str_buf = buf;
    new_node->next = NULL;
    dealloc(list, new_node, buf);
}

char    *get_line(t_list *list)
{
    int     str_len;
    char    *next_str;

    if (NULL == list)
        return (NULL);
    //counthow many char are till '\n'
    //so i know how much to malloc
    str_len = len_to_newline(list);
    next_str = malloc(str_len + 1);
    if (NULL == next_str)
        return (NULL);
    
    //Coppy the string in the buffer to return it
    cp_strto(list, next_str);
    return (next_str);

}

void    link_to(t_list **list, char *buf)
{
    t_list  *new_node;
    t_list  *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (NULL == new_node)
        return ;
    //if the list is emptu null == *list
    if (NULL == last_node)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->str_buf = buf;
    new_node->next = NULL;
}

void    create_list(t_list **list, int fd)
{
//  Necessary to place the \0
    int     char_read;
    char    *buf;

//  scan line if '\n' present
    while (!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (NULL == buf)
            return ;

        char_read = read(fd, buf, BUFFER_SIZE);
        if (!char_read)
        {
            free(buf);
            return ;
        }
        buf[char_read] = '\0';
        //apend the node
        link_to(list, buf);
    } 
}

char    *get_next_line(int fd)
{
    static t_list   *list;
    char            *next_line; // what im looking for > functions return

    if (list == NULL)
        list = NULL;

//  check for some errors
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);
    
//  Create my list till find '\n''
    create_list(&list, fd);

    if (list == NULL)
        return  (NULL);
    
//  fetch the line from list
    next_line = get_line(list);

    handle_rest(&list);
    return (next_line);
}