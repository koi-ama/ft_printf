/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:32:07 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 07:32:07 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toupperstr(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	return (str);
}

int	ft_fputx(unsigned int unum, int fd, int c)
{
	char	*str;
	int		ret;

	str = ft_uitoa_base(unum, BASE_LOW_16);
	if (!str)
		return (-1);
	if (c == 'X')
		ft_toupperstr(str);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}
