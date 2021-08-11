#include "ft_printf.h"

void		parse_width_foo(t_printf_list *printf_list)
{
	int		num;

	num = va_arg(printf_list->arg_pointer, int);
	if (num < 0)
	{
		num = num * -1;
		printf_list->bit_flag_flag = printf_list->bit_flag_flag |
																FLAG_MINUS;
	}
	printf_list->width = num;
	(printf_list->str)++;
}
