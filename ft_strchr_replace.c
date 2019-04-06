#include "libft.h"

void	ft_strchr_replace(char **s, int old, int new)
{
	size_t	i;

	if (!s || !*s || !**s)
		return ;
	i = -1;
	while ((*s)[++i])
		if ((*s)[i] == old)
			(*s)[i] = new;
}
