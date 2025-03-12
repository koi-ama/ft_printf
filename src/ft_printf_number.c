#include "ft_printf.h"

int	print_number(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		count += print_char('-');
		if (n == -2147483648)
			return (count + print_string("2147483648"));
		n = -n;
	}
	if (n >= 10)
		count += print_number(n / 10);
	c = (n % 10) + '0';
	return (count + print_char(c));
}

int	print_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	c = (n % 10) + '0';
	return (count + print_char(c));
}

int	print_hex(unsigned int n, int uppercase)
{
	int		count;
	char	c;
	char	*base;

	count = 0;
	base = uppercase ? HEX_UPPER : HEX_LOWER;
	if (n >= 16)
		count += print_hex(n / 16, uppercase);
	c = base[n % 16];
	return (count + print_char(c));
}

int	print_pointer_hex(unsigned long addr)
{
	int		count;
	char	c;
	char	*base;

	count = 0;
	base = HEX_LOWER;
	if (addr >= 16)
		count += print_pointer_hex(addr / 16);
	c = base[addr % 16];
	return (count + print_char(c));
}

int	print_pointer(void *p)
{
	int				count;
	unsigned long	addr;

	count = 0;
	count += print_string("0x");
	addr = (unsigned long)p;
	if (addr == 0)
		count += print_char('0');
	else
		count += print_pointer_hex(addr);
	return (count);
}
