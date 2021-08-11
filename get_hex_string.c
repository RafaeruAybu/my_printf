/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:44:19 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/16 01:44:25 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		foo(char *ptr, unsigned int num)
{
	unsigned long int		remain;
	int						i;

	i = 0;
	while (num > 0)
	{
		remain = num % 16;
		if (remain < 10)
			ptr[i] = '0' + remain;
		else
			ptr[i] = 'a' + (remain - 10);
		num = num / 16;
		i++;
	}
	return (i);
}

char			*get_hex_string(unsigned int num)
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
