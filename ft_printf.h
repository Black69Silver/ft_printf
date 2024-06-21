/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:26 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/11 19:08:11 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>	// to use 'write'
# include <stdarg.h>	// to use variadic functions

void	ft_print_dec(int n, int *rv);
void	ft_print_hex(unsigned long int n, int *rv, char c);
int		ft_printf(const char *c, ...);
void	ft_putchar_rv(char input, int *rv);
void	ft_putstr_rv(char *input, int *rv);
void	ft_putunsign_rv(unsigned int n, int *rv);

#endif
