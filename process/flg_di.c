#include "ft_printf.h"

static void	foo(t_printf_list *printf_list, int *i)
{
	while (*i > 0)
	{
		ft_putchar_fd('0', 1, printf_list);
		(*i)--;
	}
}

void		flg_di_print_right(t_printf_list *printf_list, char *str, int len)
{
	int	i;

	i = ft_max(len, printf_list->width);
	i = i - len;
	if ((printf_list->bit_flag_flag & FLAG_ZERO) &&
											(printf_list->no_precision == 1))
	{
		if (str[0] == '-')
		{
			ft_putchar_fd('-', 1, printf_list);
			str++;
			len--;
		}
		foo(printf_list, &i);
	}
	else
		while (i > 0)
		{
			ft_putchar_fd(' ', 1, printf_list);
			i--;
		}
	ft_putstrn(str, len, printf_list);
}

void		flg_di_print_left(t_printf_list *printf_list,
														char *str, int len)
{
	int	i;

	i = ft_max(len, printf_list->width);
	i = i - len;
	ft_putstrn(str, len, printf_list);
	while (i > 0)
	{
		ft_putchar_fd(' ', 1, printf_list);
		i--;
	}
}

void		flg_di(t_printf_list *printf_list)
{
	int		num;
	int		len;
	char	*str;
	char	*str_after_prec;
	int		minus;

	num = (int)va_arg(printf_list->arg_pointer, int);
	minus = 0;
	if (num < 0)
		minus = 1;
	str = ft_itoa(num);
	len = ft_strlen(str);
	str_after_prec = operate_prec(printf_list, str, len, minus);
	free(str);
	len = ft_strlen(str_after_prec);
	if ((num == 0) && (printf_list->no_precision == 0) &&
											(printf_list->precision == 0))
		operate_zeros(printf_list);
	else if (printf_list->bit_flag_flag & FLAG_MINUS)
		flg_di_print_left(printf_list, str_after_prec, len);
	else
		flg_di_print_right(printf_list, str_after_prec, len);
	free(str_after_prec);
}
