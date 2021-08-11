#include "ft_printf.h"

void		flg_s_print_right(t_printf_list *printf_list, char *str, int len)
{
	int		i;

	i = ft_min(len, printf_list->precision);
	if (printf_list->no_precision == 1)
		i = len;
	if (printf_list->width > i)
	{
		if (printf_list->bit_flag_flag & FLAG_ZERO)
			while (printf_list->width > i)
			{
				ft_putchar_fd('0', 1, printf_list);
				(printf_list->width)--;
			}
		else
			while (printf_list->width > i)
			{
				ft_putchar_fd(' ', 1, printf_list);
				(printf_list->width)--;
			}
	}
	ft_putstrn(str, i, printf_list);
}

void		flg_s_print_left(t_printf_list *printf_list, char *str, int len)
{
	int		i;

	i = ft_min(len, printf_list->precision);
	if (printf_list->no_precision == 1)
		i = len;
	ft_putstrn(str, i, printf_list);
	while (printf_list->width > i)
	{
		ft_putchar_fd(' ', 1, printf_list);
		(printf_list->width)--;
	}
}

void		flg_s(t_printf_list *printf_list)
{
	int		len;
	char	*str;

	if (!(str = (char *)va_arg(printf_list->arg_pointer, char *)))
		str = "(null)";
	len = ft_strlen(str);
	if (printf_list->bit_flag_flag & FLAG_MINUS)
		flg_s_print_left(printf_list, str, len);
	else
		flg_s_print_right(printf_list, str, len);
}
