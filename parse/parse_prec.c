/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 06:42:05 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/19 06:42:06 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_parce_foo2(t_printf_list *printf_list, size_t *count)
{
	while (*(printf_list->str) >= '0' && *(printf_list->str) <= '9')
	{
		(printf_list->str)++;
		(*count)++;
	}
}

void		parse_parce_foo(t_printf_list *printf_list)
{
	int				num;

	num = va_arg(printf_list->arg_pointer, int);
	if (num >= 0)
		printf_list->precision = num;
	else
		printf_list->no_precision = 1;
	(printf_list->str)++;
}
