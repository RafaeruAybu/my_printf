/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_di_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:30:23 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/19 01:30:28 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		operate_zeros(t_printf_list *printf_list)
{
	while (printf_list->width > 0)
	{
		ft_putchar_fd(' ', 1, printf_list);
		printf_list->width--;
	}
}
