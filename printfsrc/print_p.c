/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:31:25 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:35:24 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_address(void *p, t_options *opt)
{
	char	*hex;
	char	*s;
	char	*buff;
	int		len;

	s = ft_strnew(2);
	s[0] = '0';
	s[1] = 'x';
	if (opt->prec == 0 && p == NULL)
		return (s);
	hex = ft_itoa_base((unsigned long int)p, 16, 0);
	len = ft_strlen(hex);
	if (opt->prec > 0 && len < opt->prec)
	{
		buff = ft_strnew(opt->prec - len);
		ft_memset(buff, 48, opt->prec - len);
		s = ft_strrejoin(s, buff);
		free(buff);
	}
	s = ft_strrejoin(s, hex);
	free(hex);
	return (s);
}

int			print_p(void *p, t_options *opt)
{
	char	*address;
	char	*output;
	int		len;

	address = make_address(p, opt);
	len = ft_strlen(address);
	if (opt->width > len)
	{
		output = ft_strnew(opt->width);
		ft_memset(output, 32, opt->width);
		if (opt->left_side == 1)
		{
			ft_strcpy(output, address);
			output[len] = ' ';
		}
		else
			ft_strcpy(output + opt->width - len, address);
	}
	else
		output = ft_strdup(address);
	free(address);
	return (count_and_free(output));
}
