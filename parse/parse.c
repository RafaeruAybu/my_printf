/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:10:21 by igearhea          #+#    #+#             */
/*   Updated: 2020/12/28 17:10:23 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flag(t_printf_list *printf_list)
{
	while (*(printf_list->str) == '0' || *(printf_list->str) == '-')
	{
		if (*(printf_list->str) == '0')
		{
			printf_list->bit_flag_flag = printf_list->bit_flag_flag | FLAG_ZERO;
			(printf_list->str)++;
		}
		else if (*(printf_list->str) == '-')
		{
			printf_list->bit_flag_flag = printf_list->bit_flag_flag |
																	FLAG_MINUS;
			(printf_list->str)++;
		}
	}
}

int			parse_width(t_printf_list *printf_list)
{
	char	*num_start;
	char	*str_ptr;
	int		count;

	count = 0;
	if (*(printf_list->str) == '*')
	{
		parse_width_foo(printf_list);
	}
	else if (*(printf_list->str) >= '0' && *(printf_list->str) <= '9')
	{
		num_start = printf_list->str;
		while (*(printf_list->str) >= '0' && *(printf_list->str) <= '9')
		{
			(printf_list->str)++;
			count++;
		}
		str_ptr = ft_substr(printf_list->save_str, num_start -
												printf_list->save_str, count);
		if (!str_ptr)
			return (-1);
		printf_list->width = ft_atoi(str_ptr);
		free(str_ptr);
	}
	return (0);
}

int			parse_prec(t_printf_list *printf_list)
{
	char			*num_start;
	char			*str_ptr;
	size_t			count;

	count = 0;
	if (*(printf_list->str) == '.')
	{
		(printf_list->str)++;
		printf_list->no_precision = 0;
		if (*(printf_list->str) == '*')
			parse_parce_foo(printf_list);
		else if (*(printf_list->str) >= '0' && *(printf_list->str) <= '9')
		{
			num_start = printf_list->str;
			parse_parce_foo2(printf_list, &count);
			str_ptr = ft_substr(printf_list->save_str, num_start -
												printf_list->save_str, count);
			if (!str_ptr)
				return (-1);
			printf_list->precision = ft_atoi(str_ptr);
			free(str_ptr);
		}
	}
	return (0);
}

int			parse_spec(t_printf_list *printf_list)
{
	if (*(printf_list->str) == 'c')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_C;
	else if (*(printf_list->str) == 's')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_S;
	else if (*(printf_list->str) == 'p')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_P;
	else if (*(printf_list->str) == 'd' || *(printf_list->str) == 'i')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_DI;
	else if (*(printf_list->str) == 'u')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_U;
	else if (*(printf_list->str) == 'x')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_SMALL_X;
	else if (*(printf_list->str) == 'X')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_BIG_X;
	else if (*(printf_list->str) == '%')
		printf_list->bit_flag_spec = printf_list->bit_flag_spec | FLG_PERCENT;
	else
		return (-1);
	(printf_list->str)++;
	return (0);
}

int			parse(t_printf_list *printf_list)
{
	(printf_list->str)++;
	parse_flag(printf_list);
	parse_width(printf_list);
	parse_prec(printf_list);
	if (parse_spec(printf_list) < 0)
		return (-1);
	return (0);
}
