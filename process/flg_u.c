/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:45:53 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/04 10:45:54 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flg_u_print_right(t_printf_list *printf_list, char *str, int len)
{
	int	i;

	i = ft_max(len, printf_list->width);
	i = i - len;
	if ((printf_list->bit_flag_flag & FLAG_ZERO) &&
											(printf_list->no_precision == 1))
		while (i > 0)
		{
			ft_putchar_fd('0', 1, printf_list);
			i--;
		}
	else
		while (i > 0)
		{
			ft_putchar_fd(' ', 1, printf_list);
			i--;
		}
	ft_putstrn(str, len, printf_list);
}

void		flg_u_print_left(t_printf_list *printf_list, char *str, int len)
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

void		flg_u(t_printf_list *printf_list)
{
	unsigned int		num;
	unsigned int		len;
	char				*str;
	char				*str_after_prec;
	int					minus;

	num = (unsigned int)va_arg(printf_list->arg_pointer, unsigned int);
	minus = 0;
	if (num < 0)
		minus = 1;
	str = ft_utoa(num);
	len = ft_strlen(str);
	str_after_prec = operate_prec(printf_list, str, len, minus);
	free(str);
	len = ft_strlen(str_after_prec);
	if ((num == 0) && (printf_list->no_precision == 0) &&
											(printf_list->precision == 0))
		operate_zeros(printf_list);
	else if (printf_list->bit_flag_flag & FLAG_MINUS)
		flg_u_print_left(printf_list, str_after_prec, len);
	else
		flg_u_print_right(printf_list, str_after_prec, len);
	free(str_after_prec);
}
