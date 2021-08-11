#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, t_printf_list *printf_list)
{
	write(fd, &c, 1);
	printf_list->ret = printf_list->ret + 1;
}
