/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:18:19 by yuskaya           #+#    #+#             */
/*   Updated: 2025/06/03 13:50:51 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


HATA var Tam çıtı vermiyor 
#include <stddef.h>
#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len > i && haystack[i]){
		
		j = 0;
		while (len >= i + j && needle[j] == haystack[i + j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return (char *) haystack + i;
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len);

int main(void)
{
	// 1. Normal arama (bulunur)
	printf("1: %s\n", ft_strnstr("Merhaba dünya", "dünya", 20)); // beklenen: "dünya"

	// 2. Normal arama (bulunamaz)
	printf("2: %s\n", ft_strnstr("Merhaba dünya", "gezegen", 20)); // beklenen: (null)

	// 3. len sınırları dışında (bulunamaz)
	printf("3: %s\n", ft_strnstr("Merhaba dünya", "dünya", 5)); // beklenen: (null)

	// 4. len sınırı tam eşleşmeye kadar yeterli
	printf("4: %s\n", ft_strnstr("Merhaba dünya", "dünya", 13)); // beklenen: "dünya"

	// 5. needle boş string (her zaman haystack döner)
	printf("5: %s\n", ft_strnstr("test bu", "", 10)); // beklenen: "test bu"

	// 6. haystack boş, needle boş ("" içinde "" aramak)
	printf("6: %s\n", ft_strnstr("", "", 0)); // beklenen: ""

	// 7. haystack boş, needle dolu
	printf("7: %s\n", ft_strnstr("", "abc", 0)); // beklenen: (null)

	// 8. haystack içinde needle ama len küçük
	printf("8: %s\n", ft_strnstr("abcdef", "def", 4)); // beklenen: (null)

	// 9. haystack içinde needle ama sondan taşar
	printf("9: %s\n", ft_strnstr("123456", "56", 5)); // beklenen: (null)

	// 10. needle haystack’in başında
	printf("10: %s\n", ft_strnstr("hello world", "hello", 5)); // beklenen: "hello world"

	// 11. needle haystack’in sonunda, len yetiyor
	printf("11: %s\n", ft_strnstr("abcde", "e", 5)); // beklenen: "e"

	// 12. aynı string içinde arama
	printf("12: %s\n", ft_strnstr("abcabcabc", "abc", 9)); // beklenen: "abcabcabc"

	// 13. NULL karakter test (gözükmez ama arka planda olabilir)
	printf("13: %s\n", ft_strnstr("abc\0def", "def", 7)); // beklenen: (null)

	return 0;
}
