/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 08:17:27 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 08:17:27 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ullsize(unsigned long long unum, char *base)
{
	int		ret;
	size_t	base_len;

	base_len = ft_strlen(base);
	ret = 0;
	if (unum == 0)
		return (1);
	while (unum != 0)
	{
		unum /= (unsigned long long)base_len;
		ret++;
	}
	return (ret);
}
