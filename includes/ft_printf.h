/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 10:09:47 by koiama            #+#    #+#             */
/*   Updated: 2025-04-24 10:09:47 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE_10 "0123456789"
# define BASE_LOW_16 "0123456789abcdef"
# define BASE_TOP_16 "0123456789ABCDEF"

int		ft_fputi(int num, int fd);
int		ft_fputp(unsigned long long unum, int fd);
int		ft_fputs(const char *s, int fd);
int		ft_putc(int c, int fd);
int		ft_fputu(unsigned int unum, int fd);
int		ft_fputx(unsigned int unum, int fd, int c);
char	*ft_itoa_base(int num, char *base);
char	*ft_uitoa_base(unsigned int n, char *base);
char	*ft_ulltoa_base(unsigned long long unum, char *base);
size_t	ft_uisize(unsigned int n, int base);
size_t	ft_isize(int num, int base);
size_t	ft_ullsize(unsigned long long unum, char *base);
int		ft_printf_switch(const char *format, va_list ap, int fd);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vprintf(const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
