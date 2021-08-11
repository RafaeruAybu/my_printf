#include "ft_printf.h"

void		flg_c_print_left(t_printf_list *printf_list, char c)
{
	ft_putchar_fd(c, 1, printf_list);
	while (printf_list->width > 1)
	{
		ft_putchar_fd(' ', 1, printf_list);
		(printf_list->width)--;
	}
}

void		flg_c_print_right(t_printf_list *printf_list, char c)
{
	if (printf_list->bit_flag_flag & FLAG_ZERO)
	{
		while (printf_list->width > 1)
		{
			ft_putchar_fd('0', 1, printf_list);
			(printf_list->width)--;
		}
	}
	else
		while (printf_list->width > 1)
		{
			ft_putchar_fd(' ', 1, printf_list);
			(printf_list->width)--;
		}
	ft_putchar_fd(c, 1, printf_list);
}

void		flg_c(t_printf_list *printf_list)
{
	char	c;

	c = (char)va_arg(printf_list->arg_pointer, int);
	if (printf_list->bit_flag_flag & FLAG_MINUS)
		flg_c_print_left(printf_list, c);
	else
		flg_c_print_right(printf_list, c);
}
