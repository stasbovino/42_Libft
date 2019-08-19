/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:09:59 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/18 19:30:38 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	var dcase:
**	0 for double
**	1 for long double
*/

static void	create_exp_and_mant(char *bits, int dcase, char **exp, char **mant)
{
	int i;

	i = -1;
	while (++i < ((dcase == 1) ? 80 : 64))
	{
		if (i > 0 && i < ((dcase == 1) ? 16 : 12))
			*exp = ft_optstrrejoin(*exp, bits[i] == '1' ? "1" : "0", 1);
		else if (i > ((dcase == 1) ? 16 : 11) && i < ((dcase == 1) ? 80 : 64))
			*mant = ft_optstrrejoin(*mant, bits[i] == '1' ? "1" : "0", 1);
	}
}

char		*bits_div(char *bits, t_options *opt, int dcase)
{
	char	*exp;
	char	*mant;
	char	*num;
	int		i;
	int		exp_int;

	i = -1;
	exp = ft_strnew(0);
	mant = ft_strnew(0);
	create_exp_and_mant(bits, dcase, &exp, &mant);
	exp_int = ft_atoi_binary(exp);
	if (exp_int == 0)
	{
		exp_int -= (dcase == 1) ? 16382 : 1022;
		num = create_fnum(mant, exp_int, 1, dcase);
	}
	else
	{
		exp_int -= (dcase == 1) ? 16383 : 1023;
		num = create_fnum(mant, exp_int, 0, dcase);
	}
	free(exp);
	free(mant);
	num = rounding(num, opt, 0, 0);
	return (num);
}

static char	*create_bits(long double *ld, double *d, int dcase)
{
	unsigned char	*a;
	int				i;
	char			*bits;
	int				len;

	i = -1;
	if (dcase == 1)
		a = (unsigned char*)ld;
	else
		a = (unsigned char*)d;
	bits = ft_strnew(0);
	len = (dcase == 1) ? (int)sizeof(*ld) - 6 : (int)sizeof(*d);
	while (++i < len)
	{
		bits = ft_optstrrejoin(ft_itoa_base(a[i], 2, 0), bits, 3);
		while (ft_strlen(bits) % 8 != 0)
			bits = ft_optstrrejoin("0", bits, 2);
	}
	return (bits);
}

char		*ft_itoa_double(double *n, t_options *opt, int *signfp)
{
	char			*bits;
	char			*num;

	bits = create_bits(0, n, 0);
	num = is_inf(bits, opt);
	if (num && (ft_strcmp(num, "nan") == 0 || ft_strcmp(num, "inf") == 0))
		opt->zeros = 0;
	if (num && ft_strcmp(num, "nan") == 0)
		*signfp = 0;
	else
		create_fsignfp(signfp, opt, bits);
	if (num == NULL)
		num = bits_div(bits, opt, 0);
	else if (opt->type == 'F')
		make_str_upper(num);
	free(bits);
	return (num);
}

char		*ft_itoa_longdouble(long double *n, t_options *opt, int *signfp)
{
	char			*bits;
	char			*num;

	bits = create_bits(n, 0, 1);
	num = is_inf(bits, opt);
	if (num && (ft_strcmp(num, "nan") == 0 || ft_strcmp(num, "inf") == 0))
		opt->zeros = 0;
	if (num && ft_strcmp(num, "nan") == 0)
		*signfp = 0;
	else
		create_fsignfp(signfp, opt, bits);
	if (num == NULL)
		num = bits_div(bits, opt, 1);
	else if (opt->type == 'F')
		make_str_upper(num);
	free(bits);
	return (num);
}
