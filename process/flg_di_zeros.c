#include "ft_printf.h"

void		operate_zeros(t_printf_list *printf_list)
{
	while (printf_list->width > 0)
	{
		ft_putchar_fd(' ', 1, printf_list);
		printf_list->width--;
	}
}
