/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:31:49 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/14 23:31:50 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flg_per_print_right(t_printf_list *printf_list)
{
	int	i;

	i = ft_min(1, printf_list->precision);
	if (printf_list->no_precision == 1)
		i = 1;
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
	ft_putchar_fd('%', 1, printf_list);
}

void	flg_per_print_left(t_printf_list *printf_list)
{
	int	i;

	i = ft_min(1, printf_list->precision);
	if (printf_list->no_precision == 1)
		i = 1;
	ft_putchar_fd('%', 1, printf_list);
	while (printf_list->width > i)
	{
		ft_putchar_fd(' ', 1, printf_list);
		(printf_list->width)--;
	}
}

void	flg_per(t_printf_list *printf_list)
{
	if (printf_list->bit_flag_flag & FLAG_MINUS)
		flg_per_print_left(printf_list);
	else
		flg_per_print_right(printf_list);
}
