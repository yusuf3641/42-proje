char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	
	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len > i){
		if (haystack[i] == needle[0])
		{	
			while (len >= i && needle[j]){
				if (haystack[i] != needle[j])
					return (NULL); 
				i++;
				j++;	
			}
			if (j < ft_strlen((char *) needle))
				return (NULL);
			return (char *) haystack + i - j;
		}
		i++;
	}
	return (NULL);
}
benim yazdığım kod bu sence nasıl