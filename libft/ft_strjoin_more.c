#include "libft.h"

char	*ft_strjoin_more(char *s1, char const *s2)
{
	char	*str;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (i + j) + 2)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
    str[i++] = '+';
	str[i] = '\0';
	free(s1);
	return (str);
}