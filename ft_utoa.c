/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:27:09 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/19 03:27:34 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*set_s(unsigned int n, unsigned int count)
{
	char				*ptr;
	char				*save_ptr;
	unsigned int		target;
	unsigned int		sign;

	sign = 1;
	target = 0;
	ptr = malloc(sizeof(char) * count + 1);
	if (!ptr)
		return (ptr);
	save_ptr = ptr;
	ptr[count] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		target = 1;
		sign = -1;
	}
	while (count-- != target)
	{
		ptr[count] = sign * (n % 10) + '0';
		n /= 10;
	}
	return (save_ptr);
}

unsigned int		do_count(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char				*ft_utoa(unsigned int n)
{
	char	*ptr;

	ptr = set_s(n, do_count(n));
	return (ptr);
}
