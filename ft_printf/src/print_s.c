/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:32:17 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/18 16:07:22 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_output(char *cut,
		t_options *opt, int width, int len)
{
	int		i;
	char	*output;
	int		zeros;
	int		left_side;

	left_side = opt->left_side;
	zeros = (opt->zeros == 1 && opt->left_side == -1) ? 1 : 0;
	i = -1;
	output = ft_strnew(width);
	output[width] = '\0';
	if (left_side == 1)
	{
		ft_strcpy(output, cut);
		output[len] = ' ';
		while (++len < width)
			output[len] = ' ';
	}
	else
	{
		while (++i < width)
			output[i] = (zeros == 1) ? '0' : ' ';
		ft_strcpy(output + width - len, cut);
	}
	return (output);
}

int			print_s(char *s, t_options *opt)
{
	char	*output;
	int		len;
	int		width;
	char	*cut;

	if (!s)
		s = "(null)";
	width = opt->width;
	cut = (opt->prec >= 0) ? ft_strsub(s, 0, opt->prec) : ft_strdup(s);
	len = ft_strlen(cut);
	if (len < width)
		output = create_output(cut, opt, width, len);
	else
		output = ft_strdup(cut);
	free(cut);
	return (count_and_free(output));
}
