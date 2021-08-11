/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:27:04 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/14 20:27:06 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
