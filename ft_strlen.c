/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:43:10 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/04 11:43:11 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *string)
{
	const char		*ptr;
	size_t			counter;

	ptr = string;
	counter = 0;
	while (*ptr)
	{
		ptr++;
		counter++;
	}
	return (counter);
}
