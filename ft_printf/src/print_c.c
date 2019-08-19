/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:28:13 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/15 17:33:40 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_c_null(t_options *opt)
{
	char	*output;
	int		len;

	if ((opt->width - 1) > 0)
	{
		output = ft_strnew(opt->width - 1);
		if (opt->zeros == 1 && opt->left_side != 1)
			ft_memset(output, 48, opt->width - 1);
		else
			ft_memset(output, 32, opt->width - 1);
		if (opt->left_side == 1)
		{
			ft_putchar(0);
			return (count_and_free(output) + 1);
		}
		else
		{
			len = count_and_free(output);
			ft_putchar(0);
			return (len + 1);
		}
	}
	else
		ft_putchar(0);
	return (1);
}

int			print_c(char c, t_options *opt)
{
	char	*output;

	if (c == 0)
		return (print_c_null(opt));
	output = NULL;
	if (opt->width >= 1)
	{
		output = ft_strnew(opt->width);
		if (opt->zeros == 1 && opt->left_side != 1)
			ft_memset(output, 48, opt->width);
		else
			ft_memset(output, 32, opt->width);
		if (opt->left_side == 1)
			output[0] = c;
		else
			output[opt->width - 1] = c;
	}
	else if (opt->width == -1)
	{
		output = ft_strnew(1);
		output[0] = c;
	}
	return (count_and_free(output));
}
