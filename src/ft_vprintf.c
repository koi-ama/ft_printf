/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 09:27:48 by koiama            #+#    #+#             */
/*   Updated: 2025-03-20 09:27:48 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_switch(const char *format, va_list ap, int fd)
{
	void	*ptr;

	if (*format == '%')
		return (ft_putc('%', fd));
	else if (*format == 'c')
		return (ft_putc(va_arg(ap, int), fd));
	else if (*format == 's')
		return (ft_fputs(va_arg(ap, char *), fd));
	else if (*format == 'u')
		return (ft_fputu(va_arg(ap, unsigned int), fd));
	else if (*format == 'd' || *format == 'i')
		return (ft_fputi(va_arg(ap, int), fd));
	else if (*format == 'x' || *format == 'X')
		return (ft_fputx(va_arg(ap, unsigned int), fd, *format));
	else if (*format == 'p')
	{
		ptr = va_arg(ap, void *);
		return (ft_fputp((unsigned long long)ptr, fd));
	}
	else
		return (-1);
}

static int	process_vprintf_char(const char **fmt, va_list ap_copy, int *w_ret)
{
	if (**fmt == '%')
	{
		(*fmt)++;
		*w_ret = ft_printf_switch(*fmt, ap_copy, STDOUT_FILENO);
	}
	else
	{
		*w_ret = ft_putc(**fmt, STDOUT_FILENO);
	}
	if (*w_ret < 0)
		return (-1);
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		ret;
	int		w_ret;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	ret = 0;
	while (*format)
	{
		if (process_vprintf_char(&format, ap_copy, &w_ret) < 0)
			return (-1);
		ret += w_ret;
		format++;
	}
	va_end(ap_copy);
	return (ret);
}
