#include "get_next_line_bonus.h"

char    *cut_line_and_rest(char *dest, char **line, char **rest)
{
    int i;

    if(!dest)
        return (NULL);
    i = 0;
    while (dest[i] != '\n')
        i++;
    if (dest[i] == '\n')
        line = ft_substr(dest, 0, i + 1);
}

char    *allocate_init_buffer(int fd, char  **dest)
{
    char    *buf;
    size_t  bytes_read;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return(NULL);
    if (!*dest)
        dest = ft_strdup("");
    while (ft_strchr(*dest, '\n') == NULL)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buf);
            return (NULL);
        }
        buf[bytes_read] = '\0';
        *dest = ft_strjoin(*dest, buf);
    }
    return (*dest);
}
char    *get_next_line_bonus(int fd)
{
    static char **dest;
    char    **line;
    char    **rest;
    
    dest = allocate_init_buffer(fd, &dest);

}

int ft_display_file(char *file)
{
    int fd3;
    int fd4;
    int fd5;

    fd3 = open(file, O_RDONLY);
    fd4 = open(file, O_RDONLY);
    fd5 = open(file, O_RDONLY);
    get_next_line_bonus(fd3);
    get_next_line_bonus(fd4);
    get_next_line_bonus(fd5);
    get_next_line_bonus(fd3);
    get_next_line_bonus(fd4);
    close(fd3);
    close(fd4);
    close(fd5);
}

int main(int argc, char *argv[])
{
    int i;
    char    *file1;
    char    *file2;
    char    *file3;

    i = 1;
    if (argc != 4)
        return (1);
    ft_display_file(file1);
    ft_display_file(file2);
    ft_display_file(file3);

}
