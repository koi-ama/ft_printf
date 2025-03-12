#include "ft_printf.h"

static int	convert_unsigned_to_str(unsigned int n, char *buf)
{
	int	idx;

	idx = 50;
	if (n == 0)
	{
		idx--;
		buf[idx] = '0';
	}
	while (n > 0)
	{
		idx--;
		buf[idx] = (n % 10) + '0';
		n /= 10;
	}
	return (idx);
}

int	bonus_print_unsigned(unsigned int n, t_format *fmt)
{
	char	buf[51];
	int		idx;
	int		num_len;
	int		pad;
	int		printed;

	idx = convert_unsigned_to_str(n, buf);
	num_len = 50 - idx;
	printed = 0;
	if (fmt->precision_specified && fmt->precision > num_len)
		num_len = fmt->precision;
	pad = fmt->width - num_len;
	while (!fmt->minus && pad-- > 0)
	{
		if (fmt->zero && !fmt->precision_specified)
			printed += print_char('0');
		else
			printed += print_char(' ');
	}
	while (fmt->precision_specified && fmt->precision-- > (50 - idx))
		printed += print_char('0');
	buf[50] = '\0';
	printed += print_string(&buf[idx]);
	while (fmt->minus && pad-- > 0)
		printed += print_char(' ');
	return (printed);
}

static int	hex_prefix(t_format *fmt, int uppercase, int printed)
{
	if (fmt->hash)
		printed += print_string(uppercase ? "0X" : "0x");
	return (printed);
}

int	bonus_print_hex(unsigned int n, int uppercase, t_format *fmt)
{
	char	buf[51];
	char	*base;
	int		idx;
	int		num_len;
	int		pad;
	int		printed;

	base = uppercase ? HEX_UPPER : HEX_LOWER;
	idx = 50;
	printed = 0;
	if (n == 0)
	{
		if (fmt->precision_specified && fmt->precision == 0)
			idx = 50;
		else
		{
			idx--;
			buf[idx] = '0';
		}
	}
	while (n > 0)
	{
		idx--;
		buf[idx] = base[n % 16];
		n /= 16;
	}
	num_len = 50 - idx;
	if (fmt->hash && (buf[idx] != '0' || num_len == 0))
		num_len += 2;
	if (fmt->precision_specified && fmt->precision > num_len)
		num_len = fmt->precision;
	pad = fmt->width - num_len;
	while (!fmt->minus && pad-- > 0)
	{
		if (fmt->zero && !fmt->precision_specified)
			printed += print_char('0');
		else
			printed += print_char(' ');
	}
	if (fmt->hash && (50 - idx > 0 || !fmt->precision_specified || fmt->precision > 0))
		printed = hex_prefix(fmt, uppercase, printed);
	while (fmt->precision_specified && fmt->precision-- > (50 - idx))
		printed += print_char('0');
	buf[50] = '\0';
	if (50 - idx > 0)
		printed += print_string(&buf[idx]);
	while (fmt->minus && pad-- > 0)
		printed += print_char(' ');
	return (printed);
}

int	bonus_print_pointer(void *p, t_format *fmt)
{
	unsigned long	addr;
	char			buf[51];
	int				idx;
	int				num_len;
	int				pad;
	int				printed;
	char			*base;

	addr = (unsigned long)p;
	idx = 50;
	printed = 0;
	base = HEX_LOWER;
	if (addr == 0)
	{
		idx--;
		buf[idx] = '0';
	}
	while (addr > 0)
	{
		idx--;
		buf[idx] = base[addr % 16];
		addr /= 16;
	}
	num_len = 50 - idx + 2;
	pad = fmt->width - num_len;
	while (!fmt->minus && pad-- > 0)
		printed += print_char(' ');
	printed += print_string("0x");
	while (fmt->precision_specified && fmt->precision-- > (50 - idx))
		printed += print_char('0');
	buf[50] = '\0';
	printed += print_string(&buf[idx]);
	while (fmt->minus && pad-- > 0)
		printed += print_char(' ');
	return (printed);
}

int	bonus_print_percent(t_format *fmt)
{
	int	pad;
	int	printed;

	pad = fmt->width - 1;
	printed = 0;
	while (!fmt->minus && pad-- > 0)
	{
		if (fmt->zero)
			printed += print_char('0');
		else
			printed += print_char(' ');
	}
	printed += print_char('%');
	while (fmt->minus && pad-- > 0)
		printed += print_char(' ');
	return (printed);
}