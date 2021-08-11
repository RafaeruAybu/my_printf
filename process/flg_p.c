/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:45:14 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/04 10:45:15 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flg_p_print_right(char *str, size_t len, t_printf_list *printf_list)
{
	int		i;

	i = ft_min(len, printf_list->precision);
	if (printf_list->no_precision == 1)
		i = len;
	printf_list->width -= 2;
	while (printf_list->width > i)
	{
		ft_putchar_fd(' ', 1, printf_list);
		(printf_list->width)--;
	}
	ft_putstrn("0x", 2, printf_list);
	ft_putstrn(str, i, printf_list);
}

void		flg_p_print_left(char *str, size_t len, t_printf_list *printf_list)
{
	int		i;

	i = ft_min(len, printf_list->precision);
	if (printf_list->no_precision == 1)
		i = len;
	ft_putstrn("0x", 2, printf_list);
	printf_list->width -= 2;
	ft_putstrn(str, i, printf_list);
	while (printf_list->width > i)
	{
		ft_putchar_fd(' ', 1, printf_list);
		(printf_list->width)--;
	}
}

void		flg_p(t_printf_list *printf_list)
{
	unsigned long		num;
	size_t				len;
	char				*ptr;

	num = (unsigned long)va_arg(printf_list->arg_pointer, void *);
	ptr = get_long_hex_string(num);
	len = ft_strlen(ptr);
	if (printf_list->bit_flag_flag & FLAG_MINUS)
		flg_p_print_left(ptr, len, printf_list);
	else
		flg_p_print_right(ptr, len, printf_list);
	free(ptr);
}
