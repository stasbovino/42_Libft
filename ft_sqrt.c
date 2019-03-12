#include "libft.h"

size_t	ft_sqrt(size_t nb, int opt)
{
	size_t	i;

	i = 0;
	while (i < nb / 2)
	{
		if (i * i < nb && (i + 1) * (i + 1) > nb)
		{
			if (opt = -1)
				return (i);
			else
				return (i + 1);
		}
		else
			if (i * i == nb)
				return (i);
		i++;
	}
}
