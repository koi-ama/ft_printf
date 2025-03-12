#include "ft_printf.h"
#include <stdarg.h>

/* シンプルな変換ディスパッチ */
static void	convert(const char *fmt, va_list *args, int *len)
{
	if (*fmt == 'c')
		*len += print_char((char)va_arg(*args, int));
	else if (*fmt == 's')
		*len += print_string(va_arg(*args, char *));
	else if (*fmt == 'p')
	{
		*len += write(1, "0x", 2);
		*len += print_pointer(va_arg(*args, void *));
	}
	else if (*fmt == 'd' || *fmt == 'i')
		*len += print_number(va_arg(*args, int));
	else if (*fmt == 'u')
		*len += print_unsigned(va_arg(*args, unsigned int));
	else if (*fmt == 'x')
		*len += print_hex(va_arg(*args, unsigned int), 0);
	else if (*fmt == 'X')
		*len += print_hex(va_arg(*args, unsigned int), 1);
	else if (*fmt == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	args;
	int		idx;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			/* ボーナス用フラグがあればボーナス処理へ */
			if (*fmt == '-' || *fmt == '0' || *fmt == '#' || *fmt == '+'
				|| *fmt == ' ' || (*fmt >= '0' && *fmt <= '9') || *fmt == '.')
			{
				idx = 0;
				len += handle_bonus_conversion(fmt, &idx, args);
				fmt += idx; // 解析した分だけフォーマット文字列を進める
			}
			else
			{
				convert(fmt, &args, &len);
				fmt++;
			}
		}
		else
		{
			len += write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(args);
	return (len);
}
