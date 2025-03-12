#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(const char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}
