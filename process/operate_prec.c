#include "ft_printf.h"

static void	foo(int len, int str_len, int *x, char *ptr)
{
	int		counter;

	counter = 0;
	while (counter < (len - str_len))
	{
		ptr[(*x)++] = '0';
		counter++;
	}
}

char		*operate_prec(t_printf_list *printf_list, char *str,
														int str_len, int minus)
{
	char	*ptr;
	int		len;
	int		i;
	int		x;

	len = ft_max(str_len, printf_list->precision);
	i = 0;
	x = 0;
	if (minus)
	{
		if ((printf_list->precision > 0) && (str_len - 1) <
														printf_list->precision)
			ptr = (char *)malloc(len++ + 2);
		else
			ptr = (char *)malloc(len + 1);
		ptr[x++] = '-';
		i++;
	}
	else
		ptr = (char *)malloc(len + 1);
	foo(len, str_len, &x, ptr);
	while (str[i])
		ptr[x++] = str[i++];
	ptr[x] = '\0';
	return (ptr);
}
