/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 09:27:35 by koiama            #+#    #+#             */
/*   Updated: 2025-03-20 09:27:35 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	if (ret < 0)
		return (-1);
	return (ret);
}
