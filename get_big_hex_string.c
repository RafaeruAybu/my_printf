/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_big_hex_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:21:59 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/19 04:22:16 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		foo(char *ptr, size_t num)
{
	int		remain;
	int		i;

	i = 0;
	while (num > 0)
	{
		remain = num % 16;
		if (remain < 10)
			ptr[i] = '0' + remain;
		else
			ptr[i] = 'A' + (remain - 10);
		num = num / 16;
		i++;
	}
	return (i);
}

char			*get_big_hex_string(size_t num)
{
	char	*ptr;
	char	*ret;
	int		i;
	int		x;

	ptr = malloc((char)20);
	ret = malloc((char)20);
	i = 0;
	if (num == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		free(ptr);
		return (ret);
	}
	i = foo(ptr, num);
	x = 0;
	while (i--)
	{
		ret[x] = ptr[i];
		x++;
	}
	ret[x] = '\0';
	free(ptr);
	return (ret);
}
