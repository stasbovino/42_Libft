/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:25:25 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/27 20:38:04 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags(t_options *opt, char c)
{
	char	*flags;
	int		i;

	i = -1;
	flags = "0+- #";
	while (flags[++i])
		if (c == flags[i])
		{
			if (c == '-')
				opt->left_side = 1;
			else if (c == '+')
				opt->sign = 1;
			else if (c == '#')
				opt->alt_out = 1;
			else if (c == ' ')
				opt->space = 1;
			else if (c == '0')
				opt->zeros = 1;
			return (1);
		}
	return (0);
}

int		parse_type(t_options *opt, char c)
{
	char	*conv;
	int		i;

	i = -1;
	conv = "cspdiouxXfF%";
	while (conv[++i])
		if (c == conv[i])
		{
			opt->type = c;
			return (1);
		}
	return (0);
}

void	parse_len_mod(t_options *opt, char *format)
{
	char		*len;

	len = ft_strdup(format);
	if (len[1] != 'h' && len[1] != 'l')
		len[1] = '\0';
	else
		len[2] = '\0';
	if (ft_strequ(len, "hh") == 1)
		opt->len_mod = "hh";
	else if (ft_strequ(len, "h") == 1)
		opt->len_mod = "h";
	else if (ft_strequ(len, "ll") == 1)
		opt->len_mod = "ll";
	else if (ft_strequ(len, "l") == 1)
		opt->len_mod = "l";
	else if (ft_strequ(len, "L") == 1)
		opt->len_mod = "L";
	free(len);
	return ;
}

void	define_width(char *format, int *width, size_t *i)
{
	if (ft_isdigit(format[(*i)]))
	{
		*width = ft_atoi(format + *i);
		(*i)++;
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}

void	define_prec(char *format, int *prec, size_t *i)
{
	if (format[(*i)] == '.')
	{
		(*i)++;
		*prec = 0;
		*prec = ft_atoi(format + *i);
		if (*prec < 0)
			*prec = -1;
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}
