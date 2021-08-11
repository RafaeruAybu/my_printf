#include "ft_printf.h"

int			process(t_printf_list *printf_list)
{
	if (printf_list->bit_flag_spec & FLG_C)
		flg_c(printf_list);
	else if (printf_list->bit_flag_spec & FLG_S)
		flg_s(printf_list);
	else if (printf_list->bit_flag_spec & FLG_P)
		flg_p(printf_list);
	else if (printf_list->bit_flag_spec & FLG_PERCENT)
		flg_per(printf_list);
	else if (printf_list->bit_flag_spec & FLG_DI)
		flg_di(printf_list);
	else if (printf_list->bit_flag_spec & FLG_U)
		flg_u(printf_list);
	else if (printf_list->bit_flag_spec & FLG_BIG_X)
		flg_big_x(printf_list);
	else if (printf_list->bit_flag_spec & FLG_SMALL_X)
		flg_small_x(printf_list);
	return (0);
}
