#include "ft_printf.h"

int	convert_int_to_str(int n, char *buf, int *neg)
{
    int	idx;

    idx = 50;
    *neg = 0;
    if (n < 0)
    {
        *neg = 1;
        n = -n;
    }
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

void	compute_int_format(t_int_data *data)
{
    *data->idx = convert_int_to_str(data->n, data->buf, data->neg);
    *data->num_len = 50 - *data->idx;
    if (data->fmt->precision_specified && data->fmt->precision > *data->num_len)
        *data->num_len = data->fmt->precision;
    if (*data->neg || data->fmt->plus || data->fmt->space)
        *data->num_len += 1;
}

int	bonus_print_int_prefix(int neg, t_format *fmt)
{
    int	count;

    count = 0;
    if (neg)
        count += print_char('-');
    else if (fmt->plus)
        count += print_char('+');
    else if (fmt->space)
        count += print_char(' ');
    return (count);
}