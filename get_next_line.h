#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//#include <libgen.h>

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *get_next_line(int fd);

#endif