/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 19:31:50 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Output the integer ’n’ to given file descriptor 'fd':
	* handle hexadecimal numbers: ft_int_hex_2_dec
	* handle INT_MIN
	* handle sign
	* recursively print 'n'
 */

#include "ft_printf.h"

#define OLD_BASE 16
#define NEW_BASE 10

void	ft_putunsign_rv(unsigned int n, int *rv)
{
	if (n > 9)
	{
		ft_putunsign_rv(n / 10, rv);
		if (*rv == -1)
			return ;
	}
	ft_putchar_rv(n % 10 + '0', rv);
	if (*rv == -1)
		return ;
}

int	ft_int_hex_2_dec(int input)
{
	int	temp;
	int	converted;
	int	power;

	converted = 0;
	power = 1;
	while (input / NEW_BASE > 0)
	{
		temp = input % NEW_BASE;
		converted = converted + temp * power;
		power = power * OLD_BASE;
		input = input / NEW_BASE;
	}
	return (converted);
}

void	ft_print_dec(int n, int *rv)
{
	if (n >= '0' && n <= '9')
		n = ft_int_hex_2_dec(n);
	if (n == -2147483648)
	{
		ft_putstr_rv("-2147483648", rv);
		if (*rv == -1)
			return ;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_rv('-', rv);
			if (*rv == -1)
				return ;
			n = -n;
		}
		ft_putunsign_rv(n, rv);
	}
}
