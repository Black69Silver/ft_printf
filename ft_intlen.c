/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:47:18 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/13 02:27:27 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return the number of digits (including preceding '-') in an integer. */

#include "ft_printf.h"

size_t	ft_intlen(int n)
{
	size_t	intlen;

	intlen = 1;
	if (n < 0)
	{
		n = -n;
		intlen++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		intlen++;
	}
	return (intlen);
}
