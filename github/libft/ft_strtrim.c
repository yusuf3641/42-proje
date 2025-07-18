#include <stdlib.h>
#include <stdio.h>
#include "libft.h"


int    ft_strlen(const char *s)
{
    int    i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

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

static int for_start(const char *s1, const char *set)
{
    int start_location;
    int i;
    int j;
    int for_check;
    
    start_location = 0;
    i = 0;
    j = 0;
    while (s1[i]){
        j = 0;
        for_check = 0;
        while (set[j]){
            if(s1[i] == set[j])
                for_check = 1;
            j++;
        }
        if(!for_check)
            break;
        i++;
    }
    return i;
}

static int for_end(const char *s1, const char *set)
{
    int i;
    int j;
    int for_check;
    
    i = ft_strlen(s1);
    j = 0;
    while (i > 0){
        j = 0;
        for_check = 0;
        while (set[j]){
            if(s1[i - 1] == set[j])
                for_check = 1;
            j++;
        }
        i--;
        if(!for_check)
            break;
    }
    return (i);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *arr;
    int start;
    int end;
    int len;
    int i;

    if (!s1 || !set)
        return NULL;
    i = 0;
    len = ft_strlen(s1);
    start = for_start(s1,set);
    end = for_end(s1,set);
    if (start == len)
        return (ft_strdup(""));
    arr = (char *)malloc((end - start + 1) * sizeof(char));
    while (start + i <= end)
    {
        arr[i] = s1[i + start];
        i++;
    }
    arr[i] = '\0';
    return (arr);
}

#include <stdio.h>
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set); // Fonksiyon senin libft içinde olacak

int main(void)
{
    char *result;

    // 1. Baştan ve sondan kırpılma
    result = ft_strtrim("+----+3++hello+++", "-+-");
    printf("1: \"%s\"\n", result);
    free(result);



    return 0;
}
