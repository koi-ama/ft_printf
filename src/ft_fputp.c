/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:32:15 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 07:32:15 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputp(unsigned long long unum, int fd)
{
	size_t	ret;
	size_t	w_ret;
	char	*str;

	ret = 0;
	w_ret = ft_fputs("0x", fd);
	if (w_ret < 0)
		return (-1);
	ret += w_ret;
	str = ft_ulltoa_base(unum, BASE_LOW_16);
	if (!str)
		return (-1);
	w_ret = ft_fputs(str, fd);
	if (w_ret < 0)
		return (-1);
	ret += w_ret;
	free(str);
	return (ret);
}
