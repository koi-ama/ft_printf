/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 22:42:11 by koiama            #+#    #+#             */
/*   Updated: 2025-03-29 22:42:11 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputs(const char *s, int fd)
{
	int	ret;

	if (!s)
		ret = write(fd, "(null)", 6);
	else
		ret = write(fd, s, ft_strlen(s));
	if (ret < 0)
		return (-1);
	return (ret);
}
