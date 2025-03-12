#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

/*
** ========================
** Mandatory Function Prototypes
** ========================
*/
int		ft_printf(const char *format, ...);
int		handle_conversion(char conv, va_list args);
int		ft_strlen(const char *s);
int		print_char(char c);
int		print_string(const char *s);
int		print_number(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int n, int uppercase);
int		print_pointer_hex(unsigned long addr);
int		print_pointer(void *p);

/*
** ========================
** Bonus: Format Structure for Bonus Processing
** ========================
*/
typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		precision_specified;
	char	specifier;
}			t_format;

/*
** ========================
** Bonus: Integer Data Structure for Bonus Processing
** ========================
*/
typedef struct s_int_data
{
	int		n;
	t_format	*fmt;
	char		*buf;
	int		*idx;
	int		*neg;
	int		*num_len;
}	t_int_data;

/*
** ========================
** Bonus Function Prototypes
** ========================
*/
int		handle_bonus_conversion(const char *f, int *i, va_list args);

/*
** Bonus Helper Functions (for integer conversion/formatting)
*/
int		convert_int_to_str(int n, char *buf, int *neg);
void	compute_int_format(t_int_data *data);  /* 構造体を使用 */
int		bonus_print_int_prefix(int neg, t_format *fmt);

/*
** Bonus Extra Conversion Functions (for %u, %x, %X, %p, %%)
*/
int		bonus_print_unsigned(unsigned int n, t_format *fmt);
int		bonus_print_hex(unsigned int n, int uppercase, t_format *fmt);
int		bonus_print_pointer(void *p, t_format *fmt);
int		bonus_print_percent(t_format *fmt);

#endif