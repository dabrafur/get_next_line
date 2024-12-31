#include "get_next_line.h"

size_t ft_strlen(const char *str) //retorna comprimento de str
{
    int len;

    len = 0;
    while(str[len])
        len++;
    return (len);
}

char *ft_strchr(const char *s, int c) // retorna a string a partir da primeira ocorrência de c
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char *ft_strdup(const char *s1) //retorna uma cópa de s1
{
    char *s2;
    int i;

    s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!s2)
        return NULL;
    i = 0;
    while (*s1)
    {
        s2[i] = s1[i];
        i++;
    }

    s2[i] = '\0';
    return (s2);
}

char *ft_strjoin(char const *s1, char const *s2) //coloca s2 no final de s1
{
    char *s3;
    size_t i;
    size_t j;

    s3 = (char *)malloc(sizeof (char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
    if (!s3)
        return (NULL);
    
    i = 0;
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        s3[i + j] = s2[j];
        j++;
    }
    s3[i + j] = '\0';
    return (s3);
}

char *ft_substr(char const *s, unsigned int start, size_t len) //retornar substrind de s que começa em start e tem len de comprimento.
{
    char *sub;
    size_t i;

    if (!s)
        return (NULL);
    if ((size_t)start >= ft_strlen(s))
        return (ft_strdup(""));
    sub = (char *)malloc(sizeof (char) * (len + 1));
    if (!sub)
        return (NULL);
    i = 0;
    while (s[start + i] && i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
