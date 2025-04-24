/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 08:17:19 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 08:17:19 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(int n, char *base)
{
	long long	ln;
	char		*ret;
	size_t		size;
	size_t		base_len;

	ln = n;
	base_len = ft_strlen(base);
	size = ft_isize(n, base_len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size--] = '\0';
	if (ln < 0)
	{
		ln = -ln;
		ret[0] = '-';
	}
	while (ln >= (long long)base_len)
	{
		ret[size--] = base[ln % base_len];
		ln /= base_len;
	}
	ret[size] = base[ln % base_len];
	return (ret);
}
