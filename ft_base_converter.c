/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:32:49 by ggeorgie          #+#    #+#             */
/*   Updated: 2024/06/21 17:18:31 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert numbers in different bases:
 *	- hexadecimal (both upper case and lower case) to decimal,
 *	- decimal to hexadecimal.
 */

#include "printf.h"

#define OLD_BASE 16
#define NEW_BASE 10

int	ft_current_digit(char *original, size_t i, size_t len)
{
	int		temp;

	if (original[len - i] >= '0' && original[len - i] <= '9')
		temp = original[len - i] - '0';
	if (original[len - i] >= 'A' && original[len - i] <= 'Z')
		temp = original[len - i] - 'A' + 10;
	if (original[len - i] >= 'a' && original[len - i] <= 'z')
		temp = original[len - i] - 'a' + 10;
	return (temp);
}

int	ft_char_hex_2_dec(char *original)
{
	size_t	i;
	size_t	len;
	int		converted;
	int		power;
	int		temp;

	if (original[0] == '0' && (original[1] == 'x' || original[1] == 'X'))
		original = original + 2;
	i = 1;
	len = ft_strlen(original);
	power = 1;
	converted = 0;
	while (i <= len)
	{
		temp = ft_current_digit(original, i, len);
		if (temp < 0 || temp > OLD_BASE - 1)
			return (-1);
		converted = converted + temp * power;
		power = power * OLD_BASE;
		i++;
	}
	return (converted);
}

int	ft_int_hex_2_dec(int original)
{
	int	converted;
	int	power;
	int	temp;

	while (original / NEW_BASE > 0)
	{
		temp = original % NEW_BASE;
		converted = converted + temp * power;
		power = power * OLD_BASE;
		original = original / NEW_BASE;
	}
	return (converted);
}

#define OLD_BASE 10
#define NEW_BASE 16

char	*ft_dec_2_hex(int original)
{
	size_t	i;
	char	*converted;
	int		temp;

	i = 0;
	while (original / NEW_BASE > 0)
	{
		temp = original % NEW_BASE;
		if (temp < 10)
			temp = temp + 48;													// 48 is the ASCII code for '0'
		else
			temp = temp + 55;													// 55 is the ASCII code for 'A' - 10
		converted [i] = temp;
		original = original / NEW_BASE;
		i++;
	}
	if (original < 10)
		converted[i] = original + 48;
	else
		converted[i] = original + 55;
	converted[i + 1] = 0;
	return (converted);
}

void	ft_print_hex(char *original, int fd)
{
	size_t	i;
	char	*converted;

	i = 0;
	if (original[0] == '0' && (original[1] == 'x' || original[1] == 'X'))
		ft_putstr_fd(original, 1);
	else
		converted = ft_dec_2_hex((int) original);
	while (converted[i] != 0)
		i++;
	while (i != 0)
	{
		ft_putchar_fd(converted [i], 1);
		i--;
	}
	ft_putchar_fd(converted [i], 1);
}
/*
int	main(void)
{
//	char	*hex = "0x7fffffff";
//	char	*hex = "0x123456789abcdef";
//	unsigned long long int		dec = 18446744073709551615;
//	int		dec = 2147483647;

//	printf("%d is the decimal of %s hexadecimal\n", ft_hex_2_dec(hex), hex);
//	printf("%s is the hexadecimal of %d decimal\n", ft_dec_2_hex(dec), dec);
//	ft_print_hex(dec, 1);
	return (0);
}
*/