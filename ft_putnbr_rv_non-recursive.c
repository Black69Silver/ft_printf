/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_rv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/14 19:00:47 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Output the integer ’n’ to given file descriptor 'fd':
	* handle INT_MIN
	* handle sign
	* calculate length of 'n' (i_out + 1)
	* calculate appropriate divisor -> ft_divisor
	* using modulo, obtain the remains of 'n' to be printed
	* print the left-most digit
	* repeat the previous 2 steps until finished
	* if '0' is encountered -> ft_print_zero
 */

#include "ft_printf.h"

size_t	ft_divisor(size_t i_out)
{
	size_t	div;

	div = 1;
	while (i_out > 0)
	{
		div = div * 10;
		i_out--;
	}
	return (div);
}

size_t	ft_print_zero(size_t i_div, size_t i_out, int *rv)
{
	while (i_div > 1)
	{
		write(1, "0", 1);
		i_div--;
		i_out--;
		(*rv)++;
	}
	return (i_out);
}

void	ft_next(unsigned int n, int *rv, size_t i_out, size_t n_out)
{
	size_t	i_div;
	size_t	div;

	while (n / 10 > 0)
	{
		ft_putchar_rv(n_out + '0', rv);
		div = ft_divisor(i_out);
		n = n % div;
		n_out = n;
		i_div = i_out;
		while (n_out / 10 > 0)
		{
			n_out = n_out / 10;
			i_div--;
		}
		if (i_div > 1)
			i_out = ft_print_zero (i_div, i_out, rv);
		i_out--;
	}
	ft_putchar_rv(n + '0', rv);
}

void	ft_putunsign_rv(unsigned int n, int *rv)
{
	size_t	i_out;
	size_t	n_out;

	i_out = 0;
	n_out = n;
	while (n_out / 10 > 0)
	{
		n_out = n_out / 10;
		i_out++;
	}
	ft_next(n, rv, i_out, n_out);
}

void	ft_putnbr_rv(int n, int *rv)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*rv = *rv + 11;
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			(*rv)++;
		}
		ft_putunsign_rv(n, rv);
	}
}
