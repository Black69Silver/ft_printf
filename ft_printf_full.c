/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 20:43:01 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A simplified version of 'printf' from 'libc' standard C library:
 * Receive as an 'argument' a 'const char' string.
 * 'write' character by character its content.
 * When coming across '%', based on the next character, 'dispatcher'
 * handles the next 'argument' / data object (variable or pointer):
• %c Prints a single character.
	ft_putchar_rv(int c, rv);
• %s Prints a string (as defined by the common C convention).
	ft_putstr_rv((char *) c, rv);
• %p The void * pointer argument has to be printed in hexadecimal format. 
	???
• %d Prints a decimal (base 10) number.
	&
• %i Prints an integer in base 10.
	* in case input is a hexadecimal (an unsigned integer that starts with '0x'):
	ft_int_hex_2_dec(input) to convert to base 10
	ft_putnbr_rv(int n, rv)
• %u Prints an unsigned decimal (base 10) number.
	ft_putunsign_rv(unsigned int n, rv)
• %x Prints a number in hexadecimal (base 16) lowercase format.
	&
• %X Prints a number in hexadecimal (base 16) uppercase format.
	* in case input is an unsigned integer that starts with '0x':
	trim 0x
	ft_tolower(int c)	OR	ft_toupper(int c)
	ft_putstr_fd(char *s, 1)		try _short version?	
	* in case input is unsigned decimal:
	ft_dec_2_hex
• %% Prints a percent sign.
 * It does not handle the following flags: #-+ 0.
 * It does not handle floating-point format specifiers: fFeEgGaA.
 * 'rv' is the return value - the number of characters that were printed.
 * If there is an error while writing, the return value is '-1'.
 */

#include "ft_printf.h"

void	ft_putchar_rv(char input, int *rv)
{
	if (write(1, &input, 1) == -1)
	{
		*rv = -1;
		return ;
	}
	else
		(*rv)++;
}

void	ft_putstr_rv(char *input, int *rv)
{
	size_t	i;

	i = 0;
	if (input == NULL)
	{
		input = "(null)";
	}
	while (input[i] != '\0')
	{
		ft_putchar_rv(input[i], rv);
		if (*rv == -1)
			break ;
		i++;
	}
}

void	ft_dispatcher(char c, va_list *ap, int *rv)
{
	if (c == 'c')								// Prints a single character.
		ft_putchar_rv(va_arg(*ap, int), rv);	// It is 'int' instead of 'char', because of argument promotion.
	if (c == 's')								// Prints a string.
		ft_putstr_rv(va_arg(*ap, char *), rv);
	if (c == 'p')								// Prints in hexadecimal format the address where a pointer points to.
		ft_print_hex(va_arg(*ap, unsigned long int), rv, 'p');
	if (c == 'd' || c == 'i')					// Prints a (signed) decimal integer, from decimal or hexadecimal input.
	{
		ft_print_dec(va_arg(*ap, int), rv);
		if (*rv == -1)
			return ;
	}
	if (c == 'u')								// Prints an unsigned decimal integer - there are no unsigned floats.
	{
		ft_putunsign_rv(va_arg(*ap, unsigned int), rv);
		if (*rv == -1)
			return ;
	}
	if (c == 'x')								// Prints a hexadecimal number in lower case.
		ft_print_hex(va_arg(*ap, unsigned int), rv, 'x');
	if (c == 'X')								// Prints a hexadecimal number in upper case.
		ft_print_hex(va_arg(*ap, unsigned int), rv, 'X');
	if (c == '%')								// Prints '%'.
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
	va_start(ap, c);								// enables access to variadic function arguments
	while (*(c + i) != 0)
	{
		if (*(c + i) == '%')
		{
			i++;
			ft_dispatcher(*(c + i), &ap, &rv);		// Pass-by-address
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

/*

malloc();
free();
void	va_start(va_list ap, last_arg);			// enables access to variadic function arguments
	ap − (argument pointer?) This is the object of va_list and it will hold the information needed to retrieve the additional arguments with va_arg
	last_arg − This is the last known fixed argument being passed to the function, i.e. the argument before the ellipsis.

ap type	va_arg(va_list ap, ap type);			// accesses the next variadic function argument

void	va_copy(va_list dest, va_list src);		// makes a copy of the variadic function arguments

void	va_end(va_list ap);						// cleans up the mess created between va_start or va_copy and own appearance
*/

int	main(void)
{
//	const char		*c = "\tcharacter '%c',\vstring '%s',\vpointer '%p',\vdecimal '%d',\vinteger '%i',\vunsigned '%u',\vheXadecimal '%X',\vhexadecimal '%x',\vpercentage '%%', ";
	const char		*c = "%x";
	char			a = 'a';
	char			*s = "str";
	int				d = 123;
	int				g = 0xa1b2c3;
	int				h = 80;
	unsigned int	u = -1;

	printf("printf: \n");
//	   printf("return value: %i.\n",	printf(c, a, s, s, d, h, u, g, h));
//   printf("printf: ptr: %p, size of ptr: %zu", s, sizeof(s));
	printf(", return value: %i.\n",	printf("%u", UINT_MAX));
//	printf("%d", 10);
//	   printf("\n %ld ", 4498849659);
//	   printf("\n %ld ", 4498849659 / 16);
//	   printf("\n %ld ", 4498849659 / 16 / 16);
//	   printf("\n %ld ", 4498849659 / 16 / 16 / 16);
//	   printf("\n %ld ", 4498849659 / 16 / 16 / 16 / 16);
//	   printf("\n %ld ", 4498849659 / 16 / 16 / 16 / 16 / 16);
//	   printf("\n %ld ", 4498849659 / 16 / 16 / 16 / 16 / 16 / 16);
//	   printf("\n %ld ", 4498849659 / 16 / 16 / 16 / 16 / 16 / 16 / 16);
//	   printf(" %x %x %lx %lx %lx %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
//	printf("printf: ptr: %p, dec: %i, hex: %x\n", "", "", "");
	printf("\nft_printf: \n");
//	ft_printf("return value: %i.\n", ft_printf(c, a, s, s, d, h, u, g, h));
	ft_printf(", return value: %i.\n",	ft_printf("%u", UINT_MAX));
//	ft_printf("%d", 10);
//	ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	return (0);
}
