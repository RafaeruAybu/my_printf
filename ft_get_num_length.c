#include "ft_printf.h"

size_t		get_num_length(size_t num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	else
		while (num > 0)
		{
			len++;
			num = num / 10;
		}
	return (len);
}
