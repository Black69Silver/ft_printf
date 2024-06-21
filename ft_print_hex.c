/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:32:49 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 19:05:26 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert a base 10 to base 16 (both upper and lower case) number.
 */

#include "ft_printf.h"

#define OLD_BASE 10
#define NEW_BASE 16

void	ft_dec_2_char_hex(unsigned long int input, int *rv, char c)
{
	size_t	i;
	int		temp;
	char	converted[16];

	i = 0;
	while (input > 0)
	{
		temp = input % NEW_BASE;
		if (temp < 10)
			temp = temp + '0';
		else if (c == 'X')
			temp = temp + 55;
		else
			temp = temp + 87;
		converted [i] = temp;
		input = input / NEW_BASE;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_rv(converted [i], rv);
		if (*rv == -1)
			return ;
	}
}

void	ft_print_hex(unsigned long int n, int *rv, char c)
{
	if (c == 'p')
	{
		ft_putstr_rv("0x", rv);
		if (*rv == -1)
			return ;
	}
	if (n == 0)
	{
		ft_putchar_rv('0', rv);
		if (*rv == -1)
			return ;
	}
	ft_dec_2_char_hex(n, rv, c);
}
