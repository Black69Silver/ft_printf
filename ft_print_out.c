/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/16 20:02:52 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		input = "(null)";
	while (input[i] != '\0')
	{
		ft_putchar_rv(input[i], rv);
		if (*rv == -1)
			return ;
		i++;
	}
}
