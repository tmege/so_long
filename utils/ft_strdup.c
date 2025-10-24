#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*dup;

	length = ft_strlen(s);
	dup = malloc((length + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dup[i] = s[i];
		i++;
	}
	dup[length] = '\0';
	return (dup);
}
