/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 07:01:07 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/03 07:01:09 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	char *tmp;

	ptr = (char *)malloc(len + 1);
	if (s == 0)
		return (0);
	if (!ptr)
		return (ptr);
	tmp = ptr;
	if (start < (ft_strlen(s)))
	{
		while (start-- != 0)
			s++;
		while ((len-- != 0) && *s)
			*ptr++ = *s++;
	}
	*ptr = '\0';
	return (tmp);
}
