/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 20:11:06 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A simplified version of 'printf' from 'libc' standard C library:
 * Receive as an 'argument' a 'const char' string.
 * 'write' character by character its content.
 * When coming across '%', based on the next character, 'dispatcher'
 * handles the next 'argument' / data object (variable or pointer):

• %d Prints a (signed) decimal (base 10) integer.
	&
• %i Prints an (signed) integer in base 10.
	ft_print_dec(int n, rv);
	* in case input is an unsigned hexadecimal integer:
		ft_int_hex_2_dec(int input) to convert to base 10
	ft_putunsign_rv(unsigned int n, rv);
• %u Prints an unsigned decimal (base 10) integer.
	ft_putunsign_rv(unsigned int n, rv);

• %p Prints in hexadecimal format the address where the pointer points to.
	&
• %x Prints an unsigned integer in hexadecimal (base 16) lower case format.
	&
• %X Prints an unsigned integer in hexadecimal (base 16) upper case format.
	ft_print_hex(unsigned long int n, rv, c);
	ft_dec_2_char_hex;

• %c Prints a single character. Due to argument promotion, 'char' -> 'int'.
	ft_putchar_rv(int c, rv);
• %s Prints a string (as defined by the common C convention).
	ft_putstr_rv((char *) c, rv);
• %% Prints a percent sign.

 * Arguments are handled by variadic macros.
 * Pass-by-address is used for variadic function arguments and the return value.
 * 'rv' is the return value - the number of characters that were printed.
 * If there is an error while writing, the return value is '-1'.
 * It does not handle the following flags: #-+ 0.
 * It does not handle floating-point format specifiers: fFeEgGaA.
 */

#include "ft_printf.h"

void	ft_dispatcher(char c, va_list *ap, int *rv)
{
	if (c == 'c')
		ft_putchar_rv(va_arg(*ap, int), rv);
	if (c == 's')
		ft_putstr_rv(va_arg(*ap, char *), rv);
	if (c == 'p')
		ft_print_hex(va_arg(*ap, unsigned long int), rv, 'p');
	if (c == 'd' || c == 'i')
		ft_print_dec(va_arg(*ap, int), rv);
	if (c == 'u')
		ft_putunsign_rv(va_arg(*ap, unsigned int), rv);
	if (c == 'x')
		ft_print_hex(va_arg(*ap, unsigned int), rv, 'x');
	if (c == 'X')
		ft_print_hex(va_arg(*ap, unsigned int), rv, 'X');
	if (c == '%')
		ft_putchar_rv('%', rv);
}

int	ft_printf(const char *c, ...)
{
	size_t	i;
	int		rv;
	va_list	ap;

	if (c == NULL)
		return (-1);
	i = 0;
	rv = 0;
	va_start(ap, c);
	while (*(c + i) != 0)
	{
		if (*(c + i) == '%')
		{
			i++;
			ft_dispatcher(*(c + i), &ap, &rv);
		}
		else
			ft_putchar_rv(*(c + i), &rv);
		if (rv == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	return (rv);
}
