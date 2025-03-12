#include "ft_printf.h"
#include <stdarg.h>

/* ボーナス用フォーマット構造体の初期化 */
static void	init_format(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->precision_specified = 0;
	fmt->specifier = '\0';
}

/* フォーマット文字列からフラグ、幅、精度、変換指定子を解析 */
static void	parse_format(const char *f, int *i, t_format *fmt)
{
	while (f[*i] == '-' || f[*i] == '0' || f[*i] == '#' || f[*i] == '+'
		|| f[*i] == ' ')
	{
		if (f[*i] == '-')
			fmt->minus = 1;
		else if (f[*i] == '0')
			fmt->zero = 1;
		else if (f[*i] == '#')
			fmt->hash = 1;
		else if (f[*i] == '+')
			fmt->plus = 1;
		else if (f[*i] == ' ')
			fmt->space = 1;
		(*i)++;
	}
	while (f[*i] >= '0' && f[*i] <= '9')
	{
		fmt->width = fmt->width * 10 + (f[*i] - '0');
		(*i)++;
	}
	if (f[*i] == '.')
	{
		fmt->precision_specified = 1;
		(*i)++;
		while (f[*i] >= '0' && f[*i] <= '9')
		{
			fmt->precision = fmt->precision * 10 + (f[*i] - '0');
			(*i)++;
		}
	}
	fmt->specifier = f[*i];
	(*i)++;
}

static int	bonus_print_str(const char *s, t_format *fmt)
{
	int len, printed = 0, pad;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (fmt->precision_specified && fmt->precision < len)
		len = fmt->precision;
	pad = fmt->width - len;
	while (!fmt->minus && pad-- > 0)
		printed += print_char(' ');
	printed += write(1, s, len);
	while (fmt->minus && pad-- > 0)
		printed += print_char(' ');
	return (printed);
}

static int	bonus_print_int(int n, t_format *fmt)
{
    char		buf[51];
    const char	*min_str = "2147483648";
    int		idx;
    int		neg;
    int		num_len;
    int		pad;
    int		printed;
    t_int_data	data;

    printed = 0;
    if (n == -2147483648)
    {
        idx = 50 - 10;
        for (int i = 0; i < 10; i++)
            buf[idx + i] = min_str[i];
        neg = 1;
    }
    else
    {
        data.n = n;
        data.fmt = fmt;
        data.buf = buf;
        data.idx = &idx;
        data.neg = &neg;
        data.num_len = &num_len;
        compute_int_format(&data);
    }
    num_len = 50 - idx;
    if (n == 0 && fmt->precision_specified && fmt->precision == 0)
    {
        num_len = 0;
        idx = 50;
    }
    else if (fmt->precision_specified && fmt->precision > num_len)
        num_len = fmt->precision;
    if (neg || fmt->plus || fmt->space)
        num_len += 1;
    pad = fmt->width - num_len;
    while (!fmt->minus && pad-- > 0)
    {
        if (fmt->zero && !fmt->precision_specified)
            printed += print_char('0');
        else
            printed += print_char(' ');
    }
    printed += bonus_print_int_prefix(neg, fmt);
    while (fmt->precision_specified && fmt->precision-- > (50 - idx))
        printed += print_char('0');
    buf[50] = '\0';
    if (50 - idx > 0)
        printed += print_string(&buf[idx]);
    while (fmt->minus && pad-- > 0)
        printed += print_char(' ');
    return (printed);
}

int	handle_bonus_conversion(const char *f, int *i, va_list args)
{
	t_format	fmt;
	int			printed;

	init_format(&fmt);
	parse_format(f, i, &fmt);
	if (fmt.specifier == 's')
		printed = bonus_print_str(va_arg(args, char *), &fmt);
	else if (fmt.specifier == 'd' || fmt.specifier == 'i')
		printed = bonus_print_int(va_arg(args, int), &fmt);
	else if (fmt.specifier == 'u')
		printed = bonus_print_unsigned(va_arg(args, unsigned int), &fmt);
	else if (fmt.specifier == 'x')
		printed = bonus_print_hex(va_arg(args, unsigned int), 0, &fmt);
	else if (fmt.specifier == 'X')
		printed = bonus_print_hex(va_arg(args, unsigned int), 1, &fmt);
	else if (fmt.specifier == 'p')
		printed = bonus_print_pointer(va_arg(args, void *), &fmt);
	else if (fmt.specifier == '%')
		printed = bonus_print_percent(&fmt);
	else
		printed = handle_conversion(fmt.specifier, args);
	return (printed);
}
