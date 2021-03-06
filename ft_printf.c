#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf_list	printf_list;
	int				ret;

	if (!format)
		return (-1);
	va_start(printf_list.arg_pointer, format);
	set_default_params(&printf_list);
	printf_list.str = (char *)format;
	printf_list.save_str = (char *)format;
	ret = new_printf(&printf_list);
	va_end(printf_list.arg_pointer);
	if (ret == -1)
		return (ret);
	return (printf_list.ret);
}
