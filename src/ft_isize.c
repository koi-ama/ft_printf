/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 08:17:17 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 08:17:17 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_isize(int n, int base)
{
	long long	ln;
	size_t		ret;

	ln = n;
	if (n == 0)
		return (1);
	ret = 0;
	if (ln < 0)
	{
		ln = -ln;
		ret++;
	}
	while (ln != 0)
	{
		ret++;
		ln /= base;
	}
	return (ret);
}
