#include "get_next_line_bonus.h"

size_t  ft_strlen(const char *s)
{
    int len;

    if (!s)
        return (0);
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
    unsigned char ch;

    ch = (unsigned char)c;
    i = 0;
    if (str == NULL)
        return (NULL);
    while (str[i])
    {
        if (str[i] == ch)
            return ((char *)&str[i]);
        i++;
    }
    if (ch == '\0')
        return ((char *)&str[i]);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    const char  *ptr;
    char    *dest;
    char    *p;

    if (!s)
        return (NULL);
    ptr = (const char *)s;
    dest = (char *)malloc((ft_strlen(s) + 1) *sizeof(char));
    if (!dest)
        return (NULL);
    p = dest;
    while(*ptr)
        *p++ = *ptr++;
    *p = '\0';
    return (dest);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *res;
    size_t  i;

    if (!s) 
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (start + len >= ft_strlen(s))
        len = ft_strlen(s) - start;
    res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (s[start] && i <len)
        res[i++] = s[start++];
    res[i] = '\0';
    return (res);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *dest;
    char    *p;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
