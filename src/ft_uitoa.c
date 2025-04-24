/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 08:17:25 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 08:17:25 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*ret;
	size_t	size;
	size_t	base_len;

	if (n == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	size = ft_uisize(n, base_len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[--size] = base[n % base_len];
		n /= base_len;
	}
	return (ret);
}
