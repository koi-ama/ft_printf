#include "ft_printf.h"

int	handle_conversion(char conv, va_list args)
{
	int	len;

	if (conv == 'c')
		return (print_char(va_arg(args, int)));
	else if (conv == 's')
		return (print_string(va_arg(args, char *)));
	else if (conv == 'p')
	{
		len = 0;
		len += write(1, "0x", 2);
		return (len + print_pointer(va_arg(args, void *)));
	}
	else if (conv == 'd' || conv == 'i')
		return (print_number(va_arg(args, int)));
	else if (conv == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (conv == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	else if (conv == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (conv == '%')
		return (write(1, "%", 1));
	return (0);
}