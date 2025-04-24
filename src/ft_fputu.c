/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:32:11 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 07:32:11 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputu(unsigned int unum, int fd)
{
	char *str;
	int ret;

	str = ft_uitoa_base(unum, BASE_10);
	if (!str)
		return (-1);
	ret = ft_fputs(str, fd);
	free(str);
	return (ret);
}