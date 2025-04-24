#include "get_next_line_bonus.h"

char    *cut_line(char *dest, char **rest)
{
    char    *line;
    int     end;

    if (!dest)
        return (NULL);
    end = 0;
    while (dest[end] != '\n' && dest[end] != '\0')
        end++;
    if (dest[end] == '\n')
        line = ft_substr(dest, 0, end + 1);
    else
        line = ft_substr(dest, 0, end);
    if(dest[end] != '\0')
        *rest = ft_strdup(&dest[end + 1]);
    else
        *rest = NULL;
    return (line);
}

char    *allo_init_buf(int fd, char **dest)
{
    char    *buff;
    char    *temp;
    int  bytes_read;

    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    if (!*dest)
        *dest = ft_strdup("");
    bytes_read = 1;
    while (bytes_read > 0 && ft_strchr(*dest, '\n') == NULL)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buff);
            return (*dest);
        }
        buff[bytes_read] = '\0';
        temp = *dest;
        *dest = ft_strjoin(*dest, buff);
        free(temp);
    }
    free(buff);
    return (*dest);
}

char    *get_next_line_bonus(int fd)
{
    char    *line;
    char    *rest;
    char    *temp;
    static char    *dest[1024];

    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return (NULL);
    temp = allo_init_buf(fd, &dest[fd]);
    if (!temp)
        return (NULL);
    dest[fd] = temp;
    if (!dest[fd] || dest[fd][0] == '\0')
    {
        free(dest[fd]);
        dest[fd] = NULL;
        return (NULL);
    }
    line = cut_line(dest[fd], &rest);
    free(dest[fd]);
    dest[fd] = rest;
    return (line);
}

// void    ft_print_line(int fd)
// {
//     char    *line;

//     while ((line = get_next_line_bonus(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }
// }

// void ft_display_file(char *file1, char *file2, char *file3)
// {
//     int fd1;
//     int fd2;
//     int fd3;
//     char    *line;

//     fd1 = open(file1, O_RDONLY);
//     fd2 = open(file2, O_RDONLY);
//     fd3 = open(file3, O_RDONLY);
//     line = get_next_line_bonus(fd2);
//     printf("%s\n", line);
//     free(line);
//     ft_print_line(fd1);
//     ft_print_line(fd2);
//     ft_print_line(fd3);
//     close(fd1);
//     close(fd2);
//     close(fd3);
// }

// int main(int argc, char *argv[])
// {
//     char    *file1 = argv[1];
//     char    *file2 = argv[2];
//     char    *file3 = argv[3];

//     if (argc != 4)
//         return (1);
//     ft_display_file(file1, file2, file3);
// }
