/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 08:08:22 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 08:08:22 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	ret;
	int	w_ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			w_ret = ft_printf_switch(format, &ap, fd);
			if (w_ret < 0)
				return (-1);
			ret += w_ret;
		}
		else
		{
			w_ret = ft_putc(*format, fd);
			if (w_ret < 0)
				return (-1);
			ret += w_ret;
		}
		format++;
	}
	return (ret);
}
