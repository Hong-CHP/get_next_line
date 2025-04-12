#include "get_next_line.h"

//1. cut "helloo\nnew\n\0"
//2. get index of the first \n, here is 6
//3. if dest have a \n, line will be substr from dest and include the \n with end + 1 for length
//4. else if the test.txt has only one line without \n, line will be utill the end include \0
//5. if dest[end] is not at the end, rest will duplicate the the rest of dest, else null.
//6. clean and free the dest
//7. line = "helloo\n\0", rest = "new\n\0"
char    *cut_line(char *dest, char **rest)
{
    static char    *line;
    int     end;

    if (!dest)
        return (NULL);
    end = 0;
    while (dest[end] != '\n')
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

//1. check if fd is opened successfully and buf_size is positive
//2. allocate memo for buffer
//3. for the first call, dest allocated one char for '\0'
//4. while \n is not found in dest, keeping reading from the file and appending to the dest
//5. \n is found in dest, return dest
//6. if the test.txt is "helloo\nnew\nworld\n", dest will be "helloo\nnew\n\0" after the first call
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

//declare a static dest for stock buffer, line for line content, and rest for the rest of dest
//1. initial and allocate a buffer by fd and get the appended dest
//2. use cut_line for cut "helloo\nnew\n", get thr line and the rest of dest, dest is reusable
//3. give the content of rest to dest and prepare for the next time, return the line
//4. dest = "new\n\0"
//5. second call: remember the dest is still "new\n\0" buffer continue to read from the file start at 'w' found \n
//6. dest = "new\nworld\n\0", use the cut get line = "new\n\0" and rest = "world\n\0"
//7. dest = "world\n\0", get line = "world\n\0", rest = ft_strdup("") <-- ft_strdup(dest[end + 1])
//8. dest = "" bytes_read = 0 return null
char    *get_next_line(int fd)
{
    char    *line;
    char    *rest;
    static char    *dest;

    dest = allo_init_buf(fd, &dest);
    line = cut_line(dest, &rest);
    dest = rest;
    printf("%s\n", line);
    return (line);
}

void    ft_display_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    get_next_line(fd);
    //get_next_line(fd);
    //get_next_line(fd);
    close(fd);
}

int main(int argc, char *argv[])
{
    char    *file;

    if (argc != 2)
        return (1);
    file = argv[1];
    //printf("%d\n", ft_strlen(""));
    ft_display_file(file);
    return (0);
}

// char    *get_next_line(int fd)
// {
//     char    *buf;
//     static char *dest;
//     char    *line;
//     char    *rest;
//     size_t      bytes_read;

//     if (fd <= 0 || BUF_SIZE <= 0)
//         return (NULL);
//     buf = (char *)malloc((BUF_SIZE + 1) * sizeof (char));
//     if (!buf)
//         return (NULL);
//     if (!dest)
//         dest = ft_strdup("");
//     while (ft_strchr(dest, '\n') == NULL)
//     {
//         bytes_read = read(fd, buf, BUF_SIZE);
//         if (bytes_read <= 0)
//         {
//             free(buf);
//             return (NULL);
//         }
//         buf[bytes_read] = '\0';
//         dest = ft_strjoin(dest, buf);
//     }
//     //printf("%s\n", dest);
//     line = cut_line(dest, &rest);
//     dest = rest;
//     printf("%s\n", line);
//     //printf("%s\n", dest);
//     return (line);
// }
