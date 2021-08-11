#include "ft_printf.h"

void		ft_putstrn(char *str, int len, t_printf_list *printf_list)
{
	int	i;

	if (!str)
		return ;
	printf_list->ret += len;
	i = 0;
	while (*str && i < len)
		write(1, &str[i++], 1);
}
