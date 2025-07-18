#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char *arr;

    i = 0;
    arr = (char *)malloc((len + 1) * sizeof(char));
    if (!arr)
        return (NULL);
    while(start > 0 && *s)
    {
        start--;
        s++;
    }
    
    while (i < len && *s)
    {
        arr[i] = *s;
        i++;
        s++;
    }
    arr[i] = '\0';
    return arr;
}

int main()
{
    const char *s = "yusuf kaya";
    char *my_string = ft_substr(s, 6, 4);
    printf("%s", my_string);
    free(my_string);
    
}
