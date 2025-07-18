#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void	*arr;
    size_t total;

    total = size * count;
    if (count != 0 && total / count != size)
        return (NULL);
    arr = malloc(total);
    if (!arr)
        return (NULL);
    ft_bzero(arr,total);
    return (arr);
}
