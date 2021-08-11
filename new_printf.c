/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:38:30 by igearhea          #+#    #+#             */
/*   Updated: 2020/12/28 17:38:32 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_new_params(t_printf_list *printf_list)
{
	printf_list->bit_flag_flag = FLAG_DEFAULT;
	printf_list->width = 0;
	printf_list->no_precision = 1;
	printf_list->precision = 0;
	printf_list->bit_flag_spec = FLAG_DEFAULT;
}

void		set_default_params(t_printf_list *printf_list)
{
	printf_list->bit_flag_flag = FLAG_DEFAULT;
	printf_list->width = 0;
	printf_list->no_precision = 1;
	printf_list->precision = 0;
	printf_list->bit_flag_spec = FLAG_DEFAULT;
	printf_list->ret = 0;
}

int			new_printf(t_printf_list *printf_list)
{
	int		ret;

	while (*(printf_list->str))
	{
		if (*(printf_list->str) == '%')
		{
			ret = parse(printf_list);
			if (ret == -1)
				return (ret);
			process(printf_list);
			set_new_params(printf_list);
		}
		else
		{
			ft_putchar_fd(*(printf_list->str), 1, printf_list);
			(printf_list->str)++;
		}
	}
	return (0);
}
