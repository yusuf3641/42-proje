#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char    *ft_strdup(const char *s)
{
    size_t  i;
    size_t  len;
    char *array;
    
    i = 0;
    len = ft_strlen(s);
    array = (char *)malloc((len + 1) * sizeof(char));
    if (!array)
        return (NULL);
    while (i < len)
    {
        array[i] = s[i];
        i++;
    }
    array[i] = '\0';
    return (array);
}
