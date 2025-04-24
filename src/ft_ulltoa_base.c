/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 08:17:29 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 08:17:29 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa_base(unsigned long long unum, char *base)
{
	char				*ret;
	ssize_t				size;
	unsigned long long	base_len;

	base_len = (unsigned long long)ft_strlen(base);
	size = ft_ullsize(unum, base);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[--size] = base[unum % base_len];
		unum /= base_len;
	}
	return (ret);
}
