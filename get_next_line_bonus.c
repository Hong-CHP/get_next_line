#include "get_next_line_bonus.h"

char    *cut_line(char *dest, char **rest)
{
    static char    *line;
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
    free(dest);
    return (line);
}

char    *allo_init_buf(int fd, char **dest)
{
    char    *buff;
    size_t  bytes_read;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    if (!*dest)
        *dest = ft_strdup("");
    while (ft_strchr(*dest, '\n') == NULL)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buff);
            return (NULL);
        }
        buff[bytes_read] = '\0';
        *dest = ft_strjoin(*dest, buff);
    }
    return (*dest);
}

char    *get_next_line_bonus(int fd)
{
    char    *line;
    char    *rest;
    static char    *dest[1024];

    dest[fd] = allo_init_buf(fd, &dest[fd]);
    line = cut_line(dest[fd], &rest);
    dest[fd] = rest;
    return (line);
}

void ft_display_file(char *file1, char *file2, char *file3)
{
    int fd1;
    int fd2;
    int fd3;

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_RDONLY);
    fd3 = open(file3, O_RDONLY);
    printf("%s\n", get_next_line_bonus(fd1));
    printf("%s\n", get_next_line_bonus(fd2));
    printf("%s\n", get_next_line_bonus(fd3));
    printf("%s\n", get_next_line_bonus(fd1));
    printf("%s\n", get_next_line_bonus(fd2));
    close(fd1);
    close(fd2);
    close(fd3);
}

int main(int argc, char *argv[])
{
    char    *file1 = argv[1];
    char    *file2 = argv[2];
    char    *file3 = argv[3];

    if (argc != 4)
        return (1);
    ft_display_file(file1, file2, file3);
}
