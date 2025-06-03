/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:26:41 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/01 13:39:13 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t dst_len;
    
    i = 0;
    dst_len = ft_strlen(dst);
    if (dstsize <= dst_len){
        return (dstsize + ft_strlen(src));
    }

    else{
        while (i + dst_len < dstsize - 1 && src[i])
        {
            dst[dst_len + i] = src[i];
            i++;
        }
        dst[dst_len + i] = '\0';
    }
    return (dst_len + ft_strlen(src));
}