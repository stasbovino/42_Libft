/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dig_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:24:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/18 18:31:21 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_buff(t_options *opt,
		int lennum, int signfp)
{
	int		len;
	char	*buff;
	int		forsign;

	forsign = 0;
	len = lennum;
	set_len_from_signfp(&forsign, signfp);
	if (opt->prec > len)
	{
		len = opt->prec;
		if (!(signfp == 2 && opt->type == 'o' && opt->prec >= (lennum + 1)))
			len += forsign;
		else
			opt->prec--;
	}
	else
		len += forsign;
	if (opt->width > len)
		len = opt->width;
	if (len == lennum)
		len += forsign;
	buff = ft_strnew(len);
	ft_memset(buff, ' ', len);
	return (buff);
}

void	left_side_output(char *buff, int signfp, t_options *opt, char *num)
{
	int i;
	int	bufflen;
	int	numlen;

	numlen = ft_strlen(num);
	bufflen = ft_strlen(buff);
	i = (signfp != 0) ? 0 : -1;
	if (signfp != 0)
		set_sign(buff, &signfp, &i, -1);
	while (opt->prec-- - numlen > 0)
		buff[++i] = '0';
	ft_strcpy(buff + ++i, num);
	i += numlen;
	while (i < bufflen)
		buff[i++] = ' ';
}

void	right_side_output(char *buff, int signfp, t_options *opt, char *num)
{
	int		i;
	int		bufflen;
	int		numlen;
	char	paste;
	int		j;

	paste = (opt->zeros == 1 && opt->prec == -1
			&& opt->left_side != 1) ? '0' : ' ';
	numlen = ft_strlen(num);
	bufflen = ft_strlen(buff);
	i = bufflen - numlen;
	ft_strcpy(buff + i, num);
	j = (signfp == 3 || signfp == 4) ? 1 : 0;
	while (--i >= j)
		if (opt->prec-- - numlen > 0)
			buff[i] = '0';
		else if (i != j && paste == '0')
			buff[i] = paste;
		else if (signfp != 0)
			set_sign(buff, &signfp, &i, 1);
		else
			buff[i] = paste;
}

char	*create_dig_output(char *num, t_options *opt, int signfp)
{
	char	*buff;
	int		bufflen;
	int		numlen;

	numlen = ft_strlen(num);
	buff = create_buff(opt, numlen, signfp);
	bufflen = ft_strlen(buff);
	if (bufflen == numlen)
	{
		free(buff);
		return (num);
	}
	if (opt->left_side == 1)
		left_side_output(buff, signfp, opt, num);
	else
		right_side_output(buff, signfp, opt, num);
	return (buff);
}
