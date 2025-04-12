#include "get_next_line.h"

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

char    *ft_strchr(const char *s, int c)
{
    int i;
    unsigned char   ch;

    ch = (unsigned char)c;
    if (s == NULL)
        return (NULL);
    i = 0;
    while (s[i])
    {
        if (s[i] == ch)
            return ((char *)&s[i]);
        i++;
    }
    if(ch == '\0')
        return ((char *)&s[i]);
    return (NULL);
}

char	*ft_strdup(const char *s)
{
	const char	*p;
	char		*dst;
	char		*ptr;

	if (!s)
		return (NULL);
	p = (const char *)s;
	dst = (char *)malloc((ft_strlen(p) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ptr = dst;
	while (*p)
		*ptr++ = *p++;
	*ptr = '\0';
	return (dst);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *dest;
    char *tmp;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!dest)
        return (NULL);
    tmp = dest;
    while (*s1)
        *tmp++ = *s1++;
    while (*s2)
        *tmp++ = *s2++;
    *tmp ='\0';
    return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *res;
    size_t i;

    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (s[start] && i < len)
    {
        res[i++] = s[start++];
    }
    res[i] = '\0';
    return (res);
}

