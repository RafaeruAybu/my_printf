/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:04:54 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/04 12:04:56 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstrn(char *str, int len, t_printf_list *printf_list)
{
	int	i;

	if (!str)
		return ;
	printf_list->ret += len;
	i = 0;
	while (*str && i < len)
		write(1, &str[i++], 1);
}
