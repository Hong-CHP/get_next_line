#include "get_next_line_bonus.h"

size_t  ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (*s)
    {
        s++;
        len++;
    }
    return (len);
}

char    *ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return ((char *)&str[i]);
        i++;
    }
    if (c == '\0')
        return ((char *)&str[i]);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    char    *dest;
    char    *p;

    if (s == NULL)
        return (NULL);
    dest = (char *)malloc((ft_strlen(s) + 1) *sizeof(char));
    if (!dest)
        return (NULL);
    p = dest;
    while(*s)
        *p++ = *s++;
    *p = '\0';
    return (dest);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *dest;
    char    *p;

    if (!s1)
        s1 = ft_strdup("");
    if (!s2)
        s2 = ft_strdup("");
    dest = (char *)malloc((f_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!dest)
        return (NULL);
    p = dest;
    while (*s1)
        *p++ = *s1++;
    while (*s2)
        *p++ = *s2++;
    *p = '\0';
    return (dest);
}