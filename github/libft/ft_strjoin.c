#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *arr;
    int len_s1;
    int len_s2;
    int i;
    int j;

    i = 0;
    j = 0;
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    arr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if (!arr)
        return (NULL);
    while (i < len_s1 && s1[i])
    {
        arr[i] = s1[i];
        i++;
    }
    while (j < len_s2 && s2[j])
    {
        arr[i + j] = s2[j];
        j++;
    }
    arr[i + j] = '\0';
    return (arr);
}
