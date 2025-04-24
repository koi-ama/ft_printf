/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:32:17 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 07:32:17 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputi(int num, int fd)
{
	char	*str;
	int		ret;

	str = ft_itoa_base(num, BASE_10);
	if (!str)
		return (-1);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}
