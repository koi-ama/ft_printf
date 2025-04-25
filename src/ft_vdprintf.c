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

static int	process_vdprintf_char(int fd, const char **fmt, va_list ap_copy,
		int *w_ret)
{
	if (**fmt == '%')
	{
		(*fmt)++;
		*w_ret = ft_printf_switch(*fmt, ap_copy, fd);
	}
	else
	{
		*w_ret = ft_putc(**fmt, fd);
	}
	if (*w_ret < 0)
		return (-1);
	return (0);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	int		w_ret;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	ret = 0;
	while (*format)
	{
		if (process_vdprintf_char(fd, &format, ap_copy, &w_ret) < 0)
		{
			va_end(ap_copy);
			return (-1);
		}
		ret += w_ret;
		format++;
	}
	va_end(ap_copy);
	return (ret);
}
