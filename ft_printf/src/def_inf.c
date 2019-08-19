/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:35:06 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/18 20:42:06 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	expa(char *bits, int dcase)
{
	int	i;
	int len;

	len = (dcase == 1) ? 16 : 12;
	i = 0;
	if (bits[1] == '1')
	{
		while (++i < len)
			if (bits[i] != '1')
				return (-1);
		return (1);
	}
	else if (bits[1] == '0')
	{
		while (++i < len)
			if (bits[i] != '0')
				return (-1);
		return (0);
	}
	return (-1);
}

static int	mant(char *bits, int dcase)
{
	int	i;
	int len;

	len = (dcase == 1) ? 80 : 64;
	i = (dcase == 1) ? 17 : 12;
	if (bits[(dcase == 1) ? i + 1 : i] == '1')
	{
		while (++i < len)
			if (bits[i] != '1')
				return (-1);
		return (1);
	}
	else if (bits[(dcase == 1) ? i + 1 : i] == '0')
	{
		while (++i < len)
			if (bits[i] != '0')
				return (-1);
		return (0);
	}
	return (-1);
}

static	int	zero_bits(char *bits, int dcase)
{
	int				i;
	int				len;

	len = (dcase == 1) ? 80 : 64;
	i = 0;
	while (++i < len)
		if (bits[i] != '0')
			return (0);
	return (1);
}

static char	*is_inf_ld(char *b, int e, int m)
{
	if (e == 1 && b[16] == '0' && b[17] == '0' && m == 0)
		return (ft_strdup("inf"));
	if (e == 1 && b[16] == '0' && b[17] == '0' && m == 1)
		return (ft_strdup("nan"));
	if (e == 1 && b[16] == '0' && b[17] == '1')
		return (ft_strdup("nan"));
	if (e == 1 && b[16] == '1' && b[17] == '0' && m == 0)
		return (ft_strdup("inf"));
	if (e == 1 && b[16] == '1' && b[17] == '0' && m == 1)
		return (ft_strdup("nan"));
	if (e == 1 && b[16] == '1' && b[17] == '1' && m == 0)
		return (ft_strdup("nan"));
	if (e == 1 && b[16] == '1' && b[17] == '1' && m == 0)
		return (ft_strdup("nan"));
	if (e == 1 && b[16] == '1' && b[17] == '1' && m == 1)
		return (ft_strdup("nan"));
	return (NULL);
}

char		*is_inf(char *b, t_options *opt)
{
	int dcase;
	int e;
	int m;

	dcase = (ft_strlen(b) == 80) ? 1 : 0;
	e = expa(b, dcase);
	m = mant(b, dcase);
	if (zero_bits(b, dcase) == 1)
		return (rounding(ft_strdup("0."), opt, 0, 0));
	if (dcase == 1)
		return (is_inf_ld(b, e, m));
	if (e == 1 && m == 0)
		return (ft_strdup("inf"));
	else if (e == 1)
		return (ft_strdup("nan"));
	return (NULL);
}
