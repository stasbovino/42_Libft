/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:25:08 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:34:16 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			printed;

	if (!format)
		return (0);
	printed = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			printed += prepare_opt((char*)format + i, &i, &args);
		else
		{
			ft_putchar(format[i]);
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
