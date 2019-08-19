/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_float_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:17:53 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/18 19:34:58 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_fbuff(t_options *opt, int lennum, int signfp)
{
	char	*buff;
	int		len;

	len = 0;
	if (lennum > len)
	{
		len = lennum;
		if (signfp != 0)
			len++;
	}
	if (opt->width > len)
		len = opt->width;
	buff = ft_strnew(len);
	ft_memset(buff, ' ', len);
	return (buff);
}

static void	left_side_foutput(char *buff, int signfp, char *num)
{
	int i;
	int	bufflen;
	int	numlen;

	numlen = ft_strlen(num);
	bufflen = ft_strlen(buff);
	i = (signfp != 0) ? 0 : -1;
	if (signfp != 0)
		set_fsignfp(buff, &signfp, i);
	ft_strcpy(buff + ++i, num);
	i += numlen;
	while (i < bufflen)
		buff[i++] = ' ';
}

static void	right_side_foutput(char *buff, int signfp,
		t_options *opt, char *num)
{
	int		i;
	int		bufflen;
	int		numlen;
	char	paste;

	paste = (opt->zeros == 1 && opt->left_side != 1) ? '0' : ' ';
	numlen = ft_strlen(num);
	bufflen = ft_strlen(buff);
	i = bufflen - numlen;
	ft_strcpy(buff + i, num);
	while (--i >= 0)
		if (i != 0 && paste == '0')
			buff[i] = paste;
		else if (signfp != 0)
			set_fsignfp(buff, &signfp, i);
		else
			buff[i] = paste;
}

char		*create_float_output(char *num, t_options *a, int signfp)
{
	char		*buff;
	int			bufflen;
	int			numlen;
	t_options	*opt;

	opt = a;
	numlen = ft_strlen(num);
	buff = create_fbuff(opt, numlen, signfp);
	bufflen = ft_strlen(buff);
	if (bufflen == numlen)
	{
		free(buff);
		return (num);
	}
	if (opt->left_side == 1)
		left_side_foutput(buff, signfp, num);
	else
		right_side_foutput(buff, signfp, opt, num);
	return (buff);
}
